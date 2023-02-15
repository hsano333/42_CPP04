#include "Dog.hpp"
#include <iostream>
using std::cout;
using std::endl;

Dog::Dog() : Animal()
{
    this->type_ = "Dog";
    this->brain_ = new Brain;
    cout << "[Dog] default constructor called. brain address:" << this->brain_ << endl;
}
Dog::Dog(const Dog &dog) : Animal()
{
    Brain *tmp = new Brain;
    this->brain_->deepcopy(dog.brain_, tmp);
    this->type_ = std::string(dog.type_);
    this->brain_ = tmp;
    cout << "[Dog] Copy constructor called. this brain address: " << this->brain_ << " copy brain address:" << dog.brain_  << endl;
}

Dog& Dog::operator=(const Dog &dog)
{
    if (this != &dog)
    {
        this->Animal::operator=(dog);
        delete this->brain_;
        Brain *tmp = new Brain;
        this->brain_->deepcopy(dog.brain_, tmp);
        this->type_ = std::string(dog.type_);
        this->brain_ = tmp;
    }
    cout << "[Dog]Copy assignment operator called. this brain address:" << this->brain_ << " copy brain address:" << dog.brain_ << endl;
    return (*this);
}

Dog::~Dog()
{
    cout << "[Dog] Destructor called" << endl;
    delete brain_;
}

void Dog::makeSound(void) const
{
    //cout << "makeSound() brain=" << this->brain_ << endl;
    cout << "Wan!" << endl;
}
