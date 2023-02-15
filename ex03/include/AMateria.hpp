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

        AMateria();
        virtual ~AMateria();
        AMateria(const AMateria& materia);
        AMateria& operator=(const AMateria& materia);

        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);


        void unuse(void);
        bool getUsed(void);
};
#endif
