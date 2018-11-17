#include "PSPacket.h"
#include "StreamType.h"
#include "../Utils/StringUtil.h"

#include <stdio.h>

H264Packet* PSPacket::parse(){
    return NULL;
}

PSPacket::PSPacket(){

}

PSPacket::PSPacket(unsigned char* data){
    this->rowData = data;
}
