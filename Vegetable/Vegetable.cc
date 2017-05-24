#include "Vegetable.h"

Vegetable::Vegetable(const char* name, bool ownProduction, unsigned int vitamins) noexcept
: Ingredient{name, ownProduction, true}, vitaminsInMiligramsPerKilogram{vitamins} { }

unsigned int Vegetable::getVitaminsInMiligramsPerKilogram() const noexcept {
    return vitaminsInMiligramsPerKilogram;
}

std::ostream& operator<<(std::ostream& out, const Vegetable& vegetable) {
    out << "vegetable: " << ((Ingredient)vegetable) << ", vitamins: "
    << vegetable.getVitaminsInMiligramsPerKilogram() << "mg/Kg";
    return out;
}
