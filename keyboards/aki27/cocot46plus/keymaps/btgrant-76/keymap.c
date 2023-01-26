/*
Copyright 2022 aki27
pyright 2023 Brian Grant <@btgrant-76>

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
#include <stdio.h>
#include "quantum.h"
#include "btgrant-76.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_btgrant(
  //|-----------------------------------------------------|                                       |-----------------------------------------------------|
          /*TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,*/ ___BASE_1_L___, ___BASE_1_R___, /*KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,     BSPC,*/
  //|--------+--------+--------+--------+--------+--------|                                       |--------+--------+--------+--------+--------+--------|
          /*ESC,   A_CTL,   S_ALT,   D_GUI,   F_SFT,    KC_G,*/ ___BASE_2_L___, ___BASE_2_R___, /*KC_H,   J_SFT,   K_GUI,   L_ALT,SCLN_CTL,    QUOT,*/
  //|--------+--------+--------+--------+--------+--------|                                       |--------+--------+--------+--------+--------+--------|
        /*L_SFT,   Z_MEH,    KC_X,    KC_C,    KC_V,    KC_B,*/ ___BASE_3_L___, ___BASE_3_R___, /*KC_N,    KC_M, KC_COMM,  KC_DOT,SLSH_ALL,     ENT,*/
  //|--------+--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------+--------|
                                    BACK,       ___BASE_THUMB_L___,  KC_BTN1, KC_BTN2,   ___BASE_THUMB_R___,     FWD,
                             //|-----------------------------------------+--------+------------------------------------------|
                                                                 KC_PGUP, KC_BTN3,  KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_SYM] = LAYOUT_btgrant(
  //|-----------------------------------------------------|                                       |-----------------------------------------------------|
      /*XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,*/  ___SYM_1_L___, ___SYM_1_R___,    /*KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, RCBR_TD,  KC_DEL,*/
  //|--------+--------+--------+--------+--------+--------|                                       |--------+--------+--------+--------+--------+--------|
      /*KC_CAPS, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,*/  ___SYM_2_L___, ___SYM_2_R___,    /*KC_PLUS,  KC_DLR, KC_PERC, KC_CIRC,  KC_QUOT, KC_TILD,*/
  //|--------+--------+--------+--------+--------+--------|                                       |--------+--------+--------+--------+--------+--------|
      /*_______, KC_LCTL, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX,*/  ___SYM_3_L___, ___SYM_3_R___,    /*KC_PIPE, KC_EXLM,   KC_AT, KC_HASH, KC_TILD, XXXXXXX,*/
  //|--------+--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------+--------|
                                 XXXXXXX, ___SYM_THUMB_L___, /*XXXXXXX, XXXXXXX, XXXXXXX,*/ BACK,     FWD, ___SYM_THUMB_R___, /*KC_UNDS, KC_LPRN, RPRN_TD,*/ XXXXXXX,
                             //|-----------------------------------------+--------+------------------------------------------|
                                                                  XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_NUM] = LAYOUT_btgrant(
  //|-----------------------------------------------------|                                       |-----------------------------------------------------|
      /*XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,*/ ___NUM_1_L___, ___NUM_1_R___, /*KC_LBRC,    KC_7,    KC_8,    KC_9, RBRC_TD, KC_BSPC,*/
  //|--------+--------+--------+--------+--------+--------|                                       |--------+--------+--------+--------+--------+--------|
      /*XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, RGB_SPI,*/ ___NUM_2_L___, ___NUM_2_R___, /*KC_EQL,    KC_4,    KC_5,    KC_6,  KC_DQT, KC_PENT,*/
  //|--------+--------+--------+--------+--------+--------|                                       |--------+--------+--------+--------+--------+--------|
      /*_______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,*/ ___NUM_3_L___, ___NUM_3_R___, /*KC_BSLS,    KC_1,    KC_2,    KC_3, GRAV_TD, _______,*/
  //|--------+--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------+--------|
                                 XXXXXXX, /*KC_MUTE, KC_MPLY, KC_MSTP,*/ ___NUM_THUMB_L___, KC_BTN4, KC_BTN5, ___NUM_THUMB_R___, /*KC_MINS,    KC_0,  KC_DOT,*/ XXXXXXX,
                             //|-----------------------------------------+--------+------------------------------------------|
                                                                  KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_NAV] = LAYOUT_btgrant(
  //|-----------------------------------------------------|                                       |-----------------------------------------------------|
      /*XXXXXXX, TAB_LFT,    BACK,     FWD, TAB_RGT, XXXXXXX,*/ ___NAV_1_L___, ___NAV_1_R___, /*REDO,   PASTE,    COPY,     CUT,    UNDO, XXXXXXX,*/
  //|--------+--------+--------+--------+--------+--------|                                       |--------+--------+--------+--------+--------+--------|
      /*XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,*/ ___NAV_2_L___, ___NAV_2_R___, /*KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_CAPS, XXXXXXX,*/
  //|--------+--------+--------+--------+--------+--------|                                       |--------+--------+--------+--------+--------+--------|
      /*_______, KC_LCTL, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX,*/ ___NAV_3_L___, ___NAV_3_R___, /*KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS, _______,*/
  //|--------+--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------+--------|
                 _______, /*DEL_GUI, KC_BSPC,  KC_ENT,*/ ___NAV_THUMB_L___,  KC_BTN1, KC_BTN2, ___NAV_THUMB_R___, /*XXXXXXX, XXXXXXX, XXXXXXX,*/ _______,
                             //|-----------------------------------------+--------+------------------------------------------|
                                                                 LEFT_SPC,MISS_CTL,  RGHT_SPC,       XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_FUN] = LAYOUT_btgrant(
  //|-----------------------------------------------------|                                       |-----------------------------------------------------|
      /*XXXXXXX, XXXXXXX,  UP_DIR,SCRN2CLP, SCRN2FL, XXXXXXX,*/ ___FUN_1_R___, ___FUN_1_L___,     /*XXXXXXX,   KC_F7,   KC_F8,   F9_TD,  F12_TD, XXXXXXX,*/
  //|--------+--------+--------+--------+--------+--------|                                       |--------+--------+--------+--------+--------+--------|
      /*LOG_OUT, XXXXXXX, DT_PRNT,   DT_UP, DT_DOWN,*/          ___FUN_2_R___, SCRL_MO, ___FUN_2_L___, /*XXXXXXX,   KC_F4,   KC_F5,   F6_TD,  KC_F11, XXXXXXX,*/
  //|--------+--------+--------+--------+--------+--------|                                       |--------+--------+--------+--------+--------+--------|
      SCRL_TO,  CPI_SW, SCRL_SW, ROT_L15, ROT_R15, SCRL_IN,                     ___FUN_3_R___,     /*XXXXXXX,   F1_TD,   F2_TD,   KC_F3,  KC_F10, XXXXXXX,*/
  //|--------+--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------+--------|
         XXXXXXX, /*XXXXXXX,  KC_SPC,  KC_TAB,*/ ___FUN_THUMB_L___,  KC_BTN1, KC_BTN2,     ___FUN_THUMB_L___, /*XXXXXXX, XXXXXXX, XXXXXXX,*/ XXXXXXX,
                             //|-----------------------------------------+--------+------------------------------------------|
                                                                  KC_PGUP, KC_BTN3, KC_PGDN,         XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    )
};


// from default keymap
keyevent_t encoder1_ccw = {
    .key = (keypos_t){.row = 4, .col = 2},
    .pressed = false
};

keyevent_t encoder1_cw = {
    .key = (keypos_t){.row = 4, .col = 5},
    .pressed = false
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            encoder1_cw.pressed = true;
            encoder1_cw.time = (timer_read() | 1);
            action_exec(encoder1_cw);
        } else {
            encoder1_ccw.pressed = true;
            encoder1_ccw.time = (timer_read() | 1);
            action_exec(encoder1_ccw);
        }
    }

    return true;
}


void matrix_scan_user(void) {

    if (IS_PRESSED(encoder1_ccw)) {
        encoder1_ccw.pressed = false;
        encoder1_ccw.time = (timer_read() | 1);
        action_exec(encoder1_ccw);
    }

    if (IS_PRESSED(encoder1_cw)) {
        encoder1_cw.pressed = false;
        encoder1_cw.time = (timer_read() | 1);
        action_exec(encoder1_cw);
    }

}


/*
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    int8_t degree = 45;
    int8_t x_rev, y_rev;
    x_rev =  + mouse_report.x * cos(degree) + mouse_report.y * sin(degree);
    y_rev =  - mouse_report.x * sin(degree) + mouse_report.y * cos(degree);
    if (isScrollMode) {
        mouse_report.h = x_rev;
        #ifdef COCOT_DRAGSCROLL_INVERT
                // Invert vertical scroll direction
                mouse_report.v = -y_rev;
        #else
                mouse_report.v = y_rev;
        #endif
        // mouse_report.v = y_rev;
        mouse_report.x = 0;
        mouse_report.y = 0;
    } else {
        mouse_report.x = x_rev;
        mouse_report.y = y_rev;
    }
    return mouse_report;
}
*/

int hue_fst = -1;
int sat_fst = -1;
int val_fst = -1;


layer_state_t layer_state_set_user(layer_state_t state) {
    #ifdef RGBLIGHT_ENABLE
    hue_fst = rgblight_get_hue();
    sat_fst = rgblight_get_sat();
    val_fst = rgblight_get_val();
    #endif

    switch (get_highest_layer(state)) {
    case _SYM:
        #ifdef RGBLIGHT_ENABLE
        rgblight_sethsv_range(HSV_BLUE, 0, 2);
        #endif
        cocot_set_scroll_mode(true);
        break;
    case _NUM:
        #ifdef RGBLIGHT_ENABLE
        rgblight_sethsv_range(HSV_PURPLE, 0, 2);
        #endif
        cocot_set_scroll_mode(true);
        break;
    case _NAV:
        #ifdef RGBLIGHT_ENABLE
        rgblight_sethsv_range(HSV_GREEN, 0, 2);
        #endif
        cocot_set_scroll_mode(false);
        break;
    case _FUN:
        #ifdef RGBLIGHT_ENABLE
        rgblight_sethsv_range(HSV_YELLOW, 0, 2);
        #endif
        cocot_set_scroll_mode(false);
        break;
    default:
        #ifdef RGBLIGHT_ENABLE
        // rgblight_sethsv_range( 0, 0, 0, 0, 2);
        rgblight_sethsv_range(hue_fst, sat_fst, val_fst, 0, 2);
        #endif
        cocot_set_scroll_mode(false);
        break;
    }
    #ifdef RGBLIGHT_ENABLE
    rgblight_set_effect_range( 2, 10);
    #endif
  return state;
};


#ifdef OLED_ENABLE
bool oled_task_user(void) {
    render_logo();
    oled_write_layer_state();
    return false;
}
#endif

// END from default keymap
