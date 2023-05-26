#pragma once

#include <string>
#include "clothe_classifiers.h"

// Not done yet
class DatabaseSystem {
private:
public:
    DatabaseSystem() = default;
    virtual ~DatabaseSystem() = default;
    virtual bool connect(){ return false; };

    virtual ClotheClassifiers getClassifiers(){ return ClotheClassifiers{}; };
};
