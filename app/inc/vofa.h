#ifndef _VOFA_H_
#define _VOFA_H_

#include "board.h"
#include <stdint.h>

// 配置区域 ------------------------------------------------------
#define VOFA_CHANNELS 4  // 默认通道数
#define VOFA_SCI_BASE SCIB_BASE // 替换为实际使用的串口


// C28x 中 float 是 32-bit，对应 2 个 16-bit word
// 帧尾由 4 个 8-bit 字节组成 (0x00 0x00 0x80 0x7F)
// 在 C28x 中，这占用 2 个 16-bit word
typedef struct
{
    float fdata[VOFA_CHANNELS]; // 32-bit float
    uint16_t tail[2];           // 存储 4 个字节的帧尾
} VOFA_Frame_t;

extern VOFA_Frame_t vofa_frame;

// 初始化VOFA
void VOFA_Init(void);

// 设置单个通道数据
void VOFA_SetChannel(uint16_t channel, float value);

// 设置所有通道数据
void VOFA_SetAllChannels(float values[]);

// 发送数据到VOFA+ (针对 SCI 串口)
void VOFA_Send(void);

#endif
