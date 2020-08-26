#include QMK_KEYBOARD_H

enum layer_number {
    _BASE = 0,
    _CFG
};

/* because the leds are south facing and the letters 
 * are on the north side, if we do the map upside down
 * the lighting will be better 
 */
#define LAYOUT_ortho_4x4_inverse( \
	K00, K01, K02, K03, \
	K10, K11, K12, K13, \
	K20, K21, K22, K23, \
	K30, K31, K32, K33  \
) { \
	{ K33,   K32,   K31,   K30 }, \
	{ K23,   K22,   K21,   K20 }, \
	{ K13,   K12,   K11,   K10 }, \
	{ K03,   K02,   K01,   K00 }  \
}

// DEFINE KEYCODES FOR KEYMAP
#define CFG_F4 LT(_CFG, KC_F4)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT_ortho_4x4_inverse(
		KC_F1  , KC_F2  , KC_F3  , CFG_F4 , \
		KC_F5  , KC_F6  , KC_F7  , KC_F8  , \
		KC_F9  , KC_F10 , KC_F11 , KC_F12 , \
		KC_LSFT, KC_LCTL, KC_LALT, KC_DEL   \
	),
	[_CFG] = LAYOUT_ortho_4x4_inverse(
		KC_HOME, KC_UP  , KC_END , _______, \
		KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, \
		RGB_TOG, RGB_SAI, RGB_HUI, XXXXXXX, \
		RGB_MOD, RGB_SAD, RGB_HUD, RESET    \
	),
};
