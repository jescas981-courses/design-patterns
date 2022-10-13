#pragma once
#include <iostream>
#include <memory>

#include "HotDrink.hpp"

struct IHotDrinkFactory {
    virtual std::unique_ptr<IHotDrink> make() const = 0;
};

struct TeaFactory : IHotDrinkFactory {
    virtual std::unique_ptr<IHotDrink> make() const override {
        return std::make_unique<Tea>();
    }
};

struct CoffeeFactory : IHotDrinkFactory {
    virtual std::unique_ptr<IHotDrink> make() const override {
        return std::make_unique<Coffee>();
    }
};