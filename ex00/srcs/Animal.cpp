#include "Animal.hpp"
#include <iostream>
using std::cout;
using std::endl;

Animal::Animal()
{
    cout << "[Animal] default constructor called" << endl;
    this->type_ = "Animal";
}

Animal::Animal(const Animal &animal)
{
    cout << "[Animal] Copy constructor called" << endl;
    this->type_ = animal.type_;
}
Animal& Animal::operator=(const Animal &animal)
{
    cout << "[Animal]Copy assignment operator called" << endl;
    this->type_ = animal.type_;
    return (*this);
}

Animal::~Animal()
{
    cout << "[Animal] Destructor called" << endl;
}

void Animal::makeSound(void) const
{
    cout << "Animal Wan! Nya-" << endl;
}

string const &Animal::getType(void) const
{
    return (this->type_);
}
