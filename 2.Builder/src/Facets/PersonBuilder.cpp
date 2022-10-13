#include <Facets/PersonBuilder.hpp>
#include <Facets/PersonAddressBuilder.hpp>
#include <Facets/PersonJobBuilder.hpp>

PersonAddressBuilder PersonBuilderBase::lives() const {
    return PersonAddressBuilder(person);
}
PersonJobBuilder PersonBuilderBase::works() const {
    return PersonJobBuilder(person);
}