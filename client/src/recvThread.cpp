/**
Auth@ lvweikang
Data@ 2023/9/8
**/

#include "recvThread.h"

[[maybe_unused]] TP::recvThread::recvThread(QObject *parent) : QThread(parent) {

}

TP::recvThread::~recvThread() {
    QThread::terminate();
}

[[noreturn]] void TP::recvThread::run() {
    while (true) {
        if (m_recvQueue->isEmpty()) {
            sleep(1);
        }
    }
}

TP::recvThread::recvThread(QObject *parent, TP::recvQueue *l_sendQueue)
        : QThread(parent) {
    m_recvQueue = l_sendQueue;
}
