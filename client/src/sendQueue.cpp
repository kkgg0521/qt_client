/**
Auth@ lvweikang
Data@ 2023/9/7
**/

#include "sendQueue.h"

TP::sendQueue::sendQueue() = default;

TP::sendQueue::~sendQueue() = default;

[[maybe_unused]] void TP::sendQueue::push(const TP::tpsending& m_tpsending, TP::Send_lv_ lv = TP::Send_lv_::NOM) {
    switch (lv) {
        case NOM:
            NOMQue.push(m_tpsending);
            break;
        case URGENT:
            URGENTQue.push(m_tpsending);
            break;
    }
}

TP::tpsending TP::sendQueue::pop() {
    if (URGENTQue.isEmpty()) {
        return NOMQue.pop();
    }
    return URGENTQue.pop();
}

bool TP::sendQueue::isEmpty() {
    return URGENTQue.isEmpty() || NOMQue.isEmpty();
}
