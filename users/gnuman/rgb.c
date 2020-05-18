#include "gnuman.h"
#include "rgb_matrix.h"
#include "lib/lib8tion/lib8tion.h"

/*#ifdef GNU_UNDERGLOW
#if defined(KEYBOARD_massdrop_alt)
    unsigned char umode = 0;
#else
    unsigned char umode = 1;
#endif
#endif*/

void rgb_matrix_set_color_flag(HSV hsv, uint8_t led_type) {
    RGB rgb = hsv_to_rgb(hsv);
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], led_type)) {
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
}

__attribute__((weak))
void rgb_matrix_indicators_keymap(void) {};

void rgb_matrix_indicators_user(void) {
#ifdef GNU_UNDERGLOW
    HSV      hsvon  = {rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, GNU_UNDERGLOW_MAXIMUM_BRIGHTNESS};
    HSV      hsvspd = {rgb_matrix_config.hsv.h + rgb_matrix_config.speed, rgb_matrix_config.hsv.s, GNU_UNDERGLOW_MAXIMUM_BRIGHTNESS};
    //HSV      hsvwht = {0, 0, GNU_UNDERGLOW_MAXIMUM_BRIGHTNESS};
    uint8_t  time   = scale16by8(g_rgb_counters.tick, rgb_matrix_config.speed / 4);
    uint16_t timeb  = scale16by8(g_rgb_counters.tick, rgb_matrix_config.speed / 8);

    switch (user_config.umode) {
        case 0:
            break;
        case 1:
            rgb_matrix_set_color_flag(hsvon, LED_FLAG_UNDERGLOW);
            break;
        case 2:
            rgb_matrix_set_color_flag(hsvspd, LED_FLAG_UNDERGLOW);
            break;
        /*case 2:
            rgb_matrix_set_color_flag(hsvwht, LED_FLAG_UNDERGLOW);
            break;*/
        case 3:
            hsvon.v = scale8(abs8(sin8(timeb) - 128) * 2, hsvon.v);
            rgb_matrix_set_color_flag(hsvon, LED_FLAG_UNDERGLOW);
            break;
        case 4:
            hsvon.h = time;
            rgb_matrix_set_color_flag(hsvon, LED_FLAG_UNDERGLOW);
            break;
        case 5:
            for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
                if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
                    hsvon.h = g_led_config.point[i].x - time;
                    RGB rgb = hsv_to_rgb(hsvon);
                    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                }
            }
            break;
    }
#endif
    return rgb_matrix_indicators_keymap();
}
