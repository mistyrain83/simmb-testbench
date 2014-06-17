/*
 * SIM_DB CS3 0xF0400000
 *
 * base address 0xF0400000
 * */

#include "fpga.h"


uint16 _tb_FPGA_Read_Reg(unsigned int offset)
{
    uint16 ret;
    ret = ((*(volatile unsigned short *)(FPGA_BASE_ADDRSS + offset)));
    return ret;
}

void _tb_FPGA_Write_Reg(unsigned int offset, uint16 data)
{
    uint16 ret = data;
    *(volatile unsigned short *)(FPGA_BASE_ADDRSS + offset) = (ret);
}

uint16 _tb_FPGA_GetVersion(void)
{
    return _tb_FPGA_Read_Reg(FPGA_VER_ADDR);
}

// get pulse number
uint32 _tb_FPGA_GetSpd1ReportPulse(void)
{
    uint16 low = 0;
    uint16 high = 0;
    low = _tb_FPGA_Read_Reg(FPGA_SPD1_INIT_LOW_ADDR);
    high = _tb_FPGA_Read_Reg(FPGA_SPD1_INIT_HIGH_ADDR);
    return ((((uint32)high) << 16) + (uint32)low);
}

uint32 _tb_FPGA_GetSpd2ReportPulse(void)
{
    uint16 low = 0;
    uint16 high = 0;
    low = _tb_FPGA_Read_Reg(FPGA_SPD2_INIT_LOW_ADDR);
    high = _tb_FPGA_Read_Reg(FPGA_SPD2_INIT_HIGH_ADDR);
    return ((((uint32)high) << 16) + (uint32)low);
}

uint32 _tb_FPGA_GetSpd3ReportPulse(void)
{
    uint16 low = 0;
    uint16 high = 0;
    low = _tb_FPGA_Read_Reg(FPGA_SPD3_INIT_LOW_ADDR);
    high = _tb_FPGA_Read_Reg(FPGA_SPD3_INIT_HIGH_ADDR);
    return ((((uint32)high) << 16) + (uint32)low);
}

uint32 _tb_FPGA_GetSpd4ReportPulse(void)
{
    uint16 low = 0;
    uint16 high = 0;
    low = _tb_FPGA_Read_Reg(FPGA_SPD4_INIT_LOW_ADDR);
    high = _tb_FPGA_Read_Reg(FPGA_SPD4_INIT_HIGH_ADDR);
    return ((((uint32)high) << 16) + (uint32)low);
}

uint32 _tb_FPGA_GetSpd5ReportPulse(void)
{
    uint16 low = 0;
    uint16 high = 0;
    low = _tb_FPGA_Read_Reg(FPGA_SPD5_INIT_LOW_ADDR);
    high = _tb_FPGA_Read_Reg(FPGA_SPD5_INIT_HIGH_ADDR);
    return ((((uint32)high) << 16) + (uint32)low);
}

uint32 _tb_FPGA_GetSpd6ReportPulse(void)
{
    uint16 low = 0;
    uint16 high = 0;
    low = _tb_FPGA_Read_Reg(FPGA_SPD6_INIT_LOW_ADDR);
    high = _tb_FPGA_Read_Reg(FPGA_SPD6_INIT_HIGH_ADDR);
    return ((((uint32)high) << 16) + (uint32)low);
}


// enable tachometer all channel output
void _tb_FPGA_EnableSpeed(void)
{
    uint16 var = 0;
    // load CONTROL parameter
    var = _tb_FPGA_Read_Reg(FPGA_OUTPUT_CONTROL_ADDR);
    _tb_FPGA_Write_Reg(FPGA_OUTPUT_CONTROL_ADDR, (var | FPGA_SPD_CHALL_CONFIG));
}

// disenable tachometer all channel output
void _tb_FPGA_DisableSpeed(void)
{
    uint16 var = 0;
    // load CONTROL parameter
    var = _tb_FPGA_Read_Reg(FPGA_OUTPUT_CONTROL_ADDR);
    _tb_FPGA_Write_Reg(FPGA_OUTPUT_CONTROL_ADDR, (var & (~FPGA_SPD_CHALL_CONFIG)));
}


void _tb_FPGA_EnableSpd1_2(void)
{
    uint16 var = 0;
    // load CONTROL parameter
    var = _tb_FPGA_Read_Reg(FPGA_OUTPUT_CONTROL_ADDR);
    _tb_FPGA_Write_Reg(FPGA_OUTPUT_CONTROL_ADDR, (var | FPGA_SPD1_CH1_CONFIG | FPGA_SPD1_CH2_CONFIG));
}

void _tb_FPGA_DisableSpd1_2(void)
{
    uint16 var = 0;
    // load CONTROL parameter
    var = _tb_FPGA_Read_Reg(FPGA_OUTPUT_CONTROL_ADDR);
    _tb_FPGA_Write_Reg(FPGA_OUTPUT_CONTROL_ADDR, (var & (~(FPGA_SPD1_CH1_CONFIG | FPGA_SPD1_CH2_CONFIG))));
}

void _tb_FPGA_EnableSpd3_4(void)
{
    uint16 var = 0;
    // load CONTROL parameter
    var = _tb_FPGA_Read_Reg(FPGA_OUTPUT_CONTROL_ADDR);
    _tb_FPGA_Write_Reg(FPGA_OUTPUT_CONTROL_ADDR, (var | FPGA_SPD2_CONFIG));
}

void _tb_FPGA_DisableSpd3_4(void)
{
    uint16 var = 0;
    // load CONTROL parameter
    var = _tb_FPGA_Read_Reg(FPGA_OUTPUT_CONTROL_ADDR);
    _tb_FPGA_Write_Reg(FPGA_OUTPUT_CONTROL_ADDR, (var & (~FPGA_SPD2_CONFIG)));
}

void _tb_FPGA_DisableSpd5_6(void)
{
    uint16 var = 0;
    // load CONTROL parameter
    var = _tb_FPGA_Read_Reg(FPGA_OUTPUT_CONTROL_ADDR);
    _tb_FPGA_Write_Reg(FPGA_OUTPUT_CONTROL_ADDR, (var & (~FPGA_SPD3_CONFIG)));
}

void _tb_FPGA_EnableSpd5_6(void)
{
    uint16 var = 0;
    // load CONTROL parameter
    var = _tb_FPGA_Read_Reg(FPGA_OUTPUT_CONTROL_ADDR);
    _tb_FPGA_Write_Reg(FPGA_OUTPUT_CONTROL_ADDR, (var | FPGA_SPD3_CONFIG));
}

void _tb_FPGA_EnableSpd7_8(void)
{
    uint16 var = 0;
    // load CONTROL parameter
    var = _tb_FPGA_Read_Reg(FPGA_OUTPUT_CONTROL_ADDR);
    _tb_FPGA_Write_Reg(FPGA_OUTPUT_CONTROL_ADDR, (var | FPGA_SPD4_CONFIG));
}

void _tb_FPGA_DisableSpd7_8(void)
{
    uint16 var = 0;
    // load CONTROL parameter
    var = _tb_FPGA_Read_Reg(FPGA_OUTPUT_CONTROL_ADDR);
    _tb_FPGA_Write_Reg(FPGA_OUTPUT_CONTROL_ADDR, (var & (~FPGA_SPD4_CONFIG)));
}

void _tb_FPGA_EnableSpd9_10(void)
{
    uint16 var = 0;
    // load CONTROL parameter
    var = _tb_FPGA_Read_Reg(FPGA_OUTPUT_CONTROL_ADDR);
    _tb_FPGA_Write_Reg(FPGA_OUTPUT_CONTROL_ADDR, (var | FPGA_SPD5_CONFIG));
}

void _tb_FPGA_DisableSpd9_10(void)
{
    uint16 var = 0;
    // load CONTROL parameter
    var = _tb_FPGA_Read_Reg(FPGA_OUTPUT_CONTROL_ADDR);
    _tb_FPGA_Write_Reg(FPGA_OUTPUT_CONTROL_ADDR, (var & (~FPGA_SPD5_CONFIG)));
}

void _tb_FPGA_EnableSpd11_12(void)
{
    uint16 var = 0;
    // load CONTROL parameter
    var = _tb_FPGA_Read_Reg(FPGA_OUTPUT_CONTROL_ADDR);
    _tb_FPGA_Write_Reg(FPGA_OUTPUT_CONTROL_ADDR, (var | FPGA_SPD6_CONFIG));
}

void _tb_FPGA_DisableSpd11_12(void)
{
    uint16 var = 0;
    // load CONTROL parameter
    var = _tb_FPGA_Read_Reg(FPGA_OUTPUT_CONTROL_ADDR);
    _tb_FPGA_Write_Reg(FPGA_OUTPUT_CONTROL_ADDR, (var & (~FPGA_SPD6_CONFIG)));
}


// set tachometer mode
void _tb_FPGA_SetSpeedMode(uint16 spdMode, uint32 spdPulse)
{
    _tb_FPGA_SetSpd1_2Mode(spdMode, spdPulse);
    _tb_FPGA_SetSpd3_4Mode(spdMode, spdPulse);
    _tb_FPGA_SetSpd5_6Mode(spdMode, spdPulse);
    _tb_FPGA_SetSpd7_8Mode(spdMode, spdPulse);
    _tb_FPGA_SetSpd9_10Mode(spdMode, spdPulse);
    _tb_FPGA_SetSpd11_12Mode(spdMode, spdPulse);
}

// set tachometer frequency
void _tb_FPGA_SetSpeedFreq(uint32 spdFreq, uint32 spdPha)
{
    _tb_FPGA_SetSpd1_2Freq(spdFreq, spdPha);
    _tb_FPGA_SetSpd3_4Freq(spdFreq, spdPha);
    _tb_FPGA_SetSpd5_6Freq(spdFreq, spdPha);
    _tb_FPGA_SetSpd7_8Freq(spdFreq, spdPha);
    _tb_FPGA_SetSpd9_10Freq(spdFreq, spdPha);
    _tb_FPGA_SetSpd11_12Freq(spdFreq, spdPha);
}

// set tachometer init pulse
void _tb_FPGA_SetSpeedInitPulse(uint32 initPulse)
{
    _tb_FPGA_SetSpd1_2InitPulse(initPulse);
    _tb_FPGA_SetSpd3_4InitPulse(initPulse);
    _tb_FPGA_SetSpd5_6InitPulse(initPulse);
    _tb_FPGA_SetSpd7_8InitPulse(initPulse);
    _tb_FPGA_SetSpd9_10InitPulse(initPulse);
    _tb_FPGA_SetSpd11_12InitPulse(initPulse);
}

void _tb_FPGA_SetSpd1_2Mode(uint16 spdMode, uint32 spdPulse)
{
    // 1. set LOAD REG 0
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, 0x0000);
    // 2. load parameters
    _tb_FPGA_Write_Reg(FPGA_SPD_MODE_ADDR, spdMode);
    _tb_FPGA_Write_Reg(FPGA_SPD1_PLUSE_ADDR, spdPulse);
    // 3. set LOAD REG 1, enable parameters
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, FPGA_SPD1_CONFIG);
}

void _tb_FPGA_SetSpd1_2Freq(uint32 spdFreq, uint32 spdPha)
{
    // 1. set LOAD REG 0
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, 0x0000);
    // 2. load parameters
    _tb_FPGA_Write_Reg(FPGA_SPD1_FCONFIG_LOW_ADDR, (spdFreq & 0x0000FFFF));
    _tb_FPGA_Write_Reg(FPGA_SPD1_FCONFIG_HIGH_ADDR, ((spdFreq >> 16) & 0x0000FFFF));
    _tb_FPGA_Write_Reg(FPGA_SPD1_PCONFIG_LOW_ADDR, (spdPha & 0x0000FFFF));
    _tb_FPGA_Write_Reg(FPGA_SPD1_PCONFIG_HIGH_ADDR, ((spdPha >> 16) & 0x0000FFFF));
    // 3. set LOAD REG 1, enable parameters
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, FPGA_SPD1_CONFIG);
}

void _tb_FPGA_SetSpd1_2InitPulse(uint32 initPulse)
{
    // 1. set LOAD REG 0
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, 0x0000);
    // 2. load parameters
    _tb_FPGA_Write_Reg(FPGA_SPD1_INIT_LOW_ADDR, (initPulse & 0x0000FFFF));
    _tb_FPGA_Write_Reg(FPGA_SPD1_INIT_HIGH_ADDR, ((initPulse >> 16) & 0x0000FFFF));
    // 3. set LOAD REG 1, enable parameters
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, FPGA_SPD1_INITPULSE_CONFIG);
}

void _tb_FPGA_SetSpd3_4Mode(uint16 spdMode, uint32 spdPulse)
{
    // 1. set LOAD REG 0
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, 0x0000);
    // 2. load parameters
    _tb_FPGA_Write_Reg(FPGA_SPD_MODE_ADDR, spdMode);
    _tb_FPGA_Write_Reg(FPGA_SPD2_PLUSE_ADDR, spdPulse);
    // 3. set LOAD REG 1, enable parameters
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, FPGA_SPD2_CONFIG);
}

void _tb_FPGA_SetSpd3_4Freq(uint32 spdFreq, uint32 spdPha)
{
    // 1. set LOAD REG 0
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, 0x0000);
    // 2. load parameters
    _tb_FPGA_Write_Reg(FPGA_SPD2_FCONFIG_LOW_ADDR, (spdFreq & 0x0000FFFF));
    _tb_FPGA_Write_Reg(FPGA_SPD2_FCONFIG_HIGH_ADDR, ((spdFreq >> 16) & 0x0000FFFF));
    _tb_FPGA_Write_Reg(FPGA_SPD2_PCONFIG_LOW_ADDR, (spdPha & 0x0000FFFF));
    _tb_FPGA_Write_Reg(FPGA_SPD2_PCONFIG_HIGH_ADDR, ((spdPha >> 16) & 0x0000FFFF));
    // 3. set LOAD REG 1, enable parameters
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, FPGA_SPD2_CONFIG);
}

void _tb_FPGA_SetSpd3_4InitPulse(uint32 initPulse)
{
    // 1. set LOAD REG 0
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, 0x0000);
    // 2. load parameters
    _tb_FPGA_Write_Reg(FPGA_SPD2_INIT_LOW_ADDR, (initPulse & 0x0000FFFF));
    _tb_FPGA_Write_Reg(FPGA_SPD2_INIT_HIGH_ADDR, ((initPulse >> 16) & 0x0000FFFF));
    // 3. set LOAD REG 1, enable parameters
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, FPGA_SPD2_INITPULSE_CONFIG);
}

void _tb_FPGA_SetSpd5_6Mode(uint16 spdMode, uint32 spdPulse)
{
    // 1. set LOAD REG 0
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, 0x0000);
    // 2. load parameters
    _tb_FPGA_Write_Reg(FPGA_SPD_MODE_ADDR, spdMode);
    _tb_FPGA_Write_Reg(FPGA_SPD3_PLUSE_ADDR, spdPulse);
    // 3. set LOAD REG 1, enable parameters
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, FPGA_SPD3_CONFIG);
}

void _tb_FPGA_SetSpd5_6Freq(uint32 spdFreq, uint32 spdPha)
{
    // 1. set LOAD REG 0
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, 0x0000);
    // 2. load parameters
    _tb_FPGA_Write_Reg(FPGA_SPD3_FCONFIG_LOW_ADDR, (spdFreq & 0x0000FFFF));
    _tb_FPGA_Write_Reg(FPGA_SPD3_FCONFIG_HIGH_ADDR, ((spdFreq >> 16) & 0x0000FFFF));
    _tb_FPGA_Write_Reg(FPGA_SPD3_PCONFIG_LOW_ADDR, (spdPha & 0x0000FFFF));
    _tb_FPGA_Write_Reg(FPGA_SPD3_PCONFIG_HIGH_ADDR, ((spdPha >> 16) & 0x0000FFFF));
    // 3. set LOAD REG 1, enable parameters
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, FPGA_SPD3_CONFIG);
}

void _tb_FPGA_SetSpd5_6InitPulse(uint32 initPulse)
{
    // 1. set LOAD REG 0
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, 0x0000);
    // 2. load parameters
    _tb_FPGA_Write_Reg(FPGA_SPD3_INIT_LOW_ADDR, (initPulse & 0x0000FFFF));
    _tb_FPGA_Write_Reg(FPGA_SPD3_INIT_HIGH_ADDR, ((initPulse >> 16) & 0x0000FFFF));
    // 3. set LOAD REG 1, enable parameters
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, FPGA_SPD3_INITPULSE_CONFIG);
}

void _tb_FPGA_SetSpd7_8Mode(uint16 spdMode, uint32 spdPulse)
{
    // 1. set LOAD REG 0
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, 0x0000);
    // 2. load parameters
    _tb_FPGA_Write_Reg(FPGA_SPD_MODE_ADDR, spdMode);
    _tb_FPGA_Write_Reg(FPGA_SPD4_PLUSE_ADDR, spdPulse);
    // 3. set LOAD REG 1, enable parameters
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, FPGA_SPD4_CONFIG);
}

void _tb_FPGA_SetSpd7_8Freq(uint32 spdFreq, uint32 spdPha)
{
    // 1. set LOAD REG 0
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, 0x0000);
    // 2. load parameters
    _tb_FPGA_Write_Reg(FPGA_SPD4_FCONFIG_LOW_ADDR, (spdFreq & 0x0000FFFF));
    _tb_FPGA_Write_Reg(FPGA_SPD4_FCONFIG_HIGH_ADDR, ((spdFreq >> 16) & 0x0000FFFF));
    _tb_FPGA_Write_Reg(FPGA_SPD4_PCONFIG_LOW_ADDR, (spdPha & 0x0000FFFF));
    _tb_FPGA_Write_Reg(FPGA_SPD4_PCONFIG_HIGH_ADDR, ((spdPha >> 16) & 0x0000FFFF));
    // 3. set LOAD REG 1, enable parameters
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, FPGA_SPD4_CONFIG);
}

void _tb_FPGA_SetSpd7_8InitPulse(uint32 initPulse)
{
    // 1. set LOAD REG 0
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, 0x0000);
    // 2. load parameters
    _tb_FPGA_Write_Reg(FPGA_SPD4_INIT_LOW_ADDR, (initPulse & 0x0000FFFF));
    _tb_FPGA_Write_Reg(FPGA_SPD4_INIT_HIGH_ADDR, ((initPulse >> 16) & 0x0000FFFF));
    // 3. set LOAD REG 1, enable parameters
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, FPGA_SPD4_INITPULSE_CONFIG);
}

void _tb_FPGA_SetSpd9_10Mode(uint16 spdMode, uint32 spdPulse)
{
    // 1. set LOAD REG 0
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, 0x0000);
    // 2. load parameters
    _tb_FPGA_Write_Reg(FPGA_SPD_MODE_ADDR, spdMode);
    _tb_FPGA_Write_Reg(FPGA_SPD5_PLUSE_ADDR, spdPulse);
    // 3. set LOAD REG 1, enable parameters
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, FPGA_SPD5_CONFIG);
}

void _tb_FPGA_SetSpd9_10Freq(uint32 spdFreq, uint32 spdPha)
{
    // 1. set LOAD REG 0
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, 0x0000);
    // 2. load parameters
    _tb_FPGA_Write_Reg(FPGA_SPD5_FCONFIG_LOW_ADDR, (spdFreq & 0x0000FFFF));
    _tb_FPGA_Write_Reg(FPGA_SPD5_FCONFIG_HIGH_ADDR, ((spdFreq >> 16) & 0x0000FFFF));
    _tb_FPGA_Write_Reg(FPGA_SPD5_PCONFIG_LOW_ADDR, (spdPha & 0x0000FFFF));
    _tb_FPGA_Write_Reg(FPGA_SPD5_PCONFIG_HIGH_ADDR, ((spdPha >> 16) & 0x0000FFFF));
    // 3. set LOAD REG 1, enable parameters
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, FPGA_SPD5_CONFIG);
}

void _tb_FPGA_SetSpd9_10InitPulse(uint32 initPulse)
{
    // 1. set LOAD REG 0
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, 0x0000);
    // 2. load parameters
    _tb_FPGA_Write_Reg(FPGA_SPD5_INIT_LOW_ADDR, (initPulse & 0x0000FFFF));
    _tb_FPGA_Write_Reg(FPGA_SPD5_INIT_HIGH_ADDR, ((initPulse >> 16) & 0x0000FFFF));
    // 3. set LOAD REG 1, enable parameters
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, FPGA_SPD5_INITPULSE_CONFIG);
}

void _tb_FPGA_SetSpd11_12Mode(uint16 spdMode, uint32 spdPulse)
{
    // 1. set LOAD REG 0
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, 0x0000);
    // 2. load parameters
    _tb_FPGA_Write_Reg(FPGA_SPD_MODE_ADDR, spdMode);
    _tb_FPGA_Write_Reg(FPGA_SPD6_PLUSE_ADDR, spdPulse);
    // 3. set LOAD REG 1, enable parameters
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, FPGA_SPD6_CONFIG);
}


void _tb_FPGA_SetSpd11_12Freq(uint32 spdFreq, uint32 spdPha)
{
    // 1. set LOAD REG 0
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, 0x0000);
    // 2. load parameters
    _tb_FPGA_Write_Reg(FPGA_SPD6_FCONFIG_LOW_ADDR, (spdFreq & 0x0000FFFF));
    _tb_FPGA_Write_Reg(FPGA_SPD6_FCONFIG_HIGH_ADDR, ((spdFreq >> 16) & 0x0000FFFF));
    _tb_FPGA_Write_Reg(FPGA_SPD6_PCONFIG_LOW_ADDR, (spdPha & 0x0000FFFF));
    _tb_FPGA_Write_Reg(FPGA_SPD6_PCONFIG_HIGH_ADDR, ((spdPha >> 16) & 0x0000FFFF));
    // 3. set LOAD REG 1, enable parameters
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, FPGA_SPD6_CONFIG);
}

void _tb_FPGA_SetSpd11_12InitPulse(uint32 initPulse)
{
    // 1. set LOAD REG 0
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, 0x0000);
    // 2. load parameters
    _tb_FPGA_Write_Reg(FPGA_SPD6_INIT_LOW_ADDR, (initPulse & 0x0000FFFF));
    _tb_FPGA_Write_Reg(FPGA_SPD6_INIT_HIGH_ADDR, ((initPulse >> 16) & 0x0000FFFF));
    // 3. set LOAD REG 1, enable parameters
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, FPGA_SPD6_INITPULSE_CONFIG);
}

//  brief  setup dop parameters
//
// setup dop parameters
//
//  version    V0.1
//  author     QiXiangbing
//  date       2013-12-05
//
// Created Function
void _tb_FPGA_SetDopParam(uint32 dopFreq)
{
    uint16 var = 0;
    // 1. set LOAD REG 0
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, 0x0000);
    // 2. load parameters
    _tb_FPGA_Write_Reg(FPGA_DOP_FCONFIG_LOW_ADDR, (dopFreq & 0x0000FFFF));
    _tb_FPGA_Write_Reg(FPGA_DOP_FCONFIG_HIGH_ADDR, ((dopFreq >> 16) & 0x0000FFFF));
    // 3. set LOAD REG 1, enable parameters
    _tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, FPGA_DOP_CONFIG);
    // 4. load CONTROL parameter
    //var = _tb_FPGA_Read_Reg(FPGA_OUTPUT_CONTROL_ADDR);
    //_tb_FPGA_Write_Reg(FPGA_OUTPUT_CONTROL_ADDR, (var | FPGA_DOP_CONFIG));
}


void _tb_FPGA_EnableDop(void)
{
    uint16 var = 0;
    // 1. set LOAD REG 0
    //_tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, 0x0000);
    // 2. load parameters
    var = _tb_FPGA_Read_Reg(FPGA_OUTPUT_CONTROL_ADDR);
    // 3. set LOAD REG 1, enable parameters
    _tb_FPGA_Write_Reg(FPGA_OUTPUT_CONTROL_ADDR, (var | FPGA_DOP_CONFIG));
}

void _tb_FPGA_DisableDop(void)
{
    uint16 var = 0;
    // 1. set LOAD REG 0
    //_tb_FPGA_Write_Reg(FPGA_SPD_LOAD_ADDR, 0x0000);
    // 2. load parameters
    var = _tb_FPGA_Read_Reg(FPGA_OUTPUT_CONTROL_ADDR);
    // 3. set LOAD REG 1, enable parameters
    _tb_FPGA_Write_Reg(FPGA_OUTPUT_CONTROL_ADDR, (var & (~FPGA_DOP_CONFIG)));
}

// param only is 1,2,3
void _tb_FPGA_SetBtmTiParam(uint16 param)
{
    _tb_FPGA_Write_Reg(FPGA_CD_TI_OUTPUT_ADDR, param);
}

// param only is 1,2
void _tb_FPGA_SetIOOutputParam(uint16 param)
{
    _tb_FPGA_Write_Reg(FPGA_IO_OUTPUT_ADDR, param);
}

// param only is 1,2
void _tb_FPGA_SetIOLedParam(uint16 param)
{
    _tb_FPGA_Write_Reg(FPGA_IO_LED_ADDR, param);
}
