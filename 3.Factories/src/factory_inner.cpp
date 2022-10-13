#include <cmath>
#include <iostream>

class Point {
    // friend class PointFactory; // Breaks Open-Closed Principle
   private:
    float x, y;
    Point(float x, float y) : x(x), y(y) {}

   public:
    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        return os << "x: " << point.x << " y: " << point.y;
    }

    class Factory {
       private:
        Factory() {}

       public:
        static Point newCartesian(float x, float y) { return {x, y}; }
        static Point newPolar(float rho, float theta) {
            return {rho * cosf(theta), rho * sinf(theta)};
        }
    };
};

int main() {
    auto p = Point::Factory::newPolar(5, M_PI_4);
    return 0;
}
