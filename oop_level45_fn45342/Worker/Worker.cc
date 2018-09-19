#include "Worker"

Worker::Worker(ConstString& name, size_t k)
: Employee{name}, failNumber{k} {}

bool Worker::willSucceed(const Task& task) const noexcept final {
    if(failNumber == 0) {
        return true;
    }
    return ((allTasks + 1) % failNumber) != 0;
}