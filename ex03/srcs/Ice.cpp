#include "Ice.hpp"
#include <iostream>

using std::cout;
using std::endl;

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice& ice) : AMateria(ice.getType())
{
}

Ice::~Ice()
{
}

Ice& Ice::operator=(const Ice& ice)
{
    this->AMateria::operator=(ice);
    //this->unused_ = ice.unused_;
    //this->type_ = ice.type_;
    return (*this);
}

void Ice::use(ICharacter& chara)
{
    if (this->unused_ == false)
        cout << "* shoots an ice bolt at " << chara.getName() << " *" << endl;
    else
        cout << "[Cure] error: this materia is not unequip()" << endl;
}

AMateria* Ice::clone() const
{
    return (new Ice());
}
