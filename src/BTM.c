
#include "fpga.h"
#include "BTM.h"

#define BTM_UART_A_NAME "/tyCo/2"
#define BTM_UART_B_NAME "/tyCo/3"

#define BTM_UART_BAUDRATE   38400
#define BTM_BUFFER_SIZE  128
#define BTM_FRAME_FOOT 0xAA

#define BTM_UART_RECV_TIMEOUT 4  // 4s
#define BTM_UART_SEND_TIMEOUT 4  // 4s
#define BTM_CD_SELECTOR  0x0003 // 1 - cd1; 2- cd2; 3 - cd1 and cd2


sint32 _tb_BTM_Init_A(void)
{
    sint32 fd;
    // 以可读可写方式打开串口
    fd = open(BTM_UART_A_NAME, O_RDWR, 0);
    
    if (fd == ERROR)
    {
        DBG_ERRO("[BTM_UART] open port failed!!!\n");
        exit(ERROR);
    }
    else
    {
        DBG_INFO("[BTM_UART] open port successfully!\n");
    }
    
    // set uart
    ioctl(fd, FIOSETOPTIONS, OPT_RAW);      // 设置串口工作模式
    ioctl(fd, FIOBAUDRATE, BTM_UART_BAUDRATE); //设置串口波特率
    ioctl(fd, FIOFLUSH, 0);                 //清空输入输出缓冲
    // 设置 8 位数据位，1位停止位，1位偶校验位,忽略MODEM控制信号,启动接收器
    ioctl(fd, SIO_HW_OPTS_SET, CS8 | PARENB | CLOCAL | CREAD);
    DBG_INFO("[BTM_UART] config OK!\n");
    return fd;
}

sint32 _tb_BTM_Init_B(void)
{
    sint32 fd;
    // 以可读可写方式打开串口
    fd = open(BTM_UART_B_NAME, O_RDWR, 0);
    
    if (fd == ERROR)
    {
        DBG_ERRO("[BTM_UART] open port failed!!!\n");
        exit(ERROR);
    }
    else
    {
        DBG_INFO("[BTM_UART] open port successfully!\n");
    }
    
    // set uart
    ioctl(fd, FIOSETOPTIONS, OPT_RAW);      // 设置串口工作模式
    ioctl(fd, FIOBAUDRATE, BTM_UART_BAUDRATE); //设置串口波特率
    ioctl(fd, FIOFLUSH, 0);                 //清空输入输出缓冲
    // 设置 8 位数据位，1位停止位，1位偶校验位,忽略MODEM控制信号,启动接收器
    ioctl(fd, SIO_HW_OPTS_SET, CS8 | PARENB | CLOCAL | CREAD);
    DBG_INFO("[BTM_UART] config OK!\n");
    return fd;
}

void _tb_BTM_Close(sint32 fd)
{
    close(fd);
    DBG_WARN("[BTM_UART] uart closed!");
}


// 从串口读数据
void _tb_BTM_UartTest(sint32 fd)
{
    uint32 i = 0;
    sint32 cycle = 0;
    sint32 recvNum = 0;  // recv data number
    sint32 sendNum = 0;  // send data number
    sint32 rst = 0;
    uint8 btmBuff[BTM_BUFFER_SIZE];
    bzero((char *)btmBuff, BTM_BUFFER_SIZE);
    DBG_INFO("[BTM_UART] ---------BEGIN--------\n");
    
    for (cycle = 0; cycle < 10; cycle++)
    {
        DBG_PRINT("cycle=%d:", cycle);
        
        for (i = 0; i < BTM_BUFFER_SIZE; i++)
        {
            rst = _tb_tread(fd, &btmBuff[i], 1, BTM_UART_RECV_TIMEOUT);
            
            // receive correct footer
            if ((btmBuff[i] == BTM_FRAME_FOOT) || (rst == -1))
            {
                recvNum = i;
                break;
            }
        }
        
        if (rst != -1)
        {
            // send back frame
            sendNum = _tb_tsendn(fd, (char *)btmBuff, recvNum, BTM_UART_SEND_TIMEOUT);
            DBG_INFO("[BTM_UART] sendback num = %d", sendNum);
        }
        else
        {
            DBG_INFO("[BTM_UART] receive timeout!");
        }
    }
    
    DBG_INFO("[BTM_UART] ---------END--------\n");
}


static void _tb_BTM_TurnOnCD(void)
{
    _tb_FPGA_SetBtmTiParam(BTM_CD_SELECTOR);
}

static void _tb_BTM_TurnOffCD(void)
{
    _tb_FPGA_SetBtmTiParam(0x0);
}

void _tb_BTM_CDTest(void)
{
    sint32 cycle = 0;
    DBG_INFO("[BTM_CD] ---------BEGIN--------\n");
    
    for (cycle = 0; cycle < 10; cycle++)
    {
        DBG_PRINT("cycle=%d:", cycle);
        _tb_BTM_TurnOnCD();
        taskDelay(sysClkRateGet());  // delay 1s
        _tb_BTM_TurnOffCD();
        taskDelay(sysClkRateGet());
    }
    
    DBG_INFO("[BTM_CD] ---------END--------\n");
}

