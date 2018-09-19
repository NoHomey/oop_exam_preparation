#pragma once

#include "../Worker/Worker.h"

class Expert: public Worker {
public:
    Expert(ConstString& name);
};