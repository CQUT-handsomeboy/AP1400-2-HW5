#ifndef INGREDIENT_H
#define INGREDIENT_H

class Ingredient
{
public:
    virtual double get_price_unit() { return price_unit; }
    virtual size_t get_units() { return units; }
    virtual std::string get_name() { return name; }
    virtual void set_name(std::string name) { this->name = name; }
    virtual void set_units(size_t units) { this->units = units; }
    virtual void set_price_unit(double price_unit) { this->price_unit = price_unit; }

    virtual double price() { return price_unit*units; }
    Ingredient(): price_unit(0),units(5) {} // 默认构造函数
    Ingredient(double price_unit, size_t units):price_unit(price_unit),units(units) {}
    virtual ~Ingredient() = default;
    

protected:
    
    double price_unit;
    size_t units;
    std::string name;
};


#endif // INGREDIENT_H