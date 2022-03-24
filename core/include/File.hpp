/*
** EPITECH PROJECT, 2022
** Include
** File description:
** File
*/

#ifndef FILE_HPP
#define FILE_HPP

#include <string>
#include <fstream>
#include <iostream>

#include "Error.hpp"

namespace arc {
    class File {
        public:
            File(void) = default;
            ~File() = default;
            std::string &getFileBuff(void);
            void readFile(std::string fileName);

        private:
            std::string _file;
    };
}

#endif // FILE_HPP
