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

//队列里最大存放的数据
#define QUEUE_DATA_CNT 1024*1024

class UDT_RECIVER_EXPORT UDT_Reciver:public QObject
{
    Q_OBJECT
public:
    UDT_Reciver();
    ~UDT_Reciver();

public slots:
    void LogSend(QString text);
    void Listen(QString ip, qint32 port, QString save_path); //监听
    void close_file();
signals:
    void sig_log(QString);
    void sig_file_recv_rate(QString,qint64,qint64,double);
    void sig_complete(double);
private:
    bool bln_listen = false;
    bool bln_recv = false; //是否正在接收

    UDTSOCKET serv;

    QSharedPointer<QFile> recv_file_p;
    QSharedPointer<QTimer> update_time;

    qint64 rec_cnt = 0; // 接收的字节数量
    qint64 recv_file_size = 0; // 接收文件的总大小
    QString recv_file_name; //接收文件的名称

    qint64 current_ms_time = 0; //当前时间
    qint64 old_ms_time = 0; //上次时间
    qint64 rx_byte = 0; // 计算接受速度


    double speed_ms_sec = 10.0; //速度;
};


class StringDataQueue
{
private:
    QReadWriteLock lock; //读写锁
    QQueue<QString> queue; //缓存数据的队列
public:
    StringDataQueue()
    {
        queue.clear();
    }

    //向队列里插入一条数据
    void write_queue(QString data)
    {
        lock.lockForWrite();
        queue.enqueue(data);
        if (queue.size() > QUEUE_DATA_CNT) //最大缓存数据
        {
            queue.clear();
        }
        lock.unlock();
    }

    //返回队列里的一条数据
    QString read_queue()
    {
        QString data = "";
        lock.lockForWrite();
        //判断队列是否为空,有数据才取
        if (queue.isEmpty() == false)
        {
            data = queue.dequeue();
        }
        lock.unlock();
        return data;
    }

    //返回队列里剩余的数据数量
    int get_queue1_cnt()
    {
        int data = -1;
        lock.lockForWrite();
        data = queue.count();
        lock.unlock();
        return data;
    }

    //清除队列里的数据
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