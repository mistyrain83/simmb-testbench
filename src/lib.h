#ifndef _LIB_H
#define _LIB_H

#include "vxWorks.h"    // contains many basic definitions and types
#include "taskLib.h"    // contains taskSpawn taskDelete taskDelay
#include "semLib.h"     // contains semMCreate semBCreate semDelete semGive semTake
#include "msgQLib.h"    // contains msgQCreate msgQSend msgQReceive
// contains bind connect getsockopt listen setsockopt accept recv recvfrom send sendto socket
#include "sockLib.h"
#include "inetLib.h"    // contains inet_ntoa inet_addr
#include "selectLib.h"  // contains select
#include "ioLib.h"      // contains open close read write ioctl (I/O interface library)
#include "ipProto.h"    // contains ipAttach
#include "net/utils/ifconfig.h"  // contains ifconfig
#include "tickLib.h"    // contains tickGet
#include "logLib.h"     // contains logMsg

#include "stdio.h"      // contains fprintf sprintf snprintf    sscanf  printf


#define FPGA_FREQ 25000000 // @todo future 66000000 should be set: 25000000

#define USE_DEBUG  // this macro is for debug information print

// this macro is for big endian or little endian
//#define VTOA_LITTLE_ENDIAN_MACRO

typedef          char       char_t;
typedef unsigned char       uint8;
typedef signed char         sint8;
typedef unsigned short      uint16;
typedef signed short        sint16;
typedef unsigned int        uint32;
typedef        int          sint32;

#ifdef USE_DEBUG

#define DBG_INFO_0(msg) \
    logMsg("[INFO]---" msg "\n", 0,0,0,0,0,0)

#define DBG_INFO_1(msg, P1) \
    logMsg("[INFO]---" msg "\n", P1,0,0,0,0,0)

#define DBG_INFO_2(msg, P1, P2) \
    logMsg("[INFO]---" msg "\n", P1,P2,0,0,0,0)

#define DBG_INFO_3(msg, P1, P2, P3) \
    logMsg("[INFO]---" msg "\n", P1,P2,P3,0,0,0)

#define DBG_INFO_4(msg, P1, P2, P3, P4) \
    logMsg("[INFO]---" msg "\n", P1,P2,P3,P4,0,0)

#define DBG_INFO_5(msg, P1, P2, P3, P4, P5) \
    logMsg("[INFO]---" msg "\n", P1,P2,P3,P4,P5,0)

#define DBG_WARN_0(msg) \
    logMsg("[WARN]---" msg "\n", 0,0,0,0,0,0)

#define DBG_WARN_1(msg, P1) \
    logMsg("[WARN]---" msg "\n", P1,0,0,0,0,0)

#define DBG_WARN_2(msg, P1, P2) \
    logMsg("[WARN]---" msg "\n", P1,P2,0,0,0,0)

#define DBG_ERRO_0(msg) \
    logMsg("[ERRO]---" msg "\n", 0,0,0,0,0,0)

#define DBG_ERRO_1(msg, P1) \
    logMsg("[ERRO]---" msg "\n", P1,0,0,0,0,0)

#define DEBUG(msg, ...) \
    DBG_INFO(msg, ##__VA_ARGS__)

//  #define DBG_INFO
#define DBG_PRINT(msg, ...) \
    printf(msg "\n", ##__VA_ARGS__)

#define DBG_INFO(msg, ...) \
    printf("[INFO]---" msg "\n", ##__VA_ARGS__)

#define DBG_WARN(msg, ...) \
    printf("[WARN]---" msg "\n", ##__VA_ARGS__)

#define DBG_ERRO(msg, ...) \
    printf("[ERRO]---" msg "\n", ##__VA_ARGS__)

#define SIM_ASSERT(e) ((e) ? (TRUE) : \
                       printf("[ASSERT] %s,%d: assertion '%s' failed!\n", \
                              __FILE__, __LINE__, #e), FALSE)
#else
#define DBG_INFO_0(msg)
#define DBG_INFO_1(msg, P1)
#define DBG_INFO_2(msg, P1, P2)
#define DBG_INFO_3(msg, P1, P2, P3)
#define DBG_INFO_4(msg, P1, P2, P3, P4)
#define DBG_INFO_5(msg, P1, P2, P3, P4, P5)
#define DBG_WARN_0(msg)
#define DBG_WARN_1(msg, P1)
#define DBG_WARN_2(msg, P1, P2)
#define DBG_ERRO_0(msg)
#define DBG_ERRO_1(msg, P1)
#define DEBUG
#define DBG_INFO
#define DBG_WARN
#define DBG_ERRO
#define SIM_ASSERT(e)
#endif // USE_DEBUG


uint8 _tb_VariableToArray_uint8(uint8 val, uint8 *str);
uint8 _tb_VariableToArray_uint16(uint16 val, uint8 *str);
uint8 _tb_VariableToArray_uint32(uint32 val, uint8 *str);

uint8 _tb_ArrayToVariable_uint8(uint8 *val, uint8 *str);
uint8 _tb_ArrayToVariable_uint16(uint16 *val, uint8 *str);
uint8 _tb_ArrayToVariable_sint16(sint16 *val, uint8 *str);
uint8 _tb_ArrayToVariable_uint32(uint32 *val, uint8 *str);
uint8 _tb_ArrayToVariable_sint32(sint32 *val, uint8 *str);

sint32 _tb_tread(int fd, uint8 *buf, uint32 nbytes, unsigned int timout);
sint32 _tb_treadn(int fd, uint8 *buf, uint32 nbytes, unsigned int timout);
sint32 _tb_tsendn(int fd, char *buf, uint32 nbytes, unsigned int timout);

#endif // _LIB_H