#include <vector>
#include <memory>
#include <string>

#include "clothe_classifiers.h"


ClotheClassifiers::ClotheClassifiers() : classifiers{} {

}

void ClotheClassifiers::addClassifier(std::string classifier) {
    this->classifiers.push_back(classifier);
}

std::string ClotheClassifiers::getClassifierString() {
    std::string toReturn{};

    for(auto ptr = this->classifiers.begin(); ptr < this->classifiers.end(); ptr++) {
        toReturn += *ptr + "\n";
    }

    return toReturn;
}

std::unique_ptr<std::vector<std::string>> ClotheClassifiers::getClassifiers() {
    return std::make_unique<std::vector<std::string>>(this->classifiers);
}