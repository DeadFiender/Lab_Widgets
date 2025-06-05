#ifndef FIGURA_H
#define FIGURA_H

#include <QPainter>
#include <QtGui>
class Figura
{
protected:
    int x,y,halflen,dx,dy,r;//dx, dy — проекции halflen на оси X и Y при повороте.
    virtual void draw(QPainter *Painter)=0;
public:
    Figura(int X,int Y,int Halflen):
        x(X),y(Y),halflen(Halflen){}//Конструктор класса Figura. Инициализирует координаты и halflen.
    void move(float Alpha,QPainter *Painter);//Метод move — перемещает фигуру под определённым углом и вызывает рисование.
};
class MyLine:public Figura
{
protected:
    void draw(QPainter *Painter);//Реализация метода draw для линии
public:
    MyLine(int x,int y,int halflen):Figura(x,y,halflen){}//Конструктор, передающий параметры в конструктор родителя.
};
class MyRect:public Figura
{
protected:
    void draw(QPainter *Painter);//Реализация метода draw для квадрата.
public:
    MyRect(int x,int y,int halflen):Figura(x,y,halflen){}//Конструктор, передающий значения в базовый класс.
};
#endif
