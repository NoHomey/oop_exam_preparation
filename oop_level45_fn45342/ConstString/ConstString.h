#pragma once

#include <iostream>

#include "../DynamicArray.h"

class ConstString {
public:
    ConstString(const char* str, size_t size);

    char operator[](size_t index) const noexcept;

    size_t length() const noexcept;

private:
    DynamicArray<char> string;
    size_t stringLength;
};

std::ostream& operator<<(std::ostream& out, const ConstString& string);