#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>

using std::string;

class Animal
{
    protected:
        string type_;
    public:
        Animal();
        Animal(const Animal &animal);
        Animal& operator=(const Animal &animal);
        virtual ~Animal();
        virtual void makeSound(void) const;
        string const &  getType(void) const;

};

#endif
