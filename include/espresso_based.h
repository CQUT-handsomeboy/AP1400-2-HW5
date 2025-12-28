#ifndef ESPRESSO_BASED_H
#define ESPRESSO_BASED_H

#include "string"
#include "vector"
#include "ingredient.h"
#include "iostream"

class EspressoBased : public Ingredient
{
public:
    void brew() {}

    std::vector<Ingredient*>& get_side_items() { return side_items; }
    std::vector<Ingredient*>& get_ingredients() { return ingredients; }

    void add_side_item(Ingredient* side) { side_items.push_back(side); }

    double price() {
        double prices = 0.0;
        for(auto& ingredient : ingredients) 
            prices += ingredient->price();
        for(auto& side_item : side_items) 
            prices += side_item->price();
        return prices;
    }

    ~EspressoBased() {
        while(!ingredients.empty()) {
            auto& ingredient = ingredients.back();
            ingredients.pop_back();
            if(ingredient != nullptr) delete ingredient;
        }
        while(!side_items.empty()) {
            auto& side_item = side_items.back();
            side_items.pop_back();
            if(side_item != nullptr) delete side_item;
        }
    }

    void operator=(EspressoBased& cap) {
        if(&cap == this) return;
        do_copy(cap); 
    }

protected:
    EspressoBased() {
        this->name = "EspressoBased";
    }

    EspressoBased(const EspressoBased& esp) {}
    void operator=(const EspressoBased& esp) {}

    std::vector<Ingredient*> ingredients = {};
    std::vector<Ingredient*> side_items = {};
    
    void do_copy(EspressoBased& cap) {
        auto side_items =  cap.get_side_items();
        this->side_items.clear();
        while(!side_items.empty()) {
            auto side_item = side_items.back();
            side_items.pop_back();
            auto new_side_item = new Ingredient{};
            new_side_item->set_name(side_item->get_name());
            new_side_item->set_units(side_item->get_units());
            new_side_item->set_price_unit(side_item->get_price_unit());
            this->side_items.push_back(new_side_item);
        }
    }

};

#endif // ESPRESSO_BASED_H