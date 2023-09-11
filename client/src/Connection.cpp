/**
Auth@
Data@ 2023/8/2
**/
#include "Connection.h"

TP::Connection::Connection(QObject *parent) : QObject(parent), socket(this)
{

    connect(&socket, &QTcpSocket::readyRead, this, &Connection::slotReadyRead);
    connect(&socket, &QTcpSocket::errorOccurred, this, &Connection::onSocketError);
}

void TP::Connection::slotReadyRead()
{
    QString serverMark = socket.localAddress().toString()+":" + QString::number(socket.peerPort());
    tprecving mreplay(serverMark);
    QByteArray data = socket.readAll();
    mreplay.loadFromQByteArray(data);
    emit ReadData(mreplay);
}

void TP::Connection::onDisconnected()
{
    qDebug("Client disconnect");

    emit ClientOFF();
}

void TP::Connection::onSocketError(QAbstractSocket::SocketError socketError)
{
    emit ConnectOFF();

    switch (socketError)
    {
        case QAbstractSocket::ConnectionRefusedError:
            qDebug() << "连接被拒绝";
            break;
        case QAbstractSocket::RemoteHostClosedError:
            qDebug() << "远程主机关闭连接";
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

bool TP::Connection::SendData(tpsending send_sending)
{
    int ret = socket.write(send_sending.getSendingByte()); //发送指令
    if (ret > 0) {
        return true;
    }
    return false;
}

TP::Connection::~Connection()
{
    socket.disconnect();
    socket.close();
    std::cout << "~Connection" << std::endl;
}


