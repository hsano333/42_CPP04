#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include <iostream>
using std::cout;
using std::endl;

/*
#include <stdio.h>
__attribute__((destructor)) void f(void){
    system("leaks Abstract_class");
}
*/

int main()
{

    {
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const Animal* k;

    cout << "Test:Dog makeSound()" << endl;
    j->makeSound();
    k = j;
    k->makeSound();


    cout << endl << "Test:make Cat()" << endl;
    Animal *array_animal[10];
    for (int i = 0; i < 5; i++)
    {
        array_animal[i] = new Cat();
    }
    cout << endl << "Test:make Dog()" << endl;
    for (int i = 5; i < 10; i++)
    {
        array_animal[i] = new Dog();
    }

    cout << endl << "Test:delete All" << endl;
    for (int i = 0; i < 10; i++)
    {
        delete array_animal[i];
    }

    cout << endl;
    delete j;
    delete i;
    cout << endl;
    }
    {
        Cat cat2;
        Cat cat3;

        cat2 = cat3;

        Dog dog2;
        Dog dog3;

        dog2 = dog3;
    }
    return (0);
}
