#include "custom_keycodes.h"

// Define custom keycodes for undo and redo based on OS detection
bool process_custom_keycodes(uint16_t keycode, keyrecord_t *record) {
    // static uint16_t ds_timer;

    switch (keycode) {
        // case BH_DRAG_SCROLL_ENT:
        //     if (record->event.pressed) {
        //         ds_timer = timer_read();  // Start the timer when the key is pressed
        //     } else {
        //         if (timer_elapsed(ds_timer) > TAPPING_TERM) {
        //             // If held longer than TAPPING_TERM, trigger DRAG_SCROLL
        //             set_scrolling = !set_scrolling;
        //         } else {
        //             // If tapped, send Enter
        //             tap_code(KC_ENT);
        //         }
        //     }
        //     return false;

        case BH_COPY:
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

        case BH_PASTE:
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

        case BH_CUT:
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

        case BH_SAVE:
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

        case BH_REDO:
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

        case BH_UNDO:
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
    return true; // Process all other keycodes normally
}
