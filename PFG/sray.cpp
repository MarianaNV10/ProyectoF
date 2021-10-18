#include "sray.h"

sray::sray(int x, int y, QLabel *obj)
{
    setPixmap(QPixmap(move[1]));
    setPos(x,y);

    objeto = obj;
}
