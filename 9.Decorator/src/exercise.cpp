#include <string>
#include <iostream>
using namespace std;

struct Flower {
    virtual string str() = 0;
};

struct Rose : Flower {
    string str() override { return "A rose"; }
};

struct RedFlower : Flower {
    Flower& flower;
    const std::string color;
    RedFlower(Flower& flower) : flower(flower), color("red") {}
    string str() override {
        if (flower.str().find(color) != std::string::npos) return flower.str();
        if (flower.str().find("that") != std::string::npos)
            return flower.str() + " and " + color;
        return flower.str() + " that is " + color;
    }
};

struct BlueFlower : Flower {
    Flower& flower;
    const std::string color;
    BlueFlower(Flower& flower) : flower(flower), color("blue") {}
    string str() override {
        if (flower.str().find(color) != std::string::npos) return flower.str();
        if (flower.str().find("that") != std::string::npos)
            return flower.str() + " and " + color;
        return flower.str() + " that is " + color;
    }
};

int main() {
    Rose rose;
    RedFlower red_rose{rose};
    RedFlower red_red_rose{red_rose};
    BlueFlower blue_red_rose{red_rose};
    cout << rose.str();           // "A rose"
    cout << red_rose.str();       // "A rose that is red"
    cout << red_red_rose.str();   // "A rose that is red"
    cout << blue_red_rose.str();  // "A rose that is red and blue"
    return 0;
}
