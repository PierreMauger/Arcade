/*
** EPITECH PROJECT, 2022
** Include
** LibLoader description:
** LibLoader
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
    class LibLoader {
        public:
            LibLoader(void);
            ~LibLoader();

            // ex: std::unique_ptr<IGame> (void)
            template<class T, class F>
            std::function<T> getLibLoader(std::string libName, std::string functionName)
            {
                std::function<T> entryPoint = nullptr;
                void *handle = NULL;

                handle = dlopen(libName.c_str(), RTLD_LAZY);
                if (handle == NULL) {
                    throw arc::FileError("FileError: " + dlerror());
                }
                entryPoint = std::function<T>(reinterpret_cast<F>(dlsym(handle, functionName.c_str())));
                if (entryPoint == nullptr) {
                    throw arc::FileError("FileError: " + dlerror());
                }
                this->handleList.emplace_back(handle);
                return entryPoint;
            }

        private:
            std::vector<void *> handleList;
    };
}

#endif // GAMELOADER_HPP
