
#ifndef CAT_H
#define CAT_H
#include <string>
#include <Animal.hpp>
#include <Brain.hpp>

class Cat : virtual public Animal
{
    private:
        Brain* brain_;
    public:
        Cat();
        Cat(const Cat &animal);
        void operator=(const Cat &animal);
        virtual ~Cat();
        virtual void makeSound() const;
};

#endif
