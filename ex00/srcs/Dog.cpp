#include "Dog.hpp"
#include <iostream>
using std::cout;
using std::endl;

Dog::Dog()
{
    cout << "[Dog] default constructor called" << endl;
    this->type_ = "Dog";
}
Dog::Dog(const Dog &dog)
{
    cout << "[Dog] Copy constructor called" << endl;
    this->type_ = dog.type_;
}

void Dog::operator=(const Dog &dog)
{
    cout << "[Dog]Copy assignment operator called" << endl;
    this->type_ = dog.type_;
}

Dog::~Dog()
{
    cout << "[Dog] Destructor called" << endl;
}

void Dog::makeSound(void) const
{
    cout << "Wan!" << endl;
}
