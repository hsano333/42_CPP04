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

/*
#include <stdio.h>
__attribute__((destructor)) void f(void){
    system("leaks  Interface_recap");
}
*/

int main(void)
{
    {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");


    AMateria* tmp;
    cout << endl << "Test:create and equip ice" << endl;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    cout << endl << "Test:create and equip cure" << endl;
    tmp = src->createMateria("cure");
    me->equip(tmp);
    cout << endl << "Test:create and equip fire:Error" << endl;
    tmp = src->createMateria("fire");
    me->equip(tmp);
    cout << endl << "Test:create and equip ice" << endl;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    cout << endl << "Test:create and equip cure" << endl;
    tmp = src->createMateria("cure");
    me->equip(tmp);

    cout << endl << "Test:create and equip Max Error" << endl;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    delete tmp;
    cout << endl << "Test:create and equip Max Error" << endl;
    tmp = src->createMateria("cure");
    me->equip(tmp);
    delete tmp;



    ICharacter* bob = new Character("bob");
    cout << endl << "Test:Use" << endl;
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    cout << endl << "Test:Use Error" << endl;
    me->use(4, *bob);

    cout << endl << "Test:Unequip" << endl;
    me->unequip(0);
    me->unequip(1);
    me->unequip(2);
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);

    me->use(-1, *bob);
    me->unequip(-1);
    me->use(UINT_MAX, *bob);
    me->unequip(UINT_MAX);
    delete bob;
    delete me;
    delete src;
    }

    return (0);
}
