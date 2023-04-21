/********************************************************************************
** Form generated from reading UI file 'UDT.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UDT_H
#define UI_UDT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UDTClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UDTClass)
    {
        if (UDTClass->objectName().isEmpty())
            UDTClass->setObjectName(QString::fromUtf8("UDTClass"));
        UDTClass->resize(600, 400);
        menuBar = new QMenuBar(UDTClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        UDTClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(UDTClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        UDTClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(UDTClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        UDTClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(UDTClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        UDTClass->setStatusBar(statusBar);

        retranslateUi(UDTClass);

        QMetaObject::connectSlotsByName(UDTClass);
    } // setupUi

    void retranslateUi(QMainWindow *UDTClass)
    {
        UDTClass->setWindowTitle(QCoreApplication::translate("UDTClass", "UDT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UDTClass: public Ui_UDTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDT_H
