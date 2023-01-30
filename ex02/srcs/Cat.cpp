#include "Cat.hpp"
#include <iostream>
using std::cout;
using std::endl;

Cat::Cat()
{
    cout << "[Cat] default constructor called" << endl;
    this->type_ = "Cat";
    this->brain_ = new Brain;
}

Cat::Cat(const Cat &cat)
{
    cout << "[Cat] Copy constructor called" << endl;
    this->type_ = cat.type_;
    this->brain_ = new Brain;
    this->brain_->deepcopy(cat.brain_, this->brain_);
}

void Cat::operator=(const Cat &cat)
{
    Brain *tmp = new Brain;
    this->brain_->deepcopy(cat.brain_, tmp);
    cout << "[Cat]Copy assignment operator called" << endl;
    this->type_ = cat.type_;
    delete this->brain_;
    this->brain_ = tmp;
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
