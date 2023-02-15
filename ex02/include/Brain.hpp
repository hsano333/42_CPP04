#ifndef BRAIN_H
#define BRAIN_H
#include <string>

class Brain
{
    private:
        const static int array_size_ = 100;
        std::string ideas[array_size_];
    public:
        Brain();
        Brain(const Brain &brain);
        Brain& operator=(const Brain &brain);
        ~Brain();
        void deepcopy(const Brain* src, Brain* dst) const;
};

#endif
