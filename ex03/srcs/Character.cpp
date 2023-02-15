#include "Character.hpp"
#include <string>
#include <iostream>

using std::string;
using std::endl;
using std::cout;

Character::Character() : slot_id_(0) , name_("")
{
}

Character::Character(string name) : slot_id_(0), name_(name)
{
}

Character::Character(const Character& chara)
{
    this->delete_all_slot();
    this->slot_id_ = chara.slot_id_;
    for (int i = 0; i < this->slot_id_; i++)
    {
        this->slot_[i] = chara.slot_[i]->clone();
    }
}

Character& Character::operator=(const Character& chara)
{
    if (this != &chara)
    {
        this->delete_all_slot();
        this->slot_id_ = chara.slot_id_;
        for (int i = 0; i < this->slot_id_; i++)
        {
            this->slot_[i] = chara.slot_[i]->clone();
        }
    }
    return (*this);
}

Character::~Character()
{
    this->delete_all_slot();
}

void Character::delete_all_slot(void)
{
    for(int i=0; i < this->slot_id_; i++)
    {
        delete this->slot_[i];
        this->slot_[i] = 0;
    }
}

std::string const &Character::getName() const
{
    return (this->name_);
}

void Character::equip(AMateria* m)
{
    if (this->slot_id_ >= slot_max_)
    {
        cout << "[Character] equip error.exceed slot_max" << endl;
        return ;
    }
    if ( m == 0)
    {
        cout << "[Character] equip error.invalid materia" << endl;
        return ;
    }
    this->slot_[this->slot_id_] = m;
    this->slot_id_++;
}

void Character::unequip(int idx)
{
    if (idx < (slot_id_))
        this->slot_[idx]->unuse();
    else
        cout << "[Character] unequip error.invalid slot id" << endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < (slot_id_))
        this->slot_[idx]->use(target);
    else
        cout << "[Character] use error.invalid slot id" << endl;
}
