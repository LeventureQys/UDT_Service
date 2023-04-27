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
    //该操作会侵入sendfile的执行过程中，关闭线程
}

//void UDT_Sender::sig_state_file_send(qint64, qint64)
//{
//}
//
//void UDT_Sender::sig_send_complete()
//{
//}
//
//void UDT_Sender::sig_log(QString)
//{
//}

void UDT_Sender::send_file(QString file)
{
    QFile SrcFile(file);//发送文件
    qint64 time1 = 0;
    qint64 time2 = 0;
    qint64 send_len = 0;
    //判断端口号
    if (this->port_server <= 0)
    {
        //emit this->sig_log("没有填写端口号.暂停发送.\n");
        return;
    }

    //判断IP地址
    if (this->ip_server.isEmpty())
    {
        //emit this->sig_log("没有填写IP地址.暂停发送.\n");
        return;
    }
    //打开文件
    
    if (!SrcFile.open(QIODevice::ReadOnly))
    {
     //emit   this->sig_log(QString("%1 文件打开失败.停止发送.\n").arg(file));
        return;
    }

    //得到文件大小信息
    this->current_total_bytes = SrcFile.size();


    //emit this->sig_log(QString("UDT文件发送开始\n"));
    struct addrinfo hints, * local, * peer;
    memset(&hints, 0, sizeof(struct addrinfo));

    hints.ai_flags = AI_PASSIVE;
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (0 != getaddrinfo(nullptr, "9000", &hints, &local))
    {
        //emit this->sig_log("非法端口号或端口正忙.\n");
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

    // 连接到服务器，隐式绑定
    if (UDT::ERROR == UDT::connect(client, peer->ai_addr, peer->ai_addrlen))
    {
        //emit this->sig_log("连接到服务器，隐式绑定. ERROR\n");
        //qDebug()<< "connect: " << UDT::getlasterror().getErrorMessage() << endl;
        return;
    }

    freeaddrinfo(peer);
    int ssize = 0;
    int ss;

    QString str;
    QFileInfo send_file_info(file);
    str = QString("image#%1#%2").arg(send_file_info.fileName()).arg(send_file_info.size());
    //emit this->sig_log(str + "\n");

    qDebug() << "str.toStdString().c_str():" << str.toStdString().c_str() << ",len:" << str.size();

    if (UDT::ERROR == (ss = UDT::send(client, str.toStdString().c_str(), strlen(str.toStdString().c_str()), 0)))
    {
        // qDebug() << "send_error:" << UDT::getlasterror().getErrorMessage() << endl;
        //emit this->sig_log("send_error\n");
        return;
    }

    //设置运行状态
    run_flag = true;

    //emit this->sig_log(QString("准备发送%1文件.目的地:%2:%3\n").arg(file).arg(this->ip_server).arg(this->port_server));
    //获取系统当前时间
    time1 = QDateTime::currentMSecsSinceEpoch();

    //开始发送
    while (run_flag) {
        QByteArray byte;

        byte = SrcFile.read(MAX_READ_LEN);

        if (UDT::ERROR == (send_len = UDT::send(client, byte.data(), byte.size(), 0)))
        {
            //emit this->sig_log("send_error....\n");
            break;
        }
        //记录发送的长度
       this->sended_bytes += send_len;

        //获取本地时间
        current_ms_time = QDateTime::currentMSecsSinceEpoch();

        //时间经过了1s
        if (current_ms_time - old_ms_time > 1000)
        {
            old_ms_time = current_ms_time;

            //更新状态
            //emit this->sig_state_file_send(this->sended_bytes, this->current_ms_time);
            //ss_FileSendState(Send_TotalBytes, File_TotalBytes);
        }

        if (this->sended_bytes >= this->current_total_bytes || (byte.size() < MAX_READ_LEN))
        {
            break;
        }

        QThread::msleep(1);
    }

    UDT::close(client);

    time2 = QDateTime::currentMSecsSinceEpoch();

    time1 = time2 - time1; // 消耗的时间

    //emit this->sig_state_file_send(this->sended_bytes, this->current_ms_time); //更新状态

    //emit this->sig_log(QString("UDT文件发送完成，总大小:%1 Bytes,耗时:%2 \n").arg(QTime(0, 0, 0, 0).addMSecs(int(time1)).toString(QString::fromLatin1("HH:mm:ss:zzz"))));

    this->sended_bytes = 0;
    this->current_total_bytes = 0;

    SrcFile.close();

    emit this->sig_send_complete(); 

   emit this->sig_log("发送完毕，允许退出线程");

}
