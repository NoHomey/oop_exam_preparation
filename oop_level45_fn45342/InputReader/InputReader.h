#pragma once

#include <istream>
#include "../InputBuffer/InputBuffer.h"

class InputReader {
public:
    class NewlineBlock {
    public:
        NewlineBlock(const char* data, size_t size);

        const char* data() const noexcept;

        size_t size() const noexcept;

    private:
        const char* blockData;
        size_t blockSize;
    };

    InputReader(std::istream&& inStraem);

    bool isEndOFileReached() const noexcept;

    NewlineBlock readNewlineBlock();

protected:
    std::istream& inputStream;
    InputBuffer inputBuffer;

private:
    void restoreState() noexcept;

    static const size_t intialSize = 8;
    static const size_t chunkSize = 4;
};