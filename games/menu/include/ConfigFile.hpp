/*
** EPITECH PROJECT, 2022
** Include
** File description:
** Error
*/

#ifndef CONFIGFILE_HPP
#define CONFIGFILE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <regex>

#include "Error.hpp"
#include "File.hpp"

namespace arc
{
    class ConfigFile {
        public:
            ConfigFile(std::string fileName);
            ~ConfigFile() = default;

            virtual void getConf(void) = 0;
            virtual void saveConf(void) = 0;

        protected:
            std::string _fileName;
            File _file;
    };
}

#endif // CONFIGFILE_HPP
