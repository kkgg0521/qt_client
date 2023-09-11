/**
Auth@ lvweikang
Data@ 2023/9/7
**/

#ifndef TP_RECVQUEUE_H
#define TP_RECVQUEUE_H

#include "tprecving.h"
#include "SafeQueue.h"

namespace TP {
    /**
     * Description: S端回复或主动推送到C端的数据包
     * Auth:        Strong
     * Data:        2023.9.7
     * **/
    class recvQueue {
    public:
        recvQueue();

        virtual ~recvQueue();
    public:
        /**
      * Description: 加入解析队列
      * Auth:        Strong
      * Data:        2023.9.8
      * **/
        [[maybe_unused]] void push(const tprecving& m_tpsending);
        /**
        * Description: 实现区分优先级出列
        * Auth:        Strong
        * Data:        2023.9.8
        * **/
        tprecving pop();
        /**
        * Description: 判断容器中是否存在指令
        * Auth:        Strong
        * Data:        2023.9.8
        * **/
        bool isEmpty();

    private:
        SafeQueue<tprecving> RECVQue;
    };
}


#endif //TP_RECVQUEUE_H
