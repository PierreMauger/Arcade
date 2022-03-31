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
    // {DisplayKey::D_F8, &Core:: /* assign */ },
    // {DisplayKey::D_F9, &Core:: /* assign */ },
    // {DisplayKey::D_F10, &Core:: /* assign */ },
    // {DisplayKey::D_F11, &Core:: /* assign */ },
    // {DisplayKey::D_F12, &Core:: /* assign */ },
};

arc::Core::Core(std::string graphLibName) :
_scoreList("./ressources/scores.conf"),
_graphList("./ressources/graphics.conf"),
_gameList("./ressources/games.conf")
{
    this->_graphList.getConf();
    // this->_gameList.getConf();
    this->_scoreList.getConf();
    this->getMenuEntryPoint();
    this->getGamesEntryPoint();
    this->getGraphsEntryPoint();
    this->getGraphLibByName(graphLibName);
    this->loadGameLib(this->_menuEntryPoint);
}

arc::Core::~Core()
{
}

void arc::Core::getGraphLibByName(std::string graphLibName)
{
    std::size_t pos = std::distance(this->_graphList._libs.begin(), std::find(this->_graphList._libs.begin(), this->_graphList._libs.end(), graphLibName));

    if (pos == this->_graphList._libs.size()) {
        throw FileError("FileError: " + graphLibName + " is not a valid lib name.");
    }
    this->_graphIdx = pos;
    this->loadGraphLib(this->_graphEntryPoint[pos]);
}

void arc::Core::getMenuEntryPoint(void)
{
    this->_menuEntryPoint = this->_libLoader.getLibLoader<std::unique_ptr<IGame> (void), std::unique_ptr<IGame> (*)(void)>(std::string(PATH_LIBS + std::string("arcade_menu.so")) , "entryPoint");
}

void arc::Core::getGamesEntryPoint(void)
{
    for (auto it : this->_gameList._libs) {
        this->_gameEntryPoint.push_back(
            this->_libLoader.getLibLoader<std::unique_ptr<IGame> (void), std::unique_ptr<IGame> (*)(void)>(std::string(PATH_LIBS + it), "entryPoint")
        );
    }
}

void arc::Core::getGraphsEntryPoint(void)
{
    for (auto it : this->_graphList._libs) {
        this->_graphEntryPoint.push_back(
            this->_libLoader.getLibLoader<std::unique_ptr<IDisplay> (void), std::unique_ptr<IDisplay> (*)(void)>(std::string(PATH_LIBS + it), "entryPoint")
        );
    }
}

void arc::Core::drawIdx(unsigned char idx, std::size_t x, std::size_t y)
{
    for(auto it = this->shapes.cbegin(); it != this->shapes.cend(); ++it) {
        if ((it->first & idx) == it->first) {
            std::bind(it->second, this->_graph, idx ^ it->first, x, y);
        }
    }
}

void arc::Core::browseMap(void)
{
    unsigned char **map;

    if (this->_game == nullptr || this->_graph == nullptr)
        return;
    map = this->_game->getMap();
    for (std::size_t y = 0; map[y] != nullptr; y++) {
        for (std::size_t x = 0; map[x][y] != '\0'; x++) {
            if ((map[x][y] & 0b10000000) == 0b10000000) {
                drawIdx(map[x][y], x, y);
            } else {
                this->_graph->drawLetter(map[x][y], x, y);
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
            std::bind(keyPos->second, this->_graph);
        } else {
            keyUpdate.push_back((GameKey)(*key));
        }
    }
    this->_game->update(keyUpdate);
}

void arc::Core::coreLoop(void)
{
    while (this->_exit == false) {
        this->browseMap();
        this->coreKey();
        this->_graph->display();
    }
}

void arc::Core::loadGameLib(std::function<std::unique_ptr<IGame>(void)> entryPoint)
{
    this->_game = entryPoint();
    this->_game->initGame();
    this->_game->setGameState(State::START);
}

void arc::Core::loadGraphLib(std::function<std::unique_ptr<IDisplay>(void)> entryPoint)
{
    this->_graph = entryPoint();
    this->_graph->initDisplay();
}

void arc::Core::unloadGameLib(void)
{
    this->_game->destroyGame();
    this->_game = nullptr;
}

void arc::Core::unloadGraphLib(void)
{
    this->_graph->destroyDisplay();
    this->_graph = nullptr;
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
