#include "pwm_hw.h"

sbit PWM_EN at GPIOC_ODR.B2;

void system_init()
{
    GPIO_Digital_Output( &GPIOC_BASE, _GPIO_PINMASK_2 );
    Delay_ms( 200 );
    
    I2C1_Init_Advanced( 400000, &_GPIO_MODULE_I2C1_PB67 );
    Delay_ms( 200 );
}

void main() 
{
    system_init();
    pwm_init( 0x40 );
    
    pwm_set_all( 2048 );
    //pwm_set_channel( 0, 0, 2048 );
    //pwm_set_channel( 1, 512, 2048 );
    //pwm_set_channel( 2, 1024, 2048 );
    //pwm_set_channel( 3, 2048, 2048 );
    //pwm_all_state( false );
    pwm_channel_state( 4, false );

