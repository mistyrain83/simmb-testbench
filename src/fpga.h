#ifndef _FPGA_H
#define _FPGA_H

#include "lib.h"

// fpga version: 0312

#define FPGA_BASE_ADDRSS 0xF0400800

#define FPGA_SPD_ALL_CONFIG        0x0555
#define FPGA_SPD_ALL_INITPULSE_CONFIG 0x0AAA
#define FPGA_SPD1_CONFIG           0x0001
#define FPGA_SPD1_INITPULSE_CONFIG 0x0002
#define FPGA_SPD2_CONFIG           0x0004
#define FPGA_SPD2_INITPULSE_CONFIG 0x0008
#define FPGA_SPD3_CONFIG           0x0010
#define FPGA_SPD3_INITPULSE_CONFIG 0x0020
#define FPGA_SPD4_CONFIG           0x0040
#define FPGA_SPD4_INITPULSE_CONFIG 0x0080
#define FPGA_SPD5_CONFIG           0x0100
#define FPGA_SPD5_INITPULSE_CONFIG 0x0200
#define FPGA_SPD6_CONFIG           0x0400
#define FPGA_SPD6_INITPULSE_CONFIG 0x0800
#define FPGA_DOP_CONFIG            0x1000

#define FPGA_SPD_CHALL_CONFIG          0x0FFF
#define FPGA_SPD1_CH1_CONFIG           0x0001
#define FPGA_SPD1_CH2_CONFIG           0x0002
#define FPGA_SPD2_CH1_CONFIG           0x0004
#define FPGA_SPD2_CH2_CONFIG           0x0008
#define FPGA_SPD3_CH1_CONFIG           0x0010
#define FPGA_SPD3_CH2_CONFIG           0x0020
#define FPGA_SPD4_CH1_CONFIG           0x0040
#define FPGA_SPD4_CH2_CONFIG           0x0080
#define FPGA_SPD5_CH1_CONFIG           0x0100
#define FPGA_SPD5_CH2_CONFIG           0x0200
#define FPGA_SPD6_CH1_CONFIG           0x0400
#define FPGA_SPD6_CH2_CONFIG           0x0800


#define FPGA_VER_ADDR  0x00
#define DATA_AAAA_ADDR 0x02
#define DATA_5555_ADDR 0x04
#define DATA_FFFF_ADDR 0x06
#define DATA_0000_ADDR 0x08

#define FPGA_SPD_MODE_ADDR       0X10
#define FPGA_OUTPUT_CONTROL_ADDR 0x12
#define FPGA_SPD_LOAD_ADDR       0x14

#define FPGA_SPD1_FCONFIG_LOW_ADDR  0x20
#define FPGA_SPD1_FCONFIG_HIGH_ADDR 0x22
#define FPGA_SPD2_FCONFIG_LOW_ADDR  0x24
#define FPGA_SPD2_FCONFIG_HIGH_ADDR 0x26
#define FPGA_SPD3_FCONFIG_LOW_ADDR  0x28
#define FPGA_SPD3_FCONFIG_HIGH_ADDR 0x2a
#define FPGA_SPD4_FCONFIG_LOW_ADDR  0x30
#define FPGA_SPD4_FCONFIG_HIGH_ADDR 0x32
#define FPGA_SPD5_FCONFIG_LOW_ADDR  0x34
#define FPGA_SPD5_FCONFIG_HIGH_ADDR 0x36
#define FPGA_SPD6_FCONFIG_LOW_ADDR  0x38
#define FPGA_SPD6_FCONFIG_HIGH_ADDR 0x3a

#define FPGA_SPD1_PCONFIG_LOW_ADDR  0x40
#define FPGA_SPD1_PCONFIG_HIGH_ADDR 0x42
#define FPGA_SPD2_PCONFIG_LOW_ADDR  0x44
#define FPGA_SPD2_PCONFIG_HIGH_ADDR 0x46
#define FPGA_SPD3_PCONFIG_LOW_ADDR  0x48
#define FPGA_SPD3_PCONFIG_HIGH_ADDR 0x4a
#define FPGA_SPD4_PCONFIG_LOW_ADDR  0x50
#define FPGA_SPD4_PCONFIG_HIGH_ADDR 0x52
#define FPGA_SPD5_PCONFIG_LOW_ADDR  0x54
#define FPGA_SPD5_PCONFIG_HIGH_ADDR 0x56
#define FPGA_SPD6_PCONFIG_LOW_ADDR  0x58
#define FPGA_SPD6_PCONFIG_HIGH_ADDR 0x5a

#define FPGA_SPD1_PLUSE_ADDR 0X60
#define FPGA_SPD2_PLUSE_ADDR 0X62
#define FPGA_SPD3_PLUSE_ADDR 0X64
#define FPGA_SPD4_PLUSE_ADDR 0X66
#define FPGA_SPD5_PLUSE_ADDR 0X68
#define FPGA_SPD6_PLUSE_ADDR 0X6a

#define FPGA_LIMITED_PLUSE_FINISHED_ADDR 0x70

#define FPGA_CD_TI_OUTPUT_ADDR 0X80
#define FPGA_DOP_FCONFIG_LOW_ADDR 0x82
#define FPGA_DOP_FCONFIG_HIGH_ADDR 0x84

#define FPGA_IO_OUTPUT_ADDR 0x90
#define FPGA_IO_LED_ADDR 0xa0

#define FPGA_SPD1_INIT_LOW_ADDR  0xb0
#define FPGA_SPD1_INIT_HIGH_ADDR 0xb2
#define FPGA_SPD2_INIT_LOW_ADDR  0xb4
#define FPGA_SPD2_INIT_HIGH_ADDR 0xb6
#define FPGA_SPD3_INIT_LOW_ADDR  0xb8
#define FPGA_SPD3_INIT_HIGH_ADDR 0xba
#define FPGA_SPD4_INIT_LOW_ADDR  0xc0
#define FPGA_SPD4_INIT_HIGH_ADDR 0xc2
#define FPGA_SPD5_INIT_LOW_ADDR  0xc4
#define FPGA_SPD5_INIT_HIGH_ADDR 0xc6
#define FPGA_SPD6_INIT_LOW_ADDR  0xc8
#define FPGA_SPD6_INIT_HIGH_ADDR 0xca


uint16 _tb_FPGA_Read_Reg(unsigned int offset);
void _tb_FPGA_Write_Reg(unsigned int offset, uint16 data);

uint16 _tb_FPGA_GetVersion(void);

uint32 FPGA_GetSpeedReportPulse(void);
uint32 _tb_FPGA_GetSpd1ReportPulse(void);
uint32 _tb_FPGA_GetSpd2ReportPulse(void);
uint32 _tb_FPGA_GetSpd3ReportPulse(void);
uint32 _tb_FPGA_GetSpd4ReportPulse(void);
uint32 _tb_FPGA_GetSpd5ReportPulse(void);
uint32 _tb_FPGA_GetSpd6ReportPulse(void);

void _tb_FPGA_SetSpeedMode(uint16 spdMode, uint32 spdPulse);
void _tb_FPGA_SetSpeedFreq(uint32 spdFreq, uint32 spdPha);
void _tb_FPGA_SetSpd1_2Mode(uint16 spdMode, uint32 spdPulse);
void _tb_FPGA_SetSpd1_2Freq(uint32 spdFreq, uint32 spdPha);
void _tb_FPGA_SetSpd1_2InitPulse(uint32 initPulse);
void _tb_FPGA_SetSpd3_4Mode(uint16 spdMode, uint32 spdPulse);
void _tb_FPGA_SetSpd3_4Freq(uint32 spdFreq, uint32 spdPha);
void _tb_FPGA_SetSpd3_4InitPulse(uint32 initPulse);
void _tb_FPGA_SetSpd5_6Mode(uint16 spdMode, uint32 spdPulse);
void _tb_FPGA_SetSpd5_6Freq(uint32 spdFreq, uint32 spdPha);
void _tb_FPGA_SetSpd5_6InitPulse(uint32 initPulse);

void _tb_FPGA_SetSpd7_8Mode(uint16 spdMode, uint32 spdPulse);
void _tb_FPGA_SetSpd7_8Freq(uint32 spdFreq, uint32 spdPha);
void _tb_FPGA_SetSpd7_8InitPulse(uint32 initPulse);
void _tb_FPGA_SetSpd9_10Mode(uint16 spdMode, uint32 spdPulse);
void _tb_FPGA_SetSpd9_10Freq(uint32 spdFreq, uint32 spdPha);
void _tb_FPGA_SetSpd9_10InitPulse(uint32 initPulse);
void _tb_FPGA_SetSpd11_12Mode(uint16 spdMode, uint32 spdPulse);
void _tb_FPGA_SetSpd11_12Freq(uint32 spdFreq, uint32 spdPha);
void _tb_FPGA_SetSpd11_12InitPulse(uint32 initPulse);


void _tb_FPGA_EnableSpeed(void);
void _tb_FPGA_DisableSpeed(void);
void _tb_FPGA_EnableSpd1_2(void);
void _tb_FPGA_DisableSpd1_2(void);
void _tb_FPGA_EnableSpd3_4(void);
void _tb_FPGA_DisableSpd3_4(void);
void _tb_FPGA_EnableSpd5_6(void);
void _tb_FPGA_DisableSpd5_6(void);
void _tb_FPGA_EnableSpd7_8(void);
void _tb_FPGA_DisableSpd7_8(void);
void _tb_FPGA_EnableSpd9_10(void);
void _tb_FPGA_DisableSpd9_10(void);
void _tb_FPGA_EnableSpd11_12(void);
void _tb_FPGA_DisableSpd11_12(void);


void _tb_FPGA_SetDopParam(uint32 dopFreq);
void _tb_FPGA_EnableDop(void);
void _tb_FPGA_DisableDop(void);

void _tb_FPGA_SetBtmTiParam(uint16 param);
void _tb_FPGA_SetIOOutputParam(uint16 param);
void _tb_FPGA_SetIOLedParam(uint16 param);

#endif // _FPGA_H


