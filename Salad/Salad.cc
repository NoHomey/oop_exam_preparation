#include "Salad.h"

#include <cstring>

Salad::Salad(const char* name)
: ingredients{}, saladName{name} { }

const Set<const Ingredient*>& Salad::getIngredients() const noexcept {
    return ingredients;
}

const char* Salad::getName() const noexcept {
    return saladName;
}

void Salad::addIngredient(const Ingredient& ingredient) {
    const size_t ingredientsSize = ingredients.size();
    for(size_t index = 0; index < ingredientsSize; ++index) {
        if(ingredients[index]->doseItCombinesWith(ingredient)) {
            return;
        }
    }
    ingredients.push(&ingredient);
}

Salad& Salad::operator+(const Ingredient& ingredient) {
    addIngredient(ingredient);
    return *this;
}

const Ingredient& Salad::operator[](size_t index) const {
    return *(ingredients[index]);
}

const Ingredient& Salad::operator[](const char* name) const {
    const size_t ingredientsSize = ingredients.size();
    for(size_t index = 0; index < ingredientsSize; ++index) {
        if(std::strcmp(ingredients[index]->getName(), name) == 0) {
            return *ingredients[index];
        }
    }
    throw std::out_of_range("ingredient not found");
}

std::ostream& operator<<(std::ostream& out, const Salad& salad) {
    const Set<const Ingredient*>& ingredients = salad.getIngredients();
    const Ingredient* ingredient = nullptr;
    const size_t ingredientsSize = ingredients.size();
    out << "salad: " << salad.getName() << std::endl
        <<"ingredients:" << std::endl;
    for(size_t index = 0; index < ingredientsSize; ++index) {
        ingredient = ingredients[index];
        out << "  ";
        if(ingredient->isVegetable()) {
            out << *(reinterpret_cast<const Vegetable*>(ingredient));
        } else {
            out << *(reinterpret_cast<const Spice*>(ingredient));
        }
        out << std::endl;
    }
    return out;
}