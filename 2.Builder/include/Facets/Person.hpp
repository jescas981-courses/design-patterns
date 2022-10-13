#pragma once
#include <ostream>
#include <string>
#include <vector>

class PersonBuilder;

class Person {
    std::string street_address, post_code, city;
    std::string company_name, position;
    int annual_income{0};

   public:
    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        return os << "Street Address: " << person.street_address
                  << " Post Code: " << person.post_code
                  << " City: " << person.city
                  << " Company Name: " << person.company_name
                  << " Position: " << person.position
                  << " Annual Income: " << person.annual_income;
    }
    static PersonBuilder create();
    friend class PersonBuilder;
    friend class PersonJobBuilder;
    friend class PersonAddressBuilder;
};