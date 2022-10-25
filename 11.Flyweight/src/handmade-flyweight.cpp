#include <boost/bimap.hpp>
#include <iostream>
#include <string>

typedef uint32_t key;

class User {
   private:
    key firstname;
    key lastname;
    static boost::bimap<key, std::string> names;
    static key seed;

   public:
    User(const std::string& firstname, const std::string& lastname)
        : firstname(add(firstname)), lastname(add(lastname)) {}
    const std::string& get_firstname() const {
        return names.left.find(firstname)->second;
    }
    const std::string& get_lastname() const {
        return names.left.find(lastname)->second;
    }
    friend std::ostream& operator<<(std::ostream& os, const User& user) {
        return os << "Firstname: " << user.get_firstname()
                  << " Lastname: " << user.get_lastname()
                  << " LastnameId: " << user.lastname;
    }

   private:
    static key add(const std::string& name) {
        auto it = names.right.find(name);
        if (it == names.right.end()) {
            key id = ++seed;
            names.insert({id, name});
            return id;
        }
        return it->second;
    }
};

key User::seed{0};

boost::bimap<key, std::string> User::names{};

int main() {
    User user1{"Mimi", "Castillo"}, user2{"Machina", "Castillo"};
    std::cout << user1 << std::endl << user2 << std::endl;
    return 0;
}