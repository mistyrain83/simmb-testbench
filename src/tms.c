
#include "tms.h"

#define TMS_UART_NAME     "/tyCo/4"
#define TMS_UART_BAUDRATE 38400
#define TMS_UART_RECV_TIMEOUT 4 // 4s sec ereceive timeout param
#define TMS_UART_SEND_TIMEOUT 4 // 4s sec ereceive timeout param

#define TMS_FRAME_FOOT  0x55
#define TMS_BUFFER_SIZE  128

// open uart
sint32 _tb_TMS_Init(void)
{
    sint32 fd;
    fd = open(TMS_UART_NAME, O_RDWR, 0);
    
    if (fd == ERROR)
    {
        DBG_ERRO("[TMS] %s open failed!", TMS_UART_NAME);
        exit(ERROR);
    }
    else
    {
        DBG_INFO("[TMS] %s open port successfully", TMS_UART_NAME);
    }
    
    ioctl(fd, FIOSETOPTIONS, OPT_RAW);         // 设置串口工作模式
    ioctl(fd, FIOBAUDRATE, TMS_UART_BAUDRATE); // 设置串口波特率
    ioctl(fd, FIOFLUSH, 0);                    // 清空输入输出缓冲
    // 设置 8 位数据位，1位停止位，无校验位,忽略MODEM控制信号,启动接收器
    ioctl(fd, SIO_HW_OPTS_SET, CS8 | CLOCAL | CREAD);
    return fd;
}

void _tb_TMS_UartTest(sint32 fd)
{
    uint32 i = 0;
    sint32 cycle = 0;
    sint32 recvNum = 0;  // recv data number
    sint32 sendNum = 0;  // send data number
    sint32 rst = 0;
    uint8 tmsBuff[TMS_BUFFER_SIZE];
    bzero((char *)tmsBuff, TMS_BUFFER_SIZE);
    DBG_INFO("[TMS_UART] ---------BEGIN--------\n");
    
    for (cycle = 0; cycle < 10; cycle++)
    {
        DBG_PRINT("cycle=%d:", cycle);

        for (i = 0; i < TMS_BUFFER_SIZE; i++)
        {
            rst = _tb_tread(fd, &tmsBuff[i], 1, TMS_UART_RECV_TIMEOUT);
            //DBG_INFO("i = %d receive = 0x%x", i, tmsBuff[i]);
            // receive correct footer
            if ((tmsBuff[i] == TMS_FRAME_FOOT) || (rst == -1))
            {
                recvNum = i;
                break;
            }
            printf("0x%x-", tmsBuff[i]);
        }
        printf("\n");

        /*
        tmsBuff[0] = 0x55;
		tmsBuff[1] = 0xaa;
		tmsBuff[2] = 0x00;
		tmsBuff[3] = 0xff;
        sendNum = _tb_tsendn(fd, (char *)tmsBuff, 4, TMS_UART_SEND_TIMEOUT);
            DBG_INFO("[TMS_UART] sendback num = %d", sendNum);
           */

        if (rst != -1)
        {
            // send back frame
            sendNum = _tb_tsendn(fd, (char *)tmsBuff, recvNum, TMS_UART_SEND_TIMEOUT);
            DBG_INFO("[TMS_UART] sendback num = %d", sendNum);
        }
        else
        {
            DBG_INFO("[TMS_UART] receive timeout!");
        }

    }
    
    DBG_INFO("[TMS_UART] ---------END--------\n");
}


void _tb_TMS_Close(sint32 fd)
{
    close(fd);
    DBG_WARN("[TMS] %s port closed!", TMS_UART_NAME);
}



