#include <cmath>
#include <iostream>

enum class PointType { kPolar, kCartesian };

struct Point {
    float x, y;
    // Point(float x, float y) : x(x), y(y) {}
    // Implementing this code can be a bit tricky and confusing
    Point(float a, float b, PointType type = PointType::kCartesian) {
        if (type == PointType::kCartesian) {
            x = a;
            y = b;
        } else {
            x = a * cos(b);
            y = a * sin(b);
        }
    }
};

int main() { return 0; }