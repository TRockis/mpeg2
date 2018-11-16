#include "RtpPacket.h"
#include "../Utils/StringUtil.h"
/**
 * 构造函数
 */
RtpPacket::RtpPacket(unsigned char* packetData){
    this->rowData = packetData;
    this->parse();

}

/**
 * 进行解析
 */
void RtpPacket::parse(){
    int start = 0;
    int length = StringUtil::getLength(rowData);
    this->version = StringUtil::stringToInt(rowData, start, start+2);
    //指针后移两位
    start = start + 2;

    this->padding = StringUtil::stringToBool(rowData, start);
    //指针后移一位
    start++;

    this->extention = StringUtil::stringToBool(rowData, start);
    //指针后移一位
    start++;

    this->csrcCount = StringUtil::stringToInt(rowData, start, start + 4);
    //指针后移四位
    start = start + 4;

    this->mark = StringUtil::stringToBool(rowData, start);
    //指针后移一位
    start++;

    this->payloadType = StringUtil::stringToInt(rowData, start, start + 7);
    //指针后移7位
    start += 7;

    this->sequence = StringUtil::stringToUint(rowData, start, start + 16);
    //指针后移16位
    start += 16;

    this->timeStamp = StringUtil::stringToUlong(rowData, start, start + 32);
    //指针后移32位
    start += 32;

    this->SSRC = StringUtil::stringToUlong(rowData, start, start + 32);
    //指针后移32位
    start += 32;

    this->CSRC = new unsigned long[csrcCount];
    for(int i = 0; i < csrcCount; ++i){
        this->CSRC[i] = StringUtil::stringToUlong(rowData, start, start + 32);
        start += 32;
    }

    this->payload = rowData + start;
}

