#include "Dificulties_Window.h"
#include <QApplication>

Dificulties_Window *window;



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    window = new Dificulties_Window();
    window->show();
    return a.exec();
}
