/*
** EPITECH PROJECT, 2022
** Include
** File description:
** GameLoader
*/

#include "GameLoader.hpp"

arc::GameLoader::GameLoader(void)
{

}

arc::GameLoader::~GameLoader()
{
    for (auto &handle : handleList) {
        dlclose(handle);
    }
}
