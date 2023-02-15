#ifndef DOG_H
#define DOG_H
#include <string>
#include <Animal.hpp>
#include <Brain.hpp>

class Dog : public Animal
{
    private:
        Brain* brain_;
    public:
        Dog();
        Dog(const Dog &dog);
        Dog& operator=(const Dog &dog);
        virtual ~Dog();
        virtual void makeSound() const;
};

#endif
