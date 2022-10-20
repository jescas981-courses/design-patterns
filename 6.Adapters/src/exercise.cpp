struct Square {
    int side{0};

    explicit Square(const int side) : side(side) {}
};

struct Rectangle {
    virtual int width() const = 0;
    virtual int height() const = 0;

    int area() const { return width() * height(); }
};

struct SquareToRectangleAdapter : Rectangle {
    SquareToRectangleAdapter(const Square& square) {
        width_ = square.side;
        height_ = square.side;
    }
    int width() const override { return width_; }
    int height() const override { return height_; }

   private:
    int width_;
    int height_;
};