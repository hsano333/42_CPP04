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
        this->slot_[i].first = chara.slot_[i].first->clone();
        this->slot_[i].second = true;
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
    if ( m == 0) 
    {
        cout << "[Character] equip error.invalid materia" << endl;
        return ;
    }
    for(int i=0; i < this->slot_max_; i++)
    {
        if (this->slot_[i].second == false)
        {
            this->slot_[i].first = m;
            this->slot_[i].second = true;
            break ;
        }
    }
}

void Character::unequip(int idx)
{
    cout << "unequip No.1:idx=" << idx  << endl;
    if (0 <= idx && idx < (this->slot_max_))
    {
        cout << "unequip No.2:idx=" << idx  << endl;
        if (this->slot_[idx].second == true)
        {
            cout << "unequip No.3:idx=" << idx  << endl;
            unequiped_slot.add(this->slot_[idx].first);
            cout << "unequip No.4:idx=" << idx  << endl;
            this->slot_[idx].first = NULL;
                cout << "unequip No.5:idx=" << idx  << endl;
            this->slot_[idx].second = false;
                cout << "unequip No.6:idx=" << idx  << endl;
        }
        else
            cout << "[Character] unequip error.This slot is empty" << endl;
    }
    else
        cout << "[Character] unequip error.invalid slot id" << endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (0 <= idx && idx < slot_max_)
    {
        if (this->slot_[idx].second)
            this->slot_[idx].first->use(target);
        else
            cout << "[Character] use error." << idx << " is empty" << endl;
    }
    else
    {
        cout << "[Character] use error.invalid slot id" << endl;
    }
}


Character::UnequipedSlot::UnequipedSlot() : slot(NULL), next(NULL)
{
}

Character::UnequipedSlot::~UnequipedSlot()
{
    this->clear();
}

void Character::UnequipedSlot::add(AMateria *slot)
{
    cout << "add No.1" << endl;
    UnequipedSlot *tmp = this;
    if (this->slot== NULL)
    {
        cout << "add No.2" << endl;
        this->slot = slot;
        return ;
    }
    cout << "add No.3" << endl;
    if (this->next != NULL)
        tmp = this->next;
    cout << "add No.3-1" << endl;
    while (tmp->next)
    {
        cout << "add No.3-2" << endl;
        tmp = tmp->next;
    }
    cout << "add No.4" << endl;
    /*
    if (tmp->slot == NULL)
    {
        cout << "add No.5" << endl;
        this->slot = slot;
        return ;
    }
    */
    cout << "add No.6" << endl;
    this->next = new UnequipedSlot();
    cout << "add No.7" << endl;
    this->next->slot = slot;
    cout << "add No.8" << endl;
}

void Character::UnequipedSlot::clear()
{
}
