/* SPDX-License-Identifier: GPL-2.0-or-later */

#include "kuma980.h"


#ifdef RGB_MATRIX_ENABLE

#    define XX NO_LED
led_config_t g_led_config = {  //

	{
        // Key Matrix to LED Index
        // !! 轴灯对应矩阵的接线顺序
		{XX, XX},
        // !! 轴灯对应矩阵的接线顺序    
	}, 
    {
        // LED Index to Physical Position  
        
        // !! 按接线顺序排列轴灯的物理位置
	}, 
    {
        // LED Index to Flag
        //!! 每个灯是干啥用的
	}
    
};

#endif

// uf2跳转bl
#define MAGIC_BOOT 0x544F4F42UL
#define MAGIC_REG *(volatile uint32_t*)0x20004000
void bootloader_jump(void) {
    MAGIC_REG = MAGIC_BOOT;
    NVIC_SystemReset();
}