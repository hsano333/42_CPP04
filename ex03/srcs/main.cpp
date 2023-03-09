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

#include <stdio.h>
__attribute__((destructor)) void f(void){
    system("leaks  Interface_recap");
}

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
        cout << "[Main:TestError]" << endl;
        tmp = src->createMateria("fire");
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
        cout << endl << "Test:Use Error" << endl;
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
    /*
    {
        cout << endl << "Test2" << endl;
        IMateriaSource* src = new MateriaSource();
        AMateria* tmp; 
        tmp = src->createMateria("ice");
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        Character me1;
        tmp = src->createMateria("ice");
        me1.equip(tmp); //1
        tmp = src->createMateria("cure");
        me1.equip(tmp); //2
                        
        //error 
        //me1.equip(tmp); //3
                        
        //Character me2;
        //me2 = me1;
        //Character me3 = Character(me2);

        Ice ice1;
        Ice ice2;
        ice2 = ice1;
        Ice ice3 = Ice(ice2);
        ice2 = ice1;

        Cure cure1;
        Cure cure2;
        cure2 = cure1;
        Cure cure3 = Cure(cure2);
        delete src;
    }
    */

    return (0);
}
