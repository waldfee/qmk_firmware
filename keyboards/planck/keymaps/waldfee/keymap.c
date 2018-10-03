/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "planck.h"
#include "action_layer.h"
#include "keymap_german.h"

extern keymap_config_t keymap_config;

static bool reset_is_lalt_pressed;
static bool reset_is_lsft_pressed;
static bool reset_is_tab_pressed;

enum planck_layers {
  _QWERTZ,
  _LOWER,
  _RAISE,
  _UMLAUT,
  _NUMPAD,
  _RESET
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define LOWER MO(_LOWER)

#define RAISE MO(_RAISE)

#define NUMPAD MO(_NUMPAD)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwertz
   * ,---------------------------------------------------------------------------------------------.
   * | Esc / ^   |   Q  |   W  |   E  |   R  |   T  |   Z  |   U  |   I  |   O  |   P  | Bksp      |
   * |-----------+------+------+------+------+-------------+------+------+------+------+-----------|
   * | Tab       |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   #  |   +       |
   * |-----------+------+------+------+------+------+------+------+------+------+------+-----------|
   * | Shift     |   Y  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  | Shift     |
   * |-----------+------+------+------+------+------+------+------+------+------+------+-----------|
   * | Ctrl      |  GUI |  Alt |   <  |Lower |  Spc |  Ent |Raise |NUMPAD| Left | Down | Right     |
   * `---------------------------------------------------------------------------------------------'
   */
  [_QWERTZ] = LAYOUT_planck_grid(
    KC_GESC,   DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    KC_BSPC   ,
    KC_TAB,    DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_HASH, DE_PLUS   ,
    KC_LSFT,   DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    KC_COMM, KC_DOT,  KC_UP,   KC_RSFT   ,
    KC_LCTL,   KC_LGUI, KC_LALT, DE_LESS, LOWER,   KC_SPC,  KC_ENT,  RAISE,   NUMPAD , KC_LEFT, KC_DOWN, KC_RGHT
  ),

  /* Lower
   * ,---------------------------------------------------------------------------------------------.
   * |    ~      |      |      |      |   !  |   ´  |   %  |   &  |  =   |      |      |   Del     |
   * |-----------+------+------+------+------+-------------+------+------+------+------+-----------|
   * |    _      |  "   |   *  |  /   |   ?  |      |      |      |      |      |      |   -       |
   * |-----------+------+------+------+------+------+------+------+------+------+------+-----------|
   * |           |      |      |      |      |   \  |      |      |      |      | Pg Up|           |
   * |-----------+------+------+------+------+------+------+------+------+------+------+-----------|
   * |           |  ^   |      |      |      |      |      |      |      | Home | Pg Dn| End       |
   * `---------------------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT_planck_grid(
    DE_TILD,   _______, _______, _______, DE_EXLM, DE_ACUT, DE_PERC, DE_AMPR, DE_EQL , _______, _______, KC_DEL    ,
    DE_UNDS,   DE_DQOT, DE_ASTR, DE_SLSH, DE_QST , _______, _______, _______, _______, _______, _______, DE_MINS   ,
    _______,   _______, _______, _______, _______, DE_BSLS, _______, _______, _______, _______, KC_PGUP, _______ ,
    _______,   DE_CIRC, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END
  ),

  /* Raise
   * ,---------------------------------------------------------------------------------------------.
   * |     F1    |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |   F12     |
   * |-----------+------+------+------+------+-------------+------+------+------+------+-----------|
   * |      1    |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |  10  |      |           |
   * |-----------+------+------+------+------+------+------+------+------+------+------+-----------|
   * | Shift     |   (  |   )  |   {  |   }  |   [  |   ]  |      |      |      |      | Shift     |
   * |-----------+------+------+------+------+------+------+------+------+------+------+-----------|
   * |           |  App |      |      |      |      |      |      |      |      |      |           |
   * `---------------------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT_planck_grid(
    KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12    ,
    KC_1,      KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______   ,
    _______,   DE_LPRN, DE_RPRN, DE_LCBR, DE_RCBR, DE_LBRC, DE_RBRC, _______, _______, _______, _______, _______ ,
    _______,   KC_APP,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ), 

  /* Umlaut (Lower + Raise)
   * ,-----------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |   Ü  |      |    Ö   |      |        |
   * |------+------+------+------+------+-------------+------+------+--------+------+--------|
   * |      |   Ä  |   ß  |      |      |      |      |      |      |        |      |        |
   * |------+------+------+------+------+------|------+------+------+--------+------+--------|
   * |      |      |      |      |      |      |      |      |      |        | Vol+ |        |
   * |------+------+------+------+------+------+------+------+------+--------+------+--------|
   * |      |      |      |      |      |      |      |      |      | Next   | Vol- | Play   |
   * `---------------------------------------------------------------------------------------'
   */
  [_UMLAUT] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, DE_UE,   _______, DE_OE,   _______, _______    ,
    _______, DE_AE,   DE_SS,   _______, _______, _______, _______, _______, _______, _______, _______, _______    ,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_MPLY
  ),

  /* Numpad (lctrl + Gui)
   * ,-----------------------------------------------------------------------------------.
   * |      |      |      |      |      |   7  |   8  |   9  |   =  |      |Print | Ins  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |      |      |   4  |   5  |   6  |   -  |      |      | Paus |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |   1  |   2  |   3  |   +  |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |   0  |   ,  |  Ent |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_NUMPAD] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, DE_7, DE_8,    DE_9,    DE_EQL,  _______, KC_PSCR, KC_INSERT,
    _______, _______, _______, _______, _______, DE_4, DE_5,    DE_6,    DE_MINS, _______, _______, KC_PAUSE ,
    _______, _______, _______, _______, _______, DE_1, DE_2,    DE_3,    DE_PLUS, _______, _______, _______  ,
    _______, _______, _______, _______, XXXXXXX, DE_0, DE_COMM, KC_ENT,  _______, _______, _______, _______
  ),

  /* Reset (Lalt + LSHFT + Tab + Bksp, in this order)
   * ,-----------------------------------------------------------------------------------.
   * |      |      |      |      | RESET|      |      |      |      |      |      |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_RESET] = LAYOUT_planck_grid(
    _______, _______, _______, _______, RESET  , _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _UMLAUT);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t layer = biton32(layer_state);

  // activate _RESET
  if (layer == _QWERTZ || layer == _RESET) {
    switch (keycode) {
      case KC_LALT:
        if (layer == _RESET && !record->event.pressed) {
          layer_off(_RESET);
          return false;
        }
        reset_is_lalt_pressed = record->event.pressed;
        break;
      case KC_LSFT:
        if (layer == _RESET && !record->event.pressed) {
          layer_off(_RESET);
          return false;
        }
        reset_is_lsft_pressed = reset_is_lalt_pressed && record->event.pressed;
        break;
      case KC_TAB:
        if (layer == _RESET && !record->event.pressed) {
          layer_off(_RESET);
          return false;
        }
        reset_is_tab_pressed = reset_is_lsft_pressed && record->event.pressed;
        break;
      case KC_BSPC:
        if (reset_is_tab_pressed && layer == _QWERTZ && record->event.pressed) {
          layer_on(_RESET);
          return false;
        }
        if (layer == _RESET && !record->event.pressed) {
          layer_off(_RESET);
          return false;
        }
        break;
    }
  }
  if (layer != _QWERTZ && layer != _RESET) {
    reset_is_lalt_pressed = false;
    reset_is_lsft_pressed = false;
    reset_is_tab_pressed = false;
  }

  return true;
}



