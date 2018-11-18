#include "JitterBuffer.h"

#include <stdio.h>

BufferNode::BufferNode()
{
    this->data = NULL;
    this->timeStamp = 0;
    this->next = NULL;
}

BufferNode::BufferNode(unsigned long timeStamp, unsigned char *data)
{
    this->timeStamp = timeStamp;
    this->data = data;
    this->next = NULL;
}

/**
 * 获取时间戳
 */
unsigned long BufferNode::getTimeStamp()
{
    return this->timeStamp;
}

/**
 * 获取数据指针
 */
unsigned char *BufferNode::getData()
{
    return this->data;
}

/**
 * 获取下一个节点的指针信息
 */
BufferNode *BufferNode::getNext()
{
    return this->next;
}

/**
 * 设置下一个节点
 */
void BufferNode::setNext(BufferNode *nextNode)
{
    this->next = nextNode;
}

bool BufferNode::hasNext()
{
    return this->next != NULL;
}

/**
 * 初始构造一个带头结点的空单链表
 */
JitterBuffer::JitterBuffer()
{
    this->buffer = new BufferNode();
}

void JitterBuffer::addNode(RtpPacket *rtpPacket)
{
    /**
     * 先定位到要插入的节点的前一个节点
     */
    BufferNode *headNode = buffer;
    bool inserted = false;
    while (headNode->hasNext())
    {
        /**
          * 当还有下一个节点的时候
          * 则找到第一个比当前时间戳更大的缓存节点
          */
        if (headNode->getNext()->getTimeStamp() == rtpPacket->getTimeStamp())
        {
            /**
             * 此时时间戳相同，则将其数据部分复制到当前节点的数据部分尾部
             */
            inserted = true;
            break;
        }
        else if (headNode->getNext()->getTimeStamp() > rtpPacket->getTimeStamp())
        {
            /**
             * 此时找到第一个比当前时间戳更大的缓存节点，插入到该节点之前
             */
            doInsert(rtpPacket, headNode);
            inserted = true;
            break;
        }
        headNode = headNode->getNext();
    }
    if (!inserted)
    {
        /**
          * 不存在比待插入的时间戳更大的缓存节点，则将该节点插入到尾部
          * 此时工作指针已经指向了最后一个节点，可以直接插入到工作指针的后面
          */
        doInsert(rtpPacket, headNode);
    }
}

void JitterBuffer::doInsert(RtpPacket* rtpPacket, BufferNode* preNode){
    BufferNode *tmpNode = new BufferNode();
    tmpNode->setTimeStamp(rtpPacket->getTimeStamp());
    tmpNode->setData(rtpPacket->getPayload());
    tmpNode->setNext(preNode->getNext());
    preNode->setNext(tmpNode);
}