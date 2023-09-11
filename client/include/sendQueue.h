/**
Auth@ lvweikang
Data@ 2023/9/7
**/

#ifndef TP_SENDQUEUE_H
#define TP_SENDQUEUE_H

#include "SafeQueue.h"
#include "tpsending.h"

namespace TP {
    /**
     * Description: 送队列的优先级
     *              NOM 普通
     *              URGENT 优先
     * Auth:        Strong
     * Data:        2023.9.7
     * **/
    enum Send_lv_{
        NOM,
        URGENT,
    };
    /**
     * Description: 实现对服务器发送的队列，优先级等级存在两个
     * Auth:        Strong
     * Data:        2023.9.7
     * **/
    class sendQueue {
    public:
        sendQueue();

        virtual ~sendQueue();

    public:
        /**
        * Description: 实现区分优先级加入队列
        * Auth:        Strong
        * Data:        2023.9.7
        * **/
        [[maybe_unused]] void push(const tpsending& m_tpsending, Send_lv_ lv);
        /**
        * Description: 实现区分优先级出列
        * Auth:        Strong
        * Data:        2023.9.7
        * **/
        tpsending pop();
        /**
        * Description: 判断容器中是否存在指令
        * Auth:        Strong
        * Data:        2023.9.7
        * **/
        bool isEmpty();

    private:
        SafeQueue<tpsending> NOMQue;
        SafeQueue<tpsending> URGENTQue;
    };
}


#endif //TP_SENDQUEUE_H
