#ifndef APP_WEATHER_UI_H
#define APP_WEATHER_UI_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "info.h"
#include "lvgl.h"

#define WAIT_ANIM                   \
    while (lv_anim_count_running()) \
        lv_task_handler(); // 等待动画完成
    void appWeatherUiInit();
    void appWeatherUiDisplayBasicInit(lv_scr_load_anim_t animType);
    void appWeatherUiDisplayBasic(struct Weather weaInfo, lv_scr_load_anim_t animType);
    void appWeatherUiDisplayDetailInit(lv_scr_load_anim_t animType);
    void appWeatherUiDisplayDetail(struct Weather weaInfo, lv_scr_load_anim_t animType);
    void appWeatherUiDelete();

    extern const lv_img_dsc_t icon_weather;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif