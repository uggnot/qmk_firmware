# Default keymap does not have any overridden options from the rev1 / rev2 rules.mk files.
# Example:
#     if you wanted to disable EXTRAKEY_ENABLE, you would copy the line from the rev1/rules.mk file
#     and paste it in to this file, changing the yes to no. Like so:
# EXTRAKEY_ENABLE         = no       # Audio control and System control(+450)
#
# To keep things clean and tidy, as well as make upgrades easier, only place overrides from the defaults in this file.

# NKRO_ENABLE = yes
MOUSEKEY_ENABLE = yes
CONSOLE_ENABLE = no


# RGB Options
RGBLIGHT_ENABLE         = no        # Enable global lighting effects. Do not enable with RGB Matrix
RGBLIGHT_ANIMATIONS     = no        # LED animations
LED_MIRRORED            = no        # Mirror LEDs across halves (enable DIP 1 on slave, and DIP 2 and 3 on master)

RGB_MATRIX_ENABLE       = WS2812    # Enable per-key coordinate based RGB effects. Do not enable with RGBlight
RGB_MATRIX_KEYPRESSES   = no        # Enable reactive per-key effects.
RGB_MATRIX_FRAMEBUFFER_EFFECTS = no # Enable frame buffer effects like the typing heatmap.

RGBLIGHT_FULL_POWER = yes

# Enable Link Time Optimizations greatly reducing firmware size by disabling the old Macros and Functions features
LINK_TIME_OPTIMIZATION_ENABLE = yes 

ifeq ($(strip $(KEYBOARD)), rgbkb/sol/rev2)
  # rev2 overrides
  FULLHAND_ENABLE = yes
endif


# example command line `sudo make rgbkb/sol/rev1:uggnot:flash NO_OLED=yes`

ifeq ($(strip $(NO_OLED)), yes)
  OLED_DRIVER_ENABLE = no
  RGB_OLED_MENU = no
else
  OLED_DRIVER_ENABLE = yes
  RGB_OLED_MENU = 0
endif

# Do not edit past here
include keyboards/$(KEYBOARD)/post_rules.mk
