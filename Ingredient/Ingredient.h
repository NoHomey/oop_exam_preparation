#pragma once

#include "./../Set/Set.h"

#include <ostream>

class Ingredient;

template class Vector<Ingredient*>;

class Ingredient {
public:
    static void badIngredientsCombination(Ingredient* ingredientA, Ingredient* ingredientB);

    Ingredient(const char* name = nullptr, bool ownProduction = true, bool isVegetable = false) noexcept;

    bool doseItCombinesWith(const Ingredient* ingredient) const noexcept;

    bool isOwnProduction() const noexcept;

    const char* getName() const noexcept;

    bool isVegetable() const noexcept;

private:
    void doseNotCombinesWith(const Ingredient* ingredient);

    Set<const Ingredient*> notCombinesWith;
    const char* ingredientName;
    bool isIngredientOwnProduction;
    bool isIngredientVegetable;
};

std::ostream& operator<<(std::ostream& out, const Ingredient& ingredient);