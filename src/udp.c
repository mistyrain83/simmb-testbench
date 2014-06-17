
#include "udp.h"


#define UDP_RECV_BUF_LEN     128 // single packet buf max length

uint8 udpBuff[UDP_RECV_BUF_LEN];

sint32 sockServerAddrLen;
struct sockaddr_in sockServerAddr;

/***********************************************************************
 * function:NetInit()
 * brief:网口初始化，两个IP地址网段要不同
 *
 ***********************************************************************/
void _tb_UDP_NetInit(void)
{
    //ipAttach (0, "mottsec");
    //ifconfig ("mottsec0 192.168.4.110 up");
    ipAttach (1, "mottsec");
    ifconfig ("mottsec1 192.168.5.126 up");
}

/***********************************************************************
 * function: UDP_InitRecvSock()
 * brief:UDP初始化，建立socket recv socket is udp server.
 *
 ***********************************************************************/
sint32 _tb_UDP_InitRecvSock(void)
{
    STATUS rst = ERROR;
    sint32 recvFd;
    sint32 sockSelfAddrLen;
    struct sockaddr_in sockSelfAddr;
    // self addr
    sockSelfAddrLen = sizeof(sockSelfAddr);
    bzero((char *)&sockSelfAddr, sockSelfAddrLen);
    //sockSelfAddr.sin_len = (u_char)sockSelfAddrLen;
    sockSelfAddr.sin_family = AF_INET;
    sockSelfAddr.sin_port = htons(UDP_SELF_PORT);
    sockSelfAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    recvFd = socket(AF_INET, SOCK_DGRAM, 0);
    
    if (recvFd == ERROR)
    {
        DBG_ERRO_0("[UDP] Can not create UDP recv socket");
        close(recvFd);
        return ERROR;
    }
    
    // bind socket to local address
    rst = bind(recvFd, (struct sockaddr *)&sockSelfAddr, sockSelfAddrLen);
    
    if (rst == ERROR)
    {
        DBG_ERRO_0("[UDP] bind recv socket error");
        close(recvFd);
        return ERROR;
    }
    
    return recvFd;
}

sint32 _tb_UDP_InitSendSock(void)
{
    sint32 sendFd;
    sendFd = socket(AF_INET, SOCK_DGRAM, 0);
    
    if (sendFd < 0)
    {
        DBG_ERRO_0("[UDP] Can not create UDP send socket");
        close(sendFd);
        return ERROR;
    }
    
    // server addr
    sockServerAddrLen = sizeof(sockServerAddr);
    bzero((char *)&sockServerAddr, sockServerAddrLen);
    //sockServerAddr.sin_len = (u_char)sockServerAddrLen;
    sockServerAddr.sin_family = AF_INET;
    sockServerAddr.sin_port = htons(UDP_SERVER_PORT);
    sockServerAddr.sin_addr.s_addr = inet_addr(UDP_SERVER_IP);
    //    rst = connect(sendFd, (struct sockaddr *)&sockServerAddr, sockServerAddrLen);
    //
    //    if (rst == ERROR)
    //    {
    //        DBG_ERRO_0("[UDP] connect send socket error");
    //        close(sendFd);
    //        return ERROR;
    //    }
    return sendFd;
}

/***********************************************************************
 * function:UDP_ReadData()
 * brief:UDP接收函数
 *
 ***********************************************************************/
sint32 _tb_UDP_ReadData(sint32 fd)
{
    sint32 len = 0;
    //sint32 sockRecvServerAddrLen;
    //struct sockaddr_in sockRecvServerAddr;
    // receive block
    //len = recvfrom(fd, (char *)udpRecvBuf, UDP_RECV_BUF_LEN, 0, (struct sockaddr *)&sockRecvServerAddr, &sockRecvServerAddrLen);
    len = recv(fd, (char *)udpBuff, UDP_RECV_BUF_LEN, 0);
    
    if (len == ERROR)
    {
        DBG_ERRO("[UDP] socket recv error!");
    }
    
    return len;
}

/***********************************************************************
 * function:UDP_WriteData()
 * brief:UDP发送函数
 *
 ***********************************************************************/
sint32 _tb_UDP_WriteData(int fd, int num)
{
    sint32 len;
    len = sendto(fd, (char *)udpBuff, num, 0, (struct sockaddr *)&sockServerAddr, sockServerAddrLen);
    //len = send(fd, (char *)udpSendBuf, UDP_SEND_BUF_LEN, 0);
    
    if (len == ERROR)
    {
        DBG_ERRO_0("[UDP] write socket error\n");
    }
    
    return len;
}

void _tb_UDP_Test(void)
{
    sint32 cycle = 0;
    sint32 recvFd;
    sint32 sendFd;
    sint32 recvNum;
    sint32 sendNum;
    DBG_INFO("[UDP] ---------BEGIN--------\n");
    recvFd = _tb_UDP_InitRecvSock();
    sendFd = _tb_UDP_InitSendSock();
    bzero((char *)udpBuff, UDP_RECV_BUF_LEN);
    
    for (cycle = 0; cycle < 10; cycle++)
    {
        DBG_PRINT("cycle=%d:", cycle);
        recvNum = _tb_UDP_ReadData(recvFd);
        
        if (recvNum > 1)
        {
            sendNum = _tb_UDP_WriteData(sendFd, recvNum);
            DBG_INFO("send num = %d", sendNum);
        }
    }
    
    DBG_INFO("[UDP] ---------END--------\n");
}


