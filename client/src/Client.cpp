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
    m_sendThread = new sendThread(this, C_sendQueue);
    m_sendThread->start();

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
    delete m_sendThread;
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
        connect(Communicator, &Connection::ReadData, this, &Client::recvOneData);

        connect(Communicator, &Connection::ConnectOFF, this, &Client::serverDisconnected);

    }else
    {
        delete Communicator;
        return false;
    }
    return true;
}

void TP::Client::recvOneData(const tprecving &m_replay)
{
    C_recvQueue->push(m_replay);
}

void TP::Client::serverDisconnected(QAbstractSocket::SocketError socketError, QString this_serverMark)
{

    switch (socketError)
    {
        case QAbstractSocket::ConnectionRefusedError:
            qDebug() << "连接被拒绝";
            break;
        case QAbstractSocket::RemoteHostClosedError:
            // todo:这里指针释放存在报错奔溃，尚未查找奔溃的原因
            //delete ConnectMap[this_serverMark];
            ConnectMap.remove(this_serverMark);
            break;
        case QAbstractSocket::HostNotFoundError:
            qDebug() << "找不到主机";
            break;
        case QAbstractSocket::SocketTimeoutError:
            qDebug() << "连接超时";
            break;
        case QAbstractSocket::NetworkError:
            qDebug() << "网络错误";
            break;
            // 其他错误类型的处理
        default:
            qDebug() << "发生了其他错误";
            break;
    }
}

bool TP::Client::sendData(tpsending m_sending)
{
    if (ConnectMap.contains(m_sending.getServerMark()))
    {
        return ConnectMap[m_sending.getServerMark()]->SendData(m_sending);

    }
    return false;
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
