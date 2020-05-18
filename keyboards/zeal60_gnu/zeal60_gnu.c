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
#include "zeal60_gnu.h"

#ifdef RGB_MATRIX_ENABLE
const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |      G location
 *   |  |      |      B location
 *   |  |      |      | */
	{0, C8_8,  C7_8, C6_8},   // LA17 ESC
	{0, C9_8,  C7_7, C6_7},   // LA16 1
	{0, C9_7,  C8_7, C6_6},   // LA15 2
	{0, C9_6,  C8_6, C7_6},   // LA14 3
	{0, C9_5,  C8_5, C7_5},   // LA13 4
	{0, C9_4,  C8_4, C7_4},   // LA12 5
	{0, C9_3,  C8_3, C7_3},   // LA11 6
	{0, C9_2,  C8_2, C7_2},   // LA10 7
	{0, C9_1,  C8_1,  C7_1},  // LA9  8
	{0, C2_9,  C3_9,  C4_9},  // LB0  9
	{0, C1_9,  C3_10, C4_10}, // LB1  0
	{0, C1_10, C2_10, C4_11}, // LB2  MINS
	{0, C1_11, C2_11, C3_11}, // LB3  EQL
	{0, C1_12, C2_12, C3_12}, // LB4  BSPC / Left BSPC
	{0, C1_13, C2_13, C3_13}, // LB5  Right BSPC
	{0, C1_7,  C2_7, C3_7},   // LA7  Tab
	{0, C1_6,  C2_6, C3_6},   // LA6  Q
	{0, C1_5,  C2_5, C3_5},   // LA5  W
	{0, C1_4,  C2_4, C3_4},   // LA4  E
	{0, C1_3,  C2_3, C3_3},   // LA3  R
	{0, C1_2,  C2_2, C4_3},   // LA2  T
	{0, C1_1,  C3_2, C4_2},   // LA1  Y
	{0, C2_1,  C3_1,  C4_1},  // LA0  U
	{0, C9_9,  C8_9,  C7_9},  // LB9  I
	{0, C9_10, C8_10, C7_10}, // LB10 O
	{0, C9_11, C8_11, C7_11}, // LB11 P
	{0, C9_12, C8_12, C7_12}, // LB12 LBRC
	{0, C9_13, C8_13, C7_13}, // LB13 RBRC
	{0, C9_14, C8_14, C7_14}, // LB14 BSLS / ENT
	{0, C1_8,  C2_8, C3_8},   // LA8  CAPS
	{1, C9_6,  C8_6, C7_6},   // LC14 A
	{1, C9_5,  C8_5, C7_5},   // LC13 S
	{1, C9_4,  C8_4, C7_4},   // LC12 D
	{1, C9_3,  C8_3, C7_3},   // LC11 F
	{1, C9_2,  C8_2, C7_2},   // LC10 G
	{1, C9_1,  C8_1,  C7_1},  // LC9  H
	{1, C2_9,  C3_9,  C4_9},  // LD0  J
	{1, C1_9,  C3_10, C4_10}, // LD1  K
	{1, C1_10, C2_10, C4_11}, // LD2  L
	{1, C1_11, C2_11, C3_11}, // LD3  SCLN
	{1, C1_12, C2_12, C3_12}, // LD4  QUOT
	{1, C1_13, C2_13, C3_13}, // LD5  ENT / NUHS
	{1, C9_8,  C7_7, C6_7},   // LC16 LSFT
	{1, C9_7,  C8_7, C6_6},   // LC15 NUBS
	{1, C1_5,  C2_5, C3_5},   // LC5  Z
	{1, C1_4,  C2_4, C3_4},   // LC4  X
	{1, C1_3,  C2_3, C3_3},   // LC3  C
	{1, C1_2,  C2_2, C4_3},   // LC2  V
	{1, C1_1,  C3_2, C4_2},   // LC1  B
	{1, C9_9,  C8_9,  C7_9},  // LD9  N
	{1, C9_10, C8_10, C7_10}, // LD10 M
	{1, C9_11, C8_11, C7_11}, // LD11 COMM
	{1, C9_12, C8_12, C7_12}, // LD12 DOT
	{1, C1_14, C2_14, C3_14}, // LD6  SLSH
	{1, C1_15, C2_15, C3_15}, // LD7  RSFT
	{1, C1_16, C2_16, C3_16}, // LD8  FN
	{1, C8_8,  C7_8, C6_8},   // LC17 LCTL
	{1, C1_8,  C2_8, C3_8},   // LC8  LGUI
	{1, C1_7,  C2_7, C3_7},   // LC7  LALT
	{1, C1_6,  C2_6, C3_6},   // LC6  SPC (Left Stabilizer)
	{1, C2_1,  C3_1,  C4_1},  // LC0  SPC
	{1, C9_13, C8_13, C7_13}, // LD13 SPC (6.5u Right Stabilizer)
	{1, C9_14, C8_14, C7_14}, // LD14 RALT / SPC (7.5u Right Stabilizer)
	{1, C9_15, C8_15, C6_14}, // LD15 RGUI
	{1, C9_16, C7_15, C6_15}, // LD16 MENU
	{1, C8_16, C7_16, C6_16}, // LD17 RCTL

	//{0, C1_14, C2_14, C3_14}, // LB6
	//{0, C1_15, C2_15, C3_15}, // LB7
	//{0, C1_16, C2_16, C3_16}, // LB8
	//{0, C9_15, C8_15, C6_14}, // LB15
	//{0, C9_16, C7_15, C6_15}, // LB16
	//{0, C8_16, C7_16, C6_16}, // LB17
};

#define XX NO_LED
led_config_t g_led_config = { {
    { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13},
    {15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28},
    {29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 14},
    {42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55},
    {56, 57, 58, 59, XX, XX, XX, 60, XX, 61, 62, 63, 64, 65}
}, {
    {0,0},  {16,0},  {32,0},  {48,0},  {64,0},  {80,0},  {96,0},   {112,0},  {128,0},  {144,0},  {160,0},  {176,0},  {192,0},  {216,0},  {224,0},
    {4,16}, {24,16}, {40,16}, {56,16}, {72,16}, {88,16}, {104,16}, {120,16}, {136,16}, {152,16}, {168,16}, {184,16}, {200,16}, {220,16},
    {4,32}, {28,32}, {44,32}, {60,32}, {76,32}, {92,32}, {108,32}, {124,32}, {140,32}, {156,32}, {172,32}, {188,32}, {214,32},
    {2,48}, {20,48}, {36,48}, {52,48}, {68,48}, {84,48}, {100,48}, {116,48}, {132,48}, {148,48}, {164,48}, {180,48}, {210,48}, {224,48},
    {3,64}, {23,64}, {43,64}, {60,64},                             {102,64},           {144,64}, {161,64}, {181,64}, {201,64}, {221,64}
}, {
#ifdef RGB_MATRIX_WIDEMODS
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 4, 4, 4, 4, 4, 1, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 1, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 1, 1, 4, 4, 4, 4, 4, 1,
    1, 1, 1, 4,          4,    4, 4, 1, 1, 1
#else
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 0,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 0,
    1, 1, 1, 4,          4,    4, 1, 1, 1, 1
#endif
} };

void suspend_power_down_kb(void)
{
	rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_kb(void)
{
	rgb_matrix_set_suspend_state(false);
}
#endif

void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up

	matrix_init_user();
}

void matrix_scan_kb(void) {
	// put your looping keyboard code here
	// runs every cycle (a lot)

	matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
	// put your per-action keyboard code here
	// runs for every action, just before processing by the firmware

	return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
	// put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

	led_set_user(usb_led);
}
