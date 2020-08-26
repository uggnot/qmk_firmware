#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum layer_number {
    _QWERTY = 0,
    _NAV_F,
    _NUMPAD,
    _KB_CONTROL
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NAVF,
  NUMPAD,
  KBCTRL,
  RGBRST,
  DYNAMIC_MACRO_RANGE,
};


//tap dance declarations
enum tap_dance_codes {
  TD_LEFT_SHIFT = 0
};


void dance_start__left_shift (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    //on single tap it's shift
    register_code (KC_LSFT);
  } else if (state->count==2) {
    // on double tap it's shift & ctrl
    register_code (KC_LSFT);
    register_code (KC_LCTL);
  } else {
    // on triple tap it's caps lock
    register_code (KC_CAPS);
  }
}

void dance_stop__left_shift (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    //on single tap it's shift
    unregister_code (KC_LSFT);
  } else if (state->count==2) {
    // on double tap it's shift & ctrl
    unregister_code (KC_LSFT);
    unregister_code (KC_LCTL);
  } else {
    // on triple tap it's caps lock
    unregister_code (KC_CAPS);
  }
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
 [TD_LEFT_SHIFT] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_start__left_shift, dance_stop__left_shift)
// Other declarations would go here, separated by commas, if you have them
};

// DEFINE KEYCODES FOR KEYMAP
#define TD_S_CS TD(TD_LEFT_SHIFT)
#define NV_ESC  LT(_NAV_F, KC_ESC)
#define NP_ENTR LT(_NUMPAD, KC_ENT)
#define NP_DEL  LT(_NUMPAD, KC_DEL)
#define M_CAD   LCA(KC_DEL)
#define M_LOCK  RWIN(KC_L)
#define S_ENT   MT(MOD_RSFT, KC_ENT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //|        |        |        |        |        |        |                          |        |        |        |        |        |        |
  //|   ~`   |   !1   |  @2    |  #3    |  $4    |  %5    |                          |  ^6    |  &7    |  *8    |  (9    |  )0    |Backspc |
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //|        |        |        |        |        |        |                          |        |        |        |        |        |        |
  //|  Tab   |   Q    |   W    |   E    |   R    |   T    |                          |   Y    |   U    |   I    |   O    |   P    |   |\   |
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     NV_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //|NavLayer|        |        |        |        |        |                          |        |        |        |        |        |        |
  //|  Esc   |   A    |   S    |   D    |   F    |   G    |                          |   H    |   J    |   K    |   L    |   :;   |   "'   |
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TD_S_CS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LWIN,          NP_DEL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, S_ENT,
  //|  Shift |        |        |        |        |        |        |        | Numpad |        |        |        |        |        | Shift  |
  //|CtlShift|   Z    |   X    |   C    |   V    |   B    |  Win   |        |  Del   |   N    |   M    |  <,    |   >.   |   ?/   | Enter  |
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LCTL, KC_LALT, NP_ENTR,                   KC_SPC,  KC_RALT, KC_RCTL
                                // |        |        | Numpad |                 |        |        |        |
                                // |  Ctrl  |  Alt   | Enter  |                 | Space  |  Alt   |  Ctrl  |
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // Nav/F Keys
  [_NAV_F] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              XXXXXXX, KC_DEL,  XXXXXXX, KC_MINS, KC_EQL,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                             KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_LBRC, KC_RBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX,                            KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, _______, _______, _______, XXXXXXX, M_CAD,            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // Num Pad / left hand nav
  [_NUMPAD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RESET,   XXXXXXX, KC_DEL,  XXXXXXX, XXXXXXX, KC_BSPC,                            XXXXXXX, XXXXXXX, KC_PSLS, KC_PAST, KC_EQL,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  XXXXXXX,                            XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,                            XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, M_LOCK,           _______, XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, KC_PDOT, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, KC_KP_0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_KB_CONTROL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};
