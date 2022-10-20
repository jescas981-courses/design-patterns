#include <string>
#include <iostream>

struct Renderer {
    virtual std::string what_to_render_as(const std::string &name) const = 0;
};

struct RasterRenderer : Renderer {
    std::string what_to_render_as(const std::string &name) const override {
        return "Drawing " + name + " as pixels";
    }
};

struct VectorRenderer : Renderer {
    std::string what_to_render_as(const std::string &name) const override {
        return "Drawing " + name + " as lines";
    }
};

struct Shape {
    Renderer &renderer;
    std::string name;
    virtual std::string str() const = 0;
    Shape(Renderer &renderer, std::string &&name)
        : renderer(renderer), name(name) {}
};

struct Triangle : Shape {
    Triangle(Renderer &renderer) : Shape(renderer, "Triangle") {}
    std::string str() const override {
        return renderer.what_to_render_as(name);
    }
};

struct Square : Shape {
    Square(Renderer &renderer) : Shape(renderer, "Square") {}
    std::string str() const override {
        return renderer.what_to_render_as(name);
    }
};

int main() {
    VectorRenderer rr;
    Triangle tri(rr);
    std::cout << tri.str() << std::endl;
    return 0;
}