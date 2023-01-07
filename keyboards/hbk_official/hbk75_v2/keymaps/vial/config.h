/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

// #define VIAL_UNLOCK_COMBO_ROWS { 0, 1 }
// #define VIAL_UNLOCK_COMBO_COLS { 0, 1 }

/*需要使用util下的vial_generate_keyboard_uid.py文件生成 */
#define VIAL_KEYBOARD_UID {0x75, 0x39, 0x1D, 0x68, 0x7D, 0x49, 0x89, 0x15}

#define DYNAMIC_KEYMAP_LAYER_COUNT 4   /* 键盘层数，默认值为 4 */
#define VIAL_TAP_DANCE_ENTRIES 8       /* Tap Dance 的个数，默认值为 8 */
#define VIAL_COMBO_ENTRIES 8           /* Combo 的个数，默认值为 8 */