#include "Brain.hpp"
#include <iostream>
using std::cout;
using std::endl;

Brain::Brain()
{
    cout << "[Brain] default constructor called" << endl;
}

Brain::Brain(const Brain &brain)
{
    cout << "[Brain] Copy constructor called" << endl;
    for(int i=0; i < array_size_; i++)
    {
        //this->ideas[i] = brain.ideas[i];
        this->ideas[i] = std::string(brain.ideas[i]);
    }
}

void Brain::operator=(const Brain &brain)
{
    cout << "[Brain]Copy assignment operator called" << endl;
    //this->deepcopy(this, brain);
    for(int i=0; i < array_size_; i++)
    {
        this->ideas[i] = std::string(brain.ideas[i]);
    }
}

Brain::~Brain()
{
    cout << "[Brain] Destructor called" << endl;
}

void Brain::deepcopy(const Brain* src, Brain* dst) const
{
    for(int i=0; i < array_size_; i++)
    {
        dst->ideas[i] = std::string(src->ideas[i]);
    }
}
