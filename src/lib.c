
#include "lib.h"


#define SIZE_BITS 8
#define SIZE_BYTE 1
#define SIZE_WORD 2
#define SIZE_DW   4

uint8 _tb_VariableToArray_uint8(uint8 val, uint8 *str)
{
    *(str) = val;
    return SIZE_BYTE;
}

uint8 _tb_VariableToArray_uint16(uint16 val, uint8 *str)
{
    uint8 i = 0;
#ifdef VTOA_LITTLE_ENDIAN_MACRO
    
    for (i = 0U; i < SIZE_WORD; i++)
    {
        *(str + i) = ((val >> i * SIZE_BITS) & 0xFF);
    }
    
#else
    
    for (i = 0U; i < SIZE_WORD; i++)
    {
        *(str + i) = ((val >> ((SIZE_WORD - 1 - i) * SIZE_BITS)) & 0xFF);
    }
    
#endif
    return SIZE_WORD;
}

uint8 _tb_VariableToArray_uint32(uint32 val, uint8 *str)
{
    uint8 i = 0;
#ifdef VTOA_LITTLE_ENDIAN_MACRO
    
    for (i = 0U; i < SIZE_DW; i++)
    {
        *(str + i) = ((val >> i * SIZE_BITS) & 0xFF);
    }
    
#else
    
    for (i = 0U; i < SIZE_DW; i++)
    {
        *(str + i) = ((val >> ((SIZE_DW - 1 - i) * SIZE_BITS)) & 0xFF);
    }
    
#endif
    return SIZE_DW;
}

uint8 _tb_ArrayToVariable_uint8(uint8 *val, uint8 *str)
{
    *val = *str;
    return SIZE_BYTE;
}

uint8 _tb_ArrayToVariable_uint16(uint16 *val, uint8 *str)
{
    uint8 i = 0;
    uint16 tmp = 0;
#ifdef ATOV_LITTLE_ENDIAN_MACRO
    
    for (i = 0U; i < SIZE_WORD; i++)
    {
        tmp = tmp << 8;
        tmp += *(str + SIZE_WORD - 1 - i);
    }
    
#else
    
    for (i = 0; i < SIZE_WORD; i++)
    {
        tmp = tmp << 8;
        tmp += *(str + i);
    }
    
#endif
    *val = tmp;
    return SIZE_WORD;
}

uint8 _tb_ArrayToVariable_sint16(sint16 *val, uint8 *str)
{
    uint8 i = 0;
    sint16 tmp = 0;
#ifdef ATOV_LITTLE_ENDIAN_MACRO
    
    for (i = 0U; i < SIZE_WORD; i++)
    {
        tmp = tmp << 8;
        tmp += *(str + SIZE_WORD - 1 - i);
    }
    
#else
    
    for (i = 0; i < SIZE_WORD; i++)
    {
        tmp = tmp << 8;
        tmp += *(str + i);
    }
    
#endif
    *val = tmp;
    return SIZE_WORD;
}

uint8 _tb_ArrayToVariable_uint32(uint32 *val, uint8 *str)
{
    uint8 i = 0;
    uint32 tmp = 0;
#ifdef ATOV_LITTLE_ENDIAN_MACRO
    
    for (i = 0U; i < SIZE_DW; i++)
    {
        tmp = tmp << 8;
        tmp += *(str + SIZE_DW - 1 - i);
    }
    
#else
    
    for (i = 0; i < SIZE_DW; i++)
    {
        tmp = tmp << 8;
        tmp += *(str + i);
    }
    
#endif
    *val = tmp;
    return SIZE_DW;
}

uint8 _tb_ArrayToVariable_sint32(sint32 *val, uint8 *str)
{
    uint8 i = 0;
    sint32 tmp = 0;
#ifdef ATOV_LITTLE_ENDIAN_MACRO
    
    for (i = 0U; i < SIZE_DW; i++)
    {
        tmp = tmp << 8;
        tmp += *(str + SIZE_DW - 1 - i);
    }
    
#else
    
    for (i = 0; i < SIZE_DW; i++)
    {
        tmp = tmp << 8;
        tmp += *(str + i);
    }
    
#endif
    *val = tmp;
    return SIZE_DW;
}

sint32 _tb_tread(int fd, uint8 *buf, uint32 nbytes, unsigned int timout)

{
    int   nfds;
    fd_set   readfds;
    struct timeval  tv;
    tv.tv_sec = timout;
    tv.tv_usec = 0;
    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);
    nfds = select(fd + 1, &readfds, NULL, NULL, &tv);
    
    if (nfds <= 0)
    {
        if (nfds == 0)
        {
            DBG_WARN("[UART] read timeout!\n");
        }
        
        return (-1);
    }
    
    return(read(fd, (char *)buf, nbytes));
}

sint32 _tb_treadn(int fd, uint8 *buf, uint32 nbytes, unsigned int timout)
{
    uint32      nleft;
    sint32     nread;
    nleft = nbytes;
    
    while (nleft > 0)
    {
        if ((nread = _tb_tread(fd, buf, nleft, timout)) < 0)
        {
            if (nleft == nbytes)
            {
                return(-1); /* error, return -1 */
            }
            else
            {
                break;      /* error, return amount read so far */
            }
        }
        else if (nread == 0)
        {
            break;          /* EOF */
        }
        
        nleft -= nread;
        buf += nread;
    }
    
    return (nbytes - nleft);      /* return >= 0 */
}

sint32 _tb_tsendn(int fd, char *buf, uint32 nbytes, unsigned int timout)
{
	int send_num;
	/*
    sint32 fi;
    fd_set   sendfds;
    struct timeval wt;
    int send_num;
    wt.tv_sec = timout;
    wt.tv_usec = 0;
    FD_ZERO(&sendfds);
    FD_SET(fd, &sendfds);
    fi = select(fd + 1, &sendfds, NULL, NULL, &wt);
    
    if (fi > 0)        // 一直检查串口的可写性
    {
        send_num = write(fd, buf, nbytes);
    }
    else
    {
        if (fi == 0)
        {
            DBG_WARN_0("[UART] port write out of time...");
        }
        else
        {
            DBG_ERRO_0("[UART] port write failed...\n");
            return(-1);
        }
    }
    */
    send_num = write(fd, buf, nbytes);
    
    return(send_num);
}

