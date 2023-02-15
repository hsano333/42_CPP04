#ifndef CHARACTER_H
#define CHARACTER_H
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

using std::string;

class Character : virtual public ICharacter
{
    private:
        const static int slot_max_ = 4;
        AMateria* slot_[slot_max_];
        int slot_id_;
        std::string name_;
        void delete_all_slot(void);
    public:
        Character();
        Character(string name);
        Character(const Character& chara);
        Character& operator=(const Character& chara);
        ~Character();
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif

