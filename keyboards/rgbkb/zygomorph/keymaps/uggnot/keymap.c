#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

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
#define WIN_BRK LWIN(KC_BRK)
#define LOCK_PC RWIN(KC_L)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*  / QWERTY \
   * /-----------------------------------------\  /-----------------------------------------\
   * |   `  |  1   |  2   |  3   |  4   |  5   |  |  6   |  7   |  8   |  9   |  0   | BkSp |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * |F Tab |   Q  |   W  |   E  |   R  |   T  |  |   Y  |   U  |   I  |   O  |   P  |   \  |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * |NV ESC|   A  |   S  |   D  |   F  |   G  |  |   H  |   J  |   K  |   L  |   ;  |   '  |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * |Shift |   Z  |   X  |   C  |   V  |   B  |  |   N  |   M  |   ,  |   .  |   /  |Shift |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * | Ctrl |  Win |  Alt |  Del |FEnter|Np Spc|  |Np Spc|  Alt |  Win |   .  | Ctrl |Enter |
   * \------+------+------+------+------+------/  \------+------+------+------+------+------/
   */
  [_QWERTY] = LAYOUT_ortho_5x12( \
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC, \
    F_TAB  , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS, \
    NV_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,     KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, \
    KC_LCTL, KC_LGUI, KC_LALT, KC_DEL , F_ENT  , NP_SPC ,     NP_SPC , KC_RALT, KC_RGUI, KC_DOT , KC_RCTL, KC_ENT \
  ),

  /*  / NAV \
   * /-----------------------------------------\  /-----------------------------------------\
   * |      |      |      |      |      |      |  |      |      |      |  -   |  =   | BkSp |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * |      |      |      |      |      |      |  | PgUp | Home |  Up  | End  |   [  |  ]   |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * |      |      |      |      |      |      |  | PgDn | Left | Down | Right|      |      |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * |Shift |   Z  |   X  |   C  |   V  |      |  |      |      |      |      |      |Shift |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * | Ctrl |  Win |  Alt |  Del |      | Space|  | Space|  Alt | Win  |      | Ctrl |Enter |
   * \------+------+------+------+------+------/  \------+------+------+------+------+------/
   */
  [_NAV] = LAYOUT_ortho_5x12( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_DEL , XXXXXXX, KC_MINS, KC_EQL , _______, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_PGUP, KC_HOME, KC_UP  , KC_END , KC_LBRC, KC_RBRC, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, \
    _______, _______, _______, _______, _______, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, _______, _______, _______, XXXXXXX, KC_SPC ,     KC_SPC , _______, _______, XXXXXXX, _______, _______ \
  ),

  /*  / Numpad \
   * /-----------------------------------------\  /-----------------------------------------\
   * |      |      |      |      |      |      |  |      | NumLk|  *   |  /   |  =   |_BkSp_|
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * |      |      | Home |  Up  |  End | PgUp |  |      |  7   |  8   |  9   |  -   |      |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * |      |      | Left | Down | Right| PgDn |  |      |  4   |  5   |  6   |  +   |      |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * |_Shift|      |      |      |      |      |  |      |  1   |  2   |  3   | Enter|_Shift|
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * |_Ctrl_|__Win_|__Alt_|__Del_|      |-HELD-|  |-HELD-|  0   |  0   |  .   | Enter|_Enter|
   * \------+------+------+------+------+------/  \------+------+------+------+------+------/
   */
  [_NUMPAD] = LAYOUT_ortho_5x12( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_NLCK, KC_PAST, KC_PSLS, KC_PEQL, _______, \
    XXXXXXX, XXXXXXX, KC_HOME, KC_UP  , KC_END , KC_PGUP,     XXXXXXX, KC_P7  , KC_P8  , KC_P9  , KC_PMNS, XXXXXXX, \
    XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,     XXXXXXX, KC_P4  , KC_P5  , KC_P6  , KC_PPLS, XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_P1  , KC_P2  , KC_P3  , KC_PENT, _______, \
    _______, _______, _______, _______, XXXXXXX, _______,     _______, KC_P0  , KC_P0  , KC_PDOT, KC_PENT, _______ \
  ),

  /*  / F \
   * /-----------------------------------------\  /-----------------------------------------\
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * |-HELD-|  Tab | Hue+ | Sat+ | Brt+ |RGBTog|  |      |      |Insert|      |PrntSc|      |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * |CapsLk|      | Hue- | Sat- | Brt- |RGBMod|  |      |      |      |LockPC|      |      |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * | Shift|      |      |      |      |WinBrk|  |      |      |      |      |      | Shift|
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * | Ctrl |  Win |  Alt |      |-HELD-| Reset|  |      |  Alt |  Win |      | Ctrl |      |
   * \------+------+------+------+------+------/  \------+------+------+------+------+------/
   */
  [_F] = LAYOUT_ortho_5x12( \
    KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,     KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , \
    _______, KC_TAB , RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG,     XXXXXXX, XXXXXXX, KC_INS , XXXXXXX, KC_PSCR, XXXXXXX, \
    KC_CAPS, XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, RGB_MOD,     XXXXXXX, XXXXXXX, XXXXXXX, LOCK_PC, XXXXXXX, XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, WIN_BRK,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, _______, _______, XXXXXXX, _______, RESET  ,     XXXXXXX, _______, _______, XXXXXXX, _______, XXXXXXX \
  )

};
