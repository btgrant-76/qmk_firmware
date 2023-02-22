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
        F1_TD,   F2_TD,   KC_F3,   KC_F4,   KC_F5,   F6_TD,            KC_F7,   KC_F8,   F9_TD,  KC_F10,  KC_F11,  F12_TD,
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
    [_NUM] = LAYOUT_btgrant(
  //|-----------------------------------------------------|        |-----------------------------------------------------|
      _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
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
       AU_TOG,  MU_TOG,  MU_MOD,         ___FUN_THUMB_L___, XXXXXXX,___FUN_THUMB_R___,          XXXXXXX, XXXXXXX, XXXXXXX
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    )
};

#ifdef ENCODER_MAP_ENABLE
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
        [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
        [_SYM]  = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
        [_NUM]  = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
        [_NAV]  = { ENCODER_CCW_CW(BACK, FWD) },
        [_FUN]  = { ENCODER_CCW_CW(KC_BRIU, KC_BRID) }
    };
#endif
