#include <Facets/Person.hpp>
#include <Facets/PersonAddressBuilder.hpp>
#include <Facets/PersonBuilder.hpp>
#include <Facets/PersonJobBuilder.hpp>
#include <iostream>

int main() {
    Person p = Person::create()
                 .lives()
                 .At("Any street")
                 .In("My random city")
                 .WithPostCode("Az 123120")
                 .works()
                 .At("PragmaSoft")
                 .As("Consultant")
                 .Earning(10e6);

    std::cout << p << std::endl;
    return 0;
}