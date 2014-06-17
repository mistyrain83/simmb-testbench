#ifndef _DOPPLER_H
#define _DOPPLER_H

#include "lib.h"

sint32 _tb_DOP_Init(void);
void _tb_Dop_PWMInit(void);
void _tb_Dop_PWMEnd(void);
void _tb_DOP_SetParam(uint32 spd);
void _tb_DOP_Close(sint32 fd);
void _tb_DOP_UartTest(sint32 fd);


#endif // _DOPPLER_H