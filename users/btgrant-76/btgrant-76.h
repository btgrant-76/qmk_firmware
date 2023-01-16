/*
Copyright 2023 Brian Grant <@btgrant-76>

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

#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

enum layer_names {
    _BASE,
    _SYM,
    _NUM,
    _NAV,
    _FUN
};

enum custom_keycodes {
    SCRN2CLP = SAFE_RANGE, // macOS take screenshot to the clip board (crkbd: y; waka: y; cocot46plus: y)
    SCRN2FL, // macOS take screenshot to a file
    QUO_INST, // TODO set up a tap dance for this
    UP_DIR,
    LOG_OUT,
    NEW_SAFE_RANGE
};

// Tap Dance declarations
enum {
    TD_ESC_CAPS,
    TD_RBRC,
    TD_RCBR,
    TD_RPRN,
    TD_GRAV,
    TD_F1,
    TD_F2,
    TD_F6,
    TD_F9,
    TD_F12,
};

// Layer Keys
#define DEL_FUN LT(_FUN, KC_DEL)
#define BS_SYM LT(_SYM, KC_BSPC)
#define ESC_SYM LT(_SYM, XXXXXXX) // KC_ESC)
#define TAB_NUM LT(_NUM, XXXXXXX) // KC_TAB)
#define ENT_MED LT(_NUM, KC_ENT)
#define SPC_NAV LT(_NAV, KC_SPC)
#define BS_MOUS LT(_FUN, XXXXXXX) // KC_BSPC)

#define ESC_L1 LT(1, KC_ESC)
#define G_NUM LT(_NUM, KC_G)
#define H_SYM LT(_SYM, KC_H)
#define BS_SYM LT(_SYM, KC_BSPC)
#define ESC_FUN LT(_FUN, KC_ESC)
#define ENT_NUM LT(_NUM, KC_ENT)


// Outer columns
#undef ENABLE_QAZ
/// left
#ifdef ENABLE_QAZ
#define TAB XXXXXXX
#define ESC XXXXXXX
#define L_SFT XXXXXXX
#else
#define TAB KC_TAB
#define ESC KC_ESC
#define L_SFT KC_LSFT
#endif

/// right
#ifdef ENABLE_QAZ
#define BSPC XXXXXXX
#define QUOT XXXXXXX
#define ENT XXXXXXX
#define ENT_SFT XXXXXXX
#else
#define BSPC KC_BSPC
#define QUOT KC_QUOT
#define ENT KC_ENT
#define ENT_SFT RSFT_T(KC_ENT)
#endif
// Outer columns end

// Mod Tap
/// Home Row Mods
#define A_CTL LCTL_T(KC_A)
#define S_ALT LALT_T(KC_S)
#define D_GUI LGUI_T(KC_D)
#define F_SFT LSFT_T(KC_F)
#define J_SFT RSFT_T(KC_J)
#define K_GUI RGUI_T(KC_K)
#define L_ALT RALT_T(KC_L)
#define SCLN_CTL RCTL_T(KC_SCLN)

/// Others
#define Z_CTL LCTL_T(KC_Z)
#define X_ALT LALT_T(KC_X)
#define DOT_ALT LALT_T(KC_DOT)
#define SLSH_CTL LCTL_T(KC_SLSH)
#define QUOT_MEH MEH_T(KC_QUOT)
#define QUOT_ALL ALL_T(KC_QUOT)
#define SCLN_ALL ALL_T(KC_SCLN)
#define SLSH_ALL ALL_T(KC_SLSH)
#define ESC_MEH MEH_T(KC_ESC)
#define Z_MEH MEH_T(KC_Z)

/// Thumb keys
#define DEL_GUI LGUI_T(KC_DEL)
#define SPC_MEH MEH_T(KC_SPC)

// Shortcuts
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#define UNDO LGUI(KC_Z)
#define REDO LSG(KC_Z)

/// macOS navigation
#define MISS_CTL LCTL(KC_UP)
#define LEFT_SPC LCTL(KC_LEFT)
#define RGHT_SPC LCTL(KC_RIGHT)

/// Shifted Keys
#define COLON LSFT(KC_SCLN)

/// Other shortcuts
#define BACK LCMD(KC_LBRC)
#define FWD LCMD(KC_RBRC)
#define TAB_LFT LSG(KC_LBRC)
#define TAB_RGT LSG(KC_RBRC)
#define Z_MUTE MEH_T(KC_SPC)

#ifdef TAP_DANCE_ENABLE
// Tap Dances
#define GRAV_TD TD(TD_GRAV)
#define RPRN_TD TD(TD_RPRN)
#define RBRC_TD TD(TD_RBRC)
#define RCBR_TD TD(TD_RCBR)
#define F1_TD TD(TD_F1)
#define F2_TD TD(TD_F2)
#define F6_TD TD(TD_F6)
#define F9_TD TD(TD_F9)
#define F12_TD TD(TD_F12)
#endif // TAP_DANCE_ENABLE

// portable keymaps
#define ___BASE_THUMB_L___ DEL_FUN, ESC_SYM, TAB_NUM
#define ___BASE_THUMB_R___ ENT_MED, SPC_NAV,  BS_MOUS

#define LAYOUT_btgrant_3x6(...) LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_btgrant(...) LAYOUT(__VA_ARGS__)
// portable keymaps end

#endif
