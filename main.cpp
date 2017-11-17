#include "mainwindow.h"
#include <QApplication>

#include "subjectapple.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
