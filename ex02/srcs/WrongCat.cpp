#include "WrongCat.hpp"
#include <iostream>
using std::cout;
using std::endl;

WrongCat::WrongCat()
{
    cout << "[WrongCat] default constructor called" << endl;
    this->type_ = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &wrong_cat) : WrongAnimal()
{
    cout << "[WrongCat] Copy constructor called" << endl;
    this->type_ = wrong_cat.type_;
}

WrongCat& WrongCat::operator=(const WrongCat &wrong_cat)
{
    cout << "[WrongCat]Copy assignment operator called" << endl;
    this->WrongAnimal::operator=(wrong_cat);
    this->type_ = wrong_cat.type_;
    return (*this);
}

WrongCat::~WrongCat()
{
    cout << "[WrongCat] Destructor called" << endl;
}

void WrongCat::makeSound(void) const
{
    cout << "Nya-" << endl;
}
