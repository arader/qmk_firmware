#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define PERMISSIVE_HOLD

#define BASE 0 // default layer
#define BOOK 1 // switch mod keys for laptop use
#define SYMB 2 // symbols
#define MDIA 3 // media keys

#define _______ KC_TRNS
#define ALT_LBRC ALT_T(KC_LBRC)
#define CTL_RBRC MT(MOD_RCTL, KC_RBRC)
#define KC_LDSK LGUI(RCTL(KC_LEFT))
#define KC_LMON LGUI(LSFT(KC_LEFT))
#define KC_LMAX LGUI(KC_LEFT)
#define KC_RDSK RGUI(RCTL(KC_RIGHT))
#define KC_RMON RGUI(RSFT(KC_RIGHT))
#define KC_RMAX RGUI(KC_RIGHT)

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
 * | CAPS   |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   E  |   R  |   T  | ESC  |           | ESC  |   Y  |   U  |   I  |   O  |   P  |   =    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LSHIFT |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------| SYMB |           | SYMB |------+------+------+------+------+--------|
 * | LCTL   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   \    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *  | LDSK  | LMON | LMAX | LGUI |[/LALT|                                       |]/RCTL| BOOK | RMAX | RMON | RDSK  |
 *  `-----------------------------------'                                       `-----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | HOME | END  |       | SCLK | PRINT  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | PGUP |       | INS  |        |      |
 *                                 | ENTER| BKSP |------|       |------| BKSP   | SPC  |
 *                                 |      |      | PGDN |       | DEL  |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_CAPS,        KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_GRV,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_ESC,
        KC_LSFT,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LCTL,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,OSL(SYMB),
        KC_LDSK,        KC_LMON,      KC_LMAX,KC_LGUI,ALT_LBRC,
                                                      KC_HOME,  KC_END,
                                                                KC_PGUP,
                                                 KC_ENT,KC_BSPC,KC_PGDN,
        // right hand
             KC_RGHT,  KC_6,   KC_7,    KC_8,   KC_9,   KC_0,             KC_MINS,
             KC_ESC,   KC_Y,   KC_U,    KC_I,   KC_O,   KC_P,             KC_EQL,
                       KC_H,   KC_J,    KC_K,   KC_L,   KC_SCLN,          KC_QUOT,
             OSL(SYMB),KC_N,   KC_M,    KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_BSLS,
                               CTL_RBRC,TG(BOOK),KC_RMAX,KC_RMON,          KC_RDSK,
             KC_SLCK,  KC_PSCR,
             KC_INS,
             KC_DEL,KC_BSPC, KC_SPC
    ),
/* Keymap 1: Laptop Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * | LCTRL   |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CAPS    |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LSHIFT  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |    . |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[BOOK] = LAYOUT_ergodox(
       // left hand
       KC_LCTL,_______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,_______,
       KC_CAPS,_______,_______,_______,_______,_______,
       KC_LSFT,_______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,
                                       _______,_______,
                                               _______,
                               _______,_______,_______,
       // right hand
       _______,_______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,_______,
               _______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,
       _______,_______,
       _______,
       _______,_______,_______
),
/* Keymap 2: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      | VOLU |      |   {  |   [  |      |           |      |  ]   |  }   |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         | PREV | PLAY | NEXT |      |      |------|           |------| LEFT | DOWN |  UP  | RIGHT|      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      | VOLD |      |      |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |    . |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,   KC_F11,
       _______,_______,KC_VOLU,_______,KC_LCBR,KC_LBRC,_______,
       _______,KC_MPRV,KC_MPLY,KC_MNXT,_______,_______,
       _______,_______,KC_VOLD,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,
                                       _______,_______,
                                               _______,
                               _______,_______,_______,
       // right hand
       KC_F12, KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, _______,
       _______,KC_RBRC,KC_RCBR,_______,_______,_______,_______,
               KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,_______,_______,
       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,
       _______,_______,
       _______,
       _______,_______,_______
),
/* Keymap 3: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_MS_U, _______, _______, _______,
       _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_BTN1, KC_BTN2,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, KC_MPLY,
       _______,  _______, _______, KC_MPRV, KC_MNXT, _______, _______,
                          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
       _______, _______,
       _______,
       _______, _______, KC_WBAK
),
};

/*
const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};
*/

/*
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

};
*/


// Runs constantly in the background, in a loop.
/*
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
*/
