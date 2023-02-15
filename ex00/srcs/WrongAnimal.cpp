#include "WrongAnimal.hpp"
#include <iostream>
using std::cout;
using std::endl;

WrongAnimal::WrongAnimal()
{
    cout << "[WrongAnimal] default constructor called" << endl;
    this->type_ = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrong_animal)
{
    cout << "[WrongAnimal] Copy constructor called" << endl;
    this->type_ = wrong_animal.type_;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &wrong_animal)
{
    cout << "[WrongAnimal]Copy assignment operator called" << endl;
    this->type_ = wrong_animal.type_;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    cout << "[WrongAnimal] Destructor called" << endl;
}

void WrongAnimal::makeSound(void) const
{
    cout << "Wrong Wan! Nya-" << endl;
}

string const &WrongAnimal::getType(void) const
{
    return (this->type_);
}
