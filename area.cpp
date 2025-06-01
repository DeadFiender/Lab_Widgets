#include <QSize>
#include <QTimerEvent>

#include "Area.h"

Area::Area(QWidget *parent):QWidget(parent)//онструктор класса Area, принимает указатель на родительский виджет.
{
    setFixedSize(QSize(300,200));//Устанавливает фиксированный размер области рисования — 300×200 пикселей.
    myline=new MyLine(80,100,50);//Создаётся линия с центром в точке (80,100) и длиной 100 пикселей.
    myrect=new MyRect(220,100,50);//Создаётся квадрат с центром в точке (220,100) и размером 100×100 пикселей.
    alpha=0;
}
void Area::showEvent(QShowEvent *)//Обработчик события показа виджета.
{
    myTimer=startTimer(50); // Запускается таймер, который будет генерировать событие каждые 50 миллисекунд.
}
void Area::paintEvent(QPaintEvent *)//Обработчик события перерисовки виджета.
{
    QPainter painter(this);//Создаётся объект QPainter для рисования внутри этого виджета.
    painter.setPen(Qt::red);//Устанавливается красная кисть/перо для рисования.
    myline->move(alpha,&painter);//линия поворачивается на угол alpha и рисуется.
    myrect->move(alpha*(-0.5),&painter);//квадрат поворачивается на угол -alpha*0.5 и рисуется.
}
void Area::timerEvent(QTimerEvent *event)//Обработчик события таймера.
{
    if (event->timerId() == myTimer) // Проверяет, принадлежит ли событие нашему таймеру.
    {
        alpha=alpha+0.2;//увеличивает угол поворота на 0.2 радиана (~11.5 градусов).
        update(); // Запрашивает перерисовку окна — вызов paintEvent
    }
    else
        QWidget::timerEvent(event); // иначе передать для стандартной
    // обработки
}
void Area::hideEvent(QHideEvent *)//Обработчик события скрытия виджета.
{
    killTimer(myTimer); // Останавливает таймер, чтобы не генерировать лишние события.
}
Area::~Area()
{
    delete myline;
    delete myrect;
}
