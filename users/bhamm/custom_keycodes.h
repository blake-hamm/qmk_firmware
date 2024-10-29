#ifndef CUSTOM_KEYCODES_H
#define CUSTOM_KEYCODES_H

#include QMK_KEYBOARD_H

// Enum for custom keycodes
enum custom_keycodes {
    BH_COPY = SAFE_RANGE,
    BH_PASTE,
    BH_CUT,
    BH_SAVE,
    BH_REDO,
    BH_UNDO,
    // BH_DRAG_SCROLL_ENT,
};

os_variant_t detected_os = OS_UNSURE;

// Function prototype
bool process_custom_keycodes(uint16_t keycode, keyrecord_t *record);

#endif
