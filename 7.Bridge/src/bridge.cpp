#include <iostream>
// Different Shapes
// Diferrent type of render

struct Renderer {
    virtual void render_circle(float x, float y, float r) = 0;
};

struct VectorRenderer : Renderer {
    void render_circle(float x, float y, float r) override {
        std::cout << "Drawing a vector circle of radius " << r << std::endl;
    }
};

struct RasterRenderer : Renderer {
    void render_circle(float x, float y, float r) override {
        std::cout << "Rastering a circle of radius " << r << std::endl;
    }
};

struct Shape {
   protected:
    Renderer& renderer;
    Shape(Renderer& renderer) : renderer(renderer) {}

   public:
    virtual void draw() = 0;
    virtual void resize(float factor) = 0;
};

struct Circle : Shape {
    float x, y, r;
    Circle(Renderer& renderer, float x, float y, float r)
        : Shape(renderer), x(x), y(y), r(r) {}
    void draw() override { renderer.render_circle(x, y, r); }
    void resize(float factor) override { r *= factor; }
};

int main() {
    RasterRenderer rr;
    Circle cirle(rr, 0, 0, 2);
    cirle.draw();
    cirle.resize(0.5);
    cirle.draw();
    return 0;
}