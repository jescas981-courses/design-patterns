#include <iostream>
class Rectangle {
   protected:
    int width, height;

   public:
    Rectangle(int width, int height) : width(width), height(height) {}
    virtual void setWidth(int width) { Rectangle::width = width; };
    virtual void setHeight(int height) { Rectangle::height = height; }
    int getWidth() const { return width; }
    virtual int getHeight() const { return height; }
    int area() const { return width * height; }
};

class Square : public Rectangle {
   public:
    Square(int size) : Rectangle(size, size) {}
    virtual void setWidth(int width) {
        Rectangle::width = Rectangle::height = width;
    };
    virtual void setHeight(int height) {
        Rectangle::height = Rectangle::width = height;
    }
};

// This method only works for rectangle class but not for squaures, so it breaks liskov substitution
//
void process(Rectangle& r) {
    int w = r.getWidth();
    r.setHeight(10);
    std::cout << "Expected area is " << (w * 10) << " ,got " << r.area()
              << std::endl;
}

int main() {
    Rectangle r{3, 4};
    process(r);

    Square sq{5};
    process(sq);
    return 0;
}