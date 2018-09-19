#include "InputReader.h"

InputReader::NewlineBlock::NewlineBlock(const char* data, size_t size)
: blockData{data}, blockSize{size} {}

const char* InputReader::NewlineBlock::data() const noexcept {
    return blockData;
}

size_t InputReader::NewlineBlock::size() const noexcept {
    return blockSize;
}

InputReader::InputReader(std::istream&& inStraem)
: inputStream{inStraem}, inputBuffer{intialSize} {}

bool InputReader::isEndOFileReached() const noexcept {
    return inputStream.eof();
}

void InputReader::restoreState() noexcept {
    const size_t size = inputBuffer.size();
    if(size > 0) {
        const size_t firstAfterlastNewline = inputBuffer.findLastNewline() + 1;
        if(size > firstAfterlastNewline) {
            const size_t difference = size - firstAfterlastNewline;
            char* buffer = inputBuffer.obtainBufferForInput();
            for(size_t i = 0; i < difference; ++i) {
                buffer[i] = buffer[firstAfterlastNewline + i];
            }
            inputBuffer.syncSize(difference);
        }
    }
}

InputReader::NewlineBlock InputReader::readNewlineBlock() {
    restoreState();
    char* buffer = inputBuffer.obtainBufferForInput();
    size_t offset = inputBuffer.size();
    size_t sizeOfBytesToRead = inputBuffer.unusedMemory();
    size_t lastNewline;
    size_t bytesRead;
    size_t isEOFReached = isEndOFileReached();
    if(isEOFReached) {
        inputBuffer.clear();
        return {nullptr, 0};
    }
    while(true) {
        inputStream.read(buffer + offset, sizeOfBytesToRead);
        bytesRead = inputStream.gcount();
        isEOFReached = isEndOFileReached();
        if((bytesRead < sizeOfBytesToRead) && (!isEOFReached)) {
            throw std::exception();
        }
        offset += bytesRead;
        inputBuffer.syncSize(offset);
        if(isEOFReached) {
            return {inputBuffer.obtainBufferForInput(), offset};
        }
        lastNewline = inputBuffer.findLastNewline();
        if(lastNewline < inputBuffer.size()) {
            return {inputBuffer.obtainBufferForInput(), lastNewline};
        }
        inputBuffer.reserve(chunkSize);
        buffer = inputBuffer.obtainBufferForInput();
        sizeOfBytesToRead = chunkSize;
        return {inputBuffer.obtainBufferForInput(), lastNewline};
    }
}