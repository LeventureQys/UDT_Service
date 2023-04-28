#include "UDT_Demo.h"

UDT_Demo::UDT_Demo(QWidget *parent)
    : QMainWindow(parent){
    ui.setupUi(this);
    
}

UDT_Demo::~UDT_Demo(){
    
}

void UDT_Demo::on_btn_sender_check_clicked(){

    QString fileName = QFileDialog::getOpenFileName(this, "ѡ�����ļ�", "./", "ALL(*.*)");

    if (!fileName.isEmpty()) {
        this->ui.line_sender->setText(fileName);
    }
    else {
        this->em_sender("�����ļ�·��Ϊ��");
        return;
    }

    QFile file(fileName);
    if (!file.exists()) {
        this->em_sender("�����ļ�������");
        return;
   }



}

void UDT_Demo::on_btn_sender_send_clicked(){
    if (this->ui.line_sender->text().isEmpty()) {
        this->em_sender("�����뷢���ļ���");
        return;
    }
    QString fileName = this->ui.line_sender->text();
    QFile file(fileName);
    if (!file.exists()) {
        this->em_sender("������ļ�ʵ���ϲ����ڣ�");
        return;
    }
    
    this->ptr_sender.data()->send_file(fileName);
    this->em_sender("���������ļ�����");
}

void UDT_Demo::on_btn_rec_init_clicked(){

}

void UDT_Demo::on_btn_rec_location_clicked(){

}

void UDT_Demo::on_btn_rec_listen_clicked(){

}

void UDT_Demo::em_sender(QString Insert)
{
    this->ui.text_sender->appendPlainText(Insert);
}

void UDT_Demo::em_rec(QString Insert)
{
    this->ui.text_rec->appendPlainText(Insert);
}

void UDT_Demo::on_btn_sender_init_clicked() {
    if (this->ptr_sender.isNull()) {
        this->ptr_sender = QSharedPointer<UDT_Sender>(new UDT_Sender());
    }

    if (this->ui.line_ip->text().isEmpty() || this->ui.line_port->text().isEmpty()) {
        this->em_sender("����ȷ����IP�Ͷ˿�");
        return;
    }
    QString sender_ip = this->ui.line_ip->text();
    quint16 sender_port = this->ui.line_port->text().toUShort();

    connect(this->ptr_sender.data(), &UDT_Sender::sig_log, [=](QString Insert) {
        em_sender(Insert);
        });

    connect(this->ptr_sender.data(), &UDT_Sender::sig_send_complete, [=]() {
        em_sender("�������");
        });

    connect(this->ptr_sender.data(), &UDT_Sender::sig_state_file_send, [=](qint64 sended_rate, qint64 total_rate) {
        em_sender(QString("%1 / %2").arg(sended_rate).arg(total_rate));
        });


    this->ptr_sender.data()->init_server(sender_ip, sender_port);

}