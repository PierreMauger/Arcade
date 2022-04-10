/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Core
*/

#include "Core.hpp"

static const std::string SIDE_MENU[] = {
    "  - F1 -",
    " < Graph",
    "  - F2 -",
    "  Graph >",
    "  - F3 -",
    " < Game",
    "  - F4 -",
    "   Game >",
    "  - F5 -",
    "  Restart",
    "  - F6 -",
    "   Menu",
    "  - F7 -",
    "   Exit",
    "  - F8 -",
    "  Pause",
    ""
};

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
_scoreList("./ressources/scores.conf"),
_graphList("./ressources/graphics.conf"),
_gameList("./ressources/games.conf"),
_sideMenu(std::vector<std::vector<int>>(40, std::vector<int>(10, 0)))
{
    this->_graphList.getConf();
    this->_gameList.getConf();
    this->_scoreList.getConf();
    this->getMenuEntryPoint();
    this->getGamesEntryPoint();
    this->getGraphsEntryPoint();
    this->getGraphLibByName(graphLibName);
    this->loadGameLib(this->_menuEntryPoint);
    this->initSideMenu();
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
    this->loadGraphLib(this->_graphEntryPoint[pos]);
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

void arc::Core::getMenuEntryPoint(void)
{
    this->_menuEntryPoint = this->_libLoader.getLibLoader<IGame *(void), IGame *(*)(void)>(std::string(PATH_LIBS + std::string("arcade_menu.so")) , "entryPoint");
}

void arc::Core::getGamesEntryPoint(void)
{
    for (auto it : this->_gameList._libs) {
        this->_gameEntryPoint.emplace_back(
            this->_libLoader.getLibLoader<IGame *(void), IGame *(*)(void)>(std::string(PATH_LIBS + it + ".so"), "entryPoint")
        );
    }
}

void arc::Core::getGraphsEntryPoint(void)
{
    for (auto it : this->_graphList._libs) {
        this->_graphEntryPoint.emplace_back(
            this->_libLoader.getLibLoader<IDisplay *(void), IDisplay *(*)(void)>(std::string(PATH_LIBS + it + ".so"), "entryPoint")
        );
    }
}

void arc::Core::initSideMenu(void)
{
    for (std::size_t i = 0; i < this->_sideMenu.size() && !SIDE_MENU[i].empty(); i++) {
        for (std::size_t j = 0; j < this->_sideMenu[i].size(); j++) {
            this->_sideMenu[i * 2 + i / 2][j] = SIDE_MENU[i][j] | arc::GameColor::G_WHITE << 16;
        }
    }
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
    for (std::size_t y = 0; y < this->_sideMenu.size(); y++) {
        for (std::size_t x = 0; x < this->_sideMenu[y].size(); x++) {
            if ((this->_sideMenu[y][x]) != 0) {
                this->_graph->drawLetter(this->getLetter(this->_sideMenu[y][x]), this->getColor(this->_sideMenu[y][x]), x + map[y].size(), y);
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

void arc::Core::loadGameLib(std::function<IGame *(void)> entryPoint)
{
    this->_game = std::unique_ptr<IGame>(entryPoint());
    this->_game->initGame();
    this->_game->setGameState(State::START);
    this->_gameName = this->_game->getGameName();
}

void arc::Core::loadGraphLib(std::function<IDisplay *(void)> entryPoint)
{
    this->_graph = std::unique_ptr<IDisplay>(entryPoint());
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
        this->_gameIdx = this->_gameEntryPoint.size() - 1;
    } else {
        this->_gameIdx--;
    }
    this->loadGameLib(this->_gameEntryPoint[this->_gameIdx]);
}

void arc::Core::nextGame(void)
{
    this->unloadGameLib();
    if (this->_gameIdx == this->_gameEntryPoint.size() - 1) {
        this->_gameIdx = 0;
    } else {
        this->_gameIdx++;
    }
    this->loadGameLib(this->_gameEntryPoint[this->_gameIdx]);
}

void arc::Core::restartGame(void)
{
    this->unloadGameLib();
    this->loadGameLib(this->_gameEntryPoint[this->_gameIdx]);
}

void arc::Core::menuGame(void)
{
    this->unloadGameLib();
    this->loadGameLib(this->_menuEntryPoint);
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
        this->_graphIdx = this->_graphEntryPoint.size() - 1;
    } else {
        this->_graphIdx--;
    }
    this->loadGraphLib(this->_graphEntryPoint[this->_graphIdx]);
}

void arc::Core::nextGraph(void)
{
    this->unloadGraphLib();
    if (this->_graphIdx == this->_graphEntryPoint.size() - 1) {
        this->_graphIdx = 0;
    } else {
        this->_graphIdx++;
    }
    this->loadGraphLib(this->_graphEntryPoint[this->_graphIdx]);
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
