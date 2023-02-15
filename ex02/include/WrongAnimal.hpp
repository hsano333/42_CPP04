#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H
#include <string>

using std::string;

class WrongAnimal
{
    protected:
        string type_;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &wrong_animal);
        WrongAnimal& operator=(const WrongAnimal &wrong_animal);
        virtual ~WrongAnimal();
        void makeSound(void) const;
        string const &  getType(void) const;

};

#endif
