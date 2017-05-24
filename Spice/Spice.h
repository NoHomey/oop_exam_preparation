#pragma once

#include "../Ingredient/Ingredient.h"

class Spice: public Ingredient {
public:
    enum SpiceType {
        Liquid,
        Dry,
        Fresh
    };

    Spice(const char* name, bool ownProduction, SpiceType type) noexcept;

    SpiceType getType() const noexcept;

private:
    SpiceType spiceType;
};

std::ostream& operator<<(std::ostream& out, const Spice& spice);