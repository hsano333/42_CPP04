#include "Cure.hpp"
#include <iostream>
using std::cout;
using std::endl;

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure& ice) : AMateria("cure")
{
}

void Cure::operator=(const Cure& cure)
{
    this->type_ = cure.type_;
}

void Cure::use(ICharacter& chara)
{
    cout << "* heals " << chara.getName() << "'s wounds *";
}

AMateria* Cure::clone() const
{
    return (new Cure());
}
