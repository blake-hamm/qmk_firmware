#include QMK_KEYBOARD_H

enum custom_keycodes {
    COPY = SAFE_RANGE,
    PASTE,
    CUT,
    SAVE,
    REDO,
    UNDO,
    DRAG_SCROLL_ENT,
};

os_variant_t detected_os = OS_UNSURE;


/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x5_2(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, DRAG_SCROLL_ENT, LT(2,KC_SPC), LT(1,KC_BSPC), LT(3,KC_DEL)),
	[1] = LAYOUT_split_3x5_2(KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_QUOT, KC_4, KC_5, KC_6, KC_EQL, KC_NO, KC_RSFT, KC_NO, KC_NO, KC_NO, KC_GRV, KC_1, KC_2, KC_3, KC_MINS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_0, KC_BSLS, KC_NO, KC_NO),
	[2] = LAYOUT_split_3x5_2(KC_WH_R, KC_WH_D, KC_WH_U, KC_WH_L, KC_NO, REDO, PASTE, COPY, CUT, UNDO, KC_NO, SAVE, KC_BTN2, KC_BTN1, KC_NO, KC_CAPS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO, KC_NO, KC_TAB, KC_ESC),
	[3] = LAYOUT_split_3x5_2(KC_LEFT_CURLY_BRACE, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_RIGHT_CURLY_BRACE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DOUBLE_QUOTE, KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_PLUS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TILDE, KC_EXCLAIM, KC_AT, KC_HASH, KC_UNDERSCORE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RIGHT_PAREN, KC_BSLS, KC_NO, KC_NO)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)



// CUSTOM BELOW

// DRAG_SCROLL key
bool set_scrolling = false;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        mouse_report.h = -mouse_report.x;
        mouse_report.v = mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}


// Process host os
bool process_detected_host_os_kb(os_variant_t os) {
    if (!process_detected_host_os_user(os)) {
        return false;
    }
    detected_os = os;  // Update the global variable
    // switch (detected_os) {
    //     case OS_MACOS:
    //     case OS_IOS:
    //         break;
    //     case OS_WINDOWS:
    //         break;
    //     case OS_LINUX:
    //         break;
    //     case OS_UNSURE:
    //         break;
    // }

    return true;
}

// Define custom keycodes for undo and redo based on OS detection
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t ds_timer;

    switch (keycode) {
        // TODO: Switch to tap dance - https://docs.qmk.fm/features/tap_dance
        case DRAG_SCROLL_ENT:
            if (record->event.pressed) {
                ds_timer = timer_read();  // Start the timer when the key is pressed
                set_scrolling = true;
            } else {
                if (timer_elapsed(ds_timer) < TAPPING_TERM) {
                    // If tapped, send Enter
                    tap_code(KC_ENT);
                }
                // Ensure scrolling is disabled when the key is released
                set_scrolling = false;
            }
            return false;

        case COPY:
            if (record->event.pressed) {
                if (detected_os == OS_MACOS) {
                    register_code(KC_LGUI);
                    register_code(KC_C);
                } else {
                    register_code(KC_LCTL);
                    register_code(KC_C);
                }
            } else {
                if (detected_os == OS_MACOS) {
                    unregister_code(KC_C);
                    unregister_code(KC_LGUI);
                } else {
                    unregister_code(KC_C);
                    unregister_code(KC_LCTL);
                }
            }
            return false;

        case PASTE:
            if (record->event.pressed) {
                if (detected_os == OS_MACOS) {
                    register_code(KC_LGUI);
                    register_code(KC_V);
                } else {
                    register_code(KC_LCTL);
                    register_code(KC_V);
                }
            } else {
                if (detected_os == OS_MACOS) {
                    unregister_code(KC_V);
                    unregister_code(KC_LGUI);
                } else {
                    unregister_code(KC_V);
                    unregister_code(KC_LCTL);
                }
            }
            return false;

        case CUT:
            if (record->event.pressed) {
                if (detected_os == OS_MACOS) {
                    register_code(KC_LGUI);
                    register_code(KC_X);
                } else {
                    register_code(KC_LCTL);
                    register_code(KC_X);
                }
            } else {
                if (detected_os == OS_MACOS) {
                    unregister_code(KC_X);
                    unregister_code(KC_LGUI);
                } else {
                    unregister_code(KC_X);
                    unregister_code(KC_LCTL);
                }
            }
            return false;

        case SAVE:
            if (record->event.pressed) {
                if (detected_os == OS_MACOS) {
                    register_code(KC_LGUI);
                    register_code(KC_S);
                } else {
                    register_code(KC_LCTL);
                    register_code(KC_S);
                }
            } else {
                if (detected_os == OS_MACOS) {
                    unregister_code(KC_S);
                    unregister_code(KC_LGUI);
                } else {
                    unregister_code(KC_S);
                    unregister_code(KC_LCTL);
                }
            }
            return false;

        case REDO:
            if (record->event.pressed) {
                if (detected_os == OS_MACOS) {
                    // On macOS, Cmd + Shift + Z is redo
                    register_code(KC_LGUI);
                    register_code(KC_LSFT);
                    register_code(KC_Z);
                } else {
                    // On Linux, Ctrl + Shift + Z is redo
                    register_code(KC_LCTL);
                    register_code(KC_LSFT);
                    register_code(KC_Z);
                }
            } else {
                if (detected_os == OS_MACOS) {
                    unregister_code(KC_Z);
                    unregister_code(KC_LSFT);
                    unregister_code(KC_LGUI);
                } else {
                    unregister_code(KC_Z);
                    unregister_code(KC_LSFT);
                    unregister_code(KC_LCTL);
                }
            }
            return false;

        case UNDO:
            if (record->event.pressed) {
                if (detected_os == OS_MACOS) {
                    // On macOS, Cmd + Z is undo
                    register_code(KC_LGUI);
                    register_code(KC_Z);
                } else {
                    // On Linux, Ctrl + Z is undo
                    register_code(KC_LCTL);
                    register_code(KC_Z);
                }
            } else {
                if (detected_os == OS_MACOS) {
                    unregister_code(KC_Z);
                    unregister_code(KC_LGUI);
                } else {
                    unregister_code(KC_Z);
                    unregister_code(KC_LCTL);
                }
            }
            return false; // We handled this keycode, do not process further

        // Add more cases here for additional custom keycodes

        default:
            return true; // Process all other keycodes normally
    }
    return true; // Process all other keycodes normally;
}
