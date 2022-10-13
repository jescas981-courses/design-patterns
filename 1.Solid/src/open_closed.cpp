#include <iostream>
#include <string>
#include <vector>

enum class Color { kGreen, kBlue, kRed };
enum class Size { kSmall, kMedium, kLarge };

struct Product {
    std::string name;
    Color color;
    Size size;
    Product(const std::string &name, Color color, Size size)
        : name(name), color(color), size(size) {}
};

// This class filter is open to modifications because
// a new method is created by when a new  filter is added, so this breaks
// the open-closed principle that states that a class is closed
// for changes and opened for extensions
// struct ProductFilter {
//     std::vector<Product *> ByColor(std::vector<Product *> items, Color color)
//     {
//         std::vector<Product *> res;
//         for (const auto &i : items) {
//             if (i->color == color) res.push_back(i);
//         }
//         return res;
//     }
//     std::vector<Product *> BySize(std::vector<Product *> items, Size size) {
//         std::vector<Product *> res;
//         for (const auto &i : items) {
//             if (i->size == size) res.push_back(i);
//         }
//         return res;
//     }
//     std::vector<Product *> ByColorAndSize(std::vector<Product *> items,
//                                           Color color, Size size) {
//         std::vector<Product *> res;
//         for (const auto &i : items) {
//             if (i->color == color && i->size == size) res.push_back(i);
//         }
//         return res;
//     }
// };

template <typename T>
struct Specification {
    virtual bool IsSatisfied(Product *item) const = 0;
};

template <typename T>
struct AndSpecification : Specification<T> {
    const Specification<T> &first;
    const Specification<T> &second;
    AndSpecification(const Specification<T> &first,
                     const Specification<T> &second)
        : first(first), second(second) {}
    bool IsSatisfied(T *item) const override {
        return first.IsSatisfied(item) && second.IsSatisfied(item);
    }
};

template <typename T>
AndSpecification<T> operator&&(const Specification<T> &first,
                               const Specification<T> &second) {
    return {first, second};
}

struct ColorSpecification : Specification<Product> {
    Color color;
    ColorSpecification(Color color) : color(color) {}
    bool IsSatisfied(Product *item) const override {
        return item->color == color;
    };
};

struct SizeSpecification : Specification<Product> {
    Size size;
    SizeSpecification(Size size) : size(size) {}
    bool IsSatisfied(Product *item) const override {
        return item->size == size;
    };
};

template <typename T>
struct Filter {
    virtual std::vector<T *> filter(std::vector<T *> items,
                                    Specification<T> &spec) {
        std::vector<T *> res;
        for (const auto &i : items) {
            if (spec.IsSatisfied(i)) res.push_back(i);
        }
        return res;
    }
};

int main() {
    Product apple{"Apple", Color::kGreen, Size::kSmall};
    Product tree{"Tree", Color::kGreen, Size::kLarge};
    Product house{"House", Color::kBlue, Size::kLarge};

    std::vector<Product *> products{&apple, &tree, &house};
    // ProductFilter pf;
    // auto green_things = pf.ByColor(products, Color::kGreen);
    // for (const auto &i : green_things) {
    //     std::cout << i->name << " is green\n";
    // }

    Filter<Product> pf;
    ColorSpecification green{Color::kGreen};
    SizeSpecification large{Size::kLarge};

    auto green_things = pf.filter(products, green);
    for (const auto &i : green_things) {
        std::cout << i->name << " is green\n";
    }

    auto green_and_large = green && large;
    for (const auto &i : pf.filter(products, green_and_large)) {
        std::cout << i->name << " is green and large\n";
    }

    return 0;
}
