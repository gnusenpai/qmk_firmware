#pragma once

#define LAYOUT_base_wrapper(...) LAYOUT_base(__VA_ARGS__)
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

#define ________________XXXXXXX________________    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
#define _________________TRANS_________________    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#ifdef GNU_ORTHO
#define SLSH KC_SLSH
#else
#define SLSH KC_SFTSL
#endif

#define _______________QWERTY_L1_______________    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _______________QWERTY_L2_______________    KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _______________QWERTY_L3_______________    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _______________QWERTY_R1_______________    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _______________QWERTY_R2_______________    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _______________QWERTY_R3_______________    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _____________COLEMAK_DHM_L1____________    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define _____________COLEMAK_DHM_L2____________    KC_A,    KC_R,    KC_S,    KC_T,    KC_G

#ifdef GNU_ORTHO
#define _____________COLEMAK_DHM_L3____________    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V
#else
#define _____________COLEMAK_DHM_L3____________    KC_X,    KC_C,    KC_D,    KC_V,    KC_Z
#endif

#define _____________COLEMAK_DHM_R1____________    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _____________COLEMAK_DHM_R2____________    KC_M,    KC_N,    KC_E,    KC_I,    KC_O
#define _____________COLEMAK_DHM_R3____________    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH

#define ______________NUMBER_LEFT______________    KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ______________NUMBER_RIGHT_____________    KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _______________FUNC_LEFT_______________    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _______________FUNC_RIGHT______________    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define ________________GAME_R1________________    KC_1,    KC_2,    KC_W,    KC_3,    KC_4
#define ________________GAME_R2________________    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_R
#define ________________GAME_R3________________    KC_LCTL, KC_Q,    KC_X,    KC_E,    KC_F

#define _________________NAV_L1________________    _________________TRANS_________________
#define _________________NAV_L2________________    OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL), _______
#define _________________NAV_L3________________    _________________TRANS_________________

#define _________________NAV_R1________________    KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______
#define _________________NAV_R2________________    KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,KC_DEL
#define _________________NAV_R3________________    _______, KC_WBSPC,_______, _______, _______

#define _________________NUM_L1________________    _______________FUNC_LEFT_______________
#define _________________NUM_L2________________    KC_1,    KC_2,    KC_3,    KC_4,    KC_6
#define _________________NUM_L3________________    KC_8,    KC_9,    KC_0,    KC_5,    KC_7

#define _________________NUM_R1________________    _______________FUNC_RIGHT______________
#define _________________NUM_R2________________    KC_F11,  KC_7,    KC_8,    KC_9,    KC_0
#define _________________NUM_R3________________    KC_F12,  KC_6,    KC_COMM, KC_DOT,  XXXXXXX

#define _________________SYM_L1________________    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________SYM_L2________________    KC_GRV,  KC_LPRN, KC_RPRN, KC_MINS, KC_EQL
#define _________________SYM_L3________________    XXXXXXX, KC_LBRC, KC_RBRC, KC_EXLM, KC_PLUS

#define _________________SYM_R1________________    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN
#define _________________SYM_R2________________    XXXXXXX, KC_UNDS, KC_PIPE, KC_TILD, XXXXXXX
#define _________________SYM_R3________________    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS

#ifdef GNU_ORTHO
#define _______________OPTION_L1_______________    RGB_SAI, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI
#define _______________OPTION_L2_______________    RGB_SAD, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD
#define _______________OPTION_L3_______________    XXXXXXX, RGB_TOG, DF_SEC,  DF_PRI,  KC_VER
#else
#define _______________OPTION_L1_______________    RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI
#define _______________OPTION_L2_______________    RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD
#define _______________OPTION_L3_______________    RGB_TOG, DF_SEC,  DF_PRI,  KC_VER,  XXXXXXX
#endif

#define _______________OPTION_R1_______________    XXXXXXX, KC_CLCK, KC_SLCK, KC_NLCK, XXXXXXX
#define _______________OPTION_R2_______________    XXXXXXX, UG_OFF,  UG_SOLD, UG_WHIT, UG_BREA
#define _______________OPTION_R3_______________    XXXXXXX, DF_PRI,  DF_SEC,  UG_HUE,  UG_CYLR

#ifdef UNICODE_ENABLE
#define _______________UNICODE_L1______________    XXXXXXX, UC_WHAT, UC_OOF, XXXXXXX, UC_THUMBSUP
#define _______________UNICODE_L2______________    UC_ANGRY, UC_RART, UC_SHRUG, UC_TWOOWO, UC_GIVEHEART
#define _______________UNICODE_L3______________    XXXXXXX, XXXXXXX, UC_SUCC, UC_DESPAIR, XXXXXXX
#define _______________UNICODE_R1______________    XXXXXXX, UC_LENNY, XXXXXXX, XXXXXXX, XXXXXXX
#define _______________UNICODE_R2______________    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UC_OWO
#define _______________UNICODE_R3______________    UC_KAWAII, UC_THOTH, XXXXXXX, XXXXXXX, XXXXXXX
#endif

#ifdef MIDI_ENABLE
#define _______________MIDI_LVEL_______________    MI_VEL_1, MI_VEL_2, MI_VEL_3, MI_VEL_4, MI_VEL_5
#define _______________MIDI_RVEL_______________    MI_VEL_6, MI_VEL_7, MI_VEL_8, MI_VEL_9, MI_VEL_10
#define ________________MIDI_L1________________    XXXXXXX, MI_Cs, MI_Ds, XXXXXXX, MI_Fs
#define ________________MIDI_L2________________    MI_C, MI_D, MI_E, MI_F, MI_G
#define ________________MIDI_L3________________    MI_OCTD, MI_OCTU, MI_MODSD, MI_MODSU, XXXXXXX
#define ________________MIDI_R1________________    MI_Gs, MI_As, XXXXXXX, MI_Cs_1, MI_Ds_1
#define ________________MIDI_R2________________    MI_A, MI_B, MI_C_1, MI_D_1, MI_E_1
#define ________________MIDI_R3________________    XXXXXXX, XXXXXXX, MI_TRNSD, MI_TRNSU, MI_TRNS_0
#endif
