/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0008
#define MANUFACTURER    Vial
#define PRODUCT         Keyboard101

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 19

#define MATRIX_ROW_PINS { E6, B0, B1, B2, B3, B7 }
#define MATRIX_COL_PINS { C7, F7, F5, F4, F1, F0, F6, D0, D1, D2, D3, D5, D4, D6, D7, B4, B5, B6, C6}

#define DIODE_DIRECTION COL2ROW

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Use 1000hz polling */
#define USB_POLLING_INTERVAL_MS 1
