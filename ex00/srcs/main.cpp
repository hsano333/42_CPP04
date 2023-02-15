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
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); 
    j->makeSound();
    meta->makeSound();



    delete meta;
    meta = i;
    cout << endl << "Cat Test" << endl;
    i->makeSound();
    delete meta;
    delete j;

    cout << endl;
    Dog k;
    Dog l = Dog(k);

    cout << endl << "Wrong Test" << endl;
    const WrongAnimal* wrong_animal = new WrongAnimal();
    const WrongAnimal* wrong_cat = new WrongCat();
    std::cout << wrong_cat->getType() << " " << std::endl;
    wrong_cat->makeSound(); 
    //wrong_animal->makeSound();

    cout << endl;
    delete wrong_animal;
    delete wrong_cat;

    //system("leaks I_dont_want_to_set_the_world_on_fire");
    return (0);
}
