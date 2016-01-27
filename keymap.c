#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |  Del |           | Ins  |   6  |   7  |   8  |   9  |   0  |   [    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   '  |   ,  |   .  |   P  |   Y  | Bkspc|           |Bkspc |   F  |   G  |   C  |   R  |   L  | ~L1/]  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Alt/Esc|   A  |   O  |   W  |   U  |   I  |------|           |------|   D  |   H  |   H  |   N  |S / L2|  RAlt  | 
 * |--------+------+------+------+------+------|Return|           |Return|------+------+------+------+------+--------|
 * | LShift |   ;  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  | Ctl/Z| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *  |Ctl/Home| Hyper| PgUp |   \  |   -  |                                       |   /  |   =  | PgDn | Meh  | END  |
 *  `------------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | VolUp|VolDwn|       |  L1  | Mute | 
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Down |       |  UP  |      |      |
 *                                 | Space| LGUI |------|       |------| RGUI |Space |
 *                                 |      |      | LEFT |       | Right|      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,         KC_1,           KC_2,    KC_3,   KC_4,   KC_5,   KC_DELT,
        KC_TAB,         KC_QUOT,        KC_COMM, KC_DOT, KC_P,   KC_Y,   KC_BSPC,
        ALT_T(KC_ESC),  KC_A,           KC_O,    KC_E,   KC_U,   KC_I,
        KC_LSFT,        KC_SCLN,        KC_Q,    KC_J,   KC_K,   KC_X,   KC_ENT,
        CTL_T(KC_HOME), ALL_T(KC_NO),   KC_PGUP, KC_BSLS,KC_MINS,
                                                                KC_VOLU, KC_VOLD,
                                                                         KC_DOWN,
                                                        KC_SPC, KC_LGUI, KC_LEFT,
        // right hand
             KC_INS,      KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_LBRC,
             KC_BSPC,     KC_F,   KC_G,   KC_C,   KC_R,   KC_L,             LT(SYMB, KC_RBRC),
                          KC_D,   KC_H,   KC_T,   KC_N,   LT(MDIA, KC_S),   KC_RALT,
             KC_ENT,      KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,             KC_RSFT,
                                  KC_SLSH,KC_EQL, KC_PGDN,MEH_T(KC_NO),     CTL_T(KC_END),
             TG(SYMB), KC_MUTE,
             KC_UP,   
             KC_RGHT,  KC_RGUI, KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    !   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |    @   |  (   |   )  |   {  |   }  |   [  |  ]   |           |      |   _  |   7  |   8  |   9  |   *  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    *   |   ^  |   $  |   <  |   >  |   `  |------|           |------|   %  |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|  |   |           |      |------+------+------+------+------+--------|
 * |    #   |   :  | LEFT | DOWN |  UP  |RIGHT |      |           |      |   &  |   1  |   2  |   3  |   /  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |   '  |   "  |  ?   |   ,  |  \   |                                       |   -  |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_EXLM,KC_F1,        KC_F2,         KC_F3,          KC_F4,       KC_F5,  KC_F6,
       KC_AT,  KC_LPRN,      KC_RPRN,       KC_LCBR,        KC_RCBR,     KC_LBRC,KC_RBRC,
       KC_ASTR,KC_CIRC,      KC_DLR,        LSFT(KC_COMM),  LSFT(KC_DOT),KC_GRV,
       KC_HASH,KC_COLN,      KC_LEFT,       KC_DOWN,        KC_UP,       KC_RGHT,KC_PIPE,
       KC_QUOT,LSFT(KC_QUOT),LSFT(KC_SLASH),KC_COMM,        KC_BSLS,
                                                            KC_TRNS,KC_TRNS,
                                                                    KC_TRNS,
                                                    KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
       KC_TRNS, KC_UNDS, KC_7,   KC_8,    KC_9,    KC_ASTR, KC_TRNS,
                KC_PERC, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_SLSH, KC_TRNS,
                         KC_MINS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      | ScrUp|      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|ScrDwn|------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      | Lclk | Mclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
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
[MDIA] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_WH_U, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN3, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
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

// Runs just one time when the keyboard initializes.
void * matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void * matrix_scan_user(void) {

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
