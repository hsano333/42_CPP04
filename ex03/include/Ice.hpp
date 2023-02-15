#ifndef ICE_H
#define ICE_H
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

using std::string;


class Ice : virtual public AMateria
{
    //private:
        //string name_;
    public:
        Ice();
        Ice(const Ice& ice);
        Ice& operator=(const Ice& ice);
        ~Ice();
        //std::string const & getType() const;
        virtual void use(ICharacter&);
        AMateria* clone() const;

};

#endif
