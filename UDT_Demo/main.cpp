#include "UDT_Demo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UDT_Demo w;
    w.show();
    return a.exec();
}
