#include "Window.h"
#include <QLayout>


Window::Window()
{
this->setWindowTitle("Обработка событий");
area = new Area( this );//Создание области рисования с родителем
btn = new QPushButton("Завершить",this );//Создание кнопки "Завершить" с родителем
QVBoxLayout *layout = new QVBoxLayout(this);
layout->addWidget(area);
layout->addWidget(btn);
connect(btn, &QPushButton::clicked,this,&QWidget::close);
};
