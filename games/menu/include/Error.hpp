/*
** EPITECH PROJECT, 2022
** Include
** File description:
** Error
*/

#ifndef ERROR_HPP
#define ERROR_HPP

#include <string>
#include <sstream>

namespace arc
{
    class Error : virtual public std::exception
    {
        private:
            std::string _message;

        public:
            explicit Error(const std::string &message);
            ~Error() = default;
            const char* what() const noexcept override;
    };

    /**
     * @brief Define a new Error class for a new error type
     *
     */
    class FileError : public Error
    {
        public:
            explicit FileError(std::string const &message);
            ~FileError() = default;
    };

}

#endif // ERROR_HPP
