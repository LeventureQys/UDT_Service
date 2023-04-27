#pragma once

//Author:Leveture
//Date: 2023.4.21
//Info:: 此工程为UDT协议的DLL，这个DLL提供更高效的基于UDP协议的文件传输协议
//此库仅可以适用于Windows下的32位程序中
#include "udt_server_global.h"
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QTimer>
#include <QDateTime>
#include <QThread>
#include <QUdpSocket>
#include <QFile>
#include <QEventLoop>
#ifndef WIN32
#include <cstdlib>
#include <netdb.h>
#else
#include <winsock2.h>
#include <ws2tcpip.h>
#endif
#include <fstream>
#include <iostream>
#include <cstring>
#include "udt_src/udt.h"
//一次读取文件的字节数
#define MAX_READ_LEN 1024*200

//一次发送数据包的数量
#define MAX_TX_PACK_CNT 10
//#define MAX_TX_PACK_CNT 100


//包发送的间隔时间
#define DELAY_US_TIME 1000

//小文件限制
#define MIN_FILE_SIZE 1024*1024
class UDT_SERVER_EXPORT UDT_Sender:public QObject
{
    Q_OBJECT
public:
    UDT_Sender();
    ~UDT_Sender(){}

    void init_server(QString ip, qint16 port);
public slots:
    void send_file(QString file);
    void close(); //中断操作

//Q_SIGNALS:
signals:

    void sig_state_file_send(qint64, qint64); //参数1:已经发送的字节数 参数2:总字节数
    void sig_send_complete();
    void sig_log(QString);

private:
    QString ip_server = "";
    qint16 port_server = 0;
    QString file_current = "";

    bool run_flag = false;
    bool bln_Init = false;
    qint64 current_total_bytes = 0; //文件总字节数
    qint64 sended_bytes = 0; //总字节数

    qint64 current_ms_time = 0; //当前时间
    qint64 old_ms_time = 0; //上次时间

    UDTSOCKET client;
};
