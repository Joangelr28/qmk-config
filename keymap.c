/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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


enum custom_keycodes {
    OP_SPOT = SAFE_RANGE,
    SRCS_FULL,
    SRCS_PART,
    SRCS_OPTS,
    COPY,
    PASTE,
    UNDO,
    REDO,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case OP_SPOT:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI(" "));
        }
        break;
    case COPY:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI("c"));
        }
        break;
    case PASTE:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI("v"));
        }
        break;
    case UNDO:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI("z"));
        }
        break;
    case REDO:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI) SS_LSFT("z") SS_UP(X_LGUI) );
        }
        break;
    case SRCS_FULL:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI) SS_LSFT("3") SS_UP(X_LGUI) );
        }
        break;
    case SRCS_PART:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI) SS_LSFT("4") SS_UP(X_LGUI) );
        }
        break;
    case SRCS_OPTS:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI) SS_LSFT("5") SS_UP(X_LGUI) );
        }
        break;
    }
    return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_SCLN, KC_COMM,  KC_DOT,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,   KC_L,  KC_RALT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
LSFT_T(KC_TAB),   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                         KC_D,    KC_H,    KC_T,    KC_N,    KC_S, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_SLSH,    KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  KC_SPC,     KC_ENT,   MO(2), KC_BSPC
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV, KC_LT,   KC_GT, KC_LPRN,  KC_RPRN, KC_EXLM,                      KC_SLSH,  KC_1,   KC_2,    KC_3,   KC_MINS,  KC_CIRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
LSFT_T(KC_TAB), KC_AMPR, KC_PIPE, KC_LBRC, KC_RBRC, KC_QUOT,                    KC_PAST,  KC_4,   KC_5,    KC_6,   KC_PPLS,  KC_RSFT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_NUBS, KC_DLR, KC_LCBR, KC_RCBR, KC_AT,                        KC_EQL,   KC_7,   KC_8,    KC_9,   KC_0,     KC_HASH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_BSPC
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, PASTE,   COPY,                         XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, KC_RALT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UNDO,    REDO,                         XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, OP_SPOT, SRCS_OPTS, SRCS_PART, SRCS_FULL, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|


                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(3), KC_BSPC
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

// Shift + esc = `
const key_override_t tilde_esc_override = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, KC_GRV);

// Control + esc = ~
const key_override_t grave_esc_override = ko_make_basic(MOD_MASK_CTRL, KC_ESC, S(KC_GRV));

// Shift + backspace = Delete
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

const key_override_t **key_overrides = (const key_override_t *[]){
    &tilde_esc_override,
    &grave_esc_override,
    &delete_key_override,
    NULL
};
