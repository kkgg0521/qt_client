/**
Auth@ lvweikang
Data@ 2023/9/8
**/

#ifndef TP_RECVTHREAD_H
#define TP_RECVTHREAD_H


#include <QThread>
#include "sendQueue.h"
#include "recvQueue.h"

namespace TP {
    /**
     * Description: 接收线程,接收服务器消息的线程
     * Auth:        Strong
     * Data:        2023.9.8
     * **/
    class recvThread : public QThread {

    public:
        explicit recvThread(QObject *parent = nullptr);
        recvThread(QObject *parent, recvQueue *l_sendQueue);

        ~recvThread() override;

    protected:
        [[noreturn]] void run() override;
    private:
        recvQueue *m_recvQueue;

    };
}


#endif //TP_RECVTHREAD_H
