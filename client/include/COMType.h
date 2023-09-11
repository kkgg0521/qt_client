#ifndef COMTYPE_H
#define COMTYPE_H

//保存通讯协议

namespace Protocals
{
    enum ComType //模块
    {
        HEART = 0,
        AXIS = 1,
        CollectCard = 3,
        Board = 2,
    };

    enum Ctrl : short //Axis动作
    {
        INIT = 1,
        EN = 3,
        BackToZero = 9,
        m_move = 0x0A,
        speed = 0x0B,
        Fwd = 0x0C,
        Rev = 0x0D,
        Stop = 0x0E,
        Read = 0xAA,
        Write = 0xBB,
        Start = 0xFF,
        AutoStack = 18,
        WoPosSwitch = 15,
        ROTATESYNC = 16,
        Placed = 17,
        RunThread = 99
    };

    enum BoardAction  //Board动作
    {
        BoardStart = 1,
        BoardStop = 0,
        BoardOutside = 2,
        BoardInside = 3,
        RP = 4,
        PW = 5,
        EV = 6,
        DB = 7,
        BoardINIT = 8
    };

    enum CollectAction //Card动作
    {
        CollectClose = -1,
        CollectInit = 0,
        CollectStart = 1,
        CollectStop = 2,
        CollectFrec = 3,
        CollectDelay = 4,
        CollectURange = 5,
        CollectOffset = 6, //补偿
        CollectOH = 7,
        Collect_TRIG_MODE = 8,
        CARD_AVAILABLE = 9,
        CARD_calibrated = 10
    };

    enum OperationObject //Axis对象
    {
        PUSH = 0x01,
        FEED = 0x02,
        CLAMP = 0x03,
        ROTATE = 0x04,
        DIVIDE = 0x05,
        All = 0x01,
        AllAxis = 0
    };

    enum ERRORCODE  //错误码
    {
        NA = 0,
        FAIED = 1,
        NOINIT = 2,
        NOFUNC = 10,

        FEEDLIMIT = 20,
        DIVIDELIMIT = 21,
    };

};


#endif // COMTYPE_H
