#ifndef APP_PAGES_UI_H
#define APP_PAGES_UI_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"

#define WAIT_ANIM                   \
    while (lv_anim_count_running()) \
        lv_task_handler(); // 等待动画完成
    void appFileUiInit();
    void appFileUiDisplayImage(const char *path, lv_scr_load_anim_t animType);
    void appFileUiDisplayText(const char *path, lv_scr_load_anim_t animType);
    void appFileUiDisplayVideo(const char *path, lv_scr_load_anim_t animType);
    void appFileUiDisplayAudio(const char *path, lv_scr_load_anim_t animType);
    void appFileUiDisplayOther(const char *path, lv_scr_load_anim_t animType);
    void appFileUiDelete();

    extern const lv_img_dsc_t icon_file;

#ifdef __cplusplus
} /* extern "C" */
#endif

//

#ifdef __cplusplus
extern "C"
{
#endif

#define LV_FILE_EXPLORER_PATH_MAX_LEN 128
#define FILE_EXPLORER_HEAD_HEIGHT 60
#define FILE_EXPLORER_QUICK_ACCESS_AREA_WIDTH 22
#define FILE_EXPLORER_BROWSER_AREA_WIDTH 78

    typedef enum
    {
        LV_EXPLORER_SORT_KIND,
        LV_EXPLORER_SORT_NAME,
    } lv_file_explorer_sort_t;

    typedef struct
    {
        lv_obj_t obj;
        lv_obj_t *cont;
        lv_obj_t *head_area;
        lv_obj_t *browser_area;
        lv_obj_t *file_list;
        lv_obj_t *quick_access_ctrl_btn;
        lv_obj_t *path_label;
        char *sel_fp;
        char cur_path[LV_FILE_EXPLORER_PATH_MAX_LEN];
    } lv_file_explorer_t;

    lv_obj_t *lv_file_explorer_create(lv_obj_t *parent);
    void lv_file_explorer_set_sort(lv_obj_t *obj, lv_file_explorer_sort_t sort);
    char *lv_file_explorer_get_sel_fn(lv_obj_t *obj);
    char *lv_file_explorer_get_cur_path(lv_obj_t *obj);
    lv_obj_t *lv_file_explorer_get_head_area(lv_obj_t *obj);
    lv_obj_t *lv_file_explorer_get_path_obj(lv_obj_t *obj);
    lv_obj_t *lv_file_explorer_get_file_list(lv_obj_t *obj);
    void lv_file_explorer_open_dir(lv_obj_t *obj, char *dir);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif