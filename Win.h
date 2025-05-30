#ifndef WIN_H
#define WIN_H
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QtGui>
class Counter:public QLineEdit
{
    Q_OBJECT
public:
    Counter(const QString & contents, QWidget *parent=0): QLineEdit(contents,parent){}//конструктор
signals:
    void tick_signal();//сигнал каждые 5 по счету
public slots:
    void add_one()
    {
        QString str=text();//текущее значение поля
        int r=str.toInt();//преобразование в число
        if (r!=0 && r%5 ==0) emit tick_signal();
        r++;
        str.setNum(r);//в строку
        setText(str);//новое значение в поле
    }
};
class Win: public QWidget
{
    Q_OBJECT
protected:
    QTextCodec *codec;
    QLabel *label1,*label2;//метки
    Counter *edit1,*edit2;//счетчики
    QPushButton *calcbutton;//+1
    QPushButton *exitbutton;//выход
public:
    Win(QWidget *parent = 0);//конструктор окна
};
#endif

