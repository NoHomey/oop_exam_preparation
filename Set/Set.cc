#include "Set.h"

template<typename Type>
Set<Type>::Set() : Vector<Type>{} { }
    
template<typename Type>
Set<Type>::Set(size_t size) : Vector<Type>{size} { }

template<typename Type>
void Set<Type>::push(const Type& element) {
    for(size_t index = 0; index < this->arraySize; ++index) {
        if(this->array[index] == element) {
            return;
        }
    }
    Vector<Type>::push(element);
}

class Ingredient;
template class Set<const Ingredient*>;