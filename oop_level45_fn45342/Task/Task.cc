#include "Task.h"

Tast::Tast(const ConstString& str) noexcept
: description{str} {}

const ConstString& Tast::getDescription() const noexcept {
    return description;
}