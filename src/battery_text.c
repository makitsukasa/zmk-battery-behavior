#include <zephyr/kernel.h>
#include <zmk/behavior.h>
#include <zmk/behavior_queue.h>
#include <zmk/keymap.h>
#include <zmk/hid.h>

static int behavior_battery_pressed(struct zmk_behavior_binding *binding,
                                    struct zmk_behavior_binding_event event) {

    // HID Usage ID for keyboard
    // 'B'=0x05, 'A'=0x04, 'T'=0x17, 'E'=0x08, 'R'=0x15, 'Y'=0x1C
    // ':'=0x33, '1'=0x1E, '0'=0x27, '%'=0x22
    const uint8_t battery_codes[] = {
        0x05, 0x04, 0x17, 0x17, 0x08, 0x15, 0x1C,  // BATTERY
        0x33,                                        // :
        0x1e, 0x27, 0x27,                           // 100
        0x22                                         // %
    };

    for (int i = 0; i < sizeof(battery_codes) / sizeof(battery_codes[0]); i++) {
        zmk_hid_keyboard_press(battery_codes[i]);
        k_msleep(10);
        zmk_hid_keyboard_release(battery_codes[i]);
        k_msleep(10);
    }

    return ZMK_BEHAVIOR_OPAQUE;
}

static int behavior_battery_released(struct zmk_behavior_binding *binding,
                                     struct zmk_behavior_binding_event event) {
    return ZMK_BEHAVIOR_OPAQUE;
}

ZMK_BEHAVIOR_DEFINE(battery,\
    NULL,\
    behavior_battery_pressed,\
    behavior_battery_released);
