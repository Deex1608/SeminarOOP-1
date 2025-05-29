#include <iostream>
#include <QApplication>

#include "Controller.h"
#include "mainwindow.h"
#include "MediaRepository.h"


int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    MediaRepository mr;
    Controller c(mr);
    MainWindow window(c);
    window.show();
    return app.exec();
}

