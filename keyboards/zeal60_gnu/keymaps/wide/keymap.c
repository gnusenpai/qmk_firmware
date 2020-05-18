/* Copyright 2018 REPLACE_WITH_YOUR_NAME
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define _______ KC_TRNS
#define FN_BSPC LT(_F1, KC_BSPC)
#define MT_SLSH RSFT_T(KC_SLSH)
#define MT_Z    LSFT_T(KC_Z)
#define CTRL_Z  LCTL(KC_Z)
#define CTRL_X  LCTL(KC_X)
#define CTRL_C  LCTL(KC_C)
#define CTRL_V  LCTL(KC_V)
#define CTRL_BS LCTL(KC_BSPC)

unsigned char gmled = 0;
bool gm = false;

//#ifdef RGB_MATRIX_ENABLE
//extern rgb_config_t rgb_matrix_config;
//#endif

enum my_layers {
	_BL,
    _DH,
    _GM,
	_EL,
	_F1,
	_F2,
	_F3,
    _F4
};

enum my_keycodes {
    QWERTY = SAFE_RANGE,
    COLEDH,
    GM_LED,
    KC_TGM,
    KC_THMB,
    E_Q,
    E_G,
    E_L,
    E_Y,
    E_R,
    E_S,
    E_T,
    E_N,
    E_O,
    E_B
};
/*
typedef struct {
	bool is_press_action;
	int state;
} tap;

enum {
	SINGLE_TAP = 1,
	SINGLE_HOLD = 2,
	DOUBLE_TAP = 3,
	DOUBLE_HOLD = 4,
	DOUBLE_SINGLE_TAP = 5, //send two single taps
	TRIPLE_TAP = 6,
	TRIPLE_HOLD = 7
};

//Tap dance enums
enum {
	TD_F1 = 0
};
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BL] = LAYOUT_all(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_GRV,  KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_SLSH, KC_ENT, \
		FN_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
		KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT, KC_TGM, \
		KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_THMB, MO(_F2), MO(_F3), KC_RCTL \
	),

	[_DH] = LAYOUT_all(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_GRV,  KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
		KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_LBRC, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_SLSH, KC_ENT, \
		FN_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_RBRC, KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
		KC_LSFT, KC_LSFT, KC_X,    KC_C,    KC_D,    KC_V,    KC_Z,    KC_EXLM, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_RSFT, KC_TGM, \
		KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_THMB, MO(_F2), MO(_F3), KC_RCTL \
    ),

	/*[_AR] = LAYOUT_all(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP, _______, \
		_______, _______, _______,                   _______,                            _______, KC_LEFT, KC_DOWN, KC_RGHT \
	),*/

	[_GM] = LAYOUT_all(
		KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
		KC_TAB,  _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_SLSH, KC_ENT, \
		KC_LALT, KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
		_______, KC_LCTL, _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_TGM, \
		_______, _______, _______,                   KC_SPC,                             KC_THMB, KC_LEFT, KC_DOWN, KC_RGHT \
    ),

	[_EL] = LAYOUT_all(
		TO(_BL), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
		KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
		KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
		KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
		KC_NO,   KC_NO, KC_NO,               KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO \
	),

	[_F1] = LAYOUT_all(
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NLCK, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_DEL, \
		KC_CAPS, KC_F24,  _______, _______, _______, _______, KC_RBRC, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_INS,  KC_BSLS, KC_PSCR, \
		_______, KC_LALT, _______, KC_LSFT, KC_LCTL, _______, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  KC_BSPC, \
		_______, _______, CTRL_Z,  CTRL_X,  CTRL_C,  CTRL_V,  _______, _______, CTRL_BS, _______, _______, _______, _______, KC_F24, \
		_______, _______, _______,                   _______,                            _______, _______, _______, _______ \
	),

	[_F2] = LAYOUT_iso_split_bs(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET, \
		_______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, _______, _______, _______, _______, _______, _______, _______, \
		_______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______, _______, \
		_______, _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
		GM_LED,  _______, _______,                   _______,                            _______, _______, _______, _______ \
	),

	[_F3] = LAYOUT_ansi(
		TO(_EL), QWERTY,  COLEDH,  _______, _______, _______, _______, KC_NLCK, KC_PSLS, KC_PAST, _______, _______, _______, _______, \
		_______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______, _______, _______, \
		_______, _______, _______, QWERTY,  COLEDH,  _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______, _______, \
		_______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, \
		_______, _______, _______,                   KC_P0,                              KC_PDOT, MO(_F4), _______, _______ \
	),

    [_F4] = LAYOUT_ansi(
        _______, UC_M_WC, UC_M_LN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, E_Q,     _______, _______, _______, E_B,     _______, _______, E_L,     _______, E_Y,     _______, _______, _______, \
        _______, _______, E_R,     E_S,     E_T,     E_G,     _______, _______, E_N,     _______, _______, E_O,     _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______ \
    )
};

/*
const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	// MACRODOWN only works in this function
	switch(id) {
		case 0:
			if (record->event.pressed) {
				register_code(KC_RSFT);
			} else {
				unregister_code(KC_RSFT);
			}
		break;
	}
	return MACRO_NONE;
};
*/


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	// If console is enabled, it will print the matrix position and status of each key pressed
	#ifdef CONSOLE_ENABLE
	xprintf("KL: row: %u, column: %u, pressed: %u\n", record->event.key.row, record->event.key.col, record->event.pressed);
	#endif

	switch (keycode) {
		case QWERTY:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_BL);
			}
			return false;
			break;
		case COLEDH:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_DH);
			}
			return false;
			break;
        case GM_LED:
            if (record->event.pressed) {
                if (gmled == 6) {
                    gmled = 0;
                } else {
                    gmled = gmled+1;
                }
            }
            return false;
            break;
        case KC_TGM:
            if (record->event.pressed) {
                if (gm == false) {
                    gm = true;
                    layer_on(_GM);
                } else {
                    gm = false;
                    layer_off(_GM);
                }
            }
            return false;
            break;
        case KC_THMB:
            if (gm == true) {
                if (record->event.pressed) {
                    layer_invert(_GM);
                }
            } else {
                if (record->event.pressed) {
                    register_code(KC_RALT);
                } else {
                    unregister_code(KC_RALT);
                }
            }
            return false;
            break;
        case E_Q:
            if (record->event.pressed) {
                send_unicode_hex_string("0028 273F 25E0 203F 25E0 0029");
            }
            return false;
            break;
        case E_G:
            if (record->event.pressed) {
                send_unicode_hex_string("2665 007E 0028 25E0 203F 25D5 273F 0029");
            }
            return false;
            break;
        case E_L:
            if (record->event.pressed) {
                send_unicode_hex_string("0028 0020 0361 00B0 0020 035C 0296 0020 0361 00B0 0029");
            }
            return false;
            break;
        case E_Y:
            if (record->event.pressed) {
                send_unicode_hex_string("10DA 0028 0CA0 76CA 0CA0 0020 10DA 0029");
            }
            return false;
            break;
        case E_R:
            if (record->event.pressed) {
                send_unicode_hex_string("FF0F 0028 2267 2207 2266 0029 FF3C");
            }
            return false;
            break;
        case E_S:
            if (record->event.pressed) {
                send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
            }
            return false;
            break;
        case E_T:
            if (record->event.pressed) {
                send_unicode_hex_string("0398 03CE 03B8");
            }
            return false;
            break;
        case E_N:
            if (record->event.pressed) {
                send_unicode_hex_string("0CA0 005F 0CA0");
            }
            return false;
            break;
        case E_O:
            if (record->event.pressed) {
                send_unicode_hex_string("25D5 03C9 25D5");
            }
            return false;
            break;
        case E_B:
            if (record->event.pressed) {
                send_unicode_hex_string("0064 0028 0020 005E 25C7 005E 0029 0062");
            }
            return false;
            break;
    default:
        return true;
	}
}

#ifdef CONSOLE_ENABLE
void led_set_user(uint8_t usb_led) {
	xprintf("USB_LED: %u\n", usb_led);
}
#endif


#ifdef RGB_MATRIX_ENABLE
void rgb_matrix_indicators_user(void) {
	HSV hsv = { .h = rgb_matrix_config.hsv.h, .s = rgb_matrix_config.hsv.s, .v = rgb_matrix_config.hsv.v };
	RGB rgb = hsv_to_rgb( hsv );
    switch (gmled) {
        case 1:
            rgb_matrix_set_color(17, 255, 255, 255);
            rgb_matrix_set_color(30, 255, 255, 255);
            rgb_matrix_set_color(31, 255, 255, 255);
            rgb_matrix_set_color(32, 255, 255, 255);
            break;
        case 2:
            rgb_matrix_set_color(17, rgb.r, rgb.g, rgb.b);
            rgb_matrix_set_color(30, rgb.r, rgb.g, rgb.b);
            rgb_matrix_set_color(31, rgb.r, rgb.g, rgb.b);
            rgb_matrix_set_color(32, rgb.r, rgb.g, rgb.b);
            break;
        case 3:
            rgb_matrix_set_color(30, 255, 255, 255);
            rgb_matrix_set_color(31, 255, 255, 255);
            rgb_matrix_set_color(32, 255, 255, 255);
            rgb_matrix_set_color(33, 255, 255, 255);
            rgb_matrix_set_color(37, 255, 255, 255);
            rgb_matrix_set_color(38, 255, 255, 255);
            rgb_matrix_set_color(39, 255, 255, 255);
            rgb_matrix_set_color(40, 255, 255, 255);
            break;
        case 4:
            rgb_matrix_set_color(30, rgb.r, rgb.g, rgb.b);
            rgb_matrix_set_color(31, rgb.r, rgb.g, rgb.b);
            rgb_matrix_set_color(32, rgb.r, rgb.g, rgb.b);
            rgb_matrix_set_color(33, rgb.r, rgb.g, rgb.b);
            rgb_matrix_set_color(37, rgb.r, rgb.g, rgb.b);
            rgb_matrix_set_color(38, rgb.r, rgb.g, rgb.b);
            rgb_matrix_set_color(39, rgb.r, rgb.g, rgb.b);
            rgb_matrix_set_color(40, rgb.r, rgb.g, rgb.b);
            break;
        /*case 5:
            #define pinkies 0, 255, 0
            #define ringl 255, 255, 0
            #define midl 255, 127, 0
            #define indl 255, 0, 0
            #define indr 255, 0, 255
            #define midr 0, 0, 255
            #define ringr 0, 255, 255
            rgb_matrix_set_color(6, pinkies);
            rgb_matrix_set_color(43, pinkies);
            rgb_matrix_set_color(25, pinkies);
            rgb_matrix_set_color(49, pinkies);
            rgb_matrix_set_color(52, pinkies);
            rgb_matrix_set_color(5, ringl);
            rgb_matrix_set_color(42, ringl);
            rgb_matrix_set_color(34, ringl);
            rgb_matrix_set_color(4, midl);
            rgb_matrix_set_color(41, midl);
            rgb_matrix_set_color(33, midl);
            rgb_matrix_set_color(3, indl);
            rgb_matrix_set_color(2, indl);
            rgb_matrix_set_color(40, indl);
            rgb_matrix_set_color(39, indl);
            rgb_matrix_set_color(32, indl);
            rgb_matrix_set_color(31, indl);
            rgb_matrix_set_color(0, indr);
            rgb_matrix_set_color(1, indr);
            rgb_matrix_set_color(38, indr);
            rgb_matrix_set_color(46, indr);
            rgb_matrix_set_color(54, indr);
            rgb_matrix_set_color(55, indr);
            rgb_matrix_set_color(23, midr);
            rgb_matrix_set_color(47, midr);
            rgb_matrix_set_color(56, midr);
            rgb_matrix_set_color(24, ringr);
            rgb_matrix_set_color(48, ringr);
            rgb_matrix_set_color(57, ringr);
            break;*/
        case 6:
            rgb_matrix_set_color(0, 0, 0, 0);
            rgb_matrix_set_color(1, 0, 0, 0);
            rgb_matrix_set_color(2, 0, 0, 0);
            rgb_matrix_set_color(3, 0, 0, 0);
            rgb_matrix_set_color(4, 0, 0, 0);
            rgb_matrix_set_color(5, 0, 0, 0);
            rgb_matrix_set_color(6, 0, 0, 0);
            rgb_matrix_set_color(7, 0, 0, 0);
            rgb_matrix_set_color(8, 0, 0, 0);
            rgb_matrix_set_color(9, 0, 0, 0);
            rgb_matrix_set_color(10, 0, 0, 0);
            rgb_matrix_set_color(11, 0, 0, 0);
            rgb_matrix_set_color(12, 0, 0, 0);
            rgb_matrix_set_color(13, 0, 0, 0);
            rgb_matrix_set_color(14, 0, 0, 0);
            rgb_matrix_set_color(15, 0, 0, 0);
            rgb_matrix_set_color(21, 0, 0, 0);
            rgb_matrix_set_color(27, 0, 0, 0);
            rgb_matrix_set_color(28, 0, 0, 0);
            rgb_matrix_set_color(29, 0, 0, 0);
            rgb_matrix_set_color(35, 0, 0, 0);
            rgb_matrix_set_color(41, 0, 0, 0);
            rgb_matrix_set_color(42, 0, 0, 0);
            rgb_matrix_set_color(48, 0, 0, 0);
            rgb_matrix_set_color(49, 0, 0, 0);
            rgb_matrix_set_color(54, 0, 0, 0);
            rgb_matrix_set_color(55, 0, 0, 0);
            rgb_matrix_set_color(56, 0, 0, 0);
            rgb_matrix_set_color(57, 0, 0, 0);
            rgb_matrix_set_color(58, 0, 0, 0);
            rgb_matrix_set_color(59, 0, 0, 0);
            rgb_matrix_set_color(60, 0, 0, 0);
            rgb_matrix_set_color(61, 0, 0, 0);
            rgb_matrix_set_color(62, 0, 0, 0);
            rgb_matrix_set_color(63, 0, 0, 0);
            rgb_matrix_set_color(63, 0, 0, 0);
            rgb_matrix_set_color(64, 0, 0, 0);
            rgb_matrix_set_color(65, 0, 0, 0);
            break;
    }
    /*if (layer_state_is(_AR)) {
        rgb_matrix_set_color(54, 255, 255, 255);
        rgb_matrix_set_color(63, 255, 255, 255);
        rgb_matrix_set_color(64, 255, 255, 255);
        rgb_matrix_set_color(65, 255, 255, 255);
    }*/
    if (gm == true) {
        rgb_matrix_set_color(55, 255, 255, 255);
    }
    if (layer_state_is(_GM)) {
        rgb_matrix_set_color(62, 255, 0, 0);
    }
    if (gm == true && layer_state_is(_BL)) {
        rgb_matrix_set_color(62, 0, 255, 0);
    }
    if (layer_state_is(_F3)) {
        rgb_matrix_set_color(18, 0, 0, 0);
        rgb_matrix_set_color(19, 0, 0, 0);
        rgb_matrix_set_color(20, 0, 0, 0);
        rgb_matrix_set_color(31, 0, 0, 0);
        rgb_matrix_set_color(34, 0, 0, 0);
        rgb_matrix_set_color(45, 0, 0, 0);
        rgb_matrix_set_color(46, 0, 0, 0);
        rgb_matrix_set_color(47, 0, 0, 0);
        switch (biton32(default_layer_state)) {
            case _BL:
                rgb_matrix_set_color(32, 255, 0, 0);
                rgb_matrix_set_color(33, 0, 0, 0);
                break;
            case _DH:
                rgb_matrix_set_color(32, 0, 0, 0);
                rgb_matrix_set_color(33, 0, 255, 0);
                break;
        }
    }
}
#endif

/*
#ifdef RGB_MATRIX_ENABLE
void rgb_matrix_indicators_user(void) {
	HSV hsv1 = { .h = rgb_matrix_config.hue+64,  .s = rgb_matrix_config.sat, .v = rgb_matrix_config.val };
	HSV hsv2 = { .h = rgb_matrix_config.hue+128, .s = rgb_matrix_config.sat, .v = rgb_matrix_config.val };
	HSV hsv3 = { .h = rgb_matrix_config.hue+192, .s = rgb_matrix_config.sat, .v = rgb_matrix_config.val };
	HSV hsv4 = { .h = rgb_matrix_config.hue+212, .s = rgb_matrix_config.sat, .v = rgb_matrix_config.val };
	RGB rgb1 = hsv_to_rgb( hsv1 );
	RGB rgb2 = hsv_to_rgb( hsv2 );
	RGB rgb3 = hsv_to_rgb( hsv3 );
	RGB rgb4 = hsv_to_rgb( hsv4 );
	if (layer_state_is(_F1)) {
		rgb_matrix_set_color(29, rgb1.r, rgb1.g, rgb1.b);
		rgb_matrix_set_color(35, rgb1.r, rgb1.g, rgb1.b);
		rgb_matrix_set_color(60, rgb1.r, rgb1.g, rgb1.b);
		// rgb_matrix_set_color(23, rgb1.r, rgb1.g, rgb1.b);
		// rgb_matrix_set_color(47, rgb1.r, rgb1.g, rgb1.b);
		// rgb_matrix_set_color(48, rgb1.r, rgb1.g, rgb1.b);
		// rgb_matrix_set_color(49, rgb1.r, rgb1.g, rgb1.b);
	}
	if (layer_state_is(_F2)) {
		rgb_matrix_set_color(29, rgb2.r, rgb2.g, rgb2.b);
		rgb_matrix_set_color(35, rgb2.r, rgb2.g, rgb2.b);
		rgb_matrix_set_color(60, rgb2.r, rgb2.g, rgb2.b);
	}
	if (layer_state_is(_F3)) {
		rgb_matrix_set_color(29, rgb3.r, rgb3.g, rgb3.b);
		rgb_matrix_set_color(35, rgb3.r, rgb3.g, rgb3.b);
		rgb_matrix_set_color(60, rgb3.r, rgb3.g, rgb3.b);
	}
	if (layer_state_is(_NU)) {
		rgb_matrix_set_color(29, rgb4.r, rgb4.g, rgb4.b);
		rgb_matrix_set_color(35, rgb4.r, rgb4.g, rgb4.b);
		rgb_matrix_set_color(60, rgb4.r, rgb4.g, rgb4.b);
	}
}
#endif
*/

/*
int cur_dance (qk_tap_dance_state_t *state) {
	if (state->count == 1) {
		return SINGLE_HOLD;
	}
	if (state->count == 2) {
		return DOUBLE_HOLD;
	}
	if (state->count == 3) {
		return TRIPLE_HOLD;
	}
	else return 8; //magic number.
}

//instanalize an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {
	.is_press_action = true,
	.state = 0
};

void x_finished (qk_tap_dance_state_t *state, void *user_data) {
	xtap_state.state = cur_dance(state);
	switch (xtap_state.state) {
		case SINGLE_HOLD: layer_on(_F1); break;
		case DOUBLE_HOLD: layer_on(_NU); break;
	}
}

void x_reset (qk_tap_dance_state_t *state, void *user_data) {
	switch (xtap_state.state) {
		case SINGLE_HOLD: layer_off(_F1); break;
		case DOUBLE_HOLD: layer_off(_NU); break;
	}
	xtap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_F1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset)
};
*/
