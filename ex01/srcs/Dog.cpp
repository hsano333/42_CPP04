#include "Dog.hpp"
#include <iostream>
using std::cout;
using std::endl;

Dog::Dog() : Animal() , brain_(NULL)
{
    this->type_ = "Dog";
    this->brain_ = new Brain;
    cout << "[Dog] default constructor called. brain address:" << this->brain_ << endl;
}
Dog::Dog(const Dog &dog) : Animal(dog) , brain_(NULL)
{
    Brain *tmp = new Brain;
    Brain::deepcopy(dog.brain_, tmp);
    this->brain_ = tmp;
    cout << "[Dog] Copy constructor called. this brain address: " << this->brain_ << " copy brain address:" << dog.brain_  << endl;
}

Dog& Dog::operator=(const Dog &dog)
{
    if (this != &dog)
    {
        this->Animal::operator=(dog);
        try{
            Brain *tmp = new Brain;
            Brain::deepcopy(dog.brain_, tmp);
            delete this->brain_;
            this->brain_ = tmp;
        }catch(std::exception &e){
            cout << e.what() << endl;
        }
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
    cout << "Wan!" << endl;
}
