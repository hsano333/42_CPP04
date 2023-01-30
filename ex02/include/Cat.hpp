
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
        void operator=(const Cat &animal);
        ~Cat();
        virtual void makeSound() const;
        //string getType(void);
};

#endif
