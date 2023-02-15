#include "Cure.hpp"
#include <iostream>
using std::cout;
using std::endl;

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure& cure) : AMateria(cure.getType())
{
}

Cure::~Cure()
{
}

Cure& Cure::operator=(const Cure& cure)
{
    this->AMateria::operator=(cure);
    //this->unused_ = cure.unused_;
    //this->type_ = cure.type_;
    return (*this);
}

void Cure::use(ICharacter& chara)
{
    if (this->unused_ == false)
        cout << "* heals " << chara.getName() << "'s wounds *" << endl;
    else
        cout << "[Cure] error: this materia is not unequip()" << endl;
}

AMateria* Cure::clone() const
{
    return (new Cure());
}
