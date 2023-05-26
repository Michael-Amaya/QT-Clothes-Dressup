#pragma once
#include <vector>
#include <string>
#include <memory>

class ClotheClassifiers {
private:
    std::vector<std::string> classifiers;
public:
    ClotheClassifiers();
    virtual ~ClotheClassifiers() = default;
    
    void addClassifier(std::string classifier);
    std::string getClassifierString();
    std::unique_ptr<std::vector<std::string>> getClassifiers();
};
