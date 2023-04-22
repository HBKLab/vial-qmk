# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # 开启boot按键(Enable Bootmagic Lite)
MOUSEKEY_ENABLE = yes       # 模拟鼠标 (Mouse keys)
EXTRAKEY_ENABLE = yes       # 音频控制和系统控制 (Audio control and System control)


# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend 灯光休眠

NKRO_ENABLE = yes           # 全键无冲


# NO
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
MIDI_ENABLE = no            # MIDI 控制器
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output on port C6
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration

QUANTUM_LIB_SRC += uart.c