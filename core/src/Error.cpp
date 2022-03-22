/*
** EPITECH PROJECT, 2022
** Include
** File description:
** Link
*/

#include "Error.hpp"

arc::Error::Error(const std::string &message) : _message(message)
{

}

const char* arc::Error::what() const noexcept
{
    return _message.c_str();
}

arc::FileError::FileError(std::string const &message) : arc::Error(message)
{

}
