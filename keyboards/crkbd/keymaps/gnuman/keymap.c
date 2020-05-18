#include QMK_KEYBOARD_H
#include "gnuman.h"

enum crkbd_keycodes {
    RUNE = KEYMAP_RANGE,
};

#ifdef TAP_DANCE_ENABLE
enum tap_dances {
    TD_ESC = 0
};
#define KC_TDESC TD(TD_ESC)
#endif

#define KC_GAMQ LT(_SECONDARY, KC_Z)
#define KC_GAML LT(_GAMEL, KC_C)
#define KC_GUIV LGUI_T(KC_V)

#define KC_RUNE RUNE
#define KC_UOFF UOFF
#define KC_UHUE UHUE
#define KC_UBRE UBRE
#define KC_UWHI UWHI

#define \
    LAYOUT_base( \
        K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
        K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
        K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
    ) \
    LAYOUT_wrapper( \
    /* ┌───────┬───────┬───────┬───────┬───────┬───────┐                  ┌───────┬───────┬───────┬───────┬───────┬───────┐ */ \
         KC_TAB,    K01,    K02,    K03,    K04,    K05,                       K06,    K07,    K08,    K09,    K0A,KC_MINS,    \
    /* ├───────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┤ */ \
         LT_NAV,    K11,    K12,    K13,    K14,    K15,                       K16,    K17,    K18,    K19,    K1A,KC_QUOT,    \
    /* ├───────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┤ */ \
        KC_LCTL,    K21,    K22,    K23,    K24,    K25,                       K26,    K27,    K28,    K29,    K2A,OS_LAYR,    \
    /* └───────┴───────┴───────┴───────┼───────┼───────┼───────┐  ┌───────┼───────┼───────┼───────┴───────┴───────┴───────┘ */ \
                                        KC_LGUI,LT_TNUM,KC_LSFT,    KC_SPC,LT_TSYM,KC_LALT                                     \
    /*                                 └───────┴───────┴───────┘  └───────┴───────┴───────┘                                 */ \
    )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_PRIMARY] = LAYOUT_base_wrapper(
        _____________COLEMAK_DHM_L1____________, _____________COLEMAK_DHM_R1____________,
        _____________COLEMAK_DHM_L2____________, _____________COLEMAK_DHM_R2____________,
        _____________COLEMAK_DHM_L3____________, _____________COLEMAK_DHM_R3____________
    ),

    [_GAME] = LAYOUT_wrapper(
    // ┌───────┬───────┬───────┬───────┬───────┬───────┐                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
         KC_ESC,________________GAME_R1________________,                   ________________XXXXXXX________________,XXXXXXX,
    // ├───────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┤
        KC_GAMQ,________________GAME_R2________________,                   ________________XXXXXXX________________,XXXXXXX,
    // ├───────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┤
        KC_LALT,________________GAME_R3________________,                   ________________XXXXXXX________________, TO_PRI,
    // └───────┴───────┴───────┴───────┼───────┼───────┼───────┐  ┌───────┼───────┼───────┼───────┴───────┴───────┴───────┘
                                        KC_GUIV,KC_GAML, KC_SPC,   XXXXXXX,XXXXXXX,XXXXXXX
    //                                 └───────┴───────┴───────┘  └───────┴───────┴───────┘
    ),

    [_SECONDARY] = LAYOUT_base_wrapper(
        _______________QWERTY_L1_______________, _______________QWERTY_R1_______________,
        _______________QWERTY_L2_______________, _______________QWERTY_R2_______________,
        _______________QWERTY_L3_______________, _______________QWERTY_R3_______________
    ),

    [_EMPTY] = LAYOUT_wrapper(
    // ┌───────┬───────┬───────┬───────┬───────┬───────┐                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
        XXXXXXX,________________XXXXXXX________________,                   ________________XXXXXXX________________, TO_PRI,
    // ├───────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┤
        XXXXXXX,________________XXXXXXX________________,                   ________________XXXXXXX________________,XXXXXXX,
    // ├───────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┤
        XXXXXXX,________________XXXXXXX________________,                   ________________XXXXXXX________________,XXXXXXX,
    // └───────┴───────┴───────┴───────┼───────┼───────┼───────┐  ┌───────┼───────┼───────┼───────┴───────┴───────┴───────┘
                                        XXXXXXX,XXXXXXX,XXXXXXX,   XXXXXXX,XXXXXXX,XXXXXXX
    //                                 └───────┴───────┴───────┘  └───────┴───────┴───────┘
    ),

    [_GAMEL] = LAYOUT_wrapper(
    // ┌───────┬───────┬───────┬───────┬───────┬───────┐                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
         KC_GRV,______________NUMBER_LEFT______________,                   _______________QWERTY_R1_______________,XXXXXXX,
    // ├───────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┤
        KC_CLCK,______________NUMBER_RIGHT_____________,                   _______________QWERTY_R2_______________,XXXXXXX,
    // ├───────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┤
        XXXXXXX,________________XXXXXXX________________,                   _______________QWERTY_R3_______________, TO_PRI,
    // └───────┴───────┴───────┴───────┼───────┼───────┼───────┐  ┌───────┼───────┼───────┼───────┴───────┴───────┴───────┘
                                        XXXXXXX,XXXXXXX,XXXXXXX,   XXXXXXX,XXXXXXX,XXXXXXX
    //                                 └───────┴───────┴───────┘  └───────┴───────┴───────┘
    ),

    [_LAYER] = LAYOUT_wrapper(
    // ┌───────┬───────┬───────┬───────┬───────┬───────┐                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
         TO_PRI,________________XXXXXXX________________,                   ________________XXXXXXX________________, TO_EMP,
    // ├───────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┤
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,TO_GAME,XXXXXXX,                   XXXXXXX,KC_RUNE,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    // ├───────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┤
        XXXXXXX,________________XXXXXXX________________,                   ________________XXXXXXX________________, TO_PRI,
    // └───────┴───────┴───────┴───────┼───────┼───────┼───────┐  ┌───────┼───────┼───────┼───────┴───────┴───────┴───────┘
                                        XXXXXXX,XXXXXXX,XXXXXXX,   XXXXXXX,XXXXXXX,XXXXXXX
    //                                 └───────┴───────┴───────┘  └───────┴───────┴───────┘
    ),

    [_NAV] = LAYOUT_wrapper(
    // ┌───────┬───────┬───────┬───────┬───────┬───────┐                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
        _______,_________________NAV_L1________________,                   _________________NAV_R1________________,_______,
    // ├───────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┤
        _______,_________________NAV_L2________________,                   _________________NAV_R2________________,_______,
    // ├───────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┤
        _______,_________________NAV_L3________________,                   _________________NAV_R3________________,_______,
    // └───────┴───────┴───────┴───────┼───────┼───────┼───────┐  ┌───────┼───────┼───────┼───────┴───────┴───────┴───────┘
                                        _______, KC_SPC,_______,   _______,_______,_______
    //                                 └───────┴───────┴───────┘  └───────┴───────┴───────┘
    ),

    [_NUM] = LAYOUT_wrapper(
    // ┌───────┬───────┬───────┬───────┬───────┬───────┐                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
         RESET ,_________________NUM_L1________________,                   _________________NUM_R1________________,_______,
    // ├───────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┤
        _______,_________________NUM_L2________________,                   _________________NUM_R2________________,_______,
    // ├───────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┤
        _______,_________________NUM_L3________________,                   _________________NUM_R3________________,_______,
    // └───────┴───────┴───────┴───────┼───────┼───────┼───────┐  ┌───────┼───────┼───────┼───────┴───────┴───────┴───────┘
                                        _______,_______,_______,   _______,_______,_______
    //                                 └───────┴───────┴───────┘  └───────┴───────┴───────┘
    ),

    [_SYM] = LAYOUT_wrapper( 
    // ┌───────┬───────┬───────┬───────┬───────┬───────┐                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
        _______,_________________SYM_L1________________,                   _________________SYM_R1________________, RESET ,
    // ├───────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┤
        _______,_________________SYM_L2________________,                   _________________SYM_R2________________,_______,
    // ├───────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┤
        _______,_________________SYM_L3________________,                   _________________SYM_R3________________,_______,
    // └───────┴───────┴───────┴───────┼───────┼───────┼───────┐  ┌───────┼───────┼───────┼───────┴───────┴───────┴───────┘
                                        _______,_______,_______,   _______,_______,_______
    //                                 └───────┴───────┴───────┘  └───────┴───────┴───────┘
    ),

    [_OPTION] = LAYOUT_wrapper( 
    // ┌───────┬───────┬───────┬───────┬───────┬───────┐                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
        XXXXXXX,_______________OPTION_L1_______________,                   _______________OPTION_R1_______________,XXXXXXX,
    // ├───────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┤
        XXXXXXX,_______________OPTION_L2_______________,                   _______________OPTION_R2_______________,XXXXXXX,
    // ├───────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┤
        KC_LCTL,_______________OPTION_L3_______________,                   _______________OPTION_R3_______________,KC_RCTL,
    // └───────┴───────┴───────┴───────┼───────┼───────┼───────┐  ┌───────┼───────┼───────┼───────┴───────┴───────┴───────┘
                                        _______,_______,_______,   _______,_______,_______
    //                                 └───────┴───────┴───────┘  └───────┴───────┴───────┘
    )
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    } else {
        return OLED_ROTATION_270;
    }
}

static uint32_t   oled_timer       = 0;
static char       keylog_str[6]    = {};
static uint16_t   log_timer        = 0;
static const char code_to_name[60] = {' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};
/*static const char PROGMEM code_to_name[0xFF] = {
//   0    1    2    3    4    5    6    7    8    9    A    B    c    D    E    F
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',  // 0x
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2',  // 1x
    '3', '4', '5', '6', '7', '8', '9', '0',  20,  19,  27,  26,  22, '-', '=', '[',  // 2x
    ']','\\', '#', ';','\'', '`', ',', '.', '/', 128, ' ', ' ', ' ', ' ', ' ', ' ',  // 3x
    ' ', ' ', ' ', ' ', ' ', ' ', 'P', 'S', ' ', ' ', ' ', ' ',  16, ' ', ' ', ' ',  // 4x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 5x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 6x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 7x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 8x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 9x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Ax
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Bx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Cx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Dx
    'C', 'S', 'A', 'C', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Ex
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '        // Fx
};*/

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    for (uint8_t i = 4; i > 0; --i) {
        keylog_str[i] = keylog_str[i - 1];
    }

    if (keycode < 60) {
        keylog_str[0] = code_to_name[keycode];
    }

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        add_keylog(0);
    }
}

static void render_status(void) {
    static const char PROGMEM emptyline[] = {""};
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layr:"), false);
    switch (biton32(layer_state)) {
        case _PRIMARY:
            switch (biton32(default_layer_state)) {
                case _PRIMARY:
                    oled_write_P(PSTR(" CLMK"), false);
                    break;
                case _SECONDARY:
                    oled_write_P(PSTR(" QWRT"), false);
                    break;
            }
            break;
        case _EMPTY:
            oled_write_P(PSTR(" EMPT"), false);
            break;
        case _GAME:
            oled_write_P(PSTR(" GAME"), false);
            break;
        case _GAMEL:
            oled_write_P(PSTR(" GM-L"), false);
            break;
        case _LAYER:
            oled_write_P(PSTR(" LYRS"), false);
            break;
        case _NAV:
            oled_write_P(PSTR(" NAV "), false);
            break;
        case _NUM:
            oled_write_P(PSTR(" NUM "), false);
            break;
        case _SYM:
            oled_write_P(PSTR(" SYM "), false);
            break;
        case _OPTION:
            oled_write_P(PSTR(" OPTN"), false);
            break;
        default:
            oled_write_P(PSTR("UNDEF"), false);
    }

    oled_write_ln_P(emptyline, false);

    // Show Mod
    uint8_t modifiers = get_mods() | get_oneshot_mods();

    oled_write_P(PSTR("Mods:"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));

    oled_write_ln_P(emptyline, false);
    oled_write_ln_P(emptyline, false);
    oled_write_ln_P(emptyline, false);
    oled_write_ln_P(emptyline, false);
    oled_write_ln_P(emptyline, false);
    oled_write_ln_P(emptyline, false);
    //oled_write_ln_P(PSTR(" owo "), false);
    oled_write_ln_P(emptyline, false);
    oled_write_ln_P(emptyline, false);
    oled_write_ln_P(emptyline, false);
    oled_write_ln_P(emptyline, false);

    oled_write(keylog_str, false);
}

static void render_logo(void) {
    /*static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };*/

    static const char PROGMEM korune_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x20,0x20,0x20,0x20,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0x20,0x20,0x20,0x20,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0x20,0x20,0x20,0x20,0
    };

    oled_write_P(korune_logo, false);
}

void oled_task_user(void) {
    update_log();
    if (is_keyboard_master()) {
        render_status();
    } else {
        render_logo();
        oled_scroll_left();
    }
}
#endif

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _NUM, _SYM, _OPTION);
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RUNE:
            if (record->event.pressed) {
                SEND_STRING("xxx");
                layer_off(_LAYER);
            }
            return false;
            break;
    }
#ifdef OLED_DRIVER_ENABLE
    if (record->event.pressed) {
        oled_timer = timer_read32();
        add_keylog(keycode);
    }
#endif
    return true;
}

#ifdef TAP_DANCE_ENABLE
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_TAB)
};
#endif

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode) {
    switch (keycode) {
        case LT_TNUM:
        case LT_TSYM:
        return 200;
    default:
        return TAPPING_TERM;
    }
}
#endif
