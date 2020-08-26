/*
Copyright 2018 Cole Markham

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

#define _______ KC_TRNS

enum custom_keycodes {
  BL = SAFE_RANGE,
  WK_RED,
  WK_GREEN,
  WK_BLUE,
  LY_NUMPAD,
  LY_ARROWS
};

enum layer_number {
  _ARROWS = 0,
  _NUMPAD,
  _RGB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_ARROWS] = LAYOUT(
    KC_INS        , KC_PSCR       , KC_PGUP       , LY_NUMPAD,
    KC_DEL        , KC_PAUS       , KC_PGDN       , MO(_RGB),
    XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX,
    KC_HOME       , KC_UP         , KC_END        , KC_ENT,
    KC_LEFT       , KC_DOWN       , KC_RGHT       , KC_ENT
  ),
  [_NUMPAD] = LAYOUT(
    KC_NLCK       , KC_PSLS       , KC_PAST       , LY_ARROWS,
    KC_P7         , KC_P8         , KC_P9         , KC_PMNS,
    KC_P4         , KC_P5         , KC_P6         , KC_PPLS,
    KC_P1         , KC_P2         , KC_P3         , KC_ENT,
    KC_P0         , KC_P0         , KC_PDOT       , KC_ENT
  ),
  [_RGB] = LAYOUT(
    RESET         , RGB_TOG       , RGB_MOD       , RGB_MODE_KNIGHT,
    RGB_MODE_SWIRL, RGB_MODE_PLAIN, RGB_MODE_SNAKE, _______,
    RGB_MODE_XMAS , XXXXXXX       , XXXXXXX       , XXXXXXX,
    RGB_HUI       , RGB_SAI       , RGB_VAI       , XXXXXXX,
    RGB_HUD       , RGB_SAD       , RGB_VAD       , XXXXXXX
  )

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  return MACRO_NONE ;
}



void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool retval = true;
  switch (keycode) {
    case LY_NUMPAD:
      if (record->event.pressed) {
        layer_on(_NUMPAD);
	layer_off(_ARROWS);
	rgblight_mode_noeeprom(1);
        rgblight_sethsv_noeeprom_red();
      }
      retval = false;
      break;
    case LY_ARROWS:
      if (record->event.pressed) {
        layer_on(_ARROWS);
        layer_off(_NUMPAD);
        rgblight_mode_noeeprom(1);
	rgblight_sethsv_noeeprom_green();
      }
      retval = false;
      break;
  }
  return retval;
  /*
  switch (keycode) {
    case BL:
      if (record->event.pressed) {
#ifdef BACKLIGHT_ENABLE
        backlight_step();
#endif
      }
      retval = false;
      break;
    case WK_RED:
      if (record->event.pressed) {
        rgblight_show_solid_color(0xFF, 0, 0);
      } else {
        rgblight_show_solid_color(0xFF, 0xFF, 0xFF);
      }
      retval = false;
      break;
    case WK_GREEN:
      if (record->event.pressed) {
        rgblight_show_solid_color(0, 0xFF, 0);
      } else
        rgblight_show_solid_color(0xFF, 0xFF, 0xFF);
      }
      retval = false;
      break;
    case WK_BLUE:
      if (record->event.pressed) {
        rgblight_show_solid_color(0, 0, 0xFF);
      } else {
        rgblight_show_solid_color(0xFF, 0xFF, 0xFF);
      }
      retval = false;
      break;
  }
  return retval;
  */
}

void led_set_user(uint8_t usb_led) {

  if (usb_led & (1 << USB_LED_NUM_LOCK)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_CAPS_LOCK)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_COMPOSE)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_KANA)) {

  } else {

  }

}
