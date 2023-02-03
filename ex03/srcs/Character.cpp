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
        this->slot_[i] = chara.slot_[i];
    }
}

void Character::operator=(const Character& chara)
{
    this->delete_all_slot();
    this->slot_id_ = chara.slot_id_;
    for (int i = 0; i < this->slot_id_; i++)
    {
        this->slot_[i] = chara.slot_[i];
    }
}

Character::~Character()
{
    this->delete_all_slot();
}

void Character::delete_all_slot(void)
{
    for(int i=0; i <= this->slot_id_; i++)
    {
        delete this->slot_[i];
    }
}

std::string const &Character::getName() const
{
    return (this->name_);
}

void Character::equip(AMateria* m)
{
    if (this->slot_id_ >= slot_max_)
        return ;
    this->slot_[this->slot_id_] = m;
    this->slot_id_++;
}

void Character::unequip(int idx)
{

}

void Character::use(int idx, ICharacter& target)
{
    if (idx < (slot_id_))
        this->slot_[idx]->use(target);
}
