#include <string>
#include <iostream>
#include <sstream>

struct Shape {
    virtual std::string str() const = 0;
};

struct Circle : Shape {
    float radius;
    Circle() {}
    Circle(float radius) : radius(radius) {}
    std::string str() const override {
        std::ostringstream oss;
        oss << "A circle of radius " << radius;
        return oss.str();
    }
    void Resize(float factor) { radius *= factor; }
};

struct Square : Shape {
    float side;
    Square() {}
    Square(float side) : side(side) {}
    std::string str() const override {
        std::ostringstream oss;
        oss << "A square of side " << side;
        return oss.str();
    }
};

struct ColoredShape : Shape {
    Shape& shape;
    std::string color;
    ColoredShape(Shape& shape, const std::string& color)
        : shape(shape), color(color) {}
    std::string str() const override {
        std::ostringstream oss;
        oss << shape.str() << " has the color " << color;
        return oss.str();
    }
};

struct TransparentShape : Shape {
    Shape& shape;
    uint8_t alpha;
    TransparentShape(Shape& shape, uint8_t alpha)
        : shape(shape), alpha(alpha) {}
    std::string str() const override {
        std::ostringstream oss;
        oss << shape.str() << " has "
            << static_cast<float>(alpha) / 255.f * 100.f
            << "% of transparency";
        return oss.str();
    }
};

int main() {
    Circle circle{5};
    ColoredShape red_circle{circle, "red"};
    std::cout << circle.str() << std::endl << red_circle.str() << std::endl;
    TransparentShape my_circle{red_circle, 51};
    std::cout << my_circle.str() << std::endl;
    return 0;
}