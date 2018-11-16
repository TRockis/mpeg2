#include "PSPacket.h"
#include "StreamType.h"
#include "../Utils/StringUtil.h"

#include <stdio.h>

H264Packet* PSPacket::parse(){
    return NULL;
}

H264Packet::H264Packet(){

}

H264Packet::H264Packet(unsigned char* data){
    this->rowData = data;
}