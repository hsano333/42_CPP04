
#ifndef CAT_H
#define CAT_H
#include <string>
#include <Animal.hpp>

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat &animal);
        Cat& operator=(const Cat &animal);
        ~Cat();
        virtual void makeSound() const;
};

#endif
