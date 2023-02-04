#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <cstdio>
#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    ICharacter* you = new Character("you");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("fire");
    me->equip(tmp);
    tmp = src->createMateria("stone");
    me->equip(tmp);
    tmp = src->createMateria("wind");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);



    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    me->use(4, *bob);

    me->unequip(0);
    me->unequip(1);
    me->unequip(2);
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);

    you = me;
    cout << "use you 0" << endl;
    you->use(0, *bob);
    cout << "use you 1" << endl;
    you->use(1, *bob);
    cout << "use you 2" << endl;
    you->use(2, *bob);
    cout << "use you 3" << endl;
    you->use(3, *bob);

    delete bob;
    delete me;
    delete you;
    delete src;

    //system("leaks  Interface_recap");
    return (0);
}
