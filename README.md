# UDT_Service
基于UDT协议开发的文件收发工具，具有UDP的速度和相应的拥塞算法，在要求不精确的场景下可以发送文件
该DLL分为发送端UDT_Sender和接收端UDT_Reciver，请将其放在单独的线程中运行，否则我无法保证是否会卡住主线程
