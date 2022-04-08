/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Core
*/

#include "Core.hpp"

std::map<arc::Shape, std::function<void (arc::IDisplay *, unsigned char, std::size_t, std::size_t)>> arc::Core::shapes = {
    {Shape::SQUARE, &IDisplay::drawSquare},
    {Shape::CIRCLE, &IDisplay::drawCircle},
    {Shape::CROSS, &IDisplay::drawCross},
};

std::map<arc::DisplayKey, std::function<void (arc::Core *)>> arc::Core::coreEvent = {
    {DisplayKey::D_F1, &Core::previousGraph},
    {DisplayKey::D_F2, &Core::nextGraph},
    {DisplayKey::D_F3, &Core::previousGame},
    {DisplayKey::D_F4, &Core::nextGame},
    {DisplayKey::D_F5, &Core::restartGame},
    {DisplayKey::D_F6, &Core::menuGame},
    {DisplayKey::D_F7, &Core::exit},
    {DisplayKey::D_F8, &Core::pauseGame},
    // {DisplayKey::D_F9, &Core:: /* assign */ },
    // {DisplayKey::D_F10, &Core:: /* assign */ },
    // {DisplayKey::D_F11, &Core:: /* assign */ },
    // {DisplayKey::D_F12, &Core:: /* assign */ },
};

arc::Core::Core(std::string graphLibName) :
_gameList("./ressources/games.conf"),
_graphList("./ressources/graphics.conf"),
_scoreList("./ressources/scores.conf")
{
    this->_graphList.getConf();
    this->_gameList.getConf();
    this->_scoreList.getConf();
    this->getGraphLibByName(graphLibName);
    this->loadGameLib(this->execGameEntryPoint("arcade_menu.so"));
}

arc::Core::~Core()
{
    this->unloadGameLib();
    this->unloadGraphLib();
    this->_scoreList.saveConf();
}

void arc::Core::getGraphLibByName(std::string graphLibName)
{
    std::string rawLibName = this->getRawLibName(graphLibName);
    std::size_t pos;

    pos = std::distance(this->_graphList._libs.begin(), std::find(this->_graphList._libs.begin(), this->_graphList._libs.end(), rawLibName));
    if (pos == this->_graphList._libs.size()) {
        throw FileError("FileError: " + rawLibName + " is not a valid lib name.");
    }
    this->_graphIdx = pos;
    this->loadGraphLib(this->execGraphEntryPoint(this->_graphList._libs[this->_graphIdx] + ".so"));
}

std::string arc::Core::getRawLibName(std::string libName)
{
    std::smatch match;
    std::regex reg("((.*\\/)?)(\\S+)(\\.so)");
    std::regex_search(libName, match, reg);
    auto lastElem = match.str(match.size() - 1);

    if (lastElem != ".so") {
        throw FileError("FileError: " + libName + " is not a valid lib name.");
    }
    return match.str(match.size() - 2);
}

std::unique_ptr<arc::IGame> arc::Core::execGameEntryPoint(std::string gameLibName)
{
    std::function<IGame *(void)> entryPointFunc =
        this->_libLoader.getLibLoader<IGame *(void), IGame *(*)(void)>(std::string(PATH_LIBS + gameLibName) , "entryPoint");
    IGame *game = entryPointFunc();

    this->_libLoader.closeHandlers();
    return std::unique_ptr<IGame>(game);
}

std::unique_ptr<arc::IDisplay> arc::Core::execGraphEntryPoint(std::string graphLibName)
{
    std::function<IDisplay *(void)> entryPointFunc =
        this->_libLoader.getLibLoader<IDisplay *(void), IDisplay *(*)(void)>(std::string(PATH_LIBS + graphLibName) , "entryPoint");
    IDisplay *graph = entryPointFunc();

    this->_libLoader.closeHandlers();
    return std::unique_ptr<IDisplay>(graph);
}

void arc::Core::drawIdx(int idx, std::size_t x, std::size_t y)
{
    Shape shapeIdx = this->getShape(idx);

    for(auto it = this->shapes.cbegin(); it != this->shapes.cend(); it++) {
        if (it->first == shapeIdx) {
            std::bind(it->second, this->_graph.get(), this->getColor(idx), x, y);
            it->second(this->_graph.get(), this->getColor(idx), x, y);
            break;
        }
    }
}

void arc::Core::browseMap(void)
{
    std::vector<std::vector<int>> map;

    if (this->_game == nullptr || this->_graph == nullptr)
        return;
    map = this->_game->getMap();
    for (std::size_t y = 0; y < map.size(); y++) {
        for (std::size_t x = 0; x < map[y].size(); x++) {
            if ((map[y][x]) != 0) {
                if (this->getLetter(map[y][x]) == 0) {
                    drawIdx(map[y][x], x, y);
                } else {
                    this->_graph->drawLetter(this->getLetter(map[y][x]), this->getColor(map[y][x]), x, y);
                }
            }
        }
    }
}

void arc::Core::coreKey(void)
{
    std::vector<DisplayKey> keys = this->_graph->getKeys();
    std::vector<GameKey> keyUpdate;

    for (auto key = keys.begin(); key != keys.end(); key++) {
        if (*key >= DisplayKey::D_F1 && *key <= DisplayKey::D_F12) {
            auto keyPos = coreEvent.find(*key);
            if (keyPos != coreEvent.end()) {
                keyPos->second(this);
            }
        } else {
            keyUpdate.push_back((GameKey)(*key));
        }
    }
    this->_game->update(keyUpdate);
}

void arc::Core::coreLoop(void)
{
    auto lastIteration = std::chrono::high_resolution_clock::now();
    auto currentIteration = std::chrono::high_resolution_clock::now();
    double elapsed = 0;

    while (this->_exit == false) {
        currentIteration = std::chrono::high_resolution_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(currentIteration - lastIteration).count();
        for (; elapsed >= FRAME_RATE; elapsed -= FRAME_RATE) {
            lastIteration = currentIteration;
            this->browseMap();
            this->coreKey();
            this->_score = this->_game->getScore();
            this->_graph->display();
        }
    }
}

void arc::Core::loadGameLib(std::unique_ptr<IGame> gameLib)
{
    this->_game = std::move(gameLib);
    this->_game->initGame();
    this->_game->setGameState(State::START);
    this->_gameName = this->_game->getGameName();
}

void arc::Core::loadGraphLib(std::unique_ptr<IDisplay> graphLib)
{
    this->_graph = std::move(graphLib);
    this->_graph->initDisplay();
}

void arc::Core::unloadGameLib(void)
{
    this->changePlayerName();
    if (this->_score != 0)
        this->_scoreList.addScore(this->_gameName, this->_playerName, this->_score);
    this->_game->destroyGame();
    this->_game.reset();
}

void arc::Core::unloadGraphLib(void)
{
    this->_graph->destroyDisplay();
    this->_graph.reset();
}

void arc::Core::previousGame(void)
{
    this->unloadGameLib();
    if (this->_gameIdx == 0) {
        this->_gameIdx = this->_gameList._libs.size() - 1;
    } else {
        this->_gameIdx--;
    }
    this->loadGameLib(this->execGameEntryPoint(this->_gameList._libs[this->_gameIdx] + ".so"));
}

void arc::Core::nextGame(void)
{
    this->unloadGameLib();
    if (this->_gameIdx == this->_gameList._libs.size() - 1) {
        this->_gameIdx = 0;
    } else {
        this->_gameIdx++;
    }
    this->loadGameLib(this->execGameEntryPoint(this->_gameList._libs[this->_gameIdx] + ".so"));
}

void arc::Core::restartGame(void)
{
    this->unloadGameLib();
    this->loadGameLib(this->execGameEntryPoint(this->_gameList._libs[this->_gameIdx] + ".so"));
}

void arc::Core::menuGame(void)
{
    this->unloadGameLib();
    this->loadGameLib(this->execGameEntryPoint("arcade_menu.so"));
}

void arc::Core::exit(void)
{
    this->_exit = true;
}

void arc::Core::pauseGame(void)
{
    State state = this->_game->getGameState();

    if (state == State::START)
        this->_game->setGameState(State::PAUSE);
    else if (state == State::PAUSE)
        this->_game->setGameState(State::START);
}

void arc::Core::previousGraph(void)
{
    this->unloadGraphLib();
    if (this->_graphIdx == 0) {
        this->_graphIdx = this->_graphList._libs.size() - 1;
    } else {
        this->_graphIdx--;
    }
    this->loadGraphLib(this->execGraphEntryPoint(this->_graphList._libs[this->_graphIdx] + ".so"));
}

void arc::Core::nextGraph(void)
{
    this->unloadGraphLib();
    if (this->_graphIdx == this->_graphList._libs.size() - 1) {
        this->_graphIdx = 0;
    } else {
        this->_graphIdx++;
    }
    this->loadGraphLib(this->execGraphEntryPoint(this->_graphList._libs[this->_graphIdx] + ".so"));
}

char arc::Core::getLetter(int mapIdx)
{
    return (char)mapIdx;
}

arc::Shape arc::Core::getShape(int mapIdx)
{
    mapIdx <<= 16;
    return (Shape)(mapIdx >>= 24);
}

arc::GameColor arc::Core::getColor(int mapIdx)
{
    mapIdx <<= 8;
    return (GameColor)(mapIdx >>= 24);
}

void arc::Core::changePlayerName(void)
{
    std::string name = this->_game->getPlayerName();

    if (name != "") {
        this->_playerName = name;
    }
}
