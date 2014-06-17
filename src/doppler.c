
#include "fpga.h"
#include "doppler.h"

#define DOP_UART_NAME    "/tyCo/1"
#define DOP_UART_BAUDRATE 19200

#define DOP_BUFF_SIZE 32
#define DOP_UART_SEND_TIMEOUT 4

sint32 _tb_DOP_Init(void)
{
    sint32 fd;
    fd = open(DOP_UART_NAME, O_RDWR, 0);
    
    if (fd == ERROR)
    {
        DBG_ERRO("[doppler] %s open failed!\n", DOP_UART_NAME);
        exit(ERROR);
    }
    else
    {
        DBG_INFO("[doppler] %s open port successfully\n", DOP_UART_NAME);
    }
    
    ioctl(fd, FIOSETOPTIONS, OPT_RAW);
    ioctl(fd, FIOBAUDRATE, DOP_UART_BAUDRATE);
    ioctl(fd, FIOFLUSH, 0);
    // 设置 8 位数据位，1位停止位，无校验位,忽略MODEM控制信号,启动接收器
    ioctl(fd, SIO_HW_OPTS_SET, CS8 | CLOCAL | CREAD);
    DBG_INFO("[doppler] %s config port successfully.\n", DOP_UART_NAME);
    return fd;
}


void _tb_DOP_UartTest(sint32 fd)
{
    sint32 cycle = 0;
    sint32 sendNum = 0;
    uint8 dopBuff[DOP_BUFF_SIZE];
    sint32 i;
    
    // init buff
    for (i = 0; i < DOP_BUFF_SIZE; i++)
    {
        dopBuff[i] = i;
    }
    
    DBG_INFO("[DOP_UART] ---------BEGIN--------\n");
    
    for (cycle = 0; cycle < 10; cycle++)
    {
        DBG_PRINT("cycle=%d:", cycle);
        sendNum = _tb_tsendn(fd, (char *)dopBuff, DOP_BUFF_SIZE, DOP_UART_SEND_TIMEOUT);
        DBG_INFO("send num = %d", sendNum);
        taskDelay(sysClkRateGet());
    }
    
    DBG_INFO("[DOP_UART] ---------END--------\n");
}

void _tb_Dop_PWMInit(void)
{
    _tb_FPGA_EnableDop();
}

void _tb_Dop_PWMEnd(void)
{
    _tb_FPGA_DisableDop();
}

void _tb_DOP_SetParam(uint32 spd)
{
	DBG_PRINT("------------%d Hz----------\n", spd);
    //_tb_FPGA_EnableDop();
    _tb_FPGA_SetDopParam((uint32)(FPGA_FREQ / spd));
}

// close uart
void _tb_DOP_Close(sint32 fd)
{
    close(fd);
    DBG_INFO("[doppler] %s port closed.\n", DOP_UART_NAME);
}


