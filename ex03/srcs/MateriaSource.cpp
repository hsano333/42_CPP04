#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
}
MateriaSource::MateriaSource(const MateriaSource& msource)
{
}
void MateriaSource::operator=(const MateriaSource& msource)
{
}
MateriaSource::~MateriaSource()
{
}

void MateriaSource::learnMateria(AMateria* materia)
{
    this->copy_ = Amateria(materia);

}

AMateria* MateriaSource::createMateria(std::string const & type)
{

}
