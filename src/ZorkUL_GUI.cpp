#include <QApplication>
#include "MainWindow.h"
#include <QLabel>
#include <QPushButton>
#include<QDebug>

using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}

