/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H
#include "uart.h"
#ifdef RGB_MATRIX_ENABLE
//eeprom 联合体
typedef union {
  uint32_t raw;
  struct {
    bool     rgb_anim :1; //在EEPROM定义变量，记录RGB开关状态
  };
} user_config_t;

user_config_t user_config;

void keyboard_post_init_user(void) {
  user_config.raw = eeconfig_read_user(); //从EEPROM读取状态
}

void eeconfig_init_user(void) {  
  user_config.raw = 0;
  user_config.rgb_anim = 1;     //清除EEPROM，默认状态
  eeconfig_update_user(user_config.raw); 
}

enum my_keycodes {
  _RGB = USER00,  //自定义一个键码
  _RIGHT,
  _LEFT,
  _GO,
  _RETURN,
  _REBOOT,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case _RGB:
      if (record->event.pressed) {  //如果按下
        user_config.rgb_anim ^= 1; //改变RGB状态
        eeconfig_update_user(user_config.raw);  //更新状态
      } else { //如果松开  
      }
      return false;   
    case _RIGHT:
      if (record->event.pressed) {  //如果按下
          uart_write(0xa1);
      } else { //如果松开  
      }
      return false;   
    case _LEFT:
      if (record->event.pressed) {  //如果按下
          uart_write(0xa2);
      } else { //如果松开  
      }
      return false;   
    case _GO:
      if (record->event.pressed) {  //如果按下
          uart_write(0xa3);
      } else { //如果松开  
      }
      return false;   
    case _RETURN:
      if (record->event.pressed) {  //如果按下
          uart_write(0xa4);
      } else { //如果松开  
      }
      return false;  
    case _REBOOT:
      if (record->event.pressed) {  //如果按下
          uart_write(0xa5);
      } else { //如果松开  
      }
      return false; 
    default:
      return true;
    }   
}

void rgb_matrix_indicators_user(void) {
  HSV hsv = {0, 0, 255};
  if(user_config.rgb_anim == 0) {
      rgb_matrix_set_color_all(0, 0, 0);  //所有RGB灯都关闭
  }
  if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
    if (hsv.v > (rgb_matrix_get_val() + 25 )) {
      hsv.v = rgb_matrix_get_val() + 25;
    }else if (hsv.v > (rgb_matrix_get_val())) {
      hsv.v = rgb_matrix_get_val();
    }
    RGB rgb = hsv_to_rgb(hsv);   
    rgb_matrix_set_color(13, rgb.r, rgb.g, rgb.b); // LED Index, R, G, B
    rgb_matrix_set_color(14, rgb.r, rgb.g, rgb.b); // LED Index, R, G, B
  }
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
		KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, _GO, 
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, 
		KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, 
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(1), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_DELETE, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [2] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [3] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(_RIGHT, _LEFT) },
    [1] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [2] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
#endif