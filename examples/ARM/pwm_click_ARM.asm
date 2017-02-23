_system_init:
;pwm_click_ARM.c,5 :: 		void system_init()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;pwm_click_ARM.c,18 :: 		GPIO_Digital_Output( &GPIOC_BASE, _GPIO_PINMASK_2 );
MOVW	R1, #4
MOVW	R0, #lo_addr(GPIOC_BASE+0)
MOVT	R0, #hi_addr(GPIOC_BASE+0)
BL	_GPIO_Digital_Output+0
;pwm_click_ARM.c,19 :: 		Delay_ms( 200 );
MOVW	R7, #40703
MOVT	R7, #36
NOP
NOP
L_system_init0:
SUBS	R7, R7, #1
BNE	L_system_init0
NOP
NOP
NOP
;pwm_click_ARM.c,20 :: 		I2C1_Init_Advanced( 100000, &_GPIO_MODULE_I2C1_PB67 );
MOVW	R1, #lo_addr(__GPIO_MODULE_I2C1_PB67+0)
MOVT	R1, #hi_addr(__GPIO_MODULE_I2C1_PB67+0)
MOVW	R0, #34464
MOVT	R0, #1
BL	_I2C1_Init_Advanced+0
;pwm_click_ARM.c,21 :: 		Delay_ms( 200 );
MOVW	R7, #40703
MOVT	R7, #36
NOP
NOP
L_system_init2:
SUBS	R7, R7, #1
BNE	L_system_init2
NOP
NOP
NOP
;pwm_click_ARM.c,22 :: 		}
L_end_system_init:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _system_init
_main:
;pwm_click_ARM.c,24 :: 		void main()
SUB	SP, SP, #4
;pwm_click_ARM.c,26 :: 		system_init();
BL	_system_init+0
;pwm_click_ARM.c,27 :: 		pwm_click_init( 0x40 );
MOVS	R0, #64
BL	_pwm_click_init+0
;pwm_click_ARM.c,28 :: 		pwm_set_all( 50 );
MOVS	R0, #50
BL	_pwm_set_all+0
;pwm_click_ARM.c,29 :: 		pwm_set_channel( 0, 0, 20 );
MOVS	R2, #20
MOVS	R1, #0
MOVS	R0, #0
BL	_pwm_set_channel+0
;pwm_click_ARM.c,30 :: 		pwm_set_channel( 1, 0, 40 );
MOVS	R2, #40
MOVS	R1, #0
MOVS	R0, #1
BL	_pwm_set_channel+0
;pwm_click_ARM.c,31 :: 		pwm_set_channel_raw( 4, 2048, 2085 );
MOVW	R2, #2085
MOVW	R1, #2048
MOVS	R0, #4
BL	_pwm_set_channel_raw+0
;pwm_click_ARM.c,32 :: 		pwm_set_channel( 5, 0, 80 );
MOVS	R2, #80
MOVS	R1, #0
MOVS	R0, #5
BL	_pwm_set_channel+0
;pwm_click_ARM.c,33 :: 		pwm_set_channel( 6, 0, 100 );
MOVS	R2, #100
MOVS	R1, #0
MOVS	R0, #6
BL	_pwm_set_channel+0
;pwm_click_ARM.c,34 :: 		pwm_set_channel( 7, 10, 10 );
MOVS	R2, #10
MOVS	R1, #10
MOVS	R0, #7
BL	_pwm_set_channel+0
;pwm_click_ARM.c,36 :: 		pwm_channel_state( 3, false );
MOVS	R1, #0
MOVS	R0, #3
BL	_pwm_channel_state+0
;pwm_click_ARM.c,37 :: 		while( 1 );
L_main4:
IT	AL
BAL	L_main4
;pwm_click_ARM.c,38 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
