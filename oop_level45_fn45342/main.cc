#include <iostream>
#include "InputReader/InputReader.h"
#include "ConstString/ConstString.h"

#include <fstream>

int main() {
    std::ifstream file("test.txt");

    InputReader r{std::move(file)};

    while(true) {
        InputReader::NewlineBlock b = r.readNewlineBlock();

        if(b.size() == 0) {
            return 0;
        }

        ConstString str{b.data(), b.size()};

        std::cout << str << std::endl;
    }


    return 0;
}