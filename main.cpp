/**
Auth@ lvweikang
Data@ 2023/9/7
**/
#include <iostream>
#include "Client.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TP::Client m_client;
    m_client.connectServer("127.0.0.1", 8080);
    m_client.connectServer("127.0.0.1", 8888);
    return a.exec();
}
