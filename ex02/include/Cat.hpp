
#ifndef CAT_H
#define CAT_H
#include <string>
#include <Animal.hpp>
#include <Brain.hpp>

class Cat : public Animal
{
    private:
        Brain* brain_;
    public:
        Cat();
        Cat(const Cat &animal);
        Cat& operator=(const Cat &animal);
        virtual ~Cat();
        virtual void makeSound() const;
};

#endif
