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
        void operator=(const Dog &dog);
        ~Dog();
        virtual void makeSound() const;
        //string getType(void);
};

#endif