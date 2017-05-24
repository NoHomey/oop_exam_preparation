#include "./../Ingredient/Ingredient.h"
#include "./../Spice/Spice.h"
#include "./../Vegetable/Vegetable.h"
#include "./../Set/Set.h"

class Salad {
public:
    Salad(const char* name);

    const Set<const Ingredient*>& getIngredients() const noexcept;

    const char* getName() const noexcept;

    void addIngredient(const Ingredient* ingredient);
 
private:
    Set<const Ingredient*> ingredients;
    const char* saladName;
};

std::ostream& operator<<(std::ostream& out, const Salad& salad);