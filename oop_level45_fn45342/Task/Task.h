#pragma once

#include "../ConstString/ConstString.h"

class Task {
public:
    Tast(const ConstString& str) noexcept;

    const ConstString& getDescription() const noexcept;

private:
    ConstString description;
};