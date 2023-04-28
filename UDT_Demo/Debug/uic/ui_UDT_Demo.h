/********************************************************************************
** Form generated from reading UI file 'UDT_Demo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UDT_DEMO_H
#define UI_UDT_DEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UDT_DemoClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UDT_DemoClass)
    {
        if (UDT_DemoClass->objectName().isEmpty())
            UDT_DemoClass->setObjectName(QString::fromUtf8("UDT_DemoClass"));
        UDT_DemoClass->resize(600, 400);
        menuBar = new QMenuBar(UDT_DemoClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        UDT_DemoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(UDT_DemoClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        UDT_DemoClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(UDT_DemoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        UDT_DemoClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(UDT_DemoClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        UDT_DemoClass->setStatusBar(statusBar);

        retranslateUi(UDT_DemoClass);

        QMetaObject::connectSlotsByName(UDT_DemoClass);
    } // setupUi

    void retranslateUi(QMainWindow *UDT_DemoClass)
    {
        UDT_DemoClass->setWindowTitle(QCoreApplication::translate("UDT_DemoClass", "UDT_Demo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UDT_DemoClass: public Ui_UDT_DemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDT_DEMO_H
