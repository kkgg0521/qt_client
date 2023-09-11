/**
Auth@ lvweikang
Data@ 2023/9/7
**/

#include "tprecving.h"

#include <utility>

TP::tprecving::tprecving() = default;

TP::tprecving::~tprecving() = default;

bool TP::tprecving::loadFromQByteArray(const QByteArray &data) {
    return false;
}

TP::tprecving::tprecving(QString server)
:serverMark(std::move(server)){
}

QString TP::tprecving::getServerMark() {
    return serverMark;
}
