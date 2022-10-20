#include <string>

struct Address {
    std::string street, city;
    int suite;
    Address(const std::string &street, const std::string &city)
        : street(street), city(city) {}
};

struct Contact {
    std::string name;
    Address address;
    Contact(const std::string &name, const Address &address)
        : name(name), address(address) {}
};

int main() { return 0; }