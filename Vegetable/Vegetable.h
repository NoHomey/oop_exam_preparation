#include "./../Ingredient/Ingredient.h"

class Vegetable: public Ingredient {
public:
    Vegetable(const char* name, bool ownProduction, unsigned int vitamins) noexcept;

    unsigned int getVitaminsInMiligramsPerKilogram() const noexcept;

private:
    unsigned int vitaminsInMiligramsPerKilogram;
};

std::ostream& operator<<(std::ostream& out, const Vegetable& vegetable);