#include "system.h"
#include "network.h"

IMU mpu;
SdCard tf;
Pixel led;
// Config g_cfg;       // 全局配置文件
Network g_network;  // 网络连接
FlashFS g_flashCfg; // flash中的文件系统（替代原先的Preferences）
Display screen;     // 屏幕对象
// Ambient ambLight;	// 光线传感器对象

// lvgl handle的锁
SemaphoreHandle_t lvgl_mutex = xSemaphoreCreateMutex();

boolean doDelayMillisTime(unsigned long interval, unsigned long *previousMillis, boolean state)
{
    unsigned long currentMillis = GET_SYS_MILLIS();
    if (currentMillis - *previousMillis >= interval)
    {
        *previousMillis = currentMillis;
        state = !state;
    }
    return state;
}

#include <TFT_eSPI.h>
/*
TFT pins should be set in path/to/Arduino/libraries/TFT_eSPI/User_Setups/Setup24_ST7789.h
*/
TFT_eSPI *tft = new TFT_eSPI(SCREEN_HOR_RES, SCREEN_VER_RES);
