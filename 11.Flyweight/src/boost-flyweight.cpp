#include <boost/flyweight.hpp>
#include <iostream>

struct User {
    boost::flyweight<std::string> firstname, lastname;
    User(const std::string& firstname, const std::string& lastname)
        : firstname(firstname), lastname(lastname) {}
};

int main() {
    User first{"John", "Smith"}, second{"Jane", "Smith"};
    std::cout << first.firstname << std::endl;
    std::cout << std::boolalpha;
    std::cout << (&first.firstname.get() == &second.firstname.get())
              << std::endl;
    std::cout << (&first.lastname.get() == &second.lastname.get()) << std::endl;
    return 0;
}