#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_UDT_Demo.h"

class UDT_Demo : public QMainWindow
{
    Q_OBJECT

public:
    UDT_Demo(QWidget *parent = nullptr);
    ~UDT_Demo();

private:
    Ui::UDT_DemoClass ui;
};
