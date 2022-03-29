/*
** EPITECH PROJECT, 2022
** Include
** File description:
** LibLoader
*/

#include "LibLoader.hpp"

arc::LibLoader::LibLoader(void)
{

}

arc::LibLoader::~LibLoader()
{
    for (auto &handle : handleList) {
        dlclose(handle);
    }
}
