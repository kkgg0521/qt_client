/**
Auth@ lvweikang
Data@ 2023/9/7
**/

#include "tpsending.h"

TP::tpsending::tpsending() = default;

TP::tpsending::~tpsending() = default;

QByteArray TP::tpsending::getSendingByte() {
    return {0X55, static_cast<char>(0Xaa)};
}
