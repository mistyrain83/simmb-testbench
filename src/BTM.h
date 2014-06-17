#ifndef _BTM_H
#define _BTM_H

#include "lib.h"

sint32 _tb_BTM_Init_A(void);
sint32 _tb_BTM_Init_B(void);
void _tb_BTM_Close(sint32 fd);
void _tb_BTM_UartTest(sint32 fd);
void _tb_BTM_CDTest(void);

static void _tb_BTM_TurnOnCD(void);
static void _tb_BTM_TurnOffCD(void);


#endif // _BTM_H