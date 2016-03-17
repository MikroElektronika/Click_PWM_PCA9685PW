/*******************************************************************************
* File: PWM.c
* File Type: C - Source Code File
* Company: (c) mikroElektronika, 2015
* Revision History:
*     - mikroC PRO(VM);
* Description:
*   PWM click is a simple solution for controlling 16 PWM outputs through a
* single I2C interface.
*   The click board carries the PCA9685PW IC.
*   In addition to mikroBUS I2C pins (SCL, SDA), the board also uses a
* LOW Output Enable Input pin (OE), which is in place of the default mikroBUS
* RST pin.
*   PWM click is designed to use either a 3.3V or 5V power supply.
*
* NOTES:
*     - Insert PWM click in mikroBUS socket 1
*     - Place jumper J8 on PA3 position for ADC module.
*******************************************************************************/
#include "PCA9685_Driver.h"

sbit PCA9685_EN at GPIOC_ODR.B2;

static unsigned int adc_result = 0;
static unsigned int adc_result_old = 0;

char i2c_init()
{
    GPIO_Digital_Input( &GPIOB_BASE, _GPIO_PINMASK_7 );
    GPIO_Digital_Output( &GPIOB_BASE, _GPIO_PINMASK_6 );
    GPIOB_ODR.B6 = 1;

    while( GPIOB_IDR.B7 == 0 )
    {
        GPIOB_ODR.B6 = 0;
        Delay_us( 10 );
        GPIOB_ODR.B6 = 1;
        Delay_us( 10 );
    }
    
    I2C1_Init_Advanced( 400000, &_GPIO_MODULE_I2C1_PB67 );
    Delay_ms( 200 );

    return 1;
}

void main() 
{
    GPIO_Digital_Output( &GPIOC_BASE, _GPIO_PINMASK_2 );
    PCA9685_EN = 0;

    while( !i2c_init() );
  
    pwm_init();
    ADC_Set_Input_Channel( _ADC_CHANNEL_3 );
    ADC1_Init();
    Delay_ms( 100 );
    pwm_set_all( 0 );
    Delay_ms( 100 );
    
    while( 1 )
    {
        adc_result = ADC1_Get_Sample( 3 );
        
        if ( adc_result != adc_result_old )
        {
            //pwm_set_channel( adc_result, 1 );
            pwm_set_all( adc_result );
            adc_result_old = adc_result;
        }
    
        Delay_ms( 200 );
    }
}
