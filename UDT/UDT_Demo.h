#pragma once
#pragma execution_character_set("utf-8") 
#include <QtWidgets/QMainWindow>
#include "ui_UDT.h"
#include "../UDT_Reciver/UDT_Reciver.h"
#include "../UDT_Server/UDT_Server.h"
#include "qsharedpointer.h"
#include "qfiledialog.h"

class UDT_Demo : public QMainWindow
{
    Q_OBJECT

public:

    UDT_Demo(QWidget *parent = nullptr);
    ~UDT_Demo();
private slots:

    void on_btn_sender_init_clicked();
    void on_btn_sender_check_clicked();
    void on_btn_sender_send_clicked();

    void on_btn_rec_init_clicked();
    void on_btn_rec_location_clicked();
    void on_btn_rec_listen_clicked();

private:

    Ui::UDTClass ui;

    QSharedPointer<UDT_Sender> ptr_sender;
    QSharedPointer<UDT_Reciver> ptr_rec;
    QSharedPointer<QThread> ptr_thread;

    void em_sender(QString Insert);
    void em_rec(QString Insert);
};
