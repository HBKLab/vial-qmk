/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

// #define VIAL_UNLOCK_COMBO_ROWS { 0, 1 }
// #define VIAL_UNLOCK_COMBO_COLS { 0, 1 }

/*需要使用util下的vial_generate_keyboard_uid.py文件生成 */
#define VIAL_KEYBOARD_UID {0xCC, 0xB5, 0xBC, 0xA4, 0x58, 0xD3, 0x1E, 0xAD}

#define DYNAMIC_KEYMAP_LAYER_COUNT 2   /* 键盘层数，默认值为 4 */
#define VIAL_TAP_DANCE_ENTRIES 4       /* Tap Dance 的个数，默认值为 8 */
#define VIAL_COMBO_ENTRIES 4           /* Combo 的个数，默认值为 8 */