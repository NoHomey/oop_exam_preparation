#include "Ingredient.h"

Ingredient::Ingredient(const char* name, bool ownProduction, bool isVegetable) noexcept
: notCombinesWith{}, ingredientName{name},
isIngredientOwnProduction{ownProduction},
isIngredientVegetable{isVegetable} { }

void Ingredient::badIngredientsCombination(Ingredient& ingredientA, Ingredient& ingredientB) {
    ingredientA.doseNotCombinesWith(ingredientB);
    ingredientB.doseNotCombinesWith(ingredientA);
}

void Ingredient::doseNotCombinesWith(const Ingredient& ingredient) {
    notCombinesWith.push(&ingredient);
}

bool Ingredient::doseItCombinesWith(const Ingredient& ingredient) const noexcept {
    const size_t notCombinesWithSize = notCombinesWith.size();
    const Ingredient* ingredientPtr = &ingredient;
    for(size_t i = 0; i < notCombinesWithSize; ++i) {
        if(notCombinesWith[i] == ingredientPtr) {
            return true;
        }
    }
    return false;
}

bool Ingredient::isOwnProduction() const noexcept {
    return isIngredientOwnProduction;
}

const char* Ingredient::getName() const noexcept {
    return ingredientName;
}

bool Ingredient::isVegetable() const noexcept {
    return isIngredientVegetable;
}

std::ostream& operator<<(std::ostream& out, const Ingredient& ingredient) {
    out << ingredient.getName() << ", own production: "
        << (ingredient.isOwnProduction() ? "yes" : "no");
    return out;
}