#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : virtual public IMateriaSource
{
    private:
        const static int slot_max_ = 4;
        AMateria* slot_[slot_max_];
        int slot_id_;
        void delete_all_slot(void);
        int searchMateria(std::string const &type);
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& msource);
        MateriaSource& operator=(const MateriaSource& msource);
        ~MateriaSource();
        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const & type);
};

#endif

