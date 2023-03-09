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
        cout << "Test0" << endl;
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;
    }
    {
        cout << endl << "Test1" << endl;
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");


        AMateria* tmp; 
        tmp = src->createMateria("ice");
        me->equip(tmp); //1
        tmp = src->createMateria("cure");
        me->equip(tmp); //2
        tmp = src->createMateria("fire"); //error
        me->equip(tmp); //error
        tmp = src->createMateria("ice");
        me->equip(tmp); //3
        tmp = src->createMateria("cure");
        me->equip(tmp); //4
        tmp = src->createMateria("ice");
        me->equip(tmp); //error
        tmp = src->createMateria("cure");
        me->equip(tmp); //error

        ICharacter* bob = new Character("bob");
        cout << endl << "Test:Use" << endl;
        me->use(0, *bob);
        me->use(1, *bob);
        me->use(2, *bob);
        me->use(3, *bob);
        me->use(4, *bob); //error

        cout << endl << "Test:Unequip" << endl;
        me->unequip(0);
        me->unequip(1);
        me->unequip(2);
        me->use(0, *bob); //error
        me->use(1, *bob); //error
        me->use(2, *bob); //error
        me->use(3, *bob); 

        me->use(-1, *bob); //error
        me->unequip(-1);   //error
        me->use(UINT_MAX, *bob);
        me->unequip(UINT_MAX);
        delete bob;
        delete me;
        delete src;
    }
    {
        cout << endl << "Test2" << endl;
        ICharacter* me = new Character("me");
        ICharacter* you= new  Character("you");

        me->equip(new Ice()); 
        me->equip(new Ice()); 
        me->equip(new Cure());
        me->unequip(0);
        me->unequip(1);
        me->unequip(2);
        me->unequip(3);
        me->unequip(0);
        me->unequip(1);
        me->equip(new Ice()); 
        me->equip(new Ice()); 
        me->equip(new Cure());
        me->unequip(0);
        me->unequip(1);
        me->unequip(2);
        me->equip(new Ice()); 
        me->equip(new Ice()); 
        me->equip(new Cure());
        me->equip(new Cure());
        me->unequip(0);
        me->unequip(1);
        me->unequip(2);
        me->unequip(3);
        me->equip(new Cure());

        you->equip(new Ice());
        you->equip(new Ice());
        you->equip(new Ice());
        you->unequip(0);
        you->unequip(1);
        you->unequip(2);
        *you = *me;
        delete you;
        delete me;
        //return 0;

    }
    return (0);
}
