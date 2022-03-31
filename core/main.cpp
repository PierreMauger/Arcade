/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** main
*/

#include "Core.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: ./arcade <lib_name>" << std::endl;
        return 84;
    }
    try {
        arc::Core core(argv[1]);
        core.coreLoop();
    } catch (arc::FileError const &error) {
        std::cerr << error.what() << std::endl;
        return 84;
    }
    return 0;
}
