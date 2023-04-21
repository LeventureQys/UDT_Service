#include "UDT.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UDT w;
    w.show();
    return a.exec();
}
