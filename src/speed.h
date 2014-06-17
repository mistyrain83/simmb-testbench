
#ifndef _SPEED_H
#define _SPEED_H

#include "lib.h"

// left is speed 1; right is speed 2
void _tb_SPD_Init(void);
void _tb_SPD_SetFreq(uint32 spdFreq);
void _tb_SPD_SetInitPulse(uint32 initPulse);
void _tb_SPD_SetMode(uint16 spdMode, uint32 spdPulse);
uint32 _tb_SPD_GetLeftSpdPluseNum(void);
uint32 _tb_SPD_GetRightSpdPluseNum(void);
void _tb_SPD_EnableOutput(void);
void _tb_SPD_DisableOutput(void);


#endif // _SPEED_H