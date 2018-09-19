#pragma once

#include <cstddef>
#include <utility>
#include <stdexcept>

template<typename Element>
class DynamicArray {
public:
    DynamicArray() noexcept;

    ~DynamicArray() noexcept;

    DynamicArray(size_t count);

    DynamicArray(const DynamicArray& other);

    DynamicArray(DynamicArray&& other) noexcept;

    DynamicArray& operator=(const DynamicArray& other);

    DynamicArray& operator=(DynamicArray&& other) noexcept;

    size_t size() const noexcept;

    size_t capacity() const noexcept;

    size_t unusedMemory() const noexcept;

    bool isEmpty() const noexcept;

    bool isFull() const noexcept;

    const Element& operator[](size_t index) const;

    Element& operator[](size_t index);

    void reserve(size_t count);

    void shrinkToFit();

    void clear() noexcept;

    void push(const Element& element);
    
    void pop();

protected:
    Element* array;
    size_t arraySize;
    size_t arrayCapacity;

private:
    void copyOtherDynamicArrayElements(const DynamicArray& other) noexcept;

    void moveOther(DynamicArray&& other) noexcept;
};

template<typename Element>
DynamicArray<Element>::DynamicArray() noexcept
: array{nullptr}, arraySize{0}, arrayCapacity{0} {}

template<typename Element>
DynamicArray<Element>::~DynamicArray() noexcept {
    delete[] array;
    array = nullptr;
}

template<typename Element>
DynamicArray<Element>::DynamicArray(size_t count)
: array{count > 0 ? new Element[count] : nullptr}, arraySize{0}, arrayCapacity{count} {}

template<typename Element>
void DynamicArray<Element>::copyOtherDynamicArrayElements(const DynamicArray& other) noexcept {
    for(; arraySize < other.arraySize; ++arraySize) {
        array[arraySize] = other.array[arraySize];
    }
}

template<typename Element>
DynamicArray<Element>::DynamicArray(const DynamicArray& other)
: DynamicArray{other.arraySize} {
    copyOtherDynamicArrayElements(other);
}

template<typename Element>
void DynamicArray<Element>::moveOther(DynamicArray&& other) noexcept {
    delete[] array;
    array = other.array;
    arraySize = other.arraySize;
    arrayCapacity = other.arrayCapacity;
    other.array = nullptr;
}

template<typename Element>
DynamicArray<Element>::DynamicArray(DynamicArray&& other) noexcept
: DynamicArray{} {
    moveOther(std::move(other));
}

template<typename Element>
DynamicArray<Element>& DynamicArray<Element>::operator=(const DynamicArray& other) {
    if(this != &other) {
        DynamicArray copy{other};
        operator=(std::move(copy));
    }
    return *this;
}

template<typename Element>
DynamicArray<Element>& DynamicArray<Element>::operator=(DynamicArray&& other) noexcept {
    if(this != &other) {
        moveOther(std::move(other));
    }
    return *this;
}

template<typename Element>
size_t DynamicArray<Element>::size() const noexcept {
    return arraySize;
}

template<typename Element>
size_t DynamicArray<Element>::capacity() const noexcept {
    return arrayCapacity;
}

template<typename Element>
size_t DynamicArray<Element>::unusedMemory() const noexcept {
    return arrayCapacity - arraySize;
}

template<typename Element>
bool DynamicArray<Element>::isEmpty() const noexcept {
    return arraySize == 0;
}

template<typename Element>
bool DynamicArray<Element>::isFull() const noexcept {
    return arraySize == arrayCapacity;
}

template<typename Element>
const Element& DynamicArray<Element>::operator[](size_t index) const {
    if(index < arraySize) {
        return array[index];
    } else  {
        throw std::out_of_range("invalid index");
    }
}

template<typename Element>
Element& DynamicArray<Element>::operator[](size_t index) {
    return const_cast<Element&>(const_cast<const DynamicArray<Element>*>(this)->operator[](index));
}

template<typename Element>
void DynamicArray<Element>::reserve(size_t count) {
    if(count > 0) {
        DynamicArray extended{arrayCapacity + count};
        extended.copyOtherDynamicArrayElements(*this);
        operator=(std::move(extended));
    }
}

template<typename Element>
void DynamicArray<Element>::shrinkToFit() {
    DynamicArray copy(*this);
    operator=(std::move(copy));
}

template<typename Element>
void DynamicArray<Element>::clear() noexcept {
    delete[] array;
    array = nullptr;
    arraySize = 0;
    arrayCapacity = 0;
}

template<typename Element>
void DynamicArray<Element>::push(const Element& element) {
    if(isFull()) {
        reserve(arrayCapacity + 2);
    }
    array[arraySize] = element;
    ++arraySize;
}

template<typename Element>
void DynamicArray<Element>::pop() {
    if(!isEmpty()) {
        --arraySize;
    } else {
        throw std::logic_error("empty");
    }
}