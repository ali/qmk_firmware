#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define L0 0 // default layer
#define L1 1 // media keys, movement

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Basic layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |   =    |   1  |   2  |   3  |   4  |   5  | ESC  |           |  L1  |   6  |   7  |   8  |   9  |   0  |   -    |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | Tab    |   Q  |   W  |   E  |   R  |   T  |  [   |           |   ]  |   Y  |   U  |   I  |   O  |   P  |   \    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | Ctrl   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
   * |--------+------+------+------+------+------|  L1  |           |  L1  |------+------+------+------+------+--------|
   * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   | Caps |   `  | Ctrl | LAlt |  L⌘  |                                       |  R⌘  | RAlt |  ⌃⌥  | ⌃⌥⌘  |  L1  |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |  L⌘  | LAlt |       | Ctrl |  R⌘  |
   *                                 ,------|------|------|       |------+-------+------.
   *                                 |      |      | Home |       | PgUp |       |      |
   *                                 | BkSp | Del  |------|       |------| Enter |Space |
   *                                 |      |      | End  |       | PgDn |       |      |
   *                                 `--------------------'       `---------------------'
   */
  [L0] = LAYOUT_ergodox(
    // Left hand
    KC_EQL,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5, KC_ESCAPE,
    KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T, KC_LBRC,
    KC_LCTL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,
    KC_LSPO, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, MO(1),
    KC_CAPS, KC_GRV, KC_LCTL, KC_LALT, KC_LCMD,
                                       KC_LCMD, KC_LALT,
                                                KC_HOME,
                              KC_BSPC, KC_DEL,  KC_END,

    // Right hand
    HYPR_T(KC_NO), KC_6,     KC_7,    KC_8,    KC_9,         KC_0,          KC_MINS,
    KC_RBRC,       KC_Y,     KC_U,    KC_I,    KC_O,         KC_P,          KC_BSLS,
                   KC_H,     KC_J,    KC_K,    KC_L,         KC_SCLN,       KC_QUOT,
    MO(1),         KC_N,     KC_M,    KC_COMM, KC_DOT,       KC_SLSH,       KC_RSPC,
                             KC_RCMD, KC_RALT, LCA_T(KC_NO), RCAG_T(KC_NO), TT(1),
                   KC_RCTRL, KC_RCMD,
                   KC_PGUP,
                   KC_PGDN,  KC_ENT, KC_SPC
  ),
  /* Keymap 1: Media and movement
   *
   * ,---------------------------------------------------.           ,--------------------------------------------------.
   * |         |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |        |
   * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
   * | CAPS    |      |      |      |      |      |      |           |      |      |      |      |  F14 |  F15 |        |
   * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |         | Vol- | Vol+ | Mute |      |      |------|           |------| Left |  Down  | Up | Right|      |        |
   * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |         | Prev | Next | Play |      |      |      |           |      |      |      |      |      |      |        |
   * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |       |      |      |      |      |                                       |      |      |      |      |      |
   *   `-----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      | Reset|       |Reset |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |      |      |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  [L1] = LAYOUT_ergodox(
    // Left hand
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,
    KC_CAPS, _______, _______, _______, _______, _______, _______,
    _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,
    _______, KC_MPRV, KC_MNXT, KC_MPLY, _______, _______, _______,
    _______, _______, _______, _______, _______,
                                        _______, RESET,
                                                 _______,
                               _______, _______, _______,

    // Right hand
    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  _______,
    _______, _______, _______, _______, KC_F14,   KC_F15,  _______,
             KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
    _______, _______, _______, _______, _______,  _______, _______,
                      _______, _______, _______,  _______, _______,
             RESET,   _______,
             _______,
             _______, _______, _______
  ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
// #ifdef RGBLIGHT_COLOR_LAYER_0
//   rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
// #endif
};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    // uint8_t layer = biton32(layer_state);

    // ergodox_board_led_off();
    // ergodox_right_led_1_off();
    // ergodox_right_led_2_off();
    // ergodox_right_led_3_off();

    // switch (layer) {
    //   case 0:
    //     #ifdef RGBLIGHT_COLOR_LAYER_0
    //       rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
    //     #endif
    //     break;
    //   case 1:
    //     ergodox_right_led_1_on();
    //     #ifdef RGBLIGHT_COLOR_LAYER_1
    //       rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
    //     #endif
    //     break;
    //   case 2:
    //     ergodox_right_led_2_on();
    //     #ifdef RGBLIGHT_COLOR_LAYER_2
    //       rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
    //     #endif
    //     break;
    //   case 3:
    //     ergodox_right_led_3_on();
    //     #ifdef RGBLIGHT_COLOR_LAYER_3
    //       rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
    //     #endif
    //     break;
    //   case 4:
    //     ergodox_right_led_1_on();
    //     ergodox_right_led_2_on();
    //     #ifdef RGBLIGHT_COLOR_LAYER_4
    //       rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
    //     #endif
    //     break;
    //   case 5:
    //     ergodox_right_led_1_on();
    //     ergodox_right_led_3_on();
    //     #ifdef RGBLIGHT_COLOR_LAYER_5
    //       rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
    //     #endif
    //     break;
    //   case 6:
    //     ergodox_right_led_2_on();
    //     ergodox_right_led_3_on();
    //     #ifdef RGBLIGHT_COLOR_LAYER_6
    //       rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
    //     #endif
    //     break;
    //   case 7:
    //     ergodox_right_led_1_on();
    //     ergodox_right_led_2_on();
    //     ergodox_right_led_3_on();
    //     #ifdef RGBLIGHT_COLOR_LAYER_7
    //       rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
    //     #endif
    //     break;
    //   default:
    //     break;
    // }
};
