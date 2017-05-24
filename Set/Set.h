#pragma once

#include "../Vector/Vector.h"

template<typename Type>
class Set: public Vector<Type> {
public:
    Set();
    
    explicit Set(size_t size);

    void push(const Type& element);
};