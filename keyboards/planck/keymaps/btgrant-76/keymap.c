/* Copyright 2015-2021 Jack Humbert
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
#include "features/achordion.h"

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_btgrant_grid(
        ___5BASE_1_L___,                      XXXXXXX, XXXXXXX,                      ___5BASE_1_R___,
        ___5BASE_2_L___,                      XXXXXXX, XXXXXXX,                      ___5BASE_2_R___,
        ___5BASE_3_L___,                      XXXXXXX, XXXXXXX,                      ___5BASE_3_R___,
        KC_MUTE, XXXXXXX, ___BASE_THUMB_L___, XXXXXXX, XXXXXXX, ___BASE_THUMB_R___, XXXXXXX, XXXXXXX
    ),
    [_NUM] = LAYOUT_btgrant_grid(
        ___5NUM_1_L___,                       XXXXXXX, XXXXXXX,                       ___5NUM_1_R___,
        ___5NUM_2_L___,                       XXXXXXX, XXXXXXX,                       ___5NUM_2_R___,
        ___5NUM_3_L___,                       XXXXXXX, XXXXXXX,                       ___5NUM_3_R___,
        KC_HOME, XXXXXXX, ___NUM_THUMB_L___,  XXXXXXX, XXXXXXX, ___NUM_THUMB_R___,  XXXXXXX, XXXXXXX
    ),
    [_SYM] = LAYOUT_btgrant_grid(
        ___5SYM_1_L___,                       XXXXXXX, XXXXXXX,                       ___5SYM_1_R___,
        ___5SYM_2_L___,                       XXXXXXX, XXXXXXX,                       ___5SYM_2_R___,
        ___5SYM_3_L___,                       XXXXXXX, XXXXXXX,                       ___5SYM_3_R___,
        KC_MPLY, XXXXXXX, ___SYM_THUMB_L___,  XXXXXXX, XXXXXXX, ___SYM_THUMB_R___,  XXXXXXX, XXXXXXX
    ),
    [_NAV] = LAYOUT_btgrant_grid(
        ___5NAV_1_L___,                       XXXXXXX, XXXXXXX,                       ___5NAV_1_R___,
        ___5NAV_2_L___,                       XXXXXXX, XXXXXXX,                       ___5NAV_2_R___,
        ___5NAV_3_L___,                       XXXXXXX, XXXXXXX,                       ___5NAV_3_R___,
        MISS_CTL,XXXXXXX, ___NAV_THUMB_L___,  XXXXXXX, XXXXXXX, ___NAV_THUMB_R___,  XXXXXXX, XXXXXXX

    ),
    [_FUN] = LAYOUT_btgrant_grid(
        ___5FUN_1_L___,                       XXXXXXX, XXXXXXX,                       ___5FUN_1_R___,
        ___5FUN_2_L___,                       XXXXXXX, XXXXXXX,                       ___5FUN_2_R___,
        ___5FUN_3_L___,                       XXXXXXX, XXXXXXX,                       ___5FUN_3_R___,
        XXXXXXX, XXXXXXX, ___FUN_THUMB_L___,  XXXXXXX, XXXXXXX, ___FUN_THUMB_R___,  XXXXXXX, XXXXXXX
    ),
    [_MSE] = LAYOUT_btgrant_grid(
        ___5MSE_1_L___,                       XXXXXXX, XXXXXXX,                       ___5MSE_1_R___,
        ___5MSE_2_L___,                       XXXXXXX, XXXXXXX,                       ___5MSE_2_R___,
        ___5MSE_3_L___,                       XXXXXXX, XXXXXXX,                       ___5MSE_3_R___,
        MISS_CTL,XXXXXXX, ___MSE_THUMB_L___,  XXXXXXX, XXXXXXX, ___MSE_THUMB_R___,  XXXXXXX, XXXXXXX
    )
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
#ifdef CONSOLE_ENABLE
  debug_enable=true;
#endif
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {

  switch (tap_hold_keycode) {
    case D_GUI:
      if (other_keycode == TAB_FUN) { return true; }
      break;
  }

  // Allow layer tap keys on the bottom row to trigger immediately
  switch (tap_hold_record->event.key.row) {
    case 3:
    case 7:
        return true;
    break;
  }
  return achordion_opposite_hands(tap_hold_record, other_record);
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) { return false; }
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void matrix_scan_user(void) {
// TODO is there a way to disable achordion with a property
  achordion_task();
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    return false;
};

#ifdef ENCODER_MAP_ENABLE
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
        [_BASE] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
        [_NUM]  = { ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
        [_SYM]  = { ENCODER_CCW_CW(KC_MNXT, KC_MPRV) },
        [_NAV]  = { ENCODER_CCW_CW(FWD, BACK) },
        [_FUN]  = { ENCODER_CCW_CW(KC_BRID, KC_BRIU) },
        [_MSE]  = { ENCODER_CCW_CW(LEFT_SPC, RGHT_SPC) }
    };
#endif
