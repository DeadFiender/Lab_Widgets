#ifndef WINDOW_H
#define WINDOW_H

#include <QtGui>
#include "Area.h"
#include <QWidget>
#include <QPushButton>

class Window : public QWidget
{
protected:
    QTextCodec *codec;
    Area * area; // область отображения рисунка
    QPushButton * btn;
public:
    Window();
};
#endif
