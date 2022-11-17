#include "btgrant-76.h"

// Tap Dance & macro functions
void braces_insert(void) {
    SEND_STRING("[]" SS_TAP(X_LEFT));
};

void curly_braces_insert(void) {
    SEND_STRING("{}" SS_TAP(X_LEFT));
};

void parens_insert(void) {
    SEND_STRING("()" SS_TAP(X_LEFT));
};

void grave_pair_cursor_insertion(void) {
    SEND_STRING("``" SS_TAP(X_LEFT));
}

void macos_log_out(void) {
    register_code(KC_LGUI);
    register_code(KC_LCTL);
    tap_code(KC_Q);
    unregister_code(KC_LGUI);
    unregister_code(KC_LCTL);
}

void code_fence(void) {
    SEND_STRING("```" SS_TAP(X_ENT) SS_TAP(X_ENT) "```" SS_TAP(X_UP));
}

void braces_tap_dance(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_RBRC);
    } else {
        braces_insert();
    }
};

void curly_brace_tap_dance(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING("}");
    } else {
        curly_braces_insert();
    }
};

void parens_tap_dance(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(")");
    } else {
        parens_insert();
    }
};

void grave_tap_dance(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        grave_pair_cursor_insertion();
    } else if (state->count == 4){
        code_fence();
    } else {
        SEND_STRING("`");
    }
};

void f1_tap_dance(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_F1);
    } else if (state->count == 2) {
        register_code(KC_LGUI);
        tap_code(KC_1);
        unregister_code(KC_LGUI);
    } else if (state->count == 3) {
        register_code(KC_LALT);
        tap_code(KC_F1);
        unregister_code(KC_LALT);
    }
}

void f2_tap_dance(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_F2);
    } else if (state->count == 2) {
        register_code(KC_LGUI);
        tap_code(KC_F2);
        unregister_code(KC_LGUI);
    }
}

void f6_tap_dance(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_F6);
    } else if (state->count == 2) {
        register_code(KC_LCTL);
        tap_code(KC_T);
        unregister_code(KC_LCTL);
    }
}

void f9_tap_dance(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_F9);
    } else if (state->count == 2) {
        register_code(KC_LGUI);
        tap_code(KC_9);
        unregister_code(KC_LGUI);
    }
}

void f12_tap_dance(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_F12);
    } else if (state->count == 2) {
        register_code(KC_LALT);
        tap_code(KC_F12);
        unregister_code(KC_LALT);
    } else if (state->count == 3) {
        register_code(KC_LGUI);
        tap_code(KC_F12);
        unregister_code(KC_LGUI);
    }
}
// END:  Tap Dance & macro functions

// Tap Dance definition
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    [TD_RBRC] = ACTION_TAP_DANCE_FN(braces_tap_dance),
    [TD_RCBR] = ACTION_TAP_DANCE_FN(curly_brace_tap_dance),
    [TD_RPRN] = ACTION_TAP_DANCE_FN(parens_tap_dance),
    [TD_GRAV] = ACTION_TAP_DANCE_FN(grave_tap_dance),
    [TD_F1] = ACTION_TAP_DANCE_FN(f1_tap_dance),
    [TD_F2] = ACTION_TAP_DANCE_FN(f2_tap_dance),
    [TD_F6] = ACTION_TAP_DANCE_FN(f6_tap_dance),
    [TD_F9] = ACTION_TAP_DANCE_FN(f9_tap_dance),
    [TD_F12] = ACTION_TAP_DANCE_FN(f12_tap_dance),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SCRN2CLP:
        if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_LCTRL);
            register_code(KC_LSHIFT);
            register_code(KC_4);

            unregister_code(KC_LGUI);
            unregister_code(KC_LCTRL);
            unregister_code(KC_LSHIFT);
            unregister_code(KC_4);
        }
        return false;
    case SCRN2FL:
        if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_LSHIFT);
            register_code(KC_4);

            unregister_code(KC_LGUI);
            unregister_code(KC_LSHIFT);
            unregister_code(KC_4);
        }
        return false;
//    case Z_MUTE:
//        if (record->event.pressed) {
//            register_code(KC_LGUI);
//            register_code(KC_LSHIFT);
//            register_code(KC_A);
//
//            unregister_code(KC_LGUI);
//            unregister_code(KC_LSHIFT);
//            unregister_code(KC_A);
//        }
//        return false;
    case BRC_INST:
        if (record->event.pressed) {
            braces_insert();
        }
        return false;
    case CBR_INST:
        if (record->event.pressed) {
            curly_braces_insert();
        }
        return false;
    case PRN_INST:
        if (record->event.pressed) {
            parens_insert();
        }
        return false;
    case GRV_INST:
        if (record->event.pressed) {
            grave_pair_cursor_insertion();
        }
        return false;
    case QUO_INST:
        if (record->event.pressed) {
            SEND_STRING("\"\"");
            tap_code(KC_LEFT);
        }
        return false;
    case UP_DIR:
        if (record->event.pressed) {
            SEND_STRING("../");
        }
        return false;
    case LOG_OUT:
        if (record->event.pressed) {
            macos_log_out();
        }
        return false;
  }
  return true;
}
