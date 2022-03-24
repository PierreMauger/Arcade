/*
** EPITECH PROJECT, 2022
** Include
** File description:
** Error
*/

#ifndef LIBLISTS_HPP
#define LIBLISTS_HPP

#include <iostream>
#include <vector>

#include "ConfigFile.hpp"

namespace arc
{
    class LibList : public ConfigFile{
        public:
            LibList(std::string fileName = "./ressources/libs.conf");
            ~LibList() = default;

            void getConf(void);
            void saveConf(void);

            std::vector<std::string> _libs;
    };
}

#endif // LIBLISTS_HPP
