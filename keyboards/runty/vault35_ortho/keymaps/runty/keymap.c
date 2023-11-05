#include QMK_KEYBOARD_H
#include <string.h>
#include "caps_word.h"
#include "process_unicode.h"

#define ___X___ XXXXXXX // KC_NO
enum phil_keycodes {
    _DUMMY = SAFE_RANGE,

    WIDETXT, // w i d e t e x t   f o r   a   w i d e   b o y
    TAUNTXT, // FoR ThE UlTiMaTe sHiTpOsTiNg eXpErIeNcE

    UC_HELP, // URL for QMK unicode help
    UC_SHRG,              // shrug       - ¯\_(ツ)_/¯
    UC_SLNK,
    UC_PHIL,
#define UC_100  X(E_100)  // hundo       - 💯
#define UC_THUM X(E_THUM) // thumbs up   - 👍
#define UC_CLAP X(E_CLAP) // clap        - 👏
#define UC_EYES X(E_EYES) // shifty eyes - 👀
#define UC_GRIM X(E_GRIM) // grimmace    - 😬
#define UC_THNK X(E_THNK) // thinking    - 🤔
#define UC_UGHH X(E_UGHH) // UGHHHHH     - 😩
#define UC_SWET X(E_SWET) // sweat smile - 😅
#define UC_CRY  X(E_CRY)  // cry laugh   - 😂
#define UC_TONG X(E_TONG) // tongue smile - 😛
#define UC_SCRM X(E_SCRM) // scream      - 😱
#define UC_WRRY X(E_WRRY) // worry       - 😨
#define UC_DOH  X(E_DOH)  // doh         - 😖
#define UC_WAVE X(E_WAVE) // wave        - 👋
#define UC_DROO X(E_DROO) // drool       - 🤤
};

enum unicode_names {
    E_100,
    E_THUM,
    E_CLAP,
    E_EYES,
    E_GRIM,
    E_THNK,
    E_UGHH,
    E_SWET,
    E_CRY,
    E_TONG,
    E_SCRM,
    E_WRRY,
    E_DOH,
    E_WAVE,
    E_DROO,
};

const uint32_t PROGMEM unicode_map[] = {
    [E_THUM]  = 0x1f44d,
    [E_100]  = 0x1f4af,
    [E_EYES] = 0x1f440,
    [E_CLAP] = 0x1f44f,
    [E_GRIM] = 0x1f62c,
    [E_THNK] = 0x1f914,
    [E_UGHH] = 0x1f629,
    [E_SWET] = 0x1f605,
    [E_CRY]  = 0x1f602,
    [E_TONG] = 0x1f61b,
    [E_SCRM] = 0x1f631,
    [E_WRRY] = 0x1f628,
    [E_DOH]  = 0x1f616,
    [E_WAVE] = 0x1f44b,
    [E_DROO] = 0x1f924,
};

#define LT3_QUOT  LT(3, KC_QUOT)
#define LT2_SPACE LT(2, KC_SPACE)
#define LT1_BSPC  LT(1, KC_BSPC)
#define MT_CTL_TB MT(MOD_LCTL,KC_TAB)
#define MT_SFT_SLS MT(MOD_LSFT | MOD_RSFT,KC_SLSH)
#define MT_SFT_UP MT(MOD_LSFT | MOD_RSFT,KC_UP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_8space(
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_MUTE,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  KC_SPC,    KC_H,    KC_J,    KC_K,    KC_L, RSFT_T(KC_QUOT),
         LSFT_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B, KC_BSPC,    KC_N,    KC_M, KC_COMM,  KC_DOT, RSFT_T(KC_SLSH),
         LALT_T(KC_ESC), LGUI_T(KC_TAB), LT1_BSPC, LT2_SPACE, LCTL_T(KC_ENT), KC_DEL

  ), [1] = LAYOUT_split_8space(
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_TRNS, KC_6, KC_7, KC_8, KC_9, KC_0,
        KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,KC_TRNS,  KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TILD,
        KC_CAPS, KC_TRNS, KC_LPRN, KC_RPRN, KC_HOME, KC_TRNS,   KC_PGUP, KC_PGDN, KC_END, LCTL(SGUI(KC_4)), OSL(4),
        KC_TRNS, TG(3), KC_TRNS, KC_MPLY, KC_F16, KC_F18

  ), [2] = LAYOUT_split_8space(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_GRAVE,
        KC_F22, KC_F23, KC_LPRN, KC_RPRN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        QK_BOOT, QK_APPLE_FN, KC_KB_MUTE, KC_MPLY, KC_TRNS, KC_TRNS

  ), [3] = LAYOUT_split_8space(
        KC_PGUP,    KC_HOME,    KC_UP,      KC_END,    KC_WBAK,KC_TRNS,     KC_PSLS,    KC_7,    KC_8,    KC_9,    KC_PMNS,
        KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RGHT,   KC_WFWD, KC_TRNS,     KC_PAST,    KC_4,    KC_5,    KC_6,    KC_TRNS,
        RGB_TOG,    RGB_MOD,    RGB_VAD,    RGB_VAI,   KC_TRNS,KC_TRNS,     KC_0,       KC_1,    KC_2,    KC_3,    KC_PDOT,
         TG(3),      KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_0, TG(3)
  ), [4] = LAYOUT_split_8space(
    UC_100,  UC_WAVE, UC_EYES, _______, UC_THUM, KC_TRNS, UC_DROO, UC_UGHH,  _______, _______, UC_SWET,
    _______, UC_SCRM, UC_DOH,  UC_SHRG, UC_GRIM, KC_TRNS, UC_THNK, UC_TONG,  _______, UC_CRY,  _______,
    _______, TAUNTXT, UC_CLAP, UC_PHIL, UC_WRRY, KC_TRNS, _______,  UC_SLNK, _______, _______, _______,
    _______, _______, _______, _______, _______, _______
  ),

};

bool mouse_jiggler_enabled = false;
static uint16_t mouse_jiggler_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool tAuNtTeXt = false;
    static bool taunt = false;

    if (tAuNtTeXt) {
        if (record->event.pressed) {
            if (keycode != KC_SPC) {
                taunt = !taunt;
                if (taunt)
                    add_weak_mods(MOD_BIT(KC_LSFT));
            }
        }
    }

  switch (keycode) {
    case KC_F22:
        mouse_jiggler_enabled = true;
        return false;
    case KC_F23:
        mouse_jiggler_enabled = false;
        return false;
    case KC_F16:
        if (record->event.pressed) {
            toggle_caps_word_mode(CWMODE_CONSTANT_CASE);
            return false;
        }
    case KC_F18:
        if (record->event.pressed) {
            toggle_caps_word_mode(CWMODE_CAMEL_CASE);
            return false;
        }
    case UC_SHRG: // ¯\_(ツ)_/¯
        if (record->event.pressed) {
            send_unicode_string("(╯°□°)╯︵ ┻━┻");
        }
        return false;
    case UC_SLNK:
        if (record->event.pressed) {
            SEND_STRING("test\n");
        }
        return false;
    case UC_PHIL:
        if (record->event.pressed) {
            SEND_STRING("test   \n");
        }
        return false;
    case TAUNTXT:
        if (record->event.pressed) {
            tAuNtTeXt = !tAuNtTeXt;
            // when it's turned on, toggle caps lock (makes first letter lowercase)
            if (tAuNtTeXt) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
        }
        return false;
  }
  return true;
}

bool has_mouse_report_changed(report_mouse_t* new_report, report_mouse_t* old_report) {
  // Only report every 5 seconds.
  if (mouse_jiggler_enabled && timer_elapsed(mouse_jiggler_timer) > 5000) {
    mouse_jiggler_timer = timer_read();
    tap_code(KC_MS_UP);
    return mouse_jiggler_enabled;
  }
  return memcmp(new_report, old_report, sizeof(report_mouse_t));
}

void eeconfig_init_user(void) {
    set_unicode_input_mode(UNICODE_MODE_MACOS);
}


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_90;
};

void oled_render_layer_state(void) {
    oled_write_P(PSTR("\n\nLayer\n"), false);
    switch (layer_state) {
        case 0:
            oled_write_ln_P(PSTR("-Base-"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("-Lwr-"), false);
            break;
        case 2:
            oled_write_ln_P(PSTR("-Rai-"), false);
            break;
        case 3:
            oled_write_ln_P(PSTR("-Cfg-"), false);
            break;
        case 4:
            oled_write_ln_P(PSTR("-Emoji-"), false);
            break;
        default :
            oled_write_ln_P(PSTR("-MUL-"), false);
    }
}

void oled_render_caps_state(void){
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_ln_P(led_state.caps_lock ? PSTR("\n=CAPS\n") : PSTR("\n    \n\n"), false);
}

bool oled_task_user(void) {
    oled_render_layer_state();
    oled_render_caps_state();
    return true;
};




