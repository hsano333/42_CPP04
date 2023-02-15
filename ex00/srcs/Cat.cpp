#include "Cat.hpp"
#include <iostream>
using std::cout;
using std::endl;

Cat::Cat()
{
    cout << "[Cat] default constructor called" << endl;
    this->type_ = "Cat";
}

Cat::Cat(const Cat &cat) : Animal()
{
    cout << "[Cat] Copy constructor called" << endl;
    this->type_ = cat.type_;
}

Cat& Cat::operator=(const Cat &cat)
{
    cout << "[Cat]Copy assignment operator called" << endl;
    this->Animal::operator=(cat);
    this->type_ = cat.type_;
    return (*this);
}

Cat::~Cat()
{
    cout << "[Cat] Destructor called" << endl;
}

void Cat::makeSound(void) const
{
    cout << "Nya-" << endl;
}
