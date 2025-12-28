#ifndef MOCHA_H
#define MOCHA_H

#include "espresso_based.h"
#include "sub_ingredients.h"

class Mocha : public EspressoBased {
    public:
        Mocha() {
            ingredients = {
                new Espresso{2},new Milk{2},
                new MilkFoam{1},new Chocolate{1}
            };
            this->name = "Mocha";
        }
};

#endif // MOCHA_H