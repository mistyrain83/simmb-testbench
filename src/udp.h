#ifndef _UDP_H
#define _UDP_H
#include "lib.h"

#define UDP_SERVER_PORT 11000
#define UDP_SERVER_IP   "192.168.5.130"

#define UDP_SELF_PORT   11001
#define UDP_SELF_IP     "192.168.5.126"


void _tb_UDP_NetInit(void);
sint32 _tb_UDP_InitRecvSock(void);
sint32 _tb_UDP_InitSendSock(void);
sint32 _tb_UDP_ReadData(sint32 fd);
sint32 _tb_UDP_WriteData(int fd, int num);

void _tb_UDP_Test(void);

#endif // _UDP_H
