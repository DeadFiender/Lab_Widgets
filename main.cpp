#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //some changes in this file
    MainWindow w;
    w.show();
    return a.exec();
}
//comment 
