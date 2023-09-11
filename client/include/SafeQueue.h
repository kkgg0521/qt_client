/**
Auth@ lvweikang
Data@ 2023/9/7
**/

#ifndef TP_SAFEQUEUE_H
#define TP_SAFEQUEUE_H

#include <QMutex>
#include <QQueue>

namespace TP {
    /**
     * Description: 线程安全的 QQueue
     * Auth:        Strong
     * Data:        2023.9.7
     * **/
    template<class T>
    class SafeQueue {
    public:
        T pop();

        void push(T value);

        bool isEmpty();

    private:
        QMutex m_mutex;
        QQueue<T> m_Queue;
    };

    template<class T>
    bool SafeQueue<T>::isEmpty() {
        QMutexLocker locker(&m_mutex);
        return m_Queue.isEmpty();
    }

    template<class T>
    void SafeQueue<T>::push(T value) {
        QMutexLocker locker(&m_mutex);
        m_Queue.enqueue(value);
    }

    template<class T>
    T SafeQueue<T>::pop() {
        QMutexLocker locker(&m_mutex);
        return m_Queue.dequeue();
    }
}

#endif //TP_SAFEQUEUE_H
