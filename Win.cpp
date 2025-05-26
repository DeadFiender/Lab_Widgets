#include <QLayout>

#include "Win.h"

Win::Win(QWidget *parent):QWidget(parent)//конструктор win
{
this->setWindowTitle("Счетчик");//установка заголовка окна
label1 = new QLabel("Cчет по 1",this);//2 метки для 2 счетчиков
label2 = new QLabel("Cчет по 5",this);
edit1 = new Counter("0",this);
edit2 = new Counter("0",this);//2 счетчика для 2 меток изначально 0
calcbutton=new QPushButton("+1",this);
exitbutton=new QPushButton("Выход",this);//создание 2 кнопок
QHBoxLayout *layout1 = new QHBoxLayout();//горизонтальный макет для меток
layout1->addWidget(label1);
layout1->addWidget(label2);
QHBoxLayout *layout2 = new QHBoxLayout();//горизонт макет для счетчиков
layout2->addWidget(edit1);
layout2->addWidget(edit2);
QHBoxLayout *layout3 = new QHBoxLayout();//горизонт макет для кнопок
layout3->addWidget(calcbutton);
layout3->addWidget(exitbutton);
QVBoxLayout *layout4 = new QVBoxLayout(this);//вертикальный объедин горизонтальные
layout4->addLayout(layout1);
layout4->addLayout(layout2);
layout4->addLayout(layout3);
// связь сигнала нажатия кнопки и слота закрытия окна
connect(calcbutton,&QPushButton::clicked,edit1,&Counter::add_one);//Когда нажата кнопка "+1" — вызывается слот add_one() у edit1.
connect(edit1,&Counter::tick_signal,edit2,&Counter::add_one);//Когда edit1 испускает сигнал tick_signal() (т.е. число делится на 5), вызывается add_one() у edit2.
connect(exitbutton,&QPushButton::clicked,this,&QWidget::close);//Когда нажата кнопка "Выход" — вызывается метод close() у окна.
}
