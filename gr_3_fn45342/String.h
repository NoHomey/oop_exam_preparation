#pragma once
#include "DynamicArray.h"
#include<iostream>

class String: public DynamicArray<char> {
private:
    using Base = DynamicArray<char>;

    size_t size() const noexcept;

    size_t capacity() const noexcept;

    bool isFull() const noexcept;

    void push(const char&);

    void pop();

    void reserve(size_t);

    void shrinkToFit();

public:
    String() noexcept = default;

    ~String() noexcept = default;

    String(const char* str);

    String(const String& other) = default;

    String(String&& other) noexcept = default;

    String& operator=(const String& other) = default;

    String& operator=(String&& other) noexcept = default;

    size_t length() const noexcept;

    bool operator==(const String& other) const noexcept;

    bool operator!=(const String& other) const noexcept;

    String& operator+=(const String& other);

    String operator+(const String& other) const;

    const char* cString() const noexcept;

private:
    static size_t stringLength(const char* str) noexcept;
};

std::ostream& operator<<(std::ostream& out, const String& str) noexcept;