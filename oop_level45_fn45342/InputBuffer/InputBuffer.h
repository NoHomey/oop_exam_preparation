#pragma once

#include "../DynamicArray.h"

class InputBuffer: public DynamicArray<char> {
public:
    InputBuffer(size_t count);

    char* obtainBufferForInput() noexcept;

    void syncSize(size_t count) noexcept;

    size_t findLastNewline() const noexcept;
};