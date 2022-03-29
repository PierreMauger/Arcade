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
    template<class T>
    class GameLoader {
        public:
            GameLoader(void);
            ~GameLoader();

            // ex: std::unique_ptr<IGame> (void)
            std::function<T> getLib(std::string libName);

            template<class T>
            std::function<T> arc::GameLoader::getLib(std::string libName, std::string functionName)
            {
                std::function<T> entryPoint = nullptr;

                this->handle = dlopen(libName.c_str(), RTLD_LAZY);
                if (this->handle == NULL) {
                    throw arc::FileError("FileError: Cannot open lib file.");
                }
                // To verif
                entryPoint = std::function<T>(reinterpret_cast<std::unique_ptr<T> (*)(void)>(dlsym(handle, functionName.c_str())));
                if (entryPoint == nullptr) {
                    throw arc::FileError("FileError: Bad lib file.");
                }
                return entryPoint;
            }

        private:
            void *handle;
    };
}

#endif // GAMELOADER_HPP
