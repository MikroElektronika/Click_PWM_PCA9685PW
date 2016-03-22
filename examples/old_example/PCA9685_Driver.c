#include "PCA9685_Driver.h"

static char tmp_data[ 10 ];

static void pwm_set_prescale( char value )
{
    tmp_data[ 0 ] = PRE_SCALE;
    tmp_data[ 1 ] = value;
    I2C1_Start();
    I2C1_Write( I2C_ADDRESS, tmp_data, 2, END_MODE_STOP );
    Delay_ms( 10 );
}

void pwm_set_all( unsigned int duty )
{
    tmp_data[ 0 ] = ALL_CH_ON_L;

    if ( duty > MAX_PWM )
    {
        duty = MAX_PWM;
    }

    tmp_data[ 1 ] = 0x00;
    tmp_data[ 2 ] = 0x00;
    tmp_data[ 3 ] = ( char )duty;
    tmp_data[ 4 ] = ( duty >> 8 ) & 0x0F;

    I2C1_Start();
    I2C1_Write( I2C_ADDRESS, tmp_data, 5, END_MODE_STOP );
    Delay_ms( 10 );
}

void pwm_set_channel( unsigned int duty, char channel )
{
    switch ( channel )
    {
        case 0:
            tmp_data[ 0 ] = CH0_ON_L;
            break;
        case 1:
            tmp_data[ 0 ] = CH1_ON_L;
            break;
        case 2:
            tmp_data[ 0 ] = CH2_ON_L;
            break;
        case 3:
            tmp_data[ 0 ] = CH3_ON_L;
            break;
        case 4:
            tmp_data[ 0 ] = CH4_ON_L;
            break;
        case 5:
            tmp_data[ 0 ] = CH5_ON_L;
            break;
        case 6:
            tmp_data[ 0 ] = CH6_ON_L;
            break;
        case 7:
            tmp_data[ 0 ] = CH7_ON_L;
            break;
        case 8:
            tmp_data[ 0 ] = CH8_ON_L;
            break;
        case 9:
            tmp_data[ 0 ] = CH9_ON_L;
            break;
        case 10:
            tmp_data[ 0 ] = CH10_ON_L;
            break;
        case 11:
            tmp_data[ 0 ] = CH11_ON_L;
            break;
        case 12:
            tmp_data[ 0 ] = CH12_ON_L;
            break;
        case 13:
            tmp_data[ 0 ] = CH13_ON_L;
            break;
        case 14:
            tmp_data[ 0 ] = CH14_ON_L;
            break;
        case 15:
            tmp_data[ 0 ] = CH15_ON_L;
    }
    if ( duty > MAX_PWM )
    {
        duty = MAX_PWM;
    }
    
    tmp_data[ 1 ] = 0x00;
    tmp_data[ 2 ] = 0x00;
    tmp_data[ 3 ] = ( char )duty;
    tmp_data[ 4 ] = ( duty >> 8 ) & 0x0F;

    I2C1_Start();
    I2C1_Write( I2C_ADDRESS, tmp_data, 5, END_MODE_STOP );
    Delay_ms( 10 );
}

void pwm_init()
{
    tmp_data[ 0 ] = MODE1_REG;
    tmp_data[ 1 ] = 0x31;
    I2C1_Start();
    I2C1_Write( I2C_ADDRESS, tmp_data, 2, END_MODE_STOP );
    Delay_ms( 10 );

    tmp_data[ 0 ] = PRE_SCALE;
    tmp_data[ 1 ] = 0x04;
    I2C1_Start();
    I2C1_Write( I2C_ADDRESS, tmp_data, 2, END_MODE_STOP );
    Delay_ms( 10 );

    tmp_data[ 0 ] = MODE1_REG;
    tmp_data[ 1 ] = 0xA1;
    I2C1_Start();
    I2C1_Write( I2C_ADDRESS, tmp_data, 2, END_MODE_STOP );
    Delay_ms( 10 );

    tmp_data[ 0 ] = MODE2_REG;
    tmp_data[ 1 ] = 0x04;
    I2C1_Start();
    I2C1_Write( I2C_ADDRESS, tmp_data, 2, END_MODE_STOP );
    Delay_ms( 10 );
}
