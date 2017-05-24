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

    Ingredient::badIngredientsCombination(cucumber, patato);

    basicSalad + tomato + cucumber + salt + peper + patato;
    patatoSalad + salt + peper + patato + cucumber;

    Salad copySalad = basicSalad;

    std::cout << basicSalad << std::endl;
    std::cout << copySalad << std::endl;
    std::cout << patatoSalad << std::endl;
    std::cout << reinterpret_cast<const Vegetable&>(patatoSalad[2]) << std::endl;
    std::cout << reinterpret_cast<const Vegetable&>(patatoSalad["patato"]) << std::endl;
    std::cout << reinterpret_cast<const Spice&>(copySalad[3]) << std::endl;
    std::cout << reinterpret_cast<const Spice&>(copySalad["peper"]) << std::endl;

    return 0;
}