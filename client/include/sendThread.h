/**
Auth@ lvweikang
Data@ 2023/9/11
**/

#ifndef TP_SENDTHREAD_H
#define TP_SENDTHREAD_H


#include <QThread>
#include "sendQueue.h"

namespace TP {
    /**
     * Description: 客户端消息发送线程,存在一个消息队列
     * Auth:        Strong
     * Data:        2023.9.11
     * **/
    class sendThread : public QThread {
    public:
        explicit sendThread(QObject *parent);

        sendThread(QObject *parent, sendQueue *l_sendQueue);

        ~sendThread() override;
    protected:
        [[noreturn]] void run() override;
    private:
        sendQueue *m_sendQueue;

    };
}


#endif //TP_SENDTHREAD_H
