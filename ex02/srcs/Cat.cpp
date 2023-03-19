#include "Cat.hpp"
#include <iostream>
using std::cout;
using std::endl;

Cat::Cat() : Animal() , brain_(NULL)
{
    this->type_ = "Cat";
    this->brain_ = new Brain;
    cout << "[Cat] default constructor called. brain address:" << this->brain_ << endl;
}

Cat::Cat(const Cat &cat) : Animal(cat) , brain_(NULL)
{
    Brain *tmp = new Brain;
    Brain::deepcopy(cat.brain_, tmp);
    this->brain_ = tmp;
    cout << "[Cat] Copy constructor called. this brain address: " << this->brain_ << " copy brain address:" << cat.brain_  << endl;
}

Cat& Cat::operator=(const Cat &cat)
{
    if (this != &cat)
    {
        this->Animal::operator=(cat);
        try{
            Brain *tmp = new Brain;
            Brain::deepcopy(cat.brain_, tmp);
            delete this->brain_;
            this->brain_ = tmp;
        }catch(std::exception &e){
            cout << e.what() << endl;
        }
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
