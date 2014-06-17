
#include "speed.h"
#include "fpga.h"

#define SPD_PHASE_SCALE 4  // 4 is 90

void _tb_SPD_Init(void)
{
    _tb_SPD_SetMode(0, 0);                          //设置速度计模式
    _tb_SPD_SetInitPulse(0);                            //初始化速度计初始脉冲
    _tb_SPD_SetFreq(0);
    _tb_SPD_EnableOutput();
}

uint32 _tb_SPD_GetLeftSpdPluseNum(void)
{
    uint32 pulseNum = 0;
    pulseNum = _tb_FPGA_GetSpd1ReportPulse();
    return pulseNum;
}

uint32 _tb_SPD_GetRightSpdPluseNum(void)
{
    uint32 pulseNum = 0;
    pulseNum = _tb_FPGA_GetSpd4ReportPulse();
    return pulseNum;
}

void _tb_SPD_SetFreq(uint32 spdFreq)
{
    uint32 freq;
    uint32 phaseA;
    uint32 phaseB;

	DBG_PRINT("------------%d Hz----------\n", spdFreq);
	
    freq = (uint32)(FPGA_FREQ / spdFreq);
    phaseA = (uint32)(freq / SPD_PHASE_SCALE);
    phaseB = (phaseA ^ 0x80000000);
    _tb_FPGA_SetSpd1_2Freq(freq, phaseA);
    _tb_FPGA_SetSpd3_4Freq(freq, phaseA);
    _tb_FPGA_SetSpd5_6Freq(freq, phaseA);
    _tb_FPGA_SetSpd7_8Freq(freq, phaseB);
    _tb_FPGA_SetSpd9_10Freq(freq, phaseB);
    _tb_FPGA_SetSpd11_12Freq(freq, phaseB);
}

void _tb_SPD_SetInitPulse(uint32 initPulse)
{
    _tb_FPGA_SetSpd1_2InitPulse(initPulse);
    _tb_FPGA_SetSpd3_4InitPulse(initPulse);
    _tb_FPGA_SetSpd5_6InitPulse(initPulse);
    _tb_FPGA_SetSpd7_8InitPulse(initPulse);
    _tb_FPGA_SetSpd9_10InitPulse(initPulse);
    _tb_FPGA_SetSpd11_12InitPulse(initPulse);
}

void _tb_SPD_SetMode(uint16 spdMode, uint32 spdPulse)
{
    _tb_FPGA_SetSpd1_2Mode(spdMode, spdPulse);
    _tb_FPGA_SetSpd3_4Mode(spdMode, spdPulse);
    _tb_FPGA_SetSpd5_6Mode(spdMode, spdPulse);
    _tb_FPGA_SetSpd7_8Mode(spdMode, spdPulse);
    _tb_FPGA_SetSpd9_10Mode(spdMode, spdPulse);
    _tb_FPGA_SetSpd11_12Mode(spdMode, spdPulse);
}

void _tb_SPD_EnableOutput(void)
{
    _tb_FPGA_EnableSpeed();
}

void _tb_SPD_DisableOutput(void)
{
    _tb_FPGA_DisableSpeed();
}


