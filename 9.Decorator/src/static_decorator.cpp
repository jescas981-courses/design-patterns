#include <string>
#include <type_traits>
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

#if __cpp_concepts
template <typename T>
concept IsAShape = std::is_base_of<Shape, T>::value;
template <IsAShape T>
#else
template <typename T>
#endif
struct ColoredShape : T {

    std::string color;
    ColoredShape() {}
    template <typename... Args>
    ColoredShape(const std::string& color, Args... args)
        : T(std::forward<Args>(args)...), color(color) {}
    std::string str() const override {
        std::ostringstream oss;
        oss << T::str() << " has the color " << color;
        return oss.str();
    }
};

#if __cpp_concepts
template <typename T>
concept IsAColoredShape = std::is_base_of<ColoredShape, T>::value;
template <IsAColoredShape T>
#else
template <typename T>
#endif
struct TransparentShape : T {
    uint8_t alpha;
    TransparentShape() {}
    template <typename... Args>
    TransparentShape(uint8_t alpha, Args... args)
        : T(std::forward<Args>(args)...), alpha(alpha) {}
    std::string str() const override {
        std::ostringstream oss;
        oss << T::str() << " has " << static_cast<float>(alpha) / 255.f * 100.f
            << "% of transparency";
        return oss.str();
    }
};

int main() {
    ColoredShape<Circle> green_circle{"green", 5};
    std::cout << green_circle.str() << std::endl;
    TransparentShape<ColoredShape<Square>> bis{43, "blue", 10};
    bis.color = "yellow";
    bis.side = 15;
    std::cout << bis.str() << std::endl;
    return 0;
}