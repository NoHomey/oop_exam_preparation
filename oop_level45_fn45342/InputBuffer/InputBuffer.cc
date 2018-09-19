#include "InputBuffer.h"

InputBuffer::InputBuffer(size_t count)
: DynamicArray<char>(count) {}

char* InputBuffer::obtainBufferForInput() noexcept {
    return array;
}

void InputBuffer::syncSize(size_t count) noexcept {
    arraySize = count <= arrayCapacity ? count : arrayCapacity;
}

size_t InputBuffer::findLastNewline() const noexcept {
    if(arraySize == 0) {
        return 0;
    }
    size_t index = arraySize - 1;
    while(true) {
        if(array[index] == '\n') {
            return index;
        }
        if(index == 0) {
            return arraySize;
        }
        --index;
    }
}