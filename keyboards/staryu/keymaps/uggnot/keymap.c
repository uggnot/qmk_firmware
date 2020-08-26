/*
Copyright 2018 Kenneth Aloysius

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "../../backlight_staryu.h"

enum custom_keycodes {
  TAKE_THEIRS = SAFE_RANGE,
  TAKE_MINE,
};

enum layers {
  _LAYER0
};

#define LY_PAGE MO(_PGUPDN)
#define LY_RGB LT(_RGB, KC_PGUP)
const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    /* Keymap 0
     * ,------------------------------.
     * |             | Enter | Ctrl-A |
     * |-------------+-------+--------|
     * |Ctrl-Shift-R |Ctrl-S | Ctrl-W |
     * `------------------------------'
     */
    LAYOUT( 
                       KC_ENT ,  KC_Y, \
           TAKE_MINE,  A(KC_F4), TAKE_THEIRS \
    )
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  return MACRO_NONE ;
}

void take(uint16_t toSend);

void take(uint16_t toSend) {
	tap_code16(KC_ENT);
	SEND_STRING(SS_DELAY(500));

	tap_code16(C(KC_A));
	SEND_STRING(SS_DELAY(200));

        tap_code16(C(S(toSend)));
	SEND_STRING(SS_DELAY(200));

	tap_code16(C(KC_S));

	SEND_STRING(SS_DELAY(200));
	tap_code16(C(KC_W));
  
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TAKE_THEIRS:
      if (record->event.pressed) {
        // when pressed
	take(KC_R);
/*	tap_code16(KC_ENT);
	SEND_STRING(SS_DELAY(500));

	tap_code16(C(KC_A));
	SEND_STRING(SS_DELAY(200));

        tap_code16(C(S(KC_R)));
	SEND_STRING(SS_DELAY(200));
	tap_code16(C(KC_S));
	SEND_STRING(SS_DELAY(200));
	tap_code16(C(KC_W));*/
      } else {
        // when keycode released
      }
      break;
    case TAKE_MINE:
      if (record->event.pressed) {
        // when pressed
	take(KC_L);
/*	tap_code16(KC_ENT);
	SEND_STRING(SS_DELAY(500));

	tap_code16(C(KC_A));
	SEND_STRING(SS_DELAY(200));

        tap_code16(C(S(KC_L)));
	SEND_STRING(SS_DELAY(200));

	tap_code16(C(KC_S));

	SEND_STRING(SS_DELAY(200));
	tap_code16(C(KC_W)); */
      } else {
        // when keycode released
      }
      break;


  }
  return true;
};
void matrix_init_user(void) {
	rgblight_enable();
}

void matrix_scan_user(void) {
}

void led_set_user(uint8_t usb_led) {
}
