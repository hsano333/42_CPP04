#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H
#include "AMateria.hpp"

class MateriaSource
{
    private:
        AMateria* copy_;
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& msource);
        void operator=(const MateriaSource& msource);
        ~MateriaSource();
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif

