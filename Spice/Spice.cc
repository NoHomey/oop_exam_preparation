#include "Spice.h"

Spice::Spice(const char* name, bool ownProduction, SpiceType type) noexcept
: Ingredient{name, ownProduction, false}, spiceType{type} { }

Spice::SpiceType Spice::getType() const noexcept {
    return spiceType;
}

std::ostream& operator<<(std::ostream& out, const Spice& spice) {
    out << ((Ingredient)spice) << ", type: ";
    switch(spice.getType()) {
        case Spice::SpiceType::Liquid:
            out << "liquid";
            break;
        case Spice::SpiceType::Dry:
            out << "dry";
            break;
        default: out << "fresh";
    }
    return out;
}