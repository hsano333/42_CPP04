#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
    this->type_ = type;
}

/*
AMateria::AMateria()
{
}
*/

AMateria::~AMateria()
{
}

std::string const &AMateria::getType(void) const
{
    return (this->type_);
}
