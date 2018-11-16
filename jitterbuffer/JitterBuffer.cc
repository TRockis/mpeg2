#include "JitterBuffer.h"

#include <stdio.h>

BufferNode::BufferNode(){
    this->data = NULL;
    this->timeStamp = 0;
    this->next = NULL;
}

BufferNode::BufferNode(unsigned long timeStamp, RtpPacket* data){
    this->timeStamp = timeStamp;
    this->data = data;
    this->next = NULL;
}

/**
 * 获取时间戳
 */
unsigned long BufferNode::getTimeStamp(){
    return this->timeStamp;
}

/**
 * 获取数据指针
 */
RtpPacket* BufferNode::getData(){
    return this->data;
}

/**
 * 获取下一个节点的指针信息
 */
BufferNode* BufferNode::getNext(){
    return this->next;
}

/**
 * 设置下一个节点
 */
void BufferNode::setNext(BufferNode* nextNode){
    this->next = nextNode;
}

/**
 * 初始构造一个带头结点的空单链表
 */
JitterBuffer::JitterBuffer(){
    this->buffer = new BufferNode();
}

void JitterBuffer::addNode(RtpPacket rtpPacket){
    /**
     * 先定位到要插入的节点的前一个节点
     */
    
}