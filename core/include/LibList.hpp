/*
** EPITECH PROJECT, 2022
** Include
** File description:
** Error
*/

#ifndef LIBLISTS_HPP
#define LIBLISTS_HPP

#include "ConfigFile.hpp"

namespace arc
{
    class LibList : public ConfigFile {
        public:
            LibList(std::string fileName);
            ~LibList() = default;

            void getConf(void);
            void saveConf(void);

            std::vector<std::string> _libs;

        private:
            std::string getRawLibName(std::string libName);
    };
}

#endif // LIBLISTS_HPP
