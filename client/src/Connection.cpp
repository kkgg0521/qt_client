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

//    emit ClientOFF();
}

void TP::Connection::onSocketError(QAbstractSocket::SocketError socketError)
{
    QString serverMark = socket.localAddress().toString()+":" + QString::number(socket.peerPort());
    emit ConnectOFF(socketError, serverMark);
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


