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

  [_QWERTY] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, 
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_LPRN,        KC_RPRN, KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, 
    KC_LSFT, KC_LCTL, KC_TAB, KC_LALT,  RAISE, KC_SPC ,        KC_ENT , LOWER , KC_BSPC,  KC_DEL,  EISU,    KC_MINS
  ),
  [_LOWER] = LAYOUT(
    KC_NO  , KC_NO  , KC_PSCR, KC_HOME, KC_PGUP,                              KC_F1  ,   KC_F2,   KC_F3,   KC_F4, KC_NO  ,
    KC_ESC,  KC_NO  , KC_SCRL, KC_END , KC_PGDN,                              KC_F5  ,   KC_F6,   KC_F7,   KC_F8, KC_NO  ,
    KC_TAB,  KC_LGUI, KC_PAUS, KC_NO  , KC_NO  , KC_LCBR,            KC_RCBR, KC_F9  ,  KC_F10,  KC_F11,  KC_F12, KC_NO  ,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [_RAISE] = LAYOUT(
     KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                                 KC_P7  , KC_P8   ,  KC_P9  ,   KC_P0,   KC_ESC,
     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,                                 KC_P4  , KC_P5   ,  KC_P6  ,  KC_NUM,    KC_UP, 
     KC_LBRC, KC_RBRC, KC_MINS, KC_EQL ,    EISU, KC_LBRC,                KC_RBRC, KC_P1 , KC_P2   ,  KC_P3  ,  KC_DOT,  KC_DOWN,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_RGHT
    )
};

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_90;
}
#ifdef OLED_ENABLE

bool oled_task_user(void) {
    oled_write_ln_P(PSTR("SimpleKey"), false); 
    oled_write_ln_P(PSTR(" "), false);	
    oled_write_ln_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {				
        case _QWERTY:
            oled_write_ln_P(PSTR("Default\n"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("Raise\n"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }
led_t led_state = host_keyboard_led_state();
{
    oled_write_P(PSTR("NumL:"), false);
    oled_write_ln_P(led_state.num_lock ? PSTR("o") : PSTR("-"), false);
    oled_write_P(PSTR("CapsL:"), false);
    oled_write_ln_P(led_state.caps_lock ? PSTR("o") : PSTR("-"), false);
    oled_write_P(PSTR("ScrollL:"), false);
    oled_write_ln_P(led_state.scroll_lock ? PSTR("o") : PSTR("-"), false);
}	
	oled_write_ln_P(PSTR(" "), false);
	oled_write_P(PSTR("Powered By"), false);
    oled_write_ln_P(PSTR("      Vial"), false);
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
    if (!is_keyboard_master()){
 return OLED_ROTATION_270;
}
    return rotation;
}
#endif