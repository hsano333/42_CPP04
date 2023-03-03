#ifndef CURE_H
#define CURE_H
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

using std::string;

class Cure : virtual public AMateria
{
    public:
        Cure();
        Cure(const Cure& ice);
        Cure& operator=(const Cure& ice);
        ~Cure();
        virtual void use(ICharacter&);
        AMateria* clone() const;
};

#endif
