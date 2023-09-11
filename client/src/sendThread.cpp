/**
Auth@ lvweikang
Data@ 2023/9/11
**/

#include "sendThread.h"

TP::sendThread::sendThread(QObject *parent) : QThread(parent) {}

TP::sendThread::~sendThread() {
    QThread::terminate();
}

[[noreturn]] void TP::sendThread::run() {
    while (true) {
        if (m_sendQueue->isEmpty()) {
            sleep(1);
            continue;
        }
        auto this_recv = m_sendQueue->pop();
    }
}

TP::sendThread::sendThread(QObject *parent, TP::sendQueue *l_sendQueue)
: QThread(parent) {
    m_sendQueue = l_sendQueue;
}
