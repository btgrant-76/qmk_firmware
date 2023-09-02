/* Copyright 2021 Kyle McCreery
 * Copyright 2023 Brian Grant <@btgrant-76>
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

 #include QMK_KEYBOARD_H
 #include "btgrant-76.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_btgrant(

  //|-----------------------------------------------------|        |-----------------------------------------------------|
      KC_MINS,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_EQL,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                                            ___BASE_1_L___,         ___BASE_1_R___,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                                            ___BASE_2_L___,         ___BASE_2_R___,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                                            ___BASE_3_L___, KC_MUTE,___BASE_3_R___,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         BACK, KC_LCTL, KC_LALT,        ___BASE_THUMB_L___,  Z_MUTE,        ___BASE_THUMB_R___,SCRN2CLP, SCRN2FL,     FWD
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    ),
    [_NUM] = LAYOUT_btgrant(
  //|-----------------------------------------------------|        |-----------------------------------------------------|
       KC_GRV, _______, _______, _______, _______, _______,          _______, _______, _______, KC_LBRC, KC_RBRC, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                                             ___NUM_1_L___,         ___NUM_1_R___,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                                             ___NUM_2_L___,         ___NUM_2_R___,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                                             ___NUM_3_L___, KC_HOME,___NUM_3_R___,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX,         ___NUM_THUMB_L___, XXXXXXX,___NUM_THUMB_R___,          XXXXXXX, XXXXXXX, XXXXXXX
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    ),
    [_SYM] = LAYOUT_btgrant(
  //|-----------------------------------------------------|        |-----------------------------------------------------|
      _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                                             ___SYM_1_L___,         ___SYM_1_R___,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                                             ___SYM_2_L___,         ___SYM_2_R___,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                                             ___SYM_3_L___, KC_MPLY,___SYM_3_R___,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|

      XXXXXXX, XXXXXXX, XXXXXXX,         ___SYM_THUMB_L___, XXXXXXX,___SYM_THUMB_R___,          XXXXXXX, XXXXXXX, XXXXXXX
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    ),
    [_NAV] = LAYOUT_btgrant(
  //|-----------------------------------------------------|        |-----------------------------------------------------|
      _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                                             ___NAV_1_L___,         ___NAV_1_R___,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                                             ___NAV_2_L___,         ___NAV_2_R___,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                                             ___NAV_3_L___, XXXXXXX,___NAV_3_R___,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|

      XXXXXXX, KC_LCTL, KC_LALT,         ___NAV_THUMB_L___, XXXXXXX,___NAV_THUMB_R___,          XXXXXXX, XXXXXXX, XXXXXXX
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    ),
    [_FUN] = LAYOUT_btgrant(
  //|-----------------------------------------------------|        |-----------------------------------------------------|
      _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                                             ___FUN_1_L___,         ___FUN_1_R___,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                                             ___FUN_2_L___,         ___FUN_2_R___,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                                             ___FUN_3_L___, XXXXXXX,___FUN_3_R___,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      AU_TOGG, MU_TOGG, MU_NEXT,         ___FUN_THUMB_L___, XXXXXXX,___FUN_THUMB_R___,          XXXXXXX, XXXXXXX, XXXXXXX
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    ),
    [_MSE] = LAYOUT_btgrant(
  //|-----------------------------------------------------|        |-----------------------------------------------------|
      _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
     XXXXXXX,                               ___5MSE_1_L___,         ___5MSE_1_R___,                               XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
     XXXXXXX,                               ___5MSE_2_L___,         ___5MSE_2_R___,                               XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
     XXXXXXX,                               ___5MSE_3_L___,MISS_CTL,___5MSE_3_R___,                               XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, XXXXXXX,          ___MSE_THUMB_L___, XXXXXXX,___MSE_THUMB_R___,          XXXXXXX, XXXXXXX, XXXXXXX
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    ),
    [_ADD] = LAYOUT_btgrant(
  //|-----------------------------------------------------|        |-----------------------------------------------------|
      _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
     XXXXXXX,                               ___5ADD_1_L___,         ___5ADD_1_R___,                               XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
     XXXXXXX,                               ___5ADD_2_L___,         ___5ADD_2_R___,                               XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
     XXXXXXX,                               ___5ADD_3_L___, QK_BOOT,___5ADD_3_R___,                               XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, XXXXXXX,          ___ADD_THUMB_L___, XXXXXXX,___ADD_THUMB_R___,          XXXXXXX, XXXXXXX, XXXXXXX
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    )
};

bool achordion_chord_keymap(uint16_t tap_hold_keycode,
                            keyrecord_t* tap_hold_record,
                            uint16_t other_keycode,
                            keyrecord_t* other_record) {

  switch (tap_hold_record->event.key.row) {
    case 4:
    case 9:
        return true;
    break;
  }

  return false;
}

#ifdef ENCODER_MAP_ENABLE
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
        [_BASE] = { ENCODER_CCW_CW(KC_VOLD,  KC_VOLU) },
        [_NUM]  = { ENCODER_CCW_CW(KC_PGUP,  KC_PGDN) },
        [_SYM]  = { ENCODER_CCW_CW(KC_MPRV,  KC_MNXT) },
        [_NAV]  = { ENCODER_CCW_CW(BACK,     FWD) },
        [_FUN]  = { ENCODER_CCW_CW(KC_BRIU,  KC_BRID) },
        [_MSE]  = { ENCODER_CCW_CW(LEFT_SPC, RGHT_SPC) },
        [_ADD]  = { ENCODER_CCW_CW(XXXXXXX,  XXXXXXX) }
    };
#endif

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_YELLOW);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
}
#endif
