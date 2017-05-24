#include <iostream>

#include "Vector/Vector.h"

int main() {
    Vector<int> v = Vector<int>{73};
    std::cout << v.size() << ' ' << v.capacity() << std::endl;
    v.push(9);
    std::cout << v.size() << ' ' << v.capacity() << std::endl;
    v.push(4);
    std::cout << v.size() << ' ' << v.capacity() << std::endl;
    v.push(2);
    std::cout << v.size() << ' ' << v.capacity() << std::endl;
    v.pop();
    v.pop();
    v.pop();
    std::cout << v.size() << ' ' << v.capacity() << std::endl;
    try {
        v.pop();
    } catch(std::exception& error) {
        std::cout << error.what() << std::endl;
    }
    std::cout << v.size() << ' ' << v.capacity() << std::endl;
    v.push(1);
    std::cout << v.size() << ' ' << v.capacity() << std::endl;
    for(size_t i = 0; i < 165; ++i) {
        v.push(i);
        std::cout << v.size() << ' ' << v.capacity() << std::endl;
    }

    return 0;
}