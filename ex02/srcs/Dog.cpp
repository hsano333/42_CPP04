#include "Dog.hpp"
#include <iostream>
using std::cout;
using std::endl;

Dog::Dog()
{
    cout << "[Dog] default constructor called" << endl;
    this->type_ = "Dog";
    this->brain_ = new Brain;
}
Dog::Dog(const Dog &dog)
{
    cout << "[Dog] Copy constructor called" << endl;
    this->type_ = dog.type_;
    this->brain_ = dog.brain_;
    this->brain_->deepcopy(dog.brain_, this->brain_);
}

void Dog::operator=(const Dog &dog)
{
    Brain *tmp = new Brain;
    this->brain_->deepcopy(dog.brain_, tmp);
    cout << "[Dog]Copy assignment operator called" << endl;
    this->type_ = dog.type_;
    delete this->brain_;
    this->brain_ = tmp;
}

Dog::~Dog()
{
    cout << "[Dog] Destructor called" << endl;
    delete brain_;
}

void Dog::makeSound(void) const
{
    cout << "Wan!" << endl;
}
