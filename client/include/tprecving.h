/**
Auth@ lvweikang
Data@ 2023/9/7
**/

#ifndef TP_TPRECVING_H
#define TP_TPRECVING_H

#include <QByteArray>
#include <QString>

namespace TP {
    /**
    * Description: 界面接收数据包的基本类型
    * Auth:        Strong
    * Data:        2023.9.7
    * **/
    class tprecving {
    public:
        tprecving();
        tprecving(QString server);
        ~tprecving();
    public:
        /**
        * Description: 将接收的缓冲数据转换成一个接收数据包
        * Auth:        Strong
        * Data:        2023.9.8
        * Input:       接收到的数据数组
        * Ouput:       返回是否变化成功
        * **/
        bool loadFromQByteArray(const QByteArray& data);

        /**
        * Description: 获取接收到的主机标识
        * Auth:        Strong
        * Data:        2023.9.8
        * Input:       void
        * Ouput:       主机标识
        * **/
        QString getServerMark();

    private:
        /** 接收到的服务器标记由“ip:port”构成**/
        QString serverMark;

    };
}

#endif //TP_TPRECVING_H
