#pragma once
#include <Facets/Person.hpp>

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase {
   protected:
    Person &person;

   public:
    PersonBuilderBase(Person &person) : person(person) {}
    PersonAddressBuilder lives() const;
    PersonJobBuilder works() const;
    operator Person() const { return std::move(person); }
};

class PersonBuilder : public PersonBuilderBase {
    Person p;

   public:
    PersonBuilder() : PersonBuilderBase(p) {}
};