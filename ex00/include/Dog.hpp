#ifndef DOG_H
#define DOG_H
#include <string>
#include <Animal.hpp>

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog &dog);
        Dog& operator=(const Dog &dog);
        ~Dog();
        virtual void makeSound() const;
};

#endif
