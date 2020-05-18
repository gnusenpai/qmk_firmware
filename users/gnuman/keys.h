#pragma once

#define LT_NAV   LT(_NAV, KC_BSPC)
#define LT_TNUM  LT(_NUM, KC_ESC)
#define LT_TSYM  LT(_SYM, KC_ENTER)
#define OS_LAYR  OSL(_LAYER)
#define OS_UC    OSL(_UNICODE)
#define MO_OPT   MO(_OPTION)
#define MO_UC    MO(_UNICODE)
#define TG_UC    TG(_UNICODE)
#define TO_EMP   TO(_EMPTY)
#define TO_PRI   TO(_PRIMARY)
#define TO_GAME  TO(_GAME)
#define KC_WBSPC LCTL(KC_BSPC)
#define KC_SFTSL RSFT_T(KC_SLSH)

enum userspace_keycodes {
    DF_PRI = SAFE_RANGE,
    DF_SEC,
    KC_VER,
    UG_OFF,
    UG_SOLD,
    UG_WHIT,
    UG_BREA,
    UG_HUE,
    UG_CYLR,
#ifdef UNICODE_ENABLE
    UC_THUMBSUP,
    UC_GIVEHEART,
    UC_LENNY,
    UC_WHAT,
    UC_OWO,
    UC_KAWAII,
    UC_RART,
    UC_SHRUG,
    UC_THOTH,
    UC_ANGRY,
    UC_DESPAIR,
    UC_SUCC,
    UC_OOF,
    UC_TWOOWO,
#endif
    KEYMAP_RANGE
};
