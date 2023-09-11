/**
Auth@ lvweikang
Data@ 2023/9/7
**/

#include "recvQueue.h"

TP::recvQueue::recvQueue() = default;

TP::recvQueue::~recvQueue() = default;

void TP::recvQueue::push(const TP::tprecving &m_tpsending) {
    RECVQue.push(m_tpsending);
}

TP::tprecving TP::recvQueue::pop() {
    return RECVQue.pop();
}

bool TP::recvQueue::isEmpty() {
    return RECVQue.isEmpty();
}
