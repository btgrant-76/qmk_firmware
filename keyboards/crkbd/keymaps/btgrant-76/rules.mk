RGBLIGHT_ENABLE = yes    # Enable WS2812 RGB underlight.
VIA_ENABLE      = no    # reclaims 2,278 bytes
OLED_ENABLE     = yes
OLED_DRIVER     = SSD1306
LTO_ENABLE      = yes
COMBO_ENABLE    = no # FIXME yes doesn't compile
TAP_DANCE_ENABLE = yes #  1028 bytes

# space-savings
MOUSEKEY_ENABLE = no # 1334 free
AVR_USE_MINIMAL_PRINTF = yes # 1726 free
KEY_OVERRIDE_ENABLE = no # 1726 free
SPACE_CADET_ENABLE = no # 2042 free
GRAVE_ESC_ENABLE = no # 2122 free
MAGIC_ENABLE = no # 2814 free

# disabled in parent
COMMAND_ENABLE = no # disabled in parent
CONSOLE_ENABLE = no # disabled in parent
MUSIC_ENABLE = no # already disabled by AUDIO_ENABLE = no?
