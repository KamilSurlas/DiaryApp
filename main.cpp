#include "mainwindow.h"
#include "qdebug.h"
#include <QApplication>
#include "program.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Program glownyProgram;
    MainWindow w(nullptr,&glownyProgram);
    w.show();
    return a.exec();


}

