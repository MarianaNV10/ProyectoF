#ifndef OBJECT_H
#define OBJECT_H

#include <math.h>

class object
{

private:

    float e = 0.7; //constante de restitución
    float V, g = 9.8, T = 0.1;
    int Xo, Yo;
    unsigned int cont = 1;

public:
    object(int v, int x, int y);
    int rebote(int X, float V1, float V1p, char D);
    void parabolico(int *X, int *Y, char d);
};

#endif // OBJECT_H
