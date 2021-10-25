#include "object.h"

object::object(int v, int x, int y)
{
    Xo = x;
    Yo = y;
    V = v;
}

int object::rebote(int X, float V1, float V1p, char D)
{
    float Vp = 0;
    Vp = V-(V1p-e*(V1-V));

    if(D == 'D' || D == 'L'){
        X -= abs(Vp);
    }
    else if(D == 'A' || D == 'J'){
        X += abs(Vp);
    }

    return X;
}

void object::parabolico(int *X, int *Y, char d)
{
    if(d == 'A'){
        *X = (Xo-V*cont*T);
        //*X = Xo-*X;
    }
    else if(d == 'D'){
        *X = Xo+V*cont*T;
    }
    *Y = Yo-cont*T*(V-0.5*g*cont*T);
    cont += 1;
}















