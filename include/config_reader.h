#pragma once
#include <map>
#include <string>

class ConfigReader {
private:
    std::map<std::string, std::string> config;

public:
    ConfigReader(const std::string config_location);
    ~ConfigReader() = default;

    std::string getInfo();
    std::string getConfig(const std::string key);
};