#pragma once
#include <cstddef>
#include <utility>
#include <stdexcept>

template<typename Element>
class DynamicArray {
public:
    DynamicArray() noexcept;

    ~DynamicArray() noexcept;

    DynamicArray(size_t size);

    DynamicArray(const DynamicArray& other);

    DynamicArray(DynamicArray&& other) noexcept;

    DynamicArray& operator=(const DynamicArray& other);

    DynamicArray& operator=(DynamicArray&& other) noexcept;

    size_t size() const noexcept;

    size_t capacity() const noexcept;

    bool isEmpty() const noexcept;

    bool isFull() const noexcept;

    Element& operator[](size_t index);

    const Element& operator[](size_t index) const;

    void push(const Element& element);

    void pop();

    void reserve(size_t size);

    void shrinkToFit();

    size_t indexOf(bool (*finder)(const Element&)) const noexcept;

private:
    void copyOtherArray(const DynamicArray& other) noexcept;

    void destroy() noexcept;

    void moveOther(DynamicArray&& other) noexcept;

protected:
    Element* array;
    size_t arraySize;
    size_t arrayCapacity;
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
DynamicArray<Element>::DynamicArray(size_t size)
: DynamicArray{} {
    if(size > 0) {
        array = new Element[size];
        arrayCapacity = size;
    }
}

template<typename Element>
void DynamicArray<Element>::copyOtherArray(const DynamicArray& other) noexcept {
    for(; arraySize < other.arraySize; ++arraySize) {
        array[arraySize] = other.array[arraySize];
    }
}

template<typename Element>
DynamicArray<Element>::DynamicArray(const DynamicArray& other)
: DynamicArray{other.arraySize} {
    copyOtherArray(other);
}

template<typename Element>
void DynamicArray<Element>::destroy() noexcept {
    array = nullptr;
    arraySize = 0;
    arrayCapacity = 0;
}

template<typename Element>
void DynamicArray<Element>::moveOther(DynamicArray&& other) noexcept {
    array = other.array;
    arraySize = other.arraySize;
    arrayCapacity = other.arrayCapacity;
    other.destroy();
}

template<typename Element>
DynamicArray<Element>::DynamicArray(DynamicArray&& other) noexcept
: DynamicArray{} {
    moveOther(std::move(other));
}

template<typename Element>
DynamicArray<Element>& DynamicArray<Element>::operator=(const DynamicArray& other) {
    if(this != &other) {
        DynamicArray copy = other;
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
bool DynamicArray<Element>::isEmpty() const noexcept {
    return arraySize == 0;
}

template<typename Element>
bool DynamicArray<Element>::isFull() const noexcept {
    return arraySize == arrayCapacity;
}

template<typename Element>
Element& DynamicArray<Element>::operator[](size_t index) {
    return const_cast<Element&>(const_cast<const DynamicArray<Element>*>(this)->operator[](index));
}

template<typename Element>
const Element& DynamicArray<Element>::operator[](size_t index) const {
    if(index < arraySize) {
        return array[index];
    } else {
        throw std::out_of_range("invalid index");
    }
}

template<typename Element>
void DynamicArray<Element>::pop() {
    if(!isEmpty()) {
        --arraySize;
    } else {
        throw std::logic_error("empty");
    }
}

template<typename Element>
void DynamicArray<Element>::push(const Element& element) {
    if(isFull()) {
        reserve(arraySize + 2);
    }
    array[arraySize] = element;
    ++arraySize;
}

template<typename Element>
void DynamicArray<Element>::reserve(size_t size) {
    if(size > 0) {
        DynamicArray extended{arrayCapacity + size};
        extended.copyOtherArray(*this);
        operator=(std::move(extended));
    }
}

template<typename Element>
void DynamicArray<Element>::shrinkToFit() {
    DynamicArray copy = *this;
    operator=(std::move(copy));
}

template<typename Element>
size_t DynamicArray<Element>::indexOf(bool (*finder)(const Element&)) const noexcept {
    size_t index = 0;
    for(; index < arraySize; ++index) {
        if(finder(array[index])) {
            return index;
        }
    }
    return index;
}