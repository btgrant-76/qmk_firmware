// ENCODER
#undef ENCODERS_PAD_A
#undef ENCODERS_PAD_B
#define ENCODERS_PAD_A { B5 }
#define ENCODERS_PAD_B { B6 }
#define ENCODER_DIRECTION_FLIP

// RGB strip
#define WS2812_DI_PIN D1 // I have tried D0 as well
#define RGBLED_NUM 9 // I have tried different numbers here. Right now, it's 9 long, but I have tried smaller numbers because my memory tells me that you can successfully address as few as you like.
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
