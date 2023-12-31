#ifndef APP_FILE_UI_H
#define APP_FILE_UI_H

enum FileUiType
{
    FILE_UI_TYPE_EXPLORER,
    FILE_UI_TYPE_IMAGE,
    FILE_UI_TYPE_VIDEO,
    FILE_UI_TYPE_TEXT,
};

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"

#define ANIEND_WAIT                 \
    while (lv_anim_count_running()) \
        lv_task_handler(); // 等待动画完成

    void appFileUiInit();
    void appFileUiDisplayExplorerInit(const char *path, const char *file1Name,
                                      const char *file2Name, const char *file3Name,
                                      int temp, lv_scr_load_anim_t animType);
    void appFileUiDisplayExplorer(const char *path, const char *file1Name,
                                  const char *file2Name, const char *file3Name,
                                  int temp, lv_scr_load_anim_t animType, bool force);
    void appFileUiDisplayImageInit(lv_scr_load_anim_t animType);
    void appFileUiDisplayImage(const char *fileName, lv_scr_load_anim_t animType);
    void appFileUiDisplayVideoInit(lv_scr_load_anim_t animType);
    void appFileUiDisplayVideo(const char *fileName, lv_scr_load_anim_t animType);
    void appFileUiDisplayTextInit(unsigned char *text, int page,
                                  lv_scr_load_anim_t animType);
    void appFileUiDisplayText(unsigned char *text, int page,
                              lv_scr_load_anim_t animType, bool force);
    void appFileUiDelete();

    extern const lv_img_dsc_t icon_file;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif