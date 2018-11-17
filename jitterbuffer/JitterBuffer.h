/**
 * 处理得到的每一个数据包，先将分片进行缓存，
 * 得到完整的帧之后再进行PS数据包的解析
 * 这里采用基本的链表的数据结构，将timeStamp和帧数据以单链表的数据结构进行存储，便于插入
 */
#include "RtpPacket.h"
#include "../H264Packet/H264Packet.h"

/**
 * 缓存节点
 */
class BufferNode{
private:
    unsigned long timeStamp;
    RtpPacket* data;
    BufferNode* next;
public:
    BufferNode();
    BufferNode(unsigned long timeStamp, RtpPacket* data);
    unsigned long getTimeStamp();
    RtpPacket* getData();
    void setTimeStamp(unsigned long timeStamp);
    void setData(RtpPacket* data);
    BufferNode* getNext();
    void setNext(BufferNode* nextNode);
};

class JitterBuffer{
private:
    BufferNode* buffer;

public:
    JitterBuffer();
    H264Packet* pushPacket(RtpPacket rtpPacket);

private:
    void addNode(RtpPacket rtpPacket);
    void deleteNode(BufferNode* preNode);

};
