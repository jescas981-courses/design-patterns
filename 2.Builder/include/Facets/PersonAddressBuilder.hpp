#pragma once
#include <Facets/Person.hpp>
#include <Facets/PersonBuilder.hpp>
#include <string>
#include <vector>

class PersonAddressBuilder : public PersonBuilderBase {
   public:
    PersonAddressBuilder(Person& person) : PersonBuilderBase(person) {}
    PersonAddressBuilder& At(std::string street_address) {
        person.street_address = street_address;
        return *this;
    }
    PersonAddressBuilder& WithPostCode(std::string post_code) {
        person.post_code = post_code;
        return *this;
    }
    PersonAddressBuilder& In(std::string city) {
        person.city = city;
        return *this;
    }
};