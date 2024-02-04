#include "welcomewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    WelcomeWindow w;
    w.setWindowTitle("Tongji Hospital Calling System");
    w.show();
    return a.exec();
}
