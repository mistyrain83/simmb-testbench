
#ifndef _AI_H
#define _AI_H

#include "lib.h"
#include "fpga.h"


int _tb_AI_Init(void);
void _tb_AI_UartTest(sint32 fd);
void _tb_AI_Close(sint32 fd);
static void _tb_AI_TurnOnLock(void);
static void _tb_AI_TurnOffLock(void);
void _tb_AI_LockTest(void);

#endif // _AI_H