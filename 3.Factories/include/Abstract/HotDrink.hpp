#pragma once
#include <iostream>

struct IHotDrink {
    virtual void prepare(int vol) = 0;
};

struct Tea : IHotDrink {
    virtual void prepare(int vol) override {
        std::cout << "boil water, pour a tea bag, pour " << vol
                  << "ml, add some lemon\n";
    }
};

struct Coffee : IHotDrink {
    virtual void prepare(int vol) override {
        std::cout << "grind some beans, boil water, pour " << vol
                  << "ml, add cream\n";
    }
};