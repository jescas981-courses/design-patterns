#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

struct ContainsIntegers {
    virtual int total() const = 0;
};

struct SingleValue : ContainsIntegers {
    int value{0};

    SingleValue() = default;

    explicit SingleValue(const int value) : value{value} {}

    // TODO
    int total() const override { return value; }
};

struct ManyValues : vector<int>, ContainsIntegers {
    void add(const int value) { push_back(value); }
    int total() const override { return accumulate(begin(), end(), 0); }
};

int sum(const vector<ContainsIntegers*> items) {
    return accumulate(
        items.begin(), items.end(), 0,
        [](size_t sum, ContainsIntegers* ci) { return ci->total() + sum; });
}

int main() {
    SingleValue single_value{1};
    ManyValues other_values;
    other_values.add(2);
    other_values.add(3);
    cout << sum({&single_value, &other_values});
}