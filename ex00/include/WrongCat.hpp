
#ifndef WRONGCAT_H
#define WRONGCAT_H
#include <string>
#include <WrongAnimal.hpp>

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat &animal);
        void operator=(const WrongCat &animal);
        ~WrongCat();
        virtual void makeSound() const;
        //string getType(void);
};

#endif
