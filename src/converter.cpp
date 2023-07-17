#include "include/converter.hpp"

std::string enumToString(int value) {
    switch (value) {
        case E1:
            return "E1";
        case E2:
            return "E2";
        case E3:
            return "E3";
        case E4:
            return "E4";
        case E5:
            return "E5";
        case E6:
            return "E6";
        case E7:
            return "E7";
        case E8:
            return "E8";
        case E9:
            return "E9";
        case E10:
            return "E10";
        case E11:
            return "E11";
        case E12:
            return "E12";
        case E13:
            return "E13";
        case E14:
            return "E14";
        default:
            return "Unknown";
    }
}
int stringToEnum(std::string value) {
    static const std::map<std::string, ESTACOES> enumMap{
        {"E1", E1},   {"E2", E2},   {"E3", E3},   {"E4", E4},  {"E5", E5},
        {"E6", E6},   {"E7", E7},   {"E8", E8},   {"E9", E9},  {"E10", E10},
        {"E11", E11}, {"E12", E12}, {"E13", E13}, {"E14", E14}};

    auto it = enumMap.find(value);
    if (it != enumMap.end()) {
        return it->second;
    } else {
        return -1;
    }
}

std::string upper(std::string str) {
    std::string result = str;
    for (char& c : result) {
        c = std::toupper(c);
    }

    return result;
}