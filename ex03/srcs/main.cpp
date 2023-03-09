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
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");


        cout << "Test No.1" << endl;
        AMateria* tmp; 
        cout << endl << "Test:create and equip ice" << endl;
        tmp = src->createMateria("ice");
        me->equip(tmp); //1
        cout << endl << "Test:create and equip cure" << endl;
        tmp = src->createMateria("cure");
        me->equip(tmp); //2
        cout << endl << "Test:create and equip fire:Error" << endl;
        cout << "Test No.2" << endl;
        tmp = src->createMateria("fire");
        me->equip(tmp); //error
        cout << endl << "Test:create and equip ice" << endl;
        tmp = src->createMateria("ice");
        me->equip(tmp); //3
        cout << "Test No.3" << endl;
        cout << endl << "Test:create and equip cure" << endl;
        tmp = src->createMateria("cure");
        me->equip(tmp); //4
        cout << "Test No.4" << endl;

        cout << endl << "Test:create and equip Max Error" << endl;
        cout << "Test No.5" << endl;
        tmp = src->createMateria("ice");
        cout << "Test No.6" << endl;
        me->equip(tmp); //error
        cout << "Test No.7" << endl;
        //delete tmp;
        cout << "Test No.1" << endl;
        cout << endl << "Test:create and equip Max Error" << endl;
        cout << "Test No.1" << endl;
        tmp = src->createMateria("cure");
        cout << "Test No.2" << endl;
        me->equip(tmp); //error
        cout << "Test No.3" << endl;
        //delete tmp;
        cout << "Test No.4" << endl;


        ICharacter* bob = new Character("bob");
        cout << "Test No.2" << endl;
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

        cout << "main No.5" << endl;
        me->use(-1, *bob); //error
        cout << "main No.6" << endl;
        me->unequip(-1);   //error
        cout << "main No.7" << endl;
        me->use(UINT_MAX, *bob);
        cout << "main No.8" << endl;
        me->unequip(UINT_MAX);
        cout << "main No.9" << endl;
        delete bob;
        cout << "main No.10" << endl;
        delete me;
        cout << "main No.11" << endl;
        delete src;
        cout << "main No.12" << endl;
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
