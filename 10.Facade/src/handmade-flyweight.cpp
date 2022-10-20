#include <map>
#include <string>
#include <iostream>
#include <boost/bimap.hpp>

struct User {
    User(const std::string& firstname, const std::string& lastname)
        : firstname(add(firstname)), lastname(add(lastname)) {}
    std::string get_firstname() const {
        return names.left.find(firstname)->second;
    }
    std::string get_lastname() const {
        return names.left.find(lastname)->second;
    }

   private:
    uint32_t firstname;
    uint32_t lastname;
    static boost::bimap<uint32_t, std::string> names;
    static uint32_t seed;
    static uint32_t add(const std::string& s) {
        auto it = names.right.find(s);
        if (it == names.right.end()) {
            uint32_t id = ++seed;
            names.insert({seed, s});
            return id;
        }
        return it->second;
    }
    friend std::ostream& operator<<(std::ostream& os, const User& user) {
        return os << "firstname: " << user.get_firstname()
                  << " lastname: " << user.get_lastname() << " ("
                  << user.lastname << ")" << std::endl;
    }
};

uint32_t User::seed{0};
boost::bimap<uint32_t, std::string> User::names{};

int main() {
    User user1{"Mimi", "Castillo"};
    User user2{"Riqueza", "Castillo"};
    std::cout << user1 << std::endl << user2 << std::endl;
}