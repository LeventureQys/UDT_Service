#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_UDT.h"

class UDT : public QMainWindow
{
    Q_OBJECT

public:
    UDT(QWidget *parent = nullptr);
    ~UDT();

private:
    Ui::UDTClass ui;
};
