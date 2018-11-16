/**
 * 与字符串有关的操作
 */

class StringUtil{
public:
    static int getLength(unsigned char* data);
    static int stringToInt(unsigned char* data, int start, int end);
    static unsigned int stringToUint(unsigned char* data, int start, int end);
    static long stringToLong(unsigned char* data, int start, int end);
    static unsigned long stringToUlong(unsigned char* data, int start, int end);
    static bool stringToBool(unsigned char* data, int index);
};