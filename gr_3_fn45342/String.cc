#include "String.h"

size_t String::stringLength(const char* str) noexcept {
    if(str == nullptr) {
        return 0;
    }
    size_t length = 0;
    while(true) {
        if(str[length] == '\0') {
            return length;
        }
        ++length;
    }
}

String::String(const char* str)
: Base{stringLength(str) + 1} {
    for(; arraySize < arrayCapacity; ++arraySize) {
        array[arraySize] = str[arraySize];
    }
    array[arraySize - 1] = '\0';
}

size_t String::length() const noexcept {
    return arraySize - 1;
}

bool String::operator==(const String& other) const noexcept {
    const size_t thisLength = length();
    if(length() != other.length()) {
        return false;
    }
    for(size_t index = 0; index < thisLength; ++index) {
        if(array[index] != other.array[index]) {
            return false;
        }
    }
    return true;
}

bool String::operator!=(const String& other) const noexcept {
    return !operator==(other);
}

String& String::operator+=(const String& other) {
    Base::reserve(other.length());
    for(size_t index = arraySize; index < arrayCapacity; ++index) {
        array[index - 1] = other[index - arraySize];
    }
    array[arrayCapacity - 1] = '\0';
    arraySize = arrayCapacity;
    return *this;
}

String String::operator+(const String& other) const {
    String copy = *this;
    copy += other;
    return copy;
}

const char* String::cString() const noexcept {
    return array;
}

std::ostream& operator<<(std::ostream& out, const String& str) noexcept {
    if(!str.isEmpty()) {
        out.write(str.cString(), str.length());
    }
    return out;
}