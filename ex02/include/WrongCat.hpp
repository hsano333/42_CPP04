
#ifndef WRONGCAT_H
#define WRONGCAT_H
#include <string>
#include <WrongAnimal.hpp>

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat &animal);
        WrongCat& operator=(const WrongCat &animal);
        ~WrongCat();
        virtual void makeSound() const;
};

#endif
