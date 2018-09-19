#include "Employee.h"

Employee::Employee(ConstString& name) noexcept
: employeeName{name}, completedTasks{0}, allTasks{0} {}

bool Employee::execute(const Task& task) noexcept {
    const bool successful = willSucceed(task);
    if(successful) {
        ++completedTasks;
    }
    ++allTasks;
    return successful;
}

float Employee::successRate() const noexcept {
    return static_cast<float>(completedTasks) / static_cast<float>(allTasks);
}