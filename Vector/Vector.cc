#include "Vector.h"

#include <new>
#include <stdexcept>

template<typename Type>
Vector<Type>::Vector(size_t size)
: array{new Type[size]}, arraySize{0}, arrayCapacity{size} { }

template<typename Type>
Vector<Type>::~Vector() noexcept {
    delete[] array;
    array = nullptr;
}

template<typename Type>
Vector<Type>::Vector(const Vector& other)
: Vector{other.arrayCapacity} {
    copy(other);
}

template<typename Type>
Vector<Type>& Vector<Type>::operator=(const Vector& other) {
    if(this != &other) {
        if(arrayCapacity < other.arrayCapacity) {
            reallocate(other.arrayCapacity);
        }
        copy(other);
    }
    return *this;
}

template<typename Type>
size_t Vector<Type>::size() const noexcept {
    return arraySize;
}

template<typename Type>
size_t Vector<Type>::capacity() const noexcept {
    return arrayCapacity;
}

template<typename Type>
Type& Vector<Type>::operator[](size_t index) {
    if(index < arraySize) {
        return array[index];
    }
    throw std::out_of_range("invalid index");
}

template<typename Type>
const Type& Vector<Type>::operator[](size_t index) const {
    if(index < arraySize) {
        return array[index];
    }
    throw std::out_of_range("invalid index");
}

template<typename Type>
void Vector<Type>::push(const Type& element) {
    if(arraySize == arrayCapacity) {
        reallocate();
    }
    array[arraySize] = element;
    ++arraySize;
}

template<typename Type>
void Vector<Type>::pop() {
    if(arraySize > 0) {
        --arraySize;
    } else {
        throw std::length_error("vector is empty");
    }
}

template<typename Type>
void Vector<Type>::copy(const Vector& other) noexcept {
    for(arraySize = 0; arraySize < other.arraySize; ++arraySize) {
        array[arraySize] = other.array[arraySize];
    }
}

template<typename Type>
void Vector<Type>::reallocate(size_t size) {
    Type* tmp = new Type[size];
    delete[] array;
    array = tmp;
    arrayCapacity = size;
}

template<typename Type>
size_t Vector<Type>::expandedCapacity() const noexcept {
    size_t expanded = 16;
    for(unsigned int test = 64; test <= 256; test <<= 1) {
        if(arraySize > test) {
            expanded <<= 1;
        }
    }
    return arrayCapacity + expanded;
}

template<typename Type>
void Vector<Type>::reallocate() {
    reallocate(expandedCapacity());
}

template class Vector<int>;