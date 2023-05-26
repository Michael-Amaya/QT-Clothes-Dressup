#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>

#include "config_reader.h"

ConfigReader::ConfigReader(const std::string config_location): config{} {

    std::ifstream infile{config_location};
    if (!infile) {
        // Gotta throw an error
        // TODO: Make an error for ConfigReader when a file is not read correctly.
        return;
    }

    std::regex rgx{"^([\\w]+)[\\s]*[=][\\s]*(.*)$"};
    std::smatch matches;
    
    std::string current_line{};
    while (std::getline(infile, current_line)) {
        if (std::regex_search(current_line, matches, rgx)) {
            // matches[1] is key, matches[2] is val
            config[matches[1]] = matches[2];
        }
    }
}

std::string ConfigReader::getConfig(const std::string key) {
    return this->config[key];
}

    
std::string ConfigReader::getInfo() {
    std::string toReturn{};
    for (const auto& [key, value] : this->config) {
        toReturn += key + ": " + value + ", ";
    }

    return toReturn;
}
