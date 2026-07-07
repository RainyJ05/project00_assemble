#include "vofa.h"

VOFA_Frame_t vofa_frame;

// VOFA初始化函数
void VOFA_Init(void)
{
    // 初始化帧尾: 0x00, 0x00, 0x80, 0x7F
    // C28x 内存布局 (小端模式处理):
    vofa_frame.tail[0] = 0x0000; // 对应前两个字节 0x00, 0x00
    vofa_frame.tail[1] = 0x7F80; // 对应后两个字节 0x80, 0x7F (注意高低位)

    // 清零所有通道
    uint16_t i;
    for (i = 0; i < VOFA_CHANNELS; i++)
    {
        vofa_frame.fdata[i] = 0.0f;
    }
}

// 设置单个通道数据
void VOFA_SetChannel(uint16_t channel, float value)
{
    if (channel < VOFA_CHANNELS)
    {
        vofa_frame.fdata[channel] = value;
    }
}

// 设置所有通道数据
void VOFA_SetAllChannels(float values[])
{
    uint16_t i;
    for (i = 0; i < VOFA_CHANNELS; i++)
    {
        vofa_frame.fdata[i] = values[i];
    }
}

/**
 * 辅助函数：通过 SCI 发送一个字节 (8-bit)
 */
static void SCI_SendByte(uint16_t b)
{
//    while (SciaRegs.SCIFFTX.bit.TXFFST != 0); // 等待发送 FIFO 有空间
//    SciaRegs.SCITXBUF.all = (b & 0xFF);       // 只取低 8 位
    SCI_writeCharBlockingFIFO(VOFA_SCI_BASE, b);
}

// 发送数据到VOFA+ (JustFloat 协议: 数据 + 0x00 0x00 0x80 0x7F)
void VOFA_Send(void)
{
    uint16_t i;
    uint32_t *pRawData;
    uint32_t temp;

    // 1. 发送浮点数据
    for (i = 0; i < VOFA_CHANNELS; i++)
    {
        // 将 float 指针转为 uint32 指针以进行位操作
        pRawData = (uint32_t *)&vofa_frame.fdata[i];
        temp = *pRawData;

        // C28x 发送必须拆分为 4 个 8-bit 字节
        SCI_SendByte(temp & 0xFF);         // Byte 0
        SCI_SendByte((temp >> 8) & 0xFF);  // Byte 1
        SCI_SendByte((temp >> 16) & 0xFF); // Byte 2
        SCI_SendByte((temp >> 24) & 0xFF); // Byte 3
    }

    // 2. 发送帧尾 (0x00, 0x00, 0x80, 0x7F)
    SCI_SendByte(0x00);
    SCI_SendByte(0x00);
    SCI_SendByte(0x80);
    SCI_SendByte(0x7F);
}

