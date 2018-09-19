#pragma once

#include "../Employee/Employye.h"

class Worker: pulic Worker {
public:
    Worker(ConstString& name, size_t k);

    bool willSucceed(const Task& task) const noexcept final;

protected:
    size_t failNumber;
};