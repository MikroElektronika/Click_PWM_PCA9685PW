#include "pwm_hw.h"

sbit PWM_EN_PIN at GPIOC_ODR.B2;

void system_init()
{
    GPIO_Digital_Output( &GPIOC_BASE, _GPIO_PINMASK_2 );
    Delay_ms( 200 );
    I2C1_Init_Advanced( 100000, &_GPIO_MODULE_I2C1_PB67 );
    Delay_ms( 200 );
}

void main()
{
    system_init();
    pwm_click_init( 0x40 );
    pwm_set_all( 50 );
    pwm_set_channel( 0, 0, 20 );
    pwm_set_channel( 1, 0, 40 );
    pwm_set_channel_raw( 4, 2048, 2085 );
    pwm_set_channel( 5, 0, 80 );
    pwm_set_channel( 6, 0, 100 );
    pwm_set_channel( 7, 10, 10 );
    pwm_channel_state( 3, false );
    while( 1 );
}