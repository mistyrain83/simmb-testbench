
#include "ai.h"

#define AI_UART_NAME     "/tyCo/5"
#define AI_UART_BAUDRATE 9600
#define AI_UART_RECV_TIMEOUT 4 // 4s sec ereceive timeout param
#define AI_UART_SEND_TIMEOUT 4 // 4s sec ereceive timeout param

#define AI_FRAME_FOOT  0x55
#define AI_BUFFER_SIZE  128

// open uart
sint32 _tb_AI_Init(void)
{
    sint32 fd;
    fd = open(AI_UART_NAME, O_RDWR, 0);
    
    if (fd == ERROR)
    {
        DBG_ERRO("[AI] %s open failed!", AI_UART_NAME);
        exit(ERROR);
    }
    else
    {
        DBG_INFO("[AI] %s open port successfully", AI_UART_NAME);
    }
    
    ioctl(fd, FIOSETOPTIONS, OPT_RAW);         // 设置串口工作模式
    ioctl(fd, FIOBAUDRATE, AI_UART_BAUDRATE); // 设置串口波特率
    ioctl(fd, FIOFLUSH, 0);                    // 清空输入输出缓冲
    // 设置 8 位数据位，1位停止位，无校验位,忽略MODEM控制信号,启动接收器
    ioctl(fd, SIO_HW_OPTS_SET, CS8 | CLOCAL | CREAD);
    return fd;
}

void _tb_AI_UartTest(sint32 fd)
{
    uint32 i = 0;
    sint32 cycle = 0;
    sint32 recvNum = 0;  // recv data number
    sint32 sendNum = 0;  // send data number
    sint32 rst = 0;
    uint8 aiBuff[AI_BUFFER_SIZE];
    bzero((char *)aiBuff, AI_BUFFER_SIZE);
    DBG_INFO("[AI_UART] ---------BEGIN--------\n");
    
    for (cycle = 0; cycle < 10; cycle++)
    {
        DBG_PRINT("cycle=%d:", cycle);

        for (i = 0; i < AI_BUFFER_SIZE; i++)
        {
            rst = _tb_tread(fd, &aiBuff[i], 1, AI_UART_RECV_TIMEOUT);
            //DBG_INFO("i = %d receive = 0x%x", i, tmsBuff[i]);
            // receive correct footer
            if ((aiBuff[i] == AI_FRAME_FOOT) || (rst == -1))
            {
                recvNum = i;
                break;
            }
        }

        /*
        tmsBuff[0] = 0x55;
		tmsBuff[1] = 0xaa;
		tmsBuff[2] = 0x00;
		tmsBuff[3] = 0xff;
        sendNum = tsendn(fd, (char *)tmsBuff, 4, AI_UART_SEND_TIMEOUT);
            DBG_INFO("[TMS_UART] sendback num = %d", sendNum);
            */

        if (rst != -1)
        {
            // send back frame
            sendNum = _tb_tsendn(fd, (char *)aiBuff, recvNum, AI_UART_SEND_TIMEOUT);
            DBG_INFO("[AI_UART] sendback num = %d", sendNum);
        }
        else
        {
            DBG_INFO("[AI_UART] receive timeout!");
        }

    }
    
    DBG_INFO("[AI_UART] ---------END--------\n");
}


void _tb_AI_Close(sint32 fd)
{
    close(fd);
    DBG_WARN("[AI] %s port closed!", AI_UART_NAME);
}


static void _tb_AI_TurnOnLock(void)
{
    _tb_FPGA_SetBtmTiParam(0x04);
}

static void _tb_AI_TurnOffLock(void)
{
    _tb_FPGA_SetBtmTiParam(0x0);
}

void _tb_AI_LockTest(void)
{
    sint32 cycle = 0;
    DBG_INFO("[AI-LOCK] ---------BEGIN--------\n");
    
    for (cycle = 0; cycle < 10; cycle++)
    {
        DBG_PRINT("cycle=%d:", cycle);
        _tb_AI_TurnOnLock();
        taskDelay(sysClkRateGet());  // delay 1s
        _tb_AI_TurnOffLock();
        taskDelay(sysClkRateGet());
    }
    
    DBG_INFO("[AI-LOCK] ---------END--------\n");
}


