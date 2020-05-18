#include "gnuman.h"

/*#ifdef GNU_UNDERGLOW
extern unsigned char user_config.umode;
#endif*/

__attribute__((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DF_PRI:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_PRIMARY);
            }
            return false;
            break;
        case DF_SEC:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_SECONDARY);
            }
            return false;
            break;
        case KC_VER:  // Prints firmware version
            if (record->event.pressed) {
                send_string_with_delay_P(PSTR(QMK_KEYBOARD ":" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE), 10);
            }
            return false;
            break;
#ifdef GNU_UNDERGLOW
        case UG_OFF:
            if (record->event.pressed) {
                user_config.umode = 0;
                eeconfig_update_user(user_config.raw);
            }
            return false;
            break;
        case UG_SOLD:
            if (record->event.pressed) {
                user_config.umode = 1;
                eeconfig_update_user(user_config.raw);
            }
            return false;
            break;
        case UG_WHIT:
            if (record->event.pressed) {
                user_config.umode = 2;
                eeconfig_update_user(user_config.raw);
            }
            return false;
            break;
        case UG_BREA:
            if (record->event.pressed) {
                user_config.umode = 3;
                eeconfig_update_user(user_config.raw);
            }
            return false;
            break;
        case UG_HUE:
            if (record->event.pressed) {
                user_config.umode = 4;
                eeconfig_update_user(user_config.raw);
            }
            return false;
            break;
        case UG_CYLR:
            if (record->event.pressed) {
                user_config.umode = 5;
                eeconfig_update_user(user_config.raw);
            }
            return false;
            break;
#endif
#ifdef UNICODE_ENABLE
        case UC_THUMBSUP:
            if (record->event.pressed) {
                send_unicode_hex_string("0064 0028 0020 005E 25C7 005E 0029 0062");
            }
            return false;
            break;
        case UC_GIVEHEART:
            if (record->event.pressed) {
                send_unicode_hex_string("2665 007E 0028 25E0 203F 25D5 273F 0029");
            }
            return false;
            break;
        case UC_LENNY:
            if (record->event.pressed) {
                send_unicode_hex_string("0028 0020 0361 00B0 0020 035C 0296 0020 0361 00B0 0029");
            }
            return false;
            break;
        case UC_WHAT:
            if (record->event.pressed) {
                send_unicode_hex_string("0CA0 005F 0CA0");
            }
            return false;
            break;
        case UC_OWO:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    send_unicode_hex_string("0028 0020 24DB 0020 03C9 0020 24DB 0020 002A 0029");
                } else {
                    send_unicode_hex_string("25D5 03C9 25D5");
                }
            }
            return false;
            break;
        case UC_KAWAII:
            if (record->event.pressed) {
                send_unicode_hex_string("0028 273F 25E0 203F 25E0 0029");
            }
            return false;
            break;
        case UC_RART:
            if (record->event.pressed) {
                send_unicode_hex_string("FF0F 0028 2267 2207 2266 0029 FF3C");
            }
            return false;
            break;
        case UC_SHRUG:
            if (record->event.pressed) {
                send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
            }
            return false;
            break;
        case UC_THOTH:
            if (record->event.pressed) {
                send_unicode_hex_string("0398 03CE 03B8");
            }
            return false;
            break;
        case UC_ANGRY:
            if (record->event.pressed) {
                send_unicode_hex_string("10DA 0028 0CA0 76CA 0CA0 0020 10DA 0029");
            }
            return false;
            break;
        case UC_DESPAIR:
            if (record->event.pressed) {
                send_unicode_hex_string("0028 0B87 FE4F 0B87 0060 FF61 0029");
            }
            return false;
            break;
        case UC_SUCC:
            if (record->event.pressed) {
                send_unicode_hex_string("0028 22B9 3064 2022 06DD 2022 22B9 0029 3064");
            }
            return false;
            break;
        case UC_OOF:
            if (record->event.pressed) {
                send_unicode_hex_string("0028 02C3 0336 1DC4 FE3F 0E4F FF09");
            }
            return false;
            break;
        case UC_TWOOWO:
            if (record->event.pressed) {
                send_unicode_hex_string("0028 2667 25D1 03C9 25D1 0029 261E 2661 261C 0028 25D0 03C9 25D0 2667 0029");
            }
            return false;
            break;
#endif
        case RGB_TOG:
            if (record->event.pressed) {
                switch (rgb_matrix_get_flags()) {
                    case LED_FLAG_ALL: {
                        rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
                        rgb_matrix_set_color_all(0, 0, 0);
                    }
                    break;
                    case LED_FLAG_KEYLIGHT: {
                        rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                        rgb_matrix_set_color_all(0, 0, 0);
                    }
                    break;
#ifdef GNU_UNDERGLOW
                    case LED_FLAG_UNDERGLOW: {
                        rgb_matrix_set_flags(LED_FLAG_NONE);
                        rgb_matrix_disable_noeeprom();
                    }
                    break;
#endif
                    default: {
                        rgb_matrix_set_flags(LED_FLAG_ALL);
                        rgb_matrix_enable_noeeprom();
                    }
                    break;
                }
            }
            return false;
    }
    return process_record_keymap(keycode, record);
}
