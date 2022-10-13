#pragma once
#include <iostream>
#include <map>
#include <memory>

#include "HotDrink.hpp"
#include "HotDrinkFactory.hpp"

struct DrinkFactory {
    std::map<std::string, std::unique_ptr<IHotDrinkFactory>> hot_factories;

   public:
    DrinkFactory() {
        hot_factories["coffee"] = std::make_unique<CoffeeFactory>();
        hot_factories["tea"] = std::make_unique<TeaFactory>();
    }

    std::unique_ptr<IHotDrink> MakeDrink(const std::string& name) {
        auto drink = hot_factories[name]->make();
        drink->prepare(200);
        return drink;
    }
};