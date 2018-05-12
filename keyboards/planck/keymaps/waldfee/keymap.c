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

enum planck_layers {
  _QWERTZ,
  _LOWER,
  _RAISE,
  _ADJUST
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define LSFT_LPRN LSFT_T(DE_LPRN) // shift when held, ( otherwise
#define RSFT_RPRN RSFT_T(DE_RPRN) // shift when held, ) otherwise

#define LSFT_LCBR LSFT_T(DE_LCBR) // shift when held, { otherwise
#define RSFT_RCBR RSFT_T(DE_RCBR) // shift when held, } otherwise

#define LSFT_LBRC LSFT_T(DE_LBRC) // shift when held, [ otherwise
#define RSFT_RBRC RSFT_T(DE_RBRC) // shift when held, ] otherwise

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwertz
 * ,---------------------------------------------------------------------------------------------.
 * | Esc / ^   |   Q  |   W  |   E  |   R  |   T  |   Z  |   U  |   I  |   O  |   P  | Bksp      |
 * |-----------+------+------+------+------+-------------+------+------+------+------+-----------|
 * | Tab       |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   #  | Enter     |
 * |-----------+------+------+------+------+------|------+------+------+------+------+-----------|
 * | Shift / ( |   Y  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  | Shift / ) |
 * |-----------+------+------+------+------+------+------+------+------+------+------+-----------|
 * | Ctrl      | Alt  |  GUI |   <  |Lower |    Space    |Raise | AltGr| Left | Down | Right     |
 * `---------------------------------------------------------------------------------------------'
 */
[_QWERTZ] = { 
  {KC_GESC,   DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    KC_BSPC   },
  {KC_TAB,    DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_HASH, KC_ENT    },
  {LSFT_LPRN, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    KC_COMM, KC_DOT,  KC_UP,   RSFT_RPRN },
  {KC_LCTL,   KC_LALT, KC_LGUI, DE_LESS, LOWER,   KC_SPC,  KC_SPC,  RAISE,   DE_ALGR, KC_LEFT, KC_DOWN, KC_RGHT   }
},

/* Lower
 * ,---------------------------------------------------------------------------------------------.
 * |   ~       |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp      |
 * |-----------+------+------+------+------+-------------+------+------+------+------+-----------|
 * | Del       |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |        |
 * |-----------+------+------+------+------+------|------+------+------+------+------+-----------|
 * | Shift / { |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  | Shift / } |
 * |-----------+------+------+------+------+------+------+------+------+------+------+-----------|
 * |           |      |      |      |      |             |      | Next | Vol- | Vol+ | Play      |
 * `---------------------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC   },
  {KC_DEL,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE   },
  {LSFT_LCBR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  RSFT_RCBR },
  {_______,   _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY   }
},

/* Raise
 * ,---------------------------------------------------------------------------------------------.
 * |   `       |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp      |
 * |-----------+------+------+------+------+-------------+------+------+------+------+-----------|
 * | Del       |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \        |
 * |-----------+------+------+------+------+------|------+------+------+------+------+-----------|
 * | Shift / [ |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn | Shift / ] |
 * |-----------+------+------+------+------+------+------+------+------+------+------+-----------|
 * |           |      |      |      |      |             |      | Next | Vol- | Vol+ | Play      |
 * `---------------------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC   },
  {KC_DEL,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS   },
  {LSFT_LBRC, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, RSFT_RBRC },
  {_______,   _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY   }
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   DEBUG,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,  _______, _______,  _______,  _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool is_shift_active = (keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)));
  bool is_altgr_active = (keyboard_report->mods & MOD_BIT(KC_RALT));
  
  if (is_altgr_active) {
	  switch (keycode) {
		  
		case DE_O:
		  if (record->event.pressed) {
			if (is_shift_active) {
				SEND_STRING(SS_LSFT(SS_TAP(X_SCOLON))); // Ö
			}
			else {
				SEND_STRING(SS_TAP(X_SCOLON)); // ö			
			}
		  }
		  return false;
		  break;
		  
		case DE_A:
		  if (record->event.pressed) {
			if (is_shift_active) {
				SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE))); // Ä
			}
			else {
				SEND_STRING(SS_TAP(X_QUOTE)); // ä			
			}
		  }
		  return false;
		  break;
		  
		case DE_U:
		  if (record->event.pressed) {
			if (is_shift_active) {
				SEND_STRING(SS_LSFT(SS_TAP(X_LBRACKET))); // Ü
			}
			else {
				SEND_STRING(SS_TAP(X_LBRACKET)); // ü			
			}
		  }
		  return false;
		  break;
		  
		case DE_S:
		  if (record->event.pressed) {
		    SEND_STRING(SS_TAP(X_MINUS)); // ß
		  }
		  return false;
		  break;
	}
  }
  
  return true;
}
