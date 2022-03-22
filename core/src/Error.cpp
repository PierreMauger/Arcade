/*
** EPITECH PROJECT, 2022
** Include
** File description:
** Link
*/

#include "Error/Error.hpp"

#include <iostream>

nts::Error::Error(const std::string &message) : _message(message)
{

}

const char* nts::Error::what() const noexcept
{
    return _message.c_str();
}

nts::FileError::FileError(std::string const &message) : nts::Error(message)
{

}

nts::ComponentError::ComponentError(std::string const &message) : nts::Error(message)
{

}

nts::CommandError::CommandError(std::string const &message) : nts::Error(message)
{

}
