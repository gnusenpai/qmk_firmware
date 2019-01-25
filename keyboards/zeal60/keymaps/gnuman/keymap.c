// Default layout for Zeal60
#include QMK_KEYBOARD_H

#include "rgb_backlight.h"
extern backlight_config g_config;

#define _______ KC_TRNS
#define CTLBSPC LCTL(KC_BSPC)
#define FN_BSPC LT(_F1, KC_BSPC)

enum my_layers {
	_BL,
	_CM,
	_DH,
	_DHA,
	_DV,
	_EL,
	_F1,
	_F2,
	_F3
};

enum my_keycodes {
	QWERTY = SAFE_RANGE,
	COLEMAK,
	COLEDH,
	COLEDHA,
	DVORAK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BL] = LAYOUT_60_ansi(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
		FN_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
		KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_LALT, MO(_F2), MO(_F3), KC_RCTL
	),

	[_CM] = LAYOUT_60_ansi(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
		KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
		FN_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, KC_ENT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
		KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_LALT, MO(_F2), MO(_F3), KC_RCTL
	),

	[_DH] = LAYOUT_60_ansi(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
		KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
		FN_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, KC_ENT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
		KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_LALT, MO(_F2), MO(_F3), KC_RCTL
	),

	[_DHA] = LAYOUT_60_ansi(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
		KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
		FN_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, KC_ENT,
		KC_LSFT, KC_X,    KC_C,    KC_D,    KC_V,    KC_Z,    KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
		KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_LALT, MO(_F2), MO(_F3), KC_RCTL
	),

	[_DV] = LAYOUT_60_ansi(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC, KC_BSPC,
		KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,  KC_BSLS,
		FN_BSPC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS, KC_ENT,
		KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
		KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_LALT, MO(_F2), MO(_F3), KC_RCTL
	),

	[_EL] = LAYOUT_60_ansi(
		TO(_BL), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO,   KC_NO, KC_NO,               KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO
	),

	[_F1] = LAYOUT_60_ansi(
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
		KC_CAPS, _______, _______, _______, _______, _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_INS,  _______, KC_NLCK, KC_PSCR,
		_______, _______, _______, _______, _______, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  _______, _______,
		_______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, CTLBSPC, _______, _______, KC_UP,   _______,
		_______, _______, _______,                   _______,                            KC_LEFT, KC_DOWN, KC_RGHT, _______
	),

	[_F2] = LAYOUT_60_ansi(
		_______, EF_DEC,  EF_INC,  H1_DEC,  H1_INC,  H2_DEC,  H2_INC,  _______, _______, _______, _______, BR_DEC,  BR_INC,  RESET,
		_______, _______, _______, S1_DEC,  S1_INC,  S2_DEC,  S2_INC,  _______, _______, _______, _______, ES_DEC,  ES_INC,  DEBUG,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______,                            _______,                   _______, _______, _______, _______
	),

	[_F3] = LAYOUT_60_ansi(
		TO(_EL), _______, _______, _______, _______, _______, _______, KC_NLCK, KC_PSLS, KC_PAST, _______, _______, _______, _______,
		_______, _______, _______, _______, COLEDH,  _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______, _______, _______,
		_______, _______, DVORAK,  QWERTY,  COLEMAK, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______, _______,
		_______, _______, _______, _______, COLEDHA, _______, KC_PDOT, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______,
		_______, _______, _______,                   KC_P0,                              KC_PDOT, _______, _______, _______
	)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case QWERTY:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_BL);
			}
			return false;
			break;
		case COLEMAK:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_CM);
			}
			return false;
			break;
		case COLEDH:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_DH);
			}
			return false;
			break;
		case COLEDHA:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_DHA);
			}
			return false;
			break;
		case DVORAK:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_DV);
			}
			return false;
			break;
		default:
			return true;
	}
}

void backlight_indicators_user(void) {
	HS hs1 = { .h = g_config.color_1.h+64,  .s = g_config.color_1.s };
	HS hs2 = { .h = g_config.color_1.h+128, .s = g_config.color_1.s };
	HS hs3 = { .h = g_config.color_1.h+192, .s = g_config.color_1.s };
	if (layer_state_is(_F1)) {
		backlight_effect_indicators_set_colors(36, hs1);
	}
	if (layer_state_is(_F2)) {
		backlight_effect_indicators_set_colors(36, hs2);
	}
	if (layer_state_is(_F3)) {
		backlight_effect_indicators_set_colors(36, hs3);
	}
}
