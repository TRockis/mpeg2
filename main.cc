#include "jitterbuffer/JitterBuffer.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>

using namespace std;

#define PORT 7890           //端口
#define IP "127.0.0.1"      //本机IP
#define MAX_DATA 1600       //接收最大字符长度

int main(int argc, char* argv[]) {
    if(argc != 3){
        cout << "illegal param" << endl;
        return -1;
    }else{
        JitterBuffer jitterBuffer;
        int socket_fd, newfd;   //socket句柄
        struct sockaddr_in destaddr;  //目标地址信息
        char data[MAX_DATA];

        socket_fd = socket(AF_INET, SOCK_STREAM, 0);       //建立socket连接
        if(socket_fd == -1){
            cout << "建立Socket失败: " << errno << endl;
        }

    }
}
