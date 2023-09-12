/**
Auth@
Data@ 2023/7/22
**/

#ifndef CLIENT_CLIENT_H
#define CLIENT_CLIENT_H

#include <QTcpSocket>
#include "QTimer"
#include "Connection.h"
#include "sendQueue.h"
#include "recvQueue.h"
#include "recvThread.h"
#include "sendThread.h"

namespace TP {
    /**
    * Description: 界面使用的客户端与服务器通讯的
    * Auth:        Strong
    * Data:        2023.9.8
    * **/
    class Client : public QObject {
    Q_OBJECT
    public:
        explicit Client(QObject *parent = nullptr);

        ~Client() override;
    public:
        /**
        * Description: 链接一个服务器使用的方法，链接成功的服务器链接存放到一个map中
        * Auth:        Strong
        * Data:        2023.9.8
        * Input:       服务器链接ip服务器链接端口
        * Ouput:       服务器是否链接成功
        * **/
        bool connectServer(const QString &hostName, int port);

        void reconnectMethod(const QString &ip);
    public slots:
        /**
        * Description: 向服务端发送一个数据包
        * Auth:        Strong
        * Data:        2023.9.8
        * **/
        bool sendData(tpsending m_sending);
        /**
        * Description: 从服务器接收到一个数据包传递到客户端中
        * Auth:        Strong
        * Data:        2023.9.8
        * **/
        void recvOneData(const tprecving &m_replay);
        /**
        * Description: 服务端断开链接的信号，发送一个断开链接的标志
        * Auth:        Strong
        * Data:        2023.9.11
        * **/
        void serverDisconnected(QAbstractSocket::SocketError socketError ,QString this_serverMark); //获取断开服务器的ip

    signals:
        void connectFiled();
    private:
        /** 所有链接的服务器 MAP **/
        QMap<QString, Connection *> ConnectMap;
        QTimer *reconnectTimer;
        QList<QString> disconnectedIPs; //存储连接中断的服务器

        recvThread *m_recvThread;
        sendThread *m_sendThread;
        sendQueue *C_sendQueue;
        recvQueue *C_recvQueue;

    };
}

#endif //CLIENT_CLIENT_H
