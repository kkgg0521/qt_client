/**
Auth@ lvweikang
Data@ 2023/7/22
**/

#include "Client.h"
#include <memory>

TP::Client::Client(QObject *parent) : QObject(parent)
{
    reconnectTimer = new QTimer(this);

    C_sendQueue = new sendQueue();
    C_recvQueue = new recvQueue();

    m_recvThread = new recvThread(this, C_recvQueue);
    m_recvThread->start();
}

TP::Client::~Client()
{
    for (auto &pair: ConnectMap.toStdMap())
    { 
        delete pair.second;
        pair.second = nullptr;
    }
    delete reconnectTimer;
    delete m_recvThread;
    delete C_sendQueue;
    delete C_recvQueue;

}


bool TP::Client::connectServer(const QString &hostName, int Port)
{
    auto *Communicator = new Connection(this); 
    Communicator->socket.connectToHost(hostName, Port); 
    if (Communicator->socket.waitForConnected()) {
        QString serverName = hostName+":"+QString::number(Port);
        ConnectMap.insert(serverName, Communicator); //连接成功，将服务器ip,以及通讯对象填入map
//        connect(Communicator, &Connection::ConnectOFF, this, &Client::handleServerDisconnected); // 连接ServerOFF()信号与处理函数
//        qDebug() << "连接到服务器" << hostName;
        connect(Communicator, &Connection::ReadData, this, &Client::recvOneData); //接收服务器缓存
    }else
    {
        qDebug("connect failed ip address "); //输出失败日志
        emit connectFiled();
        delete Communicator;
        return false;
    }
    return true;
}

void TP::Client::printConnectedHost() //打印连接成功的服务器ip
{
    for(auto &pair: ConnectMap.toStdMap())
        qDebug() << pair.first;
}

void TP::Client::recvOneData(const tprecving &m_replay)
{
    C_recvQueue->push(m_replay);
}

void TP::Client::handleServerDisconnected()
{    
    QObject* senderObject = QObject::sender(); // 获取发送信号的对象

    if (senderObject && senderObject->inherits("Connection"))// 判断是否是Connection类型的对象
    {
        emit disconected();

        // 将senderObject转换为Connection类型的指针
        Connection* connection = qobject_cast<Connection*>(senderObject);

        QString disconnectedIP = ""; // 存储断开连接的服务器IP

        // 在ConnectMap中查找对应的服务器IP
        for (auto it = ConnectMap.begin(); it != ConnectMap.end(); ++it)
        {
            // 如果找到与connection相匹配的Connection对象，则获取对应的IP
            if (it.value() == connection)
            {
                disconnectedIPs.append(it.key());
                disconnectedIP = it.key();
                break;
            }
        }

        if (!disconnectedIP.isEmpty()) // 如果找到了对应的服务器IP
        {
            qDebug() << "服务器" << disconnectedIP << "断开连接";
            reconnectTimer->start(5000); // 例如设置为5秒钟尝试一次重新连接
        }
    }
}

bool TP::Client::sendData(const tpsending& m_sending)
{
    return true;
}

void TP::Client::reconnect()  // 重新连接断开的服务器
{
    for (const QString& ip : disconnectedIPs)
    {
        reconnectMethod(ip);
    }

    if (disconnectedIPs.isEmpty())
    {
        reconnectTimer->stop(); //全部重连成功，再关闭定时器
    }
}

void TP::Client::reconnectMethod(const QString& ip)
{
//    Connection* connection = ConnectMap.value(ip); // 先获取断开连接的Connection对象指针
//    ConnectMap.remove(ip); // 删除断开连接的Connection对象指针
//    delete connection;
//    connection = nullptr;
//
//    auto *lsocket = new Connection(this); // 创建一个新的Connection对象
//    lsocket->socket.connectToHost(ip, port); // 重连服务器
//
//    if (lsocket->socket.waitForConnected(2000))//set 2000超时，避免在连接成功之前发出超时信号
//    {
//        ConnectMap.insert(ip, lsocket);
//        connect(lsocket, &Connection::ConnectOFF, this, &Client::handleServerDisconnected);
//        qDebug() << "重新连接到服务器" << ip;
//        emit reconnected();
//        connect(lsocket, &Connection::ReadData, this, &Client::recvOneData);
//        disconnectedIPs.removeOne(ip); // 从disconnectedIPs中删除重连的IP地址
//    }
//    else
//    {
//        qDebug() << "重新连接服务器" << ip << "失败, 失败原因是 ：" << lsocket->socket.errorString();
//    }
}
