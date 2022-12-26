VIA_ENABLE = yes
VIAL_ENABLE = yes

# 开启RGB效果
VIALRGB_ENABLE = yes
# 开启旋钮效果
VIAL_ENCODERS_ENABLE = yes

# 编码器
ENCODER_ENABLE = no		
# 编码器映射	
ENCODER_MAP_ENABLE = no	

# RGB设置
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
WS2812_DRIVER = pwm
UNDERGLOW_RGB_MATRIX_ENABLE = yes
RGB_MATRIX_CONTROL_ENABLE = yes

#关闭安全检查（不关的话每次打开 Vial 要长按特定键才能改键
VIAL_INSECURE = yes 
#压缩代码，减小固件体积       
LTO_ENABLE = yes           