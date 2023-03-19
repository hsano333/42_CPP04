#include "Character.hpp"
#include <string>
#include <iostream>

using std::string;
using std::endl;
using std::cout;

void init_array(std::pair<AMateria*, bool> *slot, int max)
{
    for (int i = 0; i < max; i++)
    {
        slot[i].first = NULL;
        slot[i].second = false;
    }
}

Character::Character() : name_(""), unequiped_slot(UnequipedSlot())
{
    init_array(slot_, this->slot_max_);
}

Character::Character(string name) : name_(name), unequiped_slot(UnequipedSlot())
{
    unequiped_slot = UnequipedSlot();
    init_array(slot_, this->slot_max_);
}

Character::Character(const Character& chara) : unequiped_slot(UnequipedSlot())
{
    init_array(slot_, this->slot_max_);
    for (int i = 0; i < this->slot_max_; i++)
    {
        if (chara.slot_[i].second)
            this->slot_[i] = std::make_pair(chara.slot_[i].first->clone(), false);
    }
}

Character& Character::operator=(const Character& chara)
{
    if (this != &chara)
    {
        this->delete_all_slot();
        this->unequiped_slot.clear();
        for (int i = 0; i < this->slot_max_; i++)
        {
            if (chara.slot_[i].second)
                this->slot_[i] = std::make_pair(chara.slot_[i].first->clone(), false);
        }
    }
    return (*this);
}

Character::~Character()
{
    this->delete_all_slot();
    this->unequiped_slot.clear();
}

void Character::delete_all_slot(void)
{
    for(int i=0; i < this->slot_max_; i++)
    {
        if (this->slot_[i].second)
            delete this->slot_[i].first;
        this->slot_[i].second = false;
    }
}

std::string const &Character::getName() const
{
    return (this->name_);
}

void Character::equip(AMateria* m)
{
    bool err_flag = true;
    if ( m == 0) 
    {
        cout << "[Character] equip error.invalid materia" << endl;
        return ;
    }
    for(int i=0; i < this->slot_max_; i++)
    {
        if (this->slot_[i].second == false)
        {
            this->slot_[i].first = m->clone();
            this->slot_[i].second = true;
            err_flag = false;
            break ;
        }
    }
    delete m;
    if (err_flag)
        cout << "[Character]slot is full so can't equip." << endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= this->slot_max_)
    {
        cout << "[Character] unequip error. slot:" << idx << " is invalid slot id" << endl;
        return ;
    }
    if (this->slot_[idx].first && this->slot_[idx].second == true)
    {
        unequiped_slot.add(this->slot_[idx].first);
        this->slot_[idx].first = NULL;
        this->slot_[idx].second = false;
    }
    else
        cout << "[Character] unequip error. slot:" << idx << " is empty" << endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (0 <= idx && idx < slot_max_)
    {
        if (this->slot_[idx].second)
            this->slot_[idx].first->use(target);
        else
            cout << "[Character] can't use. slot:" << idx << " is empty" << endl;
    }
    else
    {
        cout << "[Character] can't use. slot:" << idx << " is invalid slot id" << endl;
    }
}


Character::UnequipedSlot::UnequipedSlot() : slot(NULL), next(NULL)
{
}

Character::UnequipedSlot::~UnequipedSlot()
{
}

Character::UnequipedSlot::UnequipedSlot(const UnequipedSlot& unequiped_slot)
{
    (void)unequiped_slot;
}

Character::UnequipedSlot& Character::UnequipedSlot::operator=(const UnequipedSlot& unequiped_slot)
{
    (void)unequiped_slot;
    this->clear();
    return (*this);
}

void Character::UnequipedSlot::add(AMateria *slot)
{
    UnequipedSlot *tmp = this;
    if (this->slot== NULL)
    {
        this->slot = slot;
        return ;
    }
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->next = new UnequipedSlot();
    tmp->next->slot = slot;
}

void Character::UnequipedSlot::clear()
{
    UnequipedSlot *tmp;
    UnequipedSlot *next = NULL;
    tmp = this;
    if (tmp->slot)
    {
        delete tmp->slot;
    }
    next = tmp->next;
    while (next)
    {
        tmp = next;
        next = tmp->next;
        delete tmp->slot;
        delete tmp;
    }
}
