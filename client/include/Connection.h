/**
Auth@ SongWenke
Data@ 2023/8
**/

#ifndef CLIENT_CONNECTION_H
#define CLIENT_CONNECTION_H

#include <iostream>
#include "QTcpSocket"
#include <QAbstractSocket>
#include "tpsending.h"
#include "tprecving.h"

namespace TP {
    /**
     * Description: 客户端建立链接的基本类型，包括对一个服务器的发送和接受
     * Auth:        Strong
     * Data:        2023.9.7
     * **/
    class Connection : public QObject {
    Q_OBJECT
    public:
        explicit Connection(QObject *parent);

        ~Connection() override;

    public slots:
        /**
        * Description: 向服务器发送一个数据包
        * Auth:        Strong
        * Data:        2023.9.8
        * Input:       一个数据包
        * Ouput:       是否发送成功
        * **/
        bool SendData(tpsending send_sending);

    signals:
        /**
        * Description: 接收到服务器的一个数据包,转化为tprecving数据包
        * Auth:        Strong
        * Data:        2023.9.8
        * Input:       一个数据包
        * Ouput:       是否发送成功
        * **/
        void ReadData(tprecving recv_replay);

        void ClientOFF();
        /**
        * Description: 服务器链接发生异常
        * Auth:        Strong
        * Data:        2023.9.11
        * Input:
        * Ouput:       服务器异常状态
        * **/
        void ConnectOFF(QAbstractSocket::SocketError socketError, QString this_serverMark);

    private slots:

        void slotReadyRead();

        void onDisconnected();

        void onSocketError(QAbstractSocket::SocketError socketError);


    public:
        QTcpSocket socket;

    };
}
#endif //CLIENT_CONNECTION_H
