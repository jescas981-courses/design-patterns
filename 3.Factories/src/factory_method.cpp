#include <cmath>
#include <iostream>

class Point {

   private:
    float x, y;
    Point(float x, float y) : x(x), y(y) {}

   public:
    static Point newCartesian(float x, float y) { return {x, y}; }
    static Point newPolar(float rho, float theta) {
        return {rho * cosf(theta), rho * sinf(theta)};
    }
    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        return os << "x: " << point.x << " y: " << point.y;
    }
};

int main() {
    auto p = Point::newPolar(5, M_PI_4);
    std::cout << p << std::endl;
    return 0;
}
