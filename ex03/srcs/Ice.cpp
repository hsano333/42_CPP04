#include "Ice.hpp"
#include <iostream>

using std::cout;
using std::endl;

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice& ice) : AMateria("ice")
{
}

void Ice::operator=(const Ice& ice)
{
    this->type_ = ice.type_;
}

void Ice::use(ICharacter& chara)
{
    cout << "* shoots an ice bolt at " << chara.getName() << " *";
}

AMateria* Ice::clone() const
{
    return (new Ice());
}
