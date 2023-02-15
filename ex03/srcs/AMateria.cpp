#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const & type) : unused_(false)
{
    this->type_ = type;
}

AMateria::AMateria() : type_("") , unused_(false)
{
}

AMateria::~AMateria()
{
}
AMateria::AMateria(const AMateria& materia)
{
    this->unused_ = materia.unused_;
    this->type_ = materia.type_;
}

AMateria& AMateria::operator=(const AMateria& materia)
{
    this->unused_ = materia.unused_;
    this->type_ = materia.type_;
    return (*this);
}

std::string const &AMateria::getType(void) const
{
    return (this->type_);
}
void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria use test" << std::endl;
    std::cout << "error:" << target.getName() << "is undefined materia" << std::endl;

}

void AMateria::unuse()
{
    this->unused_ = true;
}

bool AMateria::getUsed(void)
{
    return (!this->unused_);

}

