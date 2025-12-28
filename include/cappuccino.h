#ifndef CAPPUCCINO
#define CAPPUCCINO

#include "string"
#include "vector"
#include "ingredient.h"
#include "sub_ingredients.h"
#include "espresso_based.h"

class Cappuccino: public EspressoBased
{
public:
    Cappuccino() {
        ingredients = {new Espresso{2},new Milk{2},new MilkFoam{1}};
        side_items = {};
        name = "Cappuccino";
    }
    Cappuccino(Cappuccino& cap):Cappuccino{} { do_copy(cap); }
	~Cappuccino() {}
    
};

#endif // CAPPUCCINO