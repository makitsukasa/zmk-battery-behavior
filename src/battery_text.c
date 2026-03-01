#include <zephyr/kernel.h>
#include <zmk/behavior.h>
#include <zmk/behavior_queue.h>
#include <zmk/keymap.h>
#include <zmk/hid.h>

static int behavior_battery_text_pressed(struct zmk_behavior_binding *binding,
                                         struct zmk_behavior_binding_event event) {

    const char *text = "BATTERY:100%";

    while (*text) {
        zmk_hid_keyboard_press(*text);
        zmk_hid_keyboard_release(*text);
        text++;
    }

    return ZMK_BEHAVIOR_OPAQUE;
}

static int behavior_battery_text_released(struct zmk_behavior_binding *binding,
                                          struct zmk_behavior_binding_event event) {
    return ZMK_BEHAVIOR_OPAQUE;
}

ZMK_BEHAVIOR_DEFINE(battery_text, NULL,
    behavior_battery_text_pressed,
    behavior_battery_text_released);
