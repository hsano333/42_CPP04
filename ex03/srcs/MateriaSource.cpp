#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() : slot_id_(0)
{
}
MateriaSource::MateriaSource(const MateriaSource& msource)
{
    this->delete_all_slot();
    this->slot_id_ = msource.slot_id_;
    for (int i = 0; i < this->slot_id_; i++)
    {
        this->slot_[i] = msource.slot_[i]->clone();
    }
}
MateriaSource& MateriaSource::operator=(const MateriaSource& msource)
{
    if (this != &msource)
    {
        this->delete_all_slot();
        this->slot_id_ = msource.slot_id_;
        for (int i = 0; i < this->slot_id_; i++)
        {
            this->slot_[i] = msource.slot_[i]->clone();
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    this->delete_all_slot();
}

void MateriaSource::delete_all_slot(void)
{
    for(int i=0; i < this->slot_id_; i++)
    {
        delete this->slot_[i];
        this->slot_[i] = 0;
    }
}

void MateriaSource::learnMateria(AMateria* materia)
{
    if (this->slot_id_ < slot_max_)
    {
        this->slot_[slot_id_] = materia;
        slot_id_++;
    }
}

int MateriaSource::searchMateria(std::string const &type)
{
    for (int i = 0; i < slot_id_; i++)
    {
        if (this->slot_[i]->getType() == type && this->slot_[i]->getUsed())
            return (i);
    }
    return (-1);
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    int id = searchMateria(type);
    
    if (id == -1)
        return (0);
    return (this->slot_[id]->clone());
}
