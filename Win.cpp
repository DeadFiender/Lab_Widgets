#include <QLayout>
#include <QtMath>
#include <QMessageBox>
#include <QTextCodec>
#include <clocale>
#include <Windows.h>
#include <QTextStream>

#include "Win.h"

Win::Win(QWidget *parent):QWidget(parent)//Реализация конструктора, передаёт parent в базовый QWidget
{
    setWindowTitle("Возведение в квадрат");//Устанавливает заголовок окна.
    frame = new QFrame(this);//
    frame->setFrameShadow(QFrame::Raised);//
    frame->setFrameShape(QFrame::Panel);//Создаёт рамку-панель для ввода/вывода, задаёт ей стиль: приподнятая панел
    inputLabel = new QLabel("Введите число:",this);//
    inputEdit = new QLineEdit("",this);//Создаются метка и поле для ввода числа.
    StrValidator *v=new StrValidator(inputEdit);//
    inputEdit->setValidator(v);//Создаётся и устанавливается валидатор, который разрешает любой ввод
    outputLabel = new QLabel("Результат:",this);//
    outputEdit = new QLineEdit("",this);//Метка и поле вывода результата.
    nextButton = new QPushButton("Следующее",this);//
    exitButton = new QPushButton("Выход",this);//Кнопки: "Следующее" (обновить форму) и "Выход" (закрыть приложение).

    // компоновка приложения выполняется согласно рисунку 2
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame);
    vLayout1->addWidget(inputLabel);//vLayout1: вертикальная компоновка внутри frame (левая часть окна).
    vLayout1->addWidget(inputEdit);//Добавляет метки и поля.
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch();//addStretch() — добавляет гибкое пространство, чтобы при изменении размера всё тянулось вверх.
    QVBoxLayout *vLayout2 = new QVBoxLayout();
    vLayout2->addWidget(nextButton);//vLayout2: вертикальная компоновка справа (только кнопки).
    vLayout2->addWidget(exitButton);//
    vLayout2->addStretch();//
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(frame);//Основная горизонтальная компоновка: слева — frame, справа — кнопки.
    hLayout->addLayout(vLayout2);//
    begin();//Вызов метода begin() для начальной инициализации интерфейса.
    connect(exitButton,&QPushButton::clicked,this,&QWidget::close);//При нажатии "Выход" — закрыть окно.
    connect(nextButton,&QPushButton::clicked,this,&Win::begin);//При нажатии "Следующее" — очистить форму.
    connect(inputEdit,&QLineEdit::returnPressed,this,&Win::calc);//При нажатии Enter в поле ввода — вычислить.
}
void Win::begin()
{//Сброс формы:
    inputEdit->clear();//Очищается поле ввода.
    nextButton->setEnabled(false);
    nextButton->setDefault(false);//Отключается и убирается фокус с кнопки "Следующее".
    inputEdit->setEnabled(true);//Включается поле ввода.
    outputLabel->setVisible(false);//Прячется результат.
    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);
    inputEdit->setFocus();//Фокус — на поле ввода.
}
void Win::calc()
{
    bool Ok=true; float r,a;
    QString str=inputEdit->text();
    a=str.toDouble(&Ok);//Получение строки и преобразование в число (в a), Ok — флаг, удалось ли преобразование.
    if (Ok)//Если преобразование удалось:
    {
        r=a*a;
        str.setNum(r);//Вычисляется квадрат.
        outputEdit->setText(str);//Отображается результат.
        inputEdit->setEnabled(false);//Отключается поле ввода.
        outputLabel->setVisible(true);//Показывается результат.
        outputEdit->setVisible(true);
        nextButton->setDefault(true);
        nextButton->setEnabled(true);//Активируется кнопка "Следующее".
        nextButton->setFocus();
    }
    else//Если строка не пустая, но не число — показывается сообщение об ошибке.
        if (!str.isEmpty())
        {
            QMessageBox msgBox(QMessageBox::Information,
                               ("Возведение в квадрат."),
                               ("Введено неверное значение."),
                               QMessageBox::Ok);
                               msgBox.exec();
    }
}
