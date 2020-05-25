#include "simple_visualizer.h"

// This function should be implemented by the keymap visualizer
// Don't change anything else than state->target_lcd_color and state->layer_text as that's the only thing
// that the simple_visualizer assumes that you are updating
// Also make sure that the buffer passed to state->layer_text remains valid until the previous animation is
// stopped. This can be done by either double buffering it or by using constant strings
static void get_visualizer_layer_and_color(visualizer_state_t* state) {
    uint8_t saturation = 255;
    uint8_t brightness = 0;
    if (state->status.leds & (1u << USB_LED_CAPS_LOCK)) {
        saturation = 60;
        brightness = 255;
    }
    if (state->status.layer & 0x4) {
        state->target_lcd_color = LCD_COLOR(0, saturation, 0xFF);
        state->layer_text = "Layer 3";
    }
    else if (state->status.layer & 0x2) {
        state->target_lcd_color = LCD_COLOR(84, saturation, 0xFF);
        state->layer_text = "Layer 2";
    }
    else {
        state->target_lcd_color = LCD_COLOR(168, saturation, brightness);
        state->layer_text = "Default";
    }
}
