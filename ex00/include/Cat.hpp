
#ifndef CAT_H
#define CAT_H
#include <string>
#include <Animal.hpp>

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat &animal);
        void operator=(const Cat &animal);
        ~Cat();
        virtual void makeSound() const;
        //string getType(void);
};

#endif
