#include "UDT_Server.h"

#ifndef WIN32
void* sendfile(void*);
#else
DWORD WINAPI sendfile(LPVOID);
DWORD WINAPI monitor(LPVOID s);
#endif
UDT_Sender::UDT_Sender()
{
	UDT::startup();
}

void UDT_Sender::init_server(QString ip, qint16 port)
{
	this->ip_server = ip;
	this->port_server = port;
    this->bln_Init = true;
}

void UDT_Sender::close()
{
    this->run_flag = false;
    //�ò���������sendfile��ִ�й����У��ر��߳�
}

void UDT_Sender::send_file(QString file)
{
    QFile SrcFile(file);//�����ļ�
    qint64 time1 = 0;
    qint64 time2 = 0;
    qint64 send_len = 0;
    //�ж϶˿ں�
    if (this->port_server <= 0)
    {
        emit this->sig_log("û����д�˿ں�.��ͣ����.\n");
        return;
    }

    //�ж�IP��ַ
    if (this->ip_server.isEmpty())
    {
        emit this->sig_log("û����дIP��ַ.��ͣ����.\n");
        return;
    }
    //���ļ�
    
    if (!SrcFile.open(QIODevice::ReadOnly))
    {
     emit   this->sig_log(QString("%1 �ļ���ʧ��.ֹͣ����.\n").arg(file));
        return;
    }

    //�õ��ļ���С��Ϣ
    this->current_total_bytes = SrcFile.size();


    emit this->sig_log(QString("UDT�ļ����Ϳ�ʼ\n"));
    struct addrinfo hints, * local, * peer;
    memset(&hints, 0, sizeof(struct addrinfo));

    hints.ai_flags = AI_PASSIVE;
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (0 != getaddrinfo(nullptr, "9000", &hints, &local))
    {
        //emit this->sig_log("�Ƿ��˿ںŻ�˿���æ.\n");
        return;
    }

    client = UDT::socket(local->ai_family, local->ai_socktype, local->ai_protocol);

#ifdef WIN32
    UDT::setsockopt(client, 0, UDT_MSS, new int(1052), sizeof(int));
#endif
    freeaddrinfo(local);

    if (0 != getaddrinfo(QString("%1").arg(this->ip_server).toStdString().c_str(), QString("%1").arg(this->port_server).toStdString().c_str(), &hints, &peer))
    {
        qDebug() << "incorrect Sender/peer address. " << this->ip_server << ":" << this->port_server << endl;
        return;
    }

    // ���ӵ�����������ʽ��
    if (UDT::ERROR == UDT::connect(client, peer->ai_addr, peer->ai_addrlen))
    {
        emit this->sig_log("���ӵ�����������ʽ��. ERROR\n");
        qDebug()<< "connect: " << UDT::getlasterror().getErrorMessage() << endl;
        return;
    }

    freeaddrinfo(peer);
    int ssize = 0;
    int ss;

    QString str;
    QFileInfo send_file_info(file);
    str = QString("image#%1#%2").arg(send_file_info.fileName()).arg(send_file_info.size());
    emit this->sig_log(str + "\n");

    qDebug() << "str.toStdString().c_str():" << str.toStdString().c_str() << ",len:" << str.size();

    if (UDT::ERROR == (ss = UDT::send(client, str.toStdString().c_str(), strlen(str.toStdString().c_str()), 0)))
    {
         qDebug() << "send_error:" << UDT::getlasterror().getErrorMessage() << endl;
        emit this->sig_log("send_error\n");
        return;
    }

    //��������״̬
    run_flag = true;

    emit this->sig_log(QString("׼������%1�ļ�.Ŀ�ĵ�:%2:%3\n").arg(file).arg(this->ip_server).arg(this->port_server));
    //��ȡϵͳ��ǰʱ��
    time1 = QDateTime::currentMSecsSinceEpoch();

    //��ʼ����
    while (run_flag) {
        QByteArray byte;

        byte = SrcFile.read(MAX_READ_LEN);

        if (UDT::ERROR == (send_len = UDT::send(client, byte.data(), byte.size(), 0)))
        {
            emit this->sig_log("send_error....\n");
            break;
        }
        //��¼���͵ĳ���
       this->sended_bytes += send_len;

        //��ȡ����ʱ��
        current_ms_time = QDateTime::currentMSecsSinceEpoch();

        //ʱ�侭����1s
        if (current_ms_time - old_ms_time > 1000)
        {
            old_ms_time = current_ms_time;

            //����״̬
            emit this->sig_state_file_send(this->sended_bytes, this->current_ms_time);
        }

        if (this->sended_bytes >= this->current_total_bytes || (byte.size() < MAX_READ_LEN))
        {
            break;
        }

        QThread::msleep(1);
    }

    UDT::close(client);

    time2 = QDateTime::currentMSecsSinceEpoch();

    time1 = time2 - time1; // ���ĵ�ʱ��

    emit this->sig_state_file_send(this->sended_bytes, this->current_ms_time); //����״̬

    emit this->sig_log(QString("UDT�ļ�������ɣ��ܴ�С:%1 Bytes,��ʱ:%2 \n").arg(QTime(0, 0, 0, 0).addMSecs(int(time1)).toString(QString::fromLatin1("HH:mm:ss:zzz"))));

    this->sended_bytes = 0;
    this->current_total_bytes = 0;

    SrcFile.close();

    emit this->sig_send_complete(); 

   emit this->sig_log("������ϣ������˳��߳�");

}
