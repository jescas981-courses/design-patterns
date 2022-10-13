#pragma once
#include <Facets/PersonBuilder.hpp>

class PersonJobBuilder : public PersonBuilderBase {
   public:
    PersonJobBuilder(Person& person) : PersonBuilderBase(person) {}
    PersonJobBuilder& At(std::string company_name) {
        person.company_name = company_name;
        return *this;
    }
    PersonJobBuilder& As(std::string position) {
        person.position = position;
        return *this;
    }
    PersonJobBuilder& Earning(int annual_income) {
        person.annual_income = annual_income;
        return *this;
    }
};