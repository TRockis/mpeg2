/**
 * RTP数据包格式定义
 */

class RtpPacket{

private:
    unsigned char* rowData;         //原始数据

    /**
     * 版本号，占2位，当前版本号为2
     */
    int version;

    /**
     * 填充标志，占1位，如果该位为1，
     * 则报文尾部填充一个或多个额外的八位组
     * 并不是有效荷载的一部分
     */
    bool padding;

    /**
     * 扩展标志，若为1，则在RTP报文后跟有一个扩展报头
     */
    bool extention;

    /**
     * CSRC计数器，占4位，表明CSRC标识符的个数
     */
    int csrcCount;

    /**
     * 标记，占一位，对于视频，标记一帧的结束；对于音频，标记会话的开始
     */
    bool mark;

    /**
     * 有效何在类型，占7位，主要是用来区分音频流和视频流的，便于客户端进行解析
     */
    int payloadType;

    /**
     * 序列号，占16位，用于标识发送者所发送的RTP报文的序列号
     */
    unsigned int sequence;

    /**
     * 时间戳，占32位，必须使用90kHZ时钟频率
     */
    unsigned long timeStamp;

    /**
     * 同步鑫源标识符，占32位，用于标识同步信源，
     * 参加同一视频会议的两个同步信源不能有相同的SSRC
     */
    unsigned long SSRC;

    /**
     * 特约信源标识符，占32位，可以有0~15个，故用指针存储
     */
    unsigned long* CSRC;

    /**
     * RTP包含的数据部分
     */
    unsigned char* payload;

public:
    RtpPacket(unsigned char* data);
    ~RtpPacket();

    /**
     * 对传入的数据进行解析，得到结构化后的RTP数据包
     */
    void parse();

    unsigned char* getRowData();
    int getVersion();
    bool getPadding();
    bool getExtention();
    int getCsrcCount();
    bool getMark();
    int getPayloadType();
    unsigned int getSequence();
    unsigned long getTimeStamp();
    unsigned long getSSRC();
    unsigned long getCSRC();
    unsigned char* getPayload();

};
