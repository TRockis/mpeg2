#include "StringUtil.h"

/**
 * 获取字符串的长度
 */
int StringUtil::getLength(unsigned char* data){
    int ret = 0;
    char ch = data[0];
    while(ch != '\0'){
        ch = data[++ret];
    }
    return ret;
}

/**
 * 字符串转整型
 */
int StringUtil::stringToInt(unsigned char* data, int start, int end){
    int ret = 0;
    return ret;
}

/**
 * 字符转布尔类型
 */
bool StringUtil::stringToBool(unsigned char* data, int start){
    return true;
}

unsigned int StringUtil::stringToUint(unsigned char* data, int start, int end){
    return 0;
}

unsigned long StringUtil::stringToUlong(unsigned char* data, int start, int end){
    unsigned long ret = 0;
    return ret;
}
/**
 * 深拷贝
 */
unsigned char* StringUtil::deepCopy(unsigned char* data){
    int dataLength = StringUtil::getLength(data);
    unsigned char* ret = new unsigned char[dataLength];
    for(int i = 0; i < dataLength; ++i){
        ret[i] = data[i];
    }

    ret[dataLength] = '\0';
    return ret;
}

/**
 *
 */
unsigned char* StringUtil::connect(unsigned char* sourceString, unsigned char* appendex){
  int sourceLength = StringUtil.getLength(sourceString);
  int appendexLength = StringUtil.getLength(appendex);

  for(int i = 0; i < appendexLength; ++i){
    sourceString[sourceLength + i] = appendex[i];
  }

  sourceString[sourceLength + appendexLength] = '\0';
}
