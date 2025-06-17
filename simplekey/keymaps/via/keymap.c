#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [0] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, 
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_LPRN,        KC_RPRN, KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, 
    KC_LSFT, KC_LCTL, KC_TAB, KC_LALT,  KC_NO, KC_SPC ,        KC_ENT , KC_NO , KC_BSPC,  KC_DEL,  KC_NO,    KC_MINS
  ),

  [1] = LAYOUT(
    KC_EXLM, KC_MINS, KC_ASTR, KC_PLUS, KC_SLSH,                              KC_DLR,  KC_CIRC, KC_AT,   KC_AMPR, KC_PIPE,
    KC_ESC,  KC_HASH, KC_TILD, KC_PERC, KC_EQL,                               KC_LT,   KC_GT,   KC_DOT , KC_QUOT, KC_COLN,
    KC_TAB,  _______, _______, KC_UNDS, KC_MINS, KC_LCBR,            KC_RCBR, KC_QUES, KC_BSLS, KC_COMM, KC_DOT,  KC_SLSH,
    KC_LSFT, KC_LCTL,  KC_TAB, KC_LALT,   KC_NO, KC_SPC ,            KC_ENT , KC_NO , KC_BSPC,  KC_DEL,  KC_NO,    KC_MINS
  ),

   [2] = LAYOUT(
     KC_F1  , KC_F2  , KC_F3 , KC_F4  , _______,                                 KC_7  , KC_8   ,  KC_9  ,    KC_0,  _______,
     KC_F5  , KC_F6  , KC_F7 , KC_F8  , _______,                                 KC_4  , KC_5   ,  KC_6  ,  KC_NUM,  _______, 
     KC_F9  , KC_F10 , KC_F11, KC_F12 , _______, KC_LBRC,               KC_RBRC, KC_1  , KC_2   ,  KC_3  ,  KC_DOT,  KC_SLSH,
     KC_LSFT, KC_LCTL, KC_TAB, KC_LALT,  KC_NO , KC_SPC ,               KC_ENT , KC_NO , KC_BSPC,  KC_DEL,    KC_NO,  KC_MINS
    ),

   [3] = LAYOUT(
     KC_F1  , KC_F2  , KC_F3 , KC_F4  , _______,                                 KC_7  , KC_8   ,  KC_9  ,    KC_0,  _______,
     KC_F5  , KC_F6  , KC_F7 , KC_F8  , _______,                                 KC_4  , KC_5   ,  KC_6  ,  KC_NUM,  _______, 
     KC_F9  , KC_F10 , KC_F11, KC_F12 , _______, KC_LBRC,               KC_RBRC, KC_1  , KC_2   ,  KC_3  ,  KC_DOT,  KC_SLSH,
     KC_LSFT, KC_LCTL, KC_TAB, KC_LALT,  KC_NO , KC_SPC ,               KC_ENT , KC_NO , KC_BSPC,  KC_DEL,    KC_NO,  KC_MINS
    )
};