#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <cctype>
#include <map>
#include <string>

#include "include/header.hpp"

std::string enumToString(int value);
int stringToEnum(std::string value);
std::string upper(std::string);
#endif