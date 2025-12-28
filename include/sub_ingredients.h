#ifndef SUB_INGREDIENTS_H
#define SUB_INGREDIENTS_H

#include "ingredient.h"

#define DEFCLASS(CLASS_NAME,PRICE_UNIT) \
class CLASS_NAME : public Ingredient \
{ \
    public: \
        CLASS_NAME(size_t units) : Ingredient{PRICE_UNIT, units} \
        { this->name = #CLASS_NAME; this->units = units; this->price_unit = PRICE_UNIT; } \
}; \

DEFCLASS(Cinnamon, 5)
DEFCLASS(Chocolate, 5)
DEFCLASS(Sugar, 1)
DEFCLASS(Cookie, 10)
DEFCLASS(Espresso, 15)
DEFCLASS(Milk, 10)
DEFCLASS(MilkFoam, 5)
DEFCLASS(Water, 1)


#endif // SUB_INGREDIENTS_H