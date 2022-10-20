#include <string>
#include <iostream>
#include <boost/flyweight.hpp>

struct User {
    boost::flyweight<std::string> firstname, lastname;
    User(const std::string& firstname, const std::string& lastname)
        : firstname(firstname), lastname(lastname) {}
};

int main() {
    User user{"Jhon", "Smith"};
    User user1{"Jane", "Smith"};
    std::cout << user.firstname << std::endl;
    std::cout << std::boolalpha;
}