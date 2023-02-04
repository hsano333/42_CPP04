#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main()
{


    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const Animal* k;

    k = j;

    Animal *array_animal[10];
    for (int i = 0; i < 5; i++)
    {
        array_animal[i] = new Cat();
    }
    for (int i = 5; i < 10; i++)
    {
        array_animal[i] = new Dog();
    }


    for (int i = 0; i < 10; i++)
    {
        delete array_animal[i];
    }

    delete j;
    delete i;
    system("leaks I_dont_want_to_set_the_world_on_fire");
    return (0);

}
