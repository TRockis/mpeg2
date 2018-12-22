/*
 * PS数据包格式
 */

#include "PSHead.h"
#include "PESHead.h"
#include "../H264Packet/H264Packet.h"

class PSPacket {
public:
    static const int startCode = 0x000001BA;  //开始标识符
    static const int endCode = 0x000001B9;    //结束标识符
private:
    PSHead psHead;          //PS头
    PESHead videoPesHead;   //视频的PES头部分
    PESHead audioPesHead;   //音频的PES头部分
    unsigned char* h264Data;         //H264数据部分
    unsigned char* rowData;           //原始数据
    bool isEnd;           //判断是否为结束的帧

public:
    H264Packet* parse();        //用于解析一个PS数据包，返回一个H264数据包
    PSPacket();
    PSPacket(unsigned char* data);       //将一帧数据转换为一个PS数据包
};
