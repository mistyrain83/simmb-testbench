
#include "lib.h"
#include "fpga.h"
#include "udp.h"
#include "BTM.h"
#include "speed.h"
#include "doppler.h"
#include "tms.h"
#include "sim.h"

void tb_buildinfo(void)
{
  DBG_PRINT("[TestBench] Ver 0x%x, Build Date: %s, Time: %s\n", _tb_FPGA_GetVersion(), __DATE__, __TIME__);
}

void tb_speed(void)
{
    _tb_SPD_Init();
    DBG_PRINT("------------TACHOMETER----------\n");
    _tb_SPD_SetFreq(10);
    taskDelay(10 * sysClkRateGet()); // delay 30s
    _tb_SPD_SetFreq(5);
    taskDelay(10 * sysClkRateGet()); // delay 30s
    _tb_SPD_SetFreq(20);
    taskDelay(10 * sysClkRateGet()); // delay 30s
    _tb_SPD_DisableOutput();
    DBG_PRINT("------------END----------\n");
}

void tb_btm_rs422_a(void)
{
    sint32 fd;
    DBG_PRINT("------------BTM_RS422 A----------\n");
    fd = _tb_BTM_Init_A();
    _tb_BTM_UartTest(fd);
    _tb_BTM_Close(fd);
    DBG_PRINT("------------END----------\n");
}

void tb_btm_rs422_b(void)
{
    sint32 fd;
    DBG_PRINT("------------BTM_RS422 B----------\n");
    fd = _tb_BTM_Init_B();
    _tb_BTM_UartTest(fd);
    _tb_BTM_Close(fd);
	DBG_PRINT("------------END----------\n");
}

void tb_btm_cd(void)
{
    _tb_BTM_CDTest();
}

void tb_tms_rs485(void)
{
    sint32 fd;
    fd = _tb_TMS_Init();
    _tb_TMS_UartTest(fd);
    _tb_TMS_Close(fd);
}

void tb_doppler_rs485(void)
{
    sint32 fd;
    fd = _tb_DOP_Init();
	DBG_PRINT("------------DOP RS485----------\n");
    _tb_DOP_UartTest(fd);
    _tb_DOP_Close(fd);
	DBG_PRINT("------------END----------\n");
}

void tb_doppler_pwm(void)
{
    _tb_Dop_PWMInit();
    DBG_PRINT("------------TACHOMETER----------\n");
    _tb_DOP_SetParam(10);
    taskDelay(10 * sysClkRateGet()); // delay 30s
    _tb_DOP_SetParam(5);
    taskDelay(10 * sysClkRateGet()); // delay 30s
    _tb_DOP_SetParam(20);
    taskDelay(10 * sysClkRateGet()); // delay 30s
    _tb_Dop_PWMEnd();
    DBG_PRINT("------------END----------\n");
}

void tb_net(void)
{
    _tb_UDP_NetInit();
    _tb_UDP_Test();
}

