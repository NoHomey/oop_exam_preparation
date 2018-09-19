#pragma once

#include <cstddef>
#include "../ConstString/ConstString.h"
#include "../Task/Task.h"

class Employee {
public:
    Employee(ConstString& name) noexcept;

    virtual ~Employee() noexcept = default;

    virtual bool willSucceed(const Task& task) const noexcept;

    bool execute(const Task& task) noexcept;

    float successRate() const noexcept;

protected:
    ConstString emplyeeName;
    size_t completedTasks;
    size_t allTasks;
};