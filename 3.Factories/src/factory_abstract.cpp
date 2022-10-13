#include <Abstract/DrinkFactory.hpp>
#include <cmath>
#include <iostream>

int main() {
    DrinkFactory df;
    auto c = df.MakeDrink("coffee");
    return 0;
}
