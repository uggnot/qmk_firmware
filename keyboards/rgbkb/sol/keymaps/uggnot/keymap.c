#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

//#ifdef KEYBOARD_rgbkb_sol_rev1 or #ifdef KEYBOARD_rgbkb_sol_rev2


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _NAV,
    _NUMPAD,
    _F
};

#define NV_ESC  LT(_NAV, KC_ESC)
#define F_TAB   LT(_F, KC_TAB)
#define NP_ENTR LT(_NUMPAD, KC_ENT)
#define NP_SPC  LT(_NUMPAD, KC_SPC)
#define F_ENT   LT(_F, KC_ENT)
#define F_LAYER MO(_F)
#define WIN_BRK LWIN(KC_BRK)
#define LOCK_PC RWIN(KC_L)

enum custom_keycodes {
  RGBRST = SAFE_RANGE,
  RGB_MENU,
  RGB_OLED
};

#define DEFAULT_QWE_L_ENC  RGB_MENU
#define DEFAULT_NAV_L_ENC  _______
#define DEFAULT_NPD_L_ENC  _______
#define DEFAULT_FNC_L_ENC  _______


// TODO: figure out what to map the right encoder push to on all layers but NAV
#define DEFAULT_QWE_R_ENC XXXXXXX
#define DEFAULT_NAV_R_ENC KC_MUTE
#define DEFAULT_NPD_R_ENC XXXXXXX 
#define DEFAULT_FNC_R_ENC XXXXXXX


#define SOL2_L_ENC_QWE  DEFAULT_QWE_L_ENC
#define SOL2_L_ENC_NAV  DEFAULT_NAV_L_ENC
#define SOL2_L_ENC_NPD  DEFAULT_NPD_L_ENC
#define SOL2_L_ENC_FNC  DEFAULT_FNC_L_ENC

#define SOL2_R_ENC_QWE  DEFAULT_QWE_R_ENC
#define SOL2_R_ENC_NAV  DEFAULT_NAV_R_ENC
#define SOL2_R_ENC_NPD  DEFAULT_NPD_R_ENC
#define SOL2_R_ENC_FNC  DEFAULT_FNC_R_ENC

#define SOL1_L_ENC_QWE  DEFAULT_QWE_L_ENC
#define SOL1_L_ENC_NAV  DEFAULT_NAV_L_ENC
#define SOL1_L_ENC_NPD  DEFAULT_NPD_L_ENC
#define SOL1_L_ENC_FNC  DEFAULT_FNC_L_ENC

#define SOL1_R_ENC_QWE  KC_RALT
#define SOL1_R_ENC_NAV  DEFAULT_NAV_R_ENC
#define SOL1_R_ENC_NPD  DEFAULT_NPD_R_ENC
#define SOL1_R_ENC_FNC  DEFAULT_FNC_R_ENC


#define SOL2_L_BTN_QWE  F_LAYER
#define SOL2_L_BTN_NAV  XXXXXXX
#define SOL2_L_BTN_NPD  XXXXXXX
#define SOL2_L_BTN_FNC  F_LAYER

#define SOL2_R_BTN_QWE  KC_RALT
#define SOL2_R_BTN_NAV  KC_RALT
#define SOL2_R_BTN_NPD  KC_P0
#define SOL2_R_BTN_FNC  KC_RALT


#define SOL1_L_BTN_QWE  NP_ENTR
#define SOL1_L_BTN_NAV  XXXXXXX
#define SOL1_L_BTN_NPD  NP_ENTR
#define SOL1_L_BTN_FNC  XXXXXXX

#define SOL1_R_BTN_QWE  NP_ENTR 
#define SOL1_R_BTN_NAV  XXXXXXX
#define SOL1_R_BTN_NPD  NP_ENTR
#define SOL1_R_BTN_FNC  XXXXXXX




#ifdef KEYBOARD_rgbkb_sol_rev2

#define QWE_A  SOL2_L_BTN_QWE
#define NAV_A  SOL2_L_BTN_NAV
#define NPD_A  SOL2_L_BTN_NPD
#define FNC_A  SOL2_L_BTN_FNC

#define QWE_B  SOL2_L_ENC_QWE
#define NAV_B  SOL2_L_ENC_NAV
#define NPD_B  SOL2_L_ENC_NPD
#define FNC_B  SOL2_L_ENC_FNC

#define QWE_C  SOL2_R_ENC_QWE
#define NAV_C  SOL2_R_ENC_NAV
#define NPD_C  SOL2_R_ENC_NPD
#define FNC_C  SOL2_R_ENC_FNC

#define QWE_D  SOL2_R_BTN_QWE
#define NAV_D  SOL2_R_BTN_NAV
#define NPD_D  SOL2_R_BTN_NPD
#define FNC_D  SOL2_R_BTN_FNC


#else

#define QWE_A  SOL1_L_ENC_QWE
#define NAV_A  SOL1_L_ENC_NAV
#define NPD_A  SOL1_L_ENC_NPD
#define FNC_A  SOL1_L_ENC_FNC

#define QWE_B  SOL1_L_BTN_QWE
#define NAV_B  SOL1_L_BTN_NAV
#define NPD_B  SOL1_L_BTN_NPD
#define FNC_B  SOL1_L_BTN_FNC

#define QWE_C  SOL1_R_BTN_QWE
#define NAV_C  SOL1_R_BTN_NAV
#define NPD_C  SOL1_R_BTN_NPD
#define FNC_C  SOL1_R_BTN_FNC

#define QWE_D  SOL1_R_ENC_QWE
#define NAV_D  SOL1_R_ENC_NAV
#define NPD_D  SOL1_R_ENC_NPD
#define FNC_D  SOL1_R_ENC_FNC


#endif
//#ifdef KEYBOARD_rgbkb_sol_rev2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┐        ┌────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      RGB_TOG,          KC_PSCR,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
  //|   ~`   |   !1   |  @2    |  #3    |  $4    |  %5    | |        |        |PrintScr| |  ^6    |  &7    |  *8    |  (9    |  )0    |Backspc |
  //├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┤        ├────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
      F_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_F5,           KC_PAUS,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  //|Ins/Tab |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
  //|  Tab   |   Q    |   W    |   E    |   R    |   T    | |   F5   |        | Pause  | |   Y    |   U    |   I    |   O    |   P    |   |\   |
  //├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┤        ├────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
     NV_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      XXXXXXX,          KC_INS,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  //|Nav/Esc |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
  //|  Esc   |   A    |   S    |   D    |   F    |   G    | |  OLED  |        | Insert | |   H    |   J    |   K    |   L    |   :;   |   "'   |
  //├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┤        ├────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      XXXXXXX,          KC_DEL,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  //| Shift  |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
  //|        |   Z    |   X    |   C    |   V    |   B    | |  OLED  |        |  Del   | |   N    |   M    |   ,<   |   .>   |   /?   | Shift  |
  //├────────┼────────┼────────┼────────┼────────┼────────┘ └────────┘        └────────┘ └────────┼────────┼────────┼────────┼────────┼────────┤
  //|        |        |        |        |        | ┌────────┬────────┐        ┌────────┬────────┐ |        |        |        |        |        |
     KC_LCTL, KC_LWIN, KC_LALT, KC_DEL,   QWE_A,    NP_SPC,   QWE_B,            QWE_C,  KC_SPC,     QWE_D,  KC_RWIN, KC_DOT,  KC_RCTL, KC_ENT, \
  //|        |        |        |        |        | | Numpad |        |        |        |        | |        |        |        |        |        |
  //|  Ctrl  |  Win   |  Alt   |  Del   |        | | Space  |        |        |        | Space  | |        |  Win   |   .>   | Ctrl   | Enter  |
  //└────────┴────────┴────────┴────────┴────────┘ |        ├────────┤        ├────────┤        | └────────┴────────┴────────┴────────┴────────┘
                                                    NP_SPC,  NP_ENTR,          NP_ENTR, KC_SPC \
                                                // | Numpad | Numpad |        | Numpad |        |
                                                // | Space  | Enter  |        | Enter  | Space  |
                                                // └────────┴────────┘        └────────┴────────┘
  ),
[_NAV] = LAYOUT( \
  //┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┐        ┌────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,          XXXXXXX,   XXXXXXX, KC_DEL,  XXXXXXX, KC_MINS, KC_EQL,  _______, \
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
  //|        |        |        |        |        |        | |        |        |        | |        |  DEL   |        |   -_   |   =+   |Backspc |
  //├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┤        ├────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_F2,           KC_WH_U,   KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_LBRC, KC_RBRC, \
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
  //|        |        |        |        |        |        | |   F2   |        |WHEEL UP| |  PGUP  |  HOME  |   UP   |  END   |   [{   |   ]}   |
  //├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┤        ├────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
     _______, C(KC_A), C(KC_S), XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,          KC_WH_D,   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, \
  //|**HELD**|        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
  //|********| Ctrl A | Ctrl S |        |        |        | |  OLED  |        |WHEEL DN| |  PGDN  |  LEFT  |  DOWN  | RIGHT  |        |        |
  //├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┤        ├────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
     _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX,   XXXXXXX,          _______,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS, \
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
  //| Shift  | Ctrl Z | Ctrl X | Ctrl C | Ctrl V |        | |  OLED  |        | Delete | |        |        |        |        |        |CapsLock|
  //├────────┼────────┼────────┼────────┼────────┼────────┘ └────────┘        └────────┘ └────────┼────────┼────────┼────────┼────────┼────────┤
  //|        |        |        |        |        | ┌────────┬────────┐        ┌────────┬────────┐ |        |        |        |        |        |
     _______, _______, _______, _______,  NAV_A,    XXXXXXX,  NAV_B,            NAV_C,  _______,    NAV_D,  _______, XXXXXXX, _______, _______, \
  //|        |        |        |        |        | |        |        |        |        |        | |        |        |        |        |        |
  //|  Ctrl  |  Win   |  Alt   |  Del   |        | |        |        |        |        | Space  | |   Alt  |  Win   |        |  Ctrl  | Enter  |
  //└────────┴────────┴────────┴────────┴────────┘ |        ├────────┤        ├────────┤        | └────────┴────────┴────────┴────────┴────────┘
                                                    XXXXXXX, XXXXXXX,          XXXXXXX, _______ \
                                                // |        |        |        |        |        |
                                                // |        |        |        |        | Space  |
                                                // └────────┴────────┘        └────────┴────────┘
  ),
[_NUMPAD] = LAYOUT( \
  //┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┐        ┌────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
      RESET,  XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,  XXXXXXX,   KC_BSPC,          XXXXXXX,   XXXXXXX, KC_NLCK, KC_PSLS, KC_PAST, KC_PEQL, _______, \
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
  //| Reset  |        |        |        |  DEL   |        | |Backspc |        |        | |        |NUM LOCK|   /    |   *    |   =    |Backspc |
  //├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┤        ├────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
     XXXXXXX, XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP,   XXXXXXX,          XXXXXXX,   XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, XXXXXXX, \
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
  //|        |        |  HOME  |   UP   |  END   |  PGUP  | |        |        |        | |        |   7    |   8    |   9    |   -    |        |
  //├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┤        ├────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
     XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,   XXXXXXX,          XXXXXXX,   XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, XXXXXXX, \
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
  //|        |        |  LEFT  |  DOWN  | RIGHT  |  PGDN  | |  OLED  |        |        | |        |   4    |   5    |   6    |   +    |        |
  //├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┤        ├────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,          _______,   XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, \
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
  //| Shift  |        |        |        |        |        | |  OLED  |        | Delete | |        |   1    |   2    |   3    |  Enter | Shift  |
  //├────────┼────────┼────────┼────────┼────────┼────────┘ └────────┘        └────────┘ └────────┼────────┼────────┼────────┼────────┼────────┤
  //|        |        |        |        |        | ┌────────┬────────┐        ┌────────┬────────┐ |        |        |        |        |        |
     _______, _______, _______, _______,  NPD_A,    _______,  NPD_B,            NPD_C,  KC_P0,      NPD_D,  KC_P0,   KC_PDOT, KC_PENT, _______, \
  //|        |        |        |        |        | |**HELD**|        |        |        |        | |        |        |        |        |        |
  //|  Ctrl  |  Win   |  Alt   |  Del   |        | |********|        |        |        |   0    | |   0    |   0    |   .    |  Enter | Enter  |
  //└────────┴────────┴────────┴────────┴────────┘ |        ├────────┤        ├────────┤        | └────────┴────────┴────────┴────────┴────────┘
                                                    _______, _______,          _______, KC_P0   \
                                                // |**HELD**|**HELD**|        |**HELD**|        |
                                                // |********|********|        |********|   0    |
                                                // └────────┴────────┘        └────────┴────────┘
  ),
 [_F] = LAYOUT( \
  //┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┐        ┌────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,     XXXXXXX,          XXXXXXX,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
  //|   F1   |   F2   |   F3   |   F4   |   F5   |   F6   | |        |        |        | |   F7   |   F8   |   F9   |   F10  |   F11  |   F12  |
  //├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┤        ├────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
     _______, XXXXXXX, XXXXXXX, XXXXXXX, RESET,   XXXXXXX,   RESET,            XXXXXXX,   XXXXXXX, XXXXXXX, KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX,\
  //|**HELD**|        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
  //|********|        |        |        | Reset  |        | | Reset  |        |        | |        |        | Insert |        |        |        |
  //├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┤        ├────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
     XXXXXXX, XXXXXXX, KC_SLCK, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,          XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
  //|        |        |ScrollLk|        |        |        | |        |        |        | |        |        |        |        |        |        |
  //├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┤        ├────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,          XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,\
  //|        |        |        |        |        |        | |        |        |        | |        |        |        |        |        |        |
  //| Shift  |        |        |        |        |        | |        |        |        | |        |        |        |        |        | Shift  |
  //├────────┼────────┼────────┼────────┼────────┼────────┘ └────────┘        └────────┘ └────────┼────────┼────────┼────────┼────────┼────────┤
  //|        |        |        |        |        | ┌────────┬────────┐        ┌────────┬────────┐ |        |        |        |        |        |
     _______, _______, _______, _______,  FNC_A,    XXXXXXX,  FNC_B,            FNC_C,  XXXXXXX,    FNC_D,  XXXXXXX, XXXXXXX, XXXXXXX, _______,\
  //|        |        |        |        |        | |        |        |        |        |        | |        |        |        |        |        |
  //|  Ctrl  |  Win   |  Alt   |  Del   |        | |        |        |        |        |        | |        |        |        |        | Enter  |
  //└────────┴────────┴────────┴────────┴────────┘ |        ├────────┤        ├────────┤        | └────────┴────────┴────────┴────────┴────────┘
                                                    XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX \
                                                // |        |        |        |        |        |
                                                // |        |        |        |        |        |
                                                // └────────┴────────┘        └────────┴────────┘
  )
};

// For RGBRST Keycode
#if defined(RGB_MATRIX_ENABLE)
void rgb_matrix_increase_flags(void)
{
    switch (rgb_matrix_get_flags()) {
        case LED_FLAG_ALL: {
            rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
            rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_UNDERGLOW: {
            rgb_matrix_set_flags(LED_FLAG_NONE);
            rgb_matrix_disable_noeeprom();
            }
            break;
        default: {
            rgb_matrix_set_flags(LED_FLAG_ALL);
            rgb_matrix_enable_noeeprom();
            }
            break;
    }
}

void rgb_matrix_decrease_flags(void)
{
    switch (rgb_matrix_get_flags()) {
        case LED_FLAG_ALL: {
            rgb_matrix_set_flags(LED_FLAG_NONE);
            rgb_matrix_disable_noeeprom();
            }
            break;
        case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
            rgb_matrix_set_flags(LED_FLAG_ALL);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_UNDERGLOW: {
            rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        default: {
            rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
            rgb_matrix_enable_noeeprom();
            }
            break;
    }
}
#endif

#ifdef RGB_OLED_MENU
uint8_t rgb_encoder_state = 4;

typedef void (*rgb_matrix_f)(void);

// rgb_encoder_state tells us which of these pairs of functions will be used.
// clockwise will tell us which of the selected pair to call
const rgb_matrix_f rgb_matrix_functions[6][2] = {
    { rgb_matrix_increase_hue, rgb_matrix_decrease_hue },
    { rgb_matrix_increase_sat, rgb_matrix_decrease_sat },
    { rgb_matrix_increase_val, rgb_matrix_decrease_val },
    { rgb_matrix_increase_speed, rgb_matrix_decrease_speed },
    { rgb_matrix_step, rgb_matrix_step_reverse },
    { rgb_matrix_increase_flags, rgb_matrix_decrease_flags }
};
#endif
#ifdef ENCODER_ENABLE

static pin_t encoders_pad_a[] = ENCODERS_PAD_A;
#define NUMBER_OF_ENCODERS (sizeof(encoders_pad_a)/sizeof(pin_t))

const uint16_t PROGMEM encoders[][NUMBER_OF_ENCODERS * 2][2]  = {
    [_QWERTY] = ENCODER_LAYOUT( \
        KC_WH_U, KC_WH_D,
        KC_VOLD, KC_VOLU
    ),
    [_NAV] = ENCODER_LAYOUT( \
        RGB_OLED, RGB_OLED,
        _______,  _______
    ),
    [_NUMPAD] = ENCODER_LAYOUT( \
        KC_WH_L, KC_WH_R,
        _______, _______
    ),
    [_F] = ENCODER_LAYOUT( \
        KC_VOLD, KC_VOLU,
        _______, _______
    )
};

// for writing out to the oled
static uint16_t last_keycode = 0;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (!is_keyboard_master())
    return;

  uint8_t layer = biton32(layer_state);
  uint16_t keycode = pgm_read_word(&encoders[layer][index][clockwise]);
    
  // loop over the layers to find the first non-transparent keycode
  while (keycode == KC_TRANSPARENT && layer > 0) {
    layer--;
    if ((layer_state & (1 << layer)) != 0) {
        keycode = pgm_read_word(&encoders[layer][index][clockwise]);
    }
  }

#ifdef RGB_OLED_MENU
  if (keycode == RGB_OLED) {
    // if the keycode is the RGB_OLED then translate to the RGB_OLED_MENU
    (*rgb_matrix_functions[rgb_encoder_state][clockwise])();
  } else 
#endif
  if (keycode != KC_TRANSPARENT) {
    // if the keycode is not transparent then send it
    tap_code16(keycode);
  }
  // save the pressed keycode for display
  last_keycode = keycode;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t reset_timer;

  // save the keycode for display on the oled
  last_keycode = keycode;
  switch (keycode) {
    case RGBRST:
#if defined(RGBLIGHT_ENABLE)
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
#elif defined(RGB_MATRIX_ENABLE)
        if (record->event.pressed) {
          eeconfig_update_rgb_matrix_default();
        }
#endif
      return false;
    case RESET:
      if (record->event.pressed) {
          reset_timer = timer_read();
      } else {
          if (timer_elapsed(reset_timer) >= 500) {
              reset_keyboard();
          }
      }
      return false;
#if defined(RGB_MATRIX_ENABLE) && defined(KEYBOARD_rgbkb_sol_rev2)
    case RGB_TOG:
      if (record->event.pressed) {
        rgb_matrix_increase_flags();
      }
      return false;
#endif
    case RGB_MENU:
#ifdef RGB_OLED_MENU
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
          rgb_encoder_state = (rgb_encoder_state - 1);
          if (rgb_encoder_state > 5) {
            rgb_encoder_state = 5;
          }
        } else {
          rgb_encoder_state = (rgb_encoder_state + 1) % 6;
        }
      }
#endif
      return false;
    case RGB_OLED:
      return false;
  }
  return true;
}

// OLED Driver Logic
#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master())
    return OLED_ROTATION_270;
  return rotation;
}

static void render_logo(void) {
  static const char PROGMEM sol_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
  };
  oled_write_P(sol_logo, false);
}

static void render_status(void) {
  // Render to mode icon
  static const char PROGMEM sol_icon[] = {
    0x9b,0x9c,0x9d,0x9e,0x9f,
    0xbb,0xbc,0xbd,0xbe,0xbf,
    0xdb,0xdc,0xdd,0xde,0xdf,0
  };
  oled_write_P(sol_icon, false);

  // Define layers here
  oled_write_P(PSTR("Layer"), false);
  uint8_t layer = layer_state ? biton(layer_state) : biton32(default_layer_state);
  switch (layer) {
    case _QWERTY:
      oled_write_P(PSTR("BASE "), false);
      break;
    case _NAV:
      oled_write_P(PSTR(" NAV "), false);
      break;
    case _NUMPAD:
      oled_write_P(PSTR("NUMPD"), false);
      break;
    case _F:
      oled_write_P(PSTR(" FNC "), false);
      break;
    default:
      oled_write_P(PSTR("UNDEF"), false);
  }

  // write the dividing line between layer and LED status
  oled_write_P(PSTR("-----"), false);

  // Host Keyboard LED Status (all on one line)
  uint8_t led_state = host_keyboard_leds();
  static char lock_str[6] = "     ";
  lock_str[0] = IS_LED_ON(led_state, USB_LED_NUM_LOCK) ? 'N' : ' ';
  lock_str[2] = IS_LED_ON(led_state, USB_LED_CAPS_LOCK) ? 'C' : ' ';
  lock_str[4] = IS_LED_ON(led_state, USB_LED_SCROLL_LOCK) ? 'S' : ' ';
  oled_write(lock_str, false);

#ifdef RGB_OLED_MENU
  // write the dividing line between lock status and rgb menu
  oled_write_P(PSTR("-----"), false);

  // write out the rgb menu
  static char buffer[31] = { 0 };
  snprintf(buffer, sizeof(buffer), "h%3d s%3d v%3d s%3d m%3d e%3d ", rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v, rgb_matrix_config.speed, rgb_matrix_config.mode, rgb_matrix_get_flags());
  buffer[4 + rgb_encoder_state * 5] = '<';
  oled_write(buffer, false);
#endif
  static char line[33];
  itoa(last_keycode, line, 10);
  oled_write_ln(line, false);
  // there is still a little more space on the OLED if you want to display another line of text
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status();
  } else {
    render_logo();
    oled_scroll_left();
  }
}

#endif
