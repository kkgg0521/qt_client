/**
Auth@ lvweikang
Data@ 2023/9/7
**/

#ifndef TOPS_TPSENDING_H
#define TOPS_TPSENDING_H

#include <QString>

namespace TP {
    /**
     * Description: 界面发发送数据包的基本类型
     * Auth:        Strong
     * Data:        2023.9.7
     * **/
    class tpsending {

    public:
        tpsending();

        ~tpsending();

    public:
        /**
       * Description: 获取发送数据包为一个hex
       * Auth:        Strong
       * Data:        2023.9.8
       * Input:       viod
       * Ouput:       返回这个数组
       * **/
        QByteArray getSendingByte();

    private:
        /** 该包通讯的服务器ip **/
        QString ip;
        /** 该包的数据的字节长度 **/
        int size{};
        /** 发送数据包的帧头 **/
        QByteArray hearder;


    };
}


#endif //TOPS_TPSENDING_H
