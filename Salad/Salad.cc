#include "Salad.h"

Salad::Salad(const char* name)
: ingredients{}, saladName{name} { }

const Set<const Ingredient*>& Salad::getIngredients() const noexcept {
    return ingredients;
}

const char* Salad::getName() const noexcept {
    return saladName;
}

void Salad::addIngredient(const Ingredient* ingredient) {
    const size_t ingredientsSize = ingredients.size();
    for(size_t index = 0; index < ingredientsSize; ++index) {
        if(ingredients[index]->doseItCombinesWith(ingredient)) {
            return;
        }
    }
    ingredients.push(ingredient);
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