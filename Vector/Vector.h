#pragma once

#include <cstddef>

template<typename Type>
class Vector {
public:
    Vector();

    explicit Vector(size_t size);

    ~Vector() noexcept;

    Vector(const Vector& other);

    Vector& operator=(const Vector& other);

    size_t size() const noexcept;

    size_t capacity() const noexcept;

    Type& operator[](size_t index);

    const Type& operator[](size_t index) const;

    void push(const Type& element);

    void pop();

protected:
    Type* array;
    size_t arraySize;
    size_t arrayCapacity;

private:
    void copy(const Vector& other) noexcept;

    void reallocate(size_t size);

    size_t expandedCapacity() const noexcept;

    void reallocate();
};