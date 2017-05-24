#include <iostream>

#include "./../Salad/Salad.h"

int main() {
    Spice peper = {"peper", true, Spice::SpiceType::Dry};
    Spice salt = {"salt", true, Spice::SpiceType::Dry};
    Vegetable cucumber = {"cucumber", false, 103};
    Vegetable patato = {"patato", false, 89};
    Vegetable tomato = {"tomato", true, 199};
    Salad basicSalad = {"basic salad"};
    Salad patatoSalad = {"patato salad"};

    Ingredient::badIngredientsCombination(&cucumber, &patato);

    basicSalad.addIngredient(&tomato);
    basicSalad.addIngredient(&cucumber);
    basicSalad.addIngredient(&salt);
    basicSalad.addIngredient(&peper);
    basicSalad.addIngredient(&patato);

    patatoSalad.addIngredient(&salt);
    patatoSalad.addIngredient(&peper);
    patatoSalad.addIngredient(&patato);
    patatoSalad.addIngredient(&cucumber);

    std::cout << basicSalad << std::endl;
    std::cout << patatoSalad;

    return 0;
}