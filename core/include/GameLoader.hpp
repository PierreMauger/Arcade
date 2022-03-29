/*
** EPITECH PROJECT, 2022
** Include
** GameLoader description:
** GameLoader
*/

#ifndef GAMELOADER_HPP
#define GAMELOADER_HPP

#include <memory>
#include <string>
#include <dlfcn.h>
#include <elf.h>
#include <functional>

#include "IGame.hpp"

#include "Error.hpp"

namespace arc {
    class GameLoader {
        public:
            GameLoader(void);
            ~GameLoader();

            // ex: std::unique_ptr<IGame> (void)
            template<class T>
            std::function<T> getLib(std::string libName, std::string functionName)
            {
                std::function<T> entryPoint = nullptr;
                void *handle = NULL;

                handle = dlopen(libName.c_str(), RTLD_LAZY);
                if (handle == NULL) {
                    throw arc::FileError("FileError: Cannot open lib file.");
                }
                entryPoint = std::function<T>(reinterpret_cast<std::unique_ptr<T> (*)(void)>(dlsym(handle, functionName.c_str())));
                if (entryPoint == nullptr) {
                    throw arc::FileError("FileError: Bad lib file.");
                }
                this->handleList.push_back(handle);
                return entryPoint;
            }

        private:
            std::vector<void *> handleList;
    };
}

#endif // GAMELOADER_HPP
