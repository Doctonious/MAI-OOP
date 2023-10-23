#ifndef TRAINGUARD
#define TRAINGUARD

#include "Wagon.hpp"

class Train
{
public:
    Train();

    Wagon* at(int i = 0);
    void push(Wagon*);
    void pop();
    int getSize();
    void info();

private:
    Wagon* _start;
    int _size;

};

#endif //TRAINGUARD