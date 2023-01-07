/* SPDX-License-Identifier: GPL-2.0-or-later */

#include "hbk75_v2.h"


#ifdef RGB_MATRIX_ENABLE

#    define XX NO_LED
led_config_t g_led_config = {  //

	{
        // Key Matrix to LED Index
        // !! 轴灯对应矩阵的接线顺序
		{ 0,  1,  2,  3,  4,  3,  1,  0,  3,  1,  2,  1,  2,  4 },
		{ 1,  3,  4,  2,  3,  2,  0,  4,  3,  2,  1,  4,  0,  3 },
		{ 4,  2,  2,  1,  4,  2,  1,  0,  0,  3,  2,  1,  2,  4 },
		{ 1,  3,  1,  2,  3,  2,  2,  3,  2,  1,  4,  2,  3,  1 },
		{ 0,  3,  1,  0,  3,  2,  0,  3,  0,  1,  0,  2,  0,  1 },
		{ 1,  3,  2,  4, XX, XX, XX, XX, XX,  2,  4,  4,  0,  2 },
        // !! 轴灯对应矩阵的接线顺序    
	}, 
    {
        // LED Index to Physical Position  
        {7, 2}, {32, 2}, {46, 2}, {60, 2}, {74, 2}

        // !! 按接线顺序排列轴灯的物理位置
	}, 
    {
        // LED Index to Flag
		4, 4, 4, 4, 4
        //!! 每个灯是干啥用的
	}
    // {
        
    //     {0, 1},  //
    //     {2, 3}  // !! 轴灯对应矩阵的接线顺序
    // },
    // {
    //     // LED Index to Physical Position                                                                                                                                               
    //     {2, 3},    {19, 3},     // row0
    //     {184, 16}, {163, 16}   // row1
    //     //!! 按接线顺序排列轴灯的物理位置
    // },

    // {
    //     // LED Index to Flag
    //     4, 4,  //
    //     2, 2  //!! 每个灯是干啥用的

		// {7, 2}, {32, 2}, {46, 2}, {60, 2}, {74, 2}, {91, 2}, {105, 2}, {119, 2}, {133, 2}, {150, 2}, {164, 2}, {178, 2}, {192, 2}, {217, 2}, 
		// {7, 15}, {21, 15}, {35, 15}, {49, 15}, {63, 15}, {77, 15}, {91, 15}, {105, 15}, {119, 15}, {133, 15}, {147, 15}, {161, 15}, {175, 15}, {217, 15}, 		
		// {10, 25}, {28, 25}, {42, 25}, {56, 25}, {70, 25}, {84, 25}, {98, 25}, {112, 25}, {126, 25}, {140, 25}, {154, 25}, {168, 25}, {182, 25}, {196, 15},		
		// {12, 36}, {32, 36}, {46, 36}, {60, 36}, {74, 36}, {88, 36}, {102, 36}, {116, 36}, {130, 36}, {144, 36}, {158, 36}, {172, 36}, {194, 36}, {200, 25}, 
		// {16, 46}, {38, 46}, {52, 46}, {66, 46}, {80, 46}, {94, 46}, {108, 46}, {122, 46}, {136, 46}, {150, 46}, {164, 46}, {184, 46}, {203, 46}, {217, 25}, 
		// {9, 56}, {26, 56}, {44, 56}, {96, 56}, {149, 56}, {166, 56}, {189, 56}, {203, 56}, {217, 56}, 
    
};

#endif

// uf2跳转bl
#define MAGIC_BOOT 0x544F4F42UL
#define MAGIC_REG *(volatile uint32_t*)0x20004000
void bootloader_jump(void) {
    MAGIC_REG = MAGIC_BOOT;
    NVIC_SystemReset();
}