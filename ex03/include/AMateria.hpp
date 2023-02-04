#ifndef AMATERIA_H
#define AMATERIA_H
#include <string>
#include "ICharacter.hpp"

class ICharacter;

enum EMateria
{
    ICE,
    CURE,
};

class AMateria
{
    protected:
        std::string type_;
        bool unused_;
    public:
        AMateria(std::string const & type);
        virtual ~AMateria();
        std::string const & getType() const;
        void unuse(void);
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
        bool getUsed(void);
};
#endif
