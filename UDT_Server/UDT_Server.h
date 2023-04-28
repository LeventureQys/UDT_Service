#pragma once

//Author:Leveture
//Date: 2023.4.21
//Info:: �˹���ΪUDTЭ���DLL�����DLL�ṩ����Ч�Ļ���UDPЭ����ļ�����Э��
//�˿������������Windows�µ�32λ������
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
//һ�ζ�ȡ�ļ����ֽ���
#define MAX_READ_LEN 1024*200

//һ�η������ݰ�������
#define MAX_TX_PACK_CNT 10
//#define MAX_TX_PACK_CNT 100


//�����͵ļ��ʱ��
#define DELAY_US_TIME 1000

//С�ļ�����
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

    void close(); //�жϲ���

signals:

    void sig_state_file_send(qint64, qint64); //����1:�Ѿ����͵��ֽ��� ����2:���ֽ���

    void sig_send_complete();

    void sig_log(QString);

private:
    QString ip_server = "";
    qint16 port_server = 0;
    QString file_current = "";

    bool run_flag = false;
    bool bln_Init = false;
    qint64 current_total_bytes = 0; //�ļ����ֽ���
    qint64 sended_bytes = 0; //���ֽ���

    qint64 current_ms_time = 0; //��ǰʱ��
    qint64 old_ms_time = 0; //�ϴ�ʱ��

    UDTSOCKET client;
};
