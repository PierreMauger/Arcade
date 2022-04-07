/*
** EPITECH PROJECT, 2022
** Include
** File description:
** LibLoader
*/

#include "LibLoader.hpp"
#include <unistd.h>

arc::LibLoader::LibLoader(void)
{

}

void arc::LibLoader::closeHandlers(void)
{
    for (auto handle : this->handleList) {
        dlclose(handle);
    }
}
