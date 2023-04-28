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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UDTClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *btn_sender_init;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *line_sender;
    QPushButton *btn_sender_check;
    QPushButton *btn_sender_send;
    QLabel *label_2;
    QPlainTextEdit *text_sender;
    QLineEdit *line_send_ip;
    QLineEdit *line_send_port;
    QWidget *tab_2;
    QPlainTextEdit *text_rec;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *line_ip;
    QLineEdit *line_port;
    QLabel *label_3;
    QPushButton *btn_rec_init;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *line_rec_location;
    QPushButton *btn_rec_location;
    QPushButton *btn_rec_listen;

    void setupUi(QMainWindow *UDTClass)
    {
        if (UDTClass->objectName().isEmpty())
            UDTClass->setObjectName(QString::fromUtf8("UDTClass"));
        UDTClass->resize(519, 351);
        centralWidget = new QWidget(UDTClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        btn_sender_init = new QPushButton(tab);
        btn_sender_init->setObjectName(QString::fromUtf8("btn_sender_init"));

        horizontalLayout->addWidget(btn_sender_init);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        line_sender = new QLineEdit(tab);
        line_sender->setObjectName(QString::fromUtf8("line_sender"));

        horizontalLayout_2->addWidget(line_sender);

        btn_sender_check = new QPushButton(tab);
        btn_sender_check->setObjectName(QString::fromUtf8("btn_sender_check"));

        horizontalLayout_2->addWidget(btn_sender_check);

        btn_sender_send = new QPushButton(tab);
        btn_sender_send->setObjectName(QString::fromUtf8("btn_sender_send"));

        horizontalLayout_2->addWidget(btn_sender_send);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        text_sender = new QPlainTextEdit(tab);
        text_sender->setObjectName(QString::fromUtf8("text_sender"));

        gridLayout->addWidget(text_sender, 4, 0, 1, 1);

        line_send_ip = new QLineEdit(tab);
        line_send_ip->setObjectName(QString::fromUtf8("line_send_ip"));

        gridLayout->addWidget(line_send_ip, 0, 0, 1, 1);

        line_send_port = new QLineEdit(tab);
        line_send_port->setObjectName(QString::fromUtf8("line_send_port"));

        gridLayout->addWidget(line_send_port, 0, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        text_rec = new QPlainTextEdit(tab_2);
        text_rec->setObjectName(QString::fromUtf8("text_rec"));
        text_rec->setGeometry(QRect(20, 90, 451, 211));
        layoutWidget = new QWidget(tab_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 457, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        line_ip = new QLineEdit(layoutWidget);
        line_ip->setObjectName(QString::fromUtf8("line_ip"));

        horizontalLayout_3->addWidget(line_ip);

        line_port = new QLineEdit(layoutWidget);
        line_port->setObjectName(QString::fromUtf8("line_port"));

        horizontalLayout_3->addWidget(line_port);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        btn_rec_init = new QPushButton(layoutWidget);
        btn_rec_init->setObjectName(QString::fromUtf8("btn_rec_init"));

        horizontalLayout_3->addWidget(btn_rec_init);

        layoutWidget1 = new QWidget(tab_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 60, 451, 25));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        line_rec_location = new QLineEdit(layoutWidget1);
        line_rec_location->setObjectName(QString::fromUtf8("line_rec_location"));

        horizontalLayout_4->addWidget(line_rec_location);

        btn_rec_location = new QPushButton(layoutWidget1);
        btn_rec_location->setObjectName(QString::fromUtf8("btn_rec_location"));

        horizontalLayout_4->addWidget(btn_rec_location);

        btn_rec_listen = new QPushButton(layoutWidget1);
        btn_rec_listen->setObjectName(QString::fromUtf8("btn_rec_listen"));

        horizontalLayout_4->addWidget(btn_rec_listen);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        UDTClass->setCentralWidget(centralWidget);

        retranslateUi(UDTClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(UDTClass);
    } // setupUi

    void retranslateUi(QMainWindow *UDTClass)
    {
        UDTClass->setWindowTitle(QCoreApplication::translate("UDTClass", "UDT", nullptr));
        label->setText(QCoreApplication::translate("UDTClass", "\345\210\235\345\247\213\345\214\226\346\234\215\345\212\241\345\231\250:", nullptr));
        btn_sender_init->setText(QCoreApplication::translate("UDTClass", "\345\210\235\345\247\213\345\214\226", nullptr));
        line_sender->setText(QString());
        btn_sender_check->setText(QCoreApplication::translate("UDTClass", "\346\265\217\350\247\210", nullptr));
        btn_sender_send->setText(QCoreApplication::translate("UDTClass", "\345\217\221\351\200\201", nullptr));
        label_2->setText(QCoreApplication::translate("UDTClass", "\351\200\211\346\213\251\346\226\207\344\273\266\345\217\221\351\200\201", nullptr));
        line_send_ip->setText(QCoreApplication::translate("UDTClass", "127.0.0.1", nullptr));
        line_send_port->setText(QCoreApplication::translate("UDTClass", "8450", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("UDTClass", "\345\217\221\351\200\201\347\253\257", nullptr));
        label_3->setText(QCoreApplication::translate("UDTClass", "\345\210\235\345\247\213\345\214\226\346\234\215\345\212\241\345\231\250\350\277\236\346\216\245", nullptr));
        btn_rec_init->setText(QCoreApplication::translate("UDTClass", "\345\210\235\345\247\213\345\214\226", nullptr));
        label_4->setText(QCoreApplication::translate("UDTClass", "\351\200\211\346\213\251\350\276\223\345\207\272\344\275\215\347\275\256", nullptr));
        btn_rec_location->setText(QCoreApplication::translate("UDTClass", "\347\241\256\345\256\232", nullptr));
        btn_rec_listen->setText(QCoreApplication::translate("UDTClass", "\347\233\221\345\220\254\346\226\207\344\273\266", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("UDTClass", "\346\216\245\346\224\266\347\253\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UDTClass: public Ui_UDTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDT_H
