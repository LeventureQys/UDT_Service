#pragma once

#include "udt_reciver_global.h"
#include <QReadWriteLock>
#include <QQueue>
#include <QFile>
#include <QDir>
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
#include <QNetworkDatagram>
#include "qsharedpointer.h"
#ifndef WIN32
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <netdb.h>
#else
#include <winsock2.h>
#include <ws2tcpip.h>
#include <wspiapi.h>
#endif
#include <iostream>

#include "udt_src/udt.h"

//����������ŵ�����
#define QUEUE_DATA_CNT 1024*1024

class UDT_RECIVER_EXPORT UDT_Reciver:public QObject
{
    Q_OBJECT
public:
    UDT_Reciver();
    ~UDT_Reciver();

public slots:
    void LogSend(QString text);
    void Listen(QString ip, qint32 port, QString save_path); //����
    void close_file();
signals:
    void sig_log(QString);
    void sig_file_recv_rate(QString,qint64,qint64,double);
    void sig_complete(double);
private:
    bool bln_listen = false;
    bool bln_recv = false; //�Ƿ����ڽ���

    UDTSOCKET serv;

    QSharedPointer<QFile> recv_file_p;
    QSharedPointer<QTimer> update_time;

    qint64 rec_cnt = 0; // ���յ��ֽ�����
    qint64 recv_file_size = 0; // �����ļ����ܴ�С
    QString recv_file_name; //�����ļ�������

    qint64 current_ms_time = 0; //��ǰʱ��
    qint64 old_ms_time = 0; //�ϴ�ʱ��
    qint64 rx_byte = 0; // ��������ٶ�


    double speed_ms_sec = 10.0; //�ٶ�;
};


class StringDataQueue
{
private:
    QReadWriteLock lock; //��д��
    QQueue<QString> queue; //�������ݵĶ���
public:
    StringDataQueue()
    {
        queue.clear();
    }

    //����������һ������
    void write_queue(QString data)
    {
        lock.lockForWrite();
        queue.enqueue(data);
        if (queue.size() > QUEUE_DATA_CNT) //��󻺴�����
        {
            queue.clear();
        }
        lock.unlock();
    }

    //���ض������һ������
    QString read_queue()
    {
        QString data = "";
        lock.lockForWrite();
        //�ж϶����Ƿ�Ϊ��,�����ݲ�ȡ
        if (queue.isEmpty() == false)
        {
            data = queue.dequeue();
        }
        lock.unlock();
        return data;
    }

    //���ض�����ʣ�����������
    int get_queue1_cnt()
    {
        int data = -1;
        lock.lockForWrite();
        data = queue.count();
        lock.unlock();
        return data;
    }

    //��������������
    int clear_queue()
    {
        int data = -1;
        lock.lockForWrite();
        queue.clear();
        lock.unlock();
        return data;
    }
};
extern class StringDataQueue log_queue;