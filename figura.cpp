#include <math.h>
#include "Figura.h"

void Figura::move(float Alpha,QPainter *Painter)
{
    dx=halflen*cos(Alpha);
    dy=halflen*sin(Alpha);//Вычисление проекций halflen на ось X и Y при повороте на угол Alpha.
    draw(Painter);//Вызывается виртуальный метод draw для отрисовки фигуры.
}
void MyLine::draw(QPainter *Painter)//Реализация метода draw для линии.
{
    Painter->drawLine(x+dx,y+dy,x-dx,y-dy);//Рисует линию, повернутую на угол Alpha (через dx/dy).
}
void MyRect::draw(QPainter *Painter)//Реализация метода draw для квадрата.
{//Рисует квадрат, повёрнутый на угол Alpha (смешанные dx/dy создают эффект поворота).
    Painter->drawLine(x+dx,y+dy,x+dy,y-dx);
    Painter->drawLine(x+dy,y-dx,x-dx,y-dy);
    Painter->drawLine(x-dx,y-dy,x-dy,y+dx);
    Painter->drawLine(x-dy,y+dx,x+dx,y+dy);
}
