#include "ConstString.h"

ConstString::ConstString(const char* str, size_t size)
: string{size}, stringLength{size} {
    for(size_t index = 0; index < size; ++index) {
        string.push(str[index]);
    }
}

char ConstString::operator[](size_t index) const noexcept {
    if(index < stringLength) {
        return string[index];
    } else {
        return '\0';
    }
}

size_t ConstString::length() const noexcept {
    return stringLength;
}

std::ostream& operator<<(std::ostream& out, const ConstString& string) {
    const size_t length = string.length();
    for(size_t index = 0; index < length; ++index) {
        out << string[index];
    }
    return out;
}