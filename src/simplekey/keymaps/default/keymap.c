// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,------------------------------------------------------------------------------------------.
   * |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |
   * |------+------+------+------+------+--------------------+------+------+------+------+------|
   * |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |
   * |------+------+------+------+------+---------------------------+------+------+------+------|
   * |   Z  |   X  |   C  |   V  |   B  |   (  |      |   )  |   N  |   M  |   ,  |   .  |   /  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift| Ctrl | TAB  | Alt  | Raise| Space|      | Enter| Lower| BkSPC| DEL  | EISU |   -  |
   * ,------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, 
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_LPRN,        KC_RPRN, KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, 
    KC_LSFT, KC_LCTL, KC_TAB, KC_LALT,  RAISE, KC_SPC ,        KC_ENT , LOWER , KC_BSPC,  KC_DEL,  EISU,    KC_MINS
  ),

  /* Lower
   * ,------------------------------------------------------------------------------------------.
   * |   !  |   -  |   *  |   +  |   /  |                    |   $  |   ^  |   @  |   &  |  |   |
   * |------+------+------+------+------+--------------------+------+------+------+------+------|
   * |  ESC |   #  |   ~  |   %  |   =  |                    |   <  |   >  |   '  |   "  |   :  |
   * |------+------+------+------+------+---------------------------+------+------+------+------|
   * |  TAB |      |      |   _  |   -  |   {  |      |   }  |   ?  |   \  |   ,  |   .  |   /  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift| Ctrl | TAB  | Alt  | Raise| Space|      | Enter| Lower| BkSPC| DEL  | EISU |   -  |
   * ,------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_EXLM, KC_MINS, KC_ASTR, KC_PLUS, KC_SLSH,                              KC_DLR,  KC_CIRC, KC_AT,   KC_AMPR, KC_PIPE,
    KC_ESC,  KC_HASH, KC_TILD, KC_PERC, KC_EQL,                               KC_LT,   KC_GT,   KC_DOT , KC_QUOT, KC_COLN,
    KC_TAB,  _______, _______, KC_UNDS, KC_MINS, KC_LCBR,            KC_RCBR, KC_QUES, KC_BSLS, KC_COMM, KC_DOT,  KC_SLSH,
    KC_LSFT, KC_LCTL,  KC_TAB, KC_LALT,   RAISE, KC_SPC ,            KC_ENT , LOWER , KC_BSPC,  KC_DEL,  EISU,    KC_MINS
  ),

  /* Raise
   * ,------------------------------------------------------------------------------------------.
   * |   F1 |   F2 |   F3 |   F4 |      |                    |    7 |    8 |   9  |    0 |      |
   * |------+------+------+------+------+--------------------+------+------+------+------+------|
   * |   F5 |   F6 |   F7 |   F8 |      |                    |    4 |    5 |   6  |      |      |
   * |------+------+------+------+------+---------------------------+------+------+------+------|
   * |   F9 |  F10 |  F11 |  F12 |  　  |   [  |      |   ]  |    1 |    2 |   3  |   .  |   /  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift| Ctrl | TAB  | Alt  | Raise| Space|      | Enter| Lower| BkSPC| DEL  | EISU |   -  |
   * ,------------------------------------------------------------------------------------------.
  */
  [_RAISE] = LAYOUT(
     KC_F1  , KC_F2  , KC_F3 , KC_F4  , _______,                                 KC_7  , KC_8   ,  KC_9  ,    KC_0,  _______,
     KC_F5  , KC_F6  , KC_F7 , KC_F8  , _______,                                 KC_4  , KC_5   ,  KC_6  , _______,  _______, 
     KC_F9  , KC_F10 , KC_F11, KC_F12 , _______, KC_LBRC,               KC_RBRC, KC_1  , KC_2   ,  KC_3  ,  KC_DOT,  KC_SLSH,
     KC_LSFT, KC_LCTL, KC_TAB, KC_LALT,  RAISE , KC_SPC ,               KC_ENT , LOWER , KC_BSPC,  KC_DEL,    EISU,  KC_MINS
    )
  
};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    return false;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180;
    return rotation;
}

#endif
