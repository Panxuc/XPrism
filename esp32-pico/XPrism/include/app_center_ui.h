#ifndef APP_CENTER_UI_H
#define APP_CENTER_UI_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"

#define ANIEND_WAIT                 \
    while (lv_anim_count_running()) \
        lv_task_handler(); // 等待动画完成

    void app_control_gui_init(void);
    void app_control_gui_release(void);
    void display_app_scr_init(const void *src_img, const char *app_name);
    void app_control_display_scr(const void *src_img, const char *app_name,
                                 lv_scr_load_anim_t anim_type, bool force);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif