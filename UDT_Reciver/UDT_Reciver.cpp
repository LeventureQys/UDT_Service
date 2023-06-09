#include "UDT_Reciver.h"
QString recv_file_path = "";
class StringDataQueue log_queue;
UDT_Reciver::UDT_Reciver()
{
}

UDT_Reciver::~UDT_Reciver()
{
}
#ifndef WIN32
void* recvdata(void* usocket)
#else

DWORD WINAPI recvdata(LPVOID usocket)
#endif
{
    UDTSOCKET recver = *(UDTSOCKET*)usocket;
    delete (UDTSOCKET*)usocket;

    unsigned char* data;
    int size = 1024 * 1024;
    int rs = 0;
    data = new unsigned char[size];
    qint64 file_len = 0;

    int rcv_size;
    int var_size = sizeof(int);
    UDT::getsockopt(recver, 0, UDT_RCVDATA, &rcv_size, &var_size);
    qDebug() << "rcv_size:" << rcv_size;

    if (UDT::ERROR == (rs = UDT::recv(recver, (char*)data, 1024, 0)))
    {
        qDebug() << "文件头接收失败:" << UDT::getlasterror().getErrorMessage() << endl;
        return 0;
    }

    qDebug() << "rs:" << rs;

    qint64 rx_byte = 0;
    qint64 s_file_size = 0;
    QString s_file_name;
    std::string std_str_data = (char*)data;
    QString Rx_str_data = QString("%1").fromStdString(std_str_data);
    qDebug() << "接收的原始第一包数据:" << Rx_str_data;

    int addr = Rx_str_data.indexOf(QByteArray("image#"));

    QFile* recv_file_p = nullptr;
    if (addr != -1) //查找成功
    {
        QString str_size = Rx_str_data.section('#', 2, 2); //取出图片字节大小字符串
        s_file_name = QString("%1/%2").arg(recv_file_path).arg(Rx_str_data.section('#', 1, 1));
        s_file_size = str_size.toLongLong();   //得到图片字节大小

        //创建文件
        recv_file_p = new QFile(s_file_name);
        if (recv_file_p->open(QIODevice::ReadWrite) == true)
        {
            log_queue.write_queue(QString("%1 文件创建成功.\n").arg(s_file_name));
        }
        else
        {
            recv_file_p = nullptr;
            log_queue.write_queue(QString("%1 文件创建失败.\n").arg(s_file_name));
        }

        log_queue.write_queue(QString("收到新文件:%1:%2\n").arg(s_file_name).arg(s_file_size));
    }

    qint64 current_ms_time = 0, old_ms_time = 0;
    double speed_M_SEC = 0.0;

    while (true)
    {
        int rcv_size;
        int var_size = sizeof(int);
        UDT::getsockopt(recver, 0, UDT_RCVDATA, &rcv_size, &var_size);
        if (UDT::ERROR == (rs = UDT::recv(recver, (char*)data, size, 0)))
        {
            qDebug() << "recv:" << UDT::getlasterror().getErrorMessage() << endl;
            log_queue.write_queue("客户端断开连接...");
            break;
        }

        file_len += rs;

        //qDebug()<<"接收数据:"<<data;

        //获取本地时间
        current_ms_time = QDateTime::currentMSecsSinceEpoch();

        // qDebug()<<"ID:"<<recver<<",接收长度:"<<file_len<<",Time:"<<current_ms_time;

        if (current_ms_time - old_ms_time > 1000)
        {
            old_ms_time = current_ms_time;

            //计算速度
            speed_M_SEC = (file_len - rx_byte) / 1024 / 1024.0;
            //如果小于0，表示文件1秒内就传输完毕了
            if (speed_M_SEC < 1.0)speed_M_SEC = s_file_size / 1024.0 / 1024.0;
            log_queue.write_queue(QString("%1 M/s").arg(speed_M_SEC));
            rx_byte = file_len;
        }

        //存储数据到文件
        if (recv_file_p)
        {
            //存储数据到文件
            recv_file_p->write((char*)data, rs);

            //接收完毕
            if (file_len >= s_file_size)
            {
                //qDebug()<<"ID:"<<recver<<",接收长度:"<<file_len<<",Time:"<<current_ms_time;
                //qDebug()<<"接收完毕...";
                log_queue.write_queue(QString("接收完毕:%1:%2:%3\n").arg(s_file_name).arg(s_file_size).arg(file_len));
                break;
            }
        }
        else
        {
            break;
        }
    }

    recv_file_p->close();
    delete recv_file_p;
    recv_file_p = nullptr;

    log_queue.write_queue(QString("线程退出:%1:%2:%3\n").arg(s_file_name).arg(s_file_size).arg(file_len));

    delete[] data;

    UDT::close(recver);

#ifndef WIN32
    return NULL;
#else
    return 0;
#endif
}

void UDT_Reciver::LogSend(QString text) {
	if (text.isEmpty()) {
		qDebug() << "--->LogSend: text is empty";
		return;
	}
};

void UDT_Reciver::Listen(QString ip, qint32 port, QString save_path)
{
    if (ip.isEmpty()) {
        LogSend("Listen - ip is empty");
        return;
    }
    if (port <= 0) {
        LogSend("Listen - port error");
        return;
    }

    if (save_path.isEmpty()) {
        LogSend("Listen - save_path is empty");
        return;
    }
	recv_file_path = save_path;

	addrinfo hints;
	addrinfo* res;

	memset(&hints, 0, sizeof(struct addrinfo));

	hints.ai_flags = AI_PASSIVE;
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;

	if (0 != getaddrinfo(nullptr, QString("%1").arg(port).toStdString().c_str(), &hints, &res))
	{
		qDebug() << "illegal port number or port is busy.\n" << endl;
		return;
	}

	if (UDT::ERROR == UDT::bind(serv, res->ai_addr, res->ai_addrlen))
	{
		qDebug() << "bind: " << UDT::getlasterror().getErrorMessage() << endl;
		return;
	}

	freeaddrinfo(res);

	if (UDT::ERROR == UDT::listen(serv, 10))
	{
		qDebug() << "listen: " << UDT::getlasterror().getErrorMessage() << endl;
		return;
	}
    this->bln_listen = true;
	sockaddr_storage clientaddr;
	int addrlen = sizeof(clientaddr);

	UDTSOCKET recver;
	while (this->bln_listen)  //循环等待数据
	{
		if (UDT::INVALID_SOCK == (recver = UDT::accept(serv, (sockaddr*)&clientaddr, &addrlen)))
		{
			LogSend("服务器已停止监听....\n");
            this->bln_listen = false;
			return;
		}

		char clienthost[NI_MAXHOST];
		char clientservice[NI_MAXSERV];
		getnameinfo((sockaddr*)&clientaddr, addrlen, clienthost, sizeof(clienthost), clientservice, sizeof(clientservice), NI_NUMERICHOST | NI_NUMERICSERV);
		qDebug() << "new connection: " << clienthost << ":" << clientservice << endl;

#ifndef WIN32
		pthread_t_udt rcvthread;
		pthread_create(&rcvthread, NULL, recvdata, new UDTSOCKET(recver));
		pthread_detach(rcvthread);
#else
		LogSend("新的文件已到达,创建新的线程开始接收....\n");
		CreateThread(nullptr, 0, recvdata, new UDTSOCKET(recver), 0, nullptr);
#endif
	}
}

void UDT_Reciver::close_file()
{
    this->bln_listen = false;
}
