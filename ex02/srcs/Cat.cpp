#include "Cat.hpp"
#include <iostream>
using std::cout;
using std::endl;

Cat::Cat() : Animal()
{
    this->type_ = "Cat";
    this->brain_ = new Brain;
    cout << "[Cat] default constructor called. brain address:" << this->brain_ << endl;
}

Cat::Cat(const Cat &cat) : Animal()
{
    Brain *tmp = new Brain;
    this->brain_->deepcopy(cat.brain_, tmp);
    this->type_ = std::string(cat.type_);
    this->brain_ = tmp;
    cout << "[Cat] Copy constructor called. this brain address: " << this->brain_ << " copy brain address:" << cat.brain_  << endl;
}

Cat& Cat::operator=(const Cat &cat)
{
    if (this != &cat)
    {
        this->Animal::operator=(cat);
        Brain *tmp = new Brain;
        this->brain_->deepcopy(cat.brain_, tmp);
        this->type_ = std::string(cat.type_);
        this->brain_ = tmp;
    }
    cout << "[Cat] Copy constructor called. this brain address: " << this->brain_ << " copy brain address:" << cat.brain_  << endl;
    return (*this);
}

Cat::~Cat()
{
    cout << "[Cat] Destructor called" << endl;
    delete brain_;
}

void Cat::makeSound(void) const
{
    cout << "Nya-" << endl;
}
