
/**
 * pwm_hw.c
 * Hardware Layer for PWM click
 *
 */

#include "pwm_hw.h"

#if defined( __MIKROC_PRO_FOR_ARM__ )   || \
    defined( __MIKROC_PRO_FOR_AVR__ )   || \
    defined( __MIKROC_PRO_FOR_PIC__ )   || \
    defined( __MIKROC_PRO_FOR_PIC32__ ) || \
    defined( __MIKROC_PRO_FOR_DSPIC__ ) || \
    defined( __MIKROC_PRO_FOR_8051__ )  || \
    defined( __MIKROC_PRO_FOR_FT90x__ )
extern sfr sbit PWM_EN_PIN;
#endif

static uint8_t _i2c_address;

void pwm_click_init( uint8_t i2c_dev_addr )
{
    _i2c_address = i2c_dev_addr;
    
    hal_pwm_init();
    pwm_click_enable( true );
    pwm_device_config( true, false, false, false, true, false );
    pwm_set_pre_scale( 0x04 );
    pwm_device_config( true, false, false, false, false, true );
    pwm_output_config( 0x00, true, false, false );
}

void pwm_click_enable( bool state )
{
    if( state )
        PWM_EN_PIN = 0;
    else
        PWM_EN_PIN = 1;
}

void pwm_device_config( bool allcall,
                        bool sub3,
                        bool sub2,
                        bool sub1,
                        bool sleep,
                        bool restart )
{
    uint8_t tmp_data[2];

    tmp_data[0] = PWM_MODE1;
    tmp_data[1] = 0x20;
    tmp_data[1] |= ( sub1 & 0x01 )     << M1_SUB1;
    tmp_data[1] |= ( sub2 & 0x01 )     << M1_SUB2;
    tmp_data[1] |= ( sub3 & 0x01 )     << M1_SUB3;
    tmp_data[1] |= ( sleep & 0x01 )    << M1_SLEEP;
    tmp_data[1] |= ( allcall & 0x01 )  << M1_ALLCALL;
    tmp_data[1] |= ( restart & 0x01 )  << M1_RESTART;
    hal_pwm_write( _i2c_address, tmp_data, 2 );
    hal_pwm_delay( 10 );
}

void pwm_output_config( uint8_t state,
                        bool out,
                        bool och,
                        bool invert )
{
    uint8_t tmp_data[2];

    if( state > 3 )
        return;
    tmp_data[0] = PWM_MODE2;
    tmp_data[1] = 0;
    tmp_data[1] |= ( state & 0x03 )    << M2_OUTNE;
    tmp_data[1] |= ( out & 0x01 )      << M2_OUTDRV;
    tmp_data[1] |= ( och & 0x01 )      << M2_OCH;
    tmp_data[1] |= ( invert & 0x01 )   << M2_INVERT;
    hal_pwm_write( _i2c_address, tmp_data, 2 );
    hal_pwm_delay( 10 );
}

void pwm_set_pre_scale( uint8_t pre_scale )
{
    uint8_t tmp_data[2];

    if( pre_scale < 3 )
        return;
    tmp_data[0] = PWM_PRE_SCALE;
    tmp_data[1] = pre_scale;
    hal_pwm_write( _i2c_address, tmp_data, 2 );
    hal_pwm_delay( 10 );
}

void pwm_set_channel_raw( uint8_t channel_id,
                          uint16_t raw_offset,
                          uint16_t raw_dc )
{
    uint8_t tmp_data[ 5 ];
    uint16_t tmp_off;

    if((channel_id > 15) || 
       (raw_offset > PWM_RESOLUTION) ||
       (raw_dc > PWM_RESOLUTION))
        return;
    tmp_off = ( raw_offset + raw_dc ) % PWM_RESOLUTION;
    tmp_data[0] = channel_id * 4 + PWM_CHANNEL;
    tmp_data[1] = raw_offset & 0x00FF;
    tmp_data[2] = ( raw_offset & 0x0F00 ) >> 8;
    tmp_data[3] = tmp_off & 0x00FF;
    tmp_data[4] = ( tmp_off  & 0x0F00 ) >> 8;
    hal_pwm_write( _i2c_address, tmp_data, 5 );
}

void pwm_set_channel( uint8_t channel_id,
                      uint8_t offset,
                      uint8_t duty_cycle )
{
    uint16_t raw_offset;
    uint16_t raw_dc;

    raw_offset = 0;
    raw_dc = 0;
    raw_offset = PWM_RESOLUTION / 100 * offset;
    raw_dc = PWM_RESOLUTION / 100 * duty_cycle;
    pwm_set_channel_raw( channel_id, raw_offset, raw_dc );
}

void pwm_set_all_raw( uint16_t raw_dc )
{
    uint8_t tmp_data[ 5 ];

    if( raw_dc > PWM_RESOLUTION )
        return;
    tmp_data[0] = PWM_ALL;
    tmp_data[1] = 0x00;
    tmp_data[2] = 0x00;
    tmp_data[3] = raw_dc & 0x00FF;
    tmp_data[4] = ( raw_dc & 0x0F00 ) >> 8;
    hal_pwm_write( _i2c_address, tmp_data, 5 );
}

void pwm_set_all( uint8_t duty_cycle )
{
    uint16_t raw_dc;

    raw_dc = PWM_RESOLUTION / 100 * duty_cycle;
    pwm_set_all_raw( raw_dc );
}

void pwm_channel_state( uint8_t channel_id,
                        bool state )
{
    uint8_t tmp_cmd;
    uint8_t tmp_data[ 5 ];

    if( channel_id > 15 )
        return;
    tmp_data[0] = channel_id * 4 + PWM_CHANNEL;
    hal_pwm_read( _i2c_address, tmp_data, 4 );
    tmp_data[5] = tmp_data[4];
    tmp_data[4] = tmp_data[3];
    tmp_data[3] = tmp_data[2];
    tmp_data[2] = tmp_data[1];
    tmp_data[1] = tmp_data[0];
    tmp_data[0] = channel_id * 4 + PWM_CHANNEL;
    if( state )
    {
        tmp_data[ 2 ] |= 0x10;
        tmp_data[ 4 ] &= 0xEF;

    } else {

        tmp_data[ 2 ] &= 0xEF;
        tmp_data[ 4 ] |= 0x10;
    }
    hal_pwm_write( _i2c_address, tmp_data, 5 );
}

void pwm_all_state( bool state )
{
    uint8_t tmp_data[ 5 ];

    tmp_data[0] = PWM_ALL;
    hal_pwm_read( _i2c_address, tmp_data, 4 );
    tmp_data[5] = tmp_data[4];
    tmp_data[4] = tmp_data[3];
    tmp_data[3] = tmp_data[2];
    tmp_data[2] = tmp_data[1];
    tmp_data[1] = tmp_data[0];
    tmp_data[0] = PWM_ALL;
    if( state )
    {
        tmp_data[ 2 ] |= 0x10;
        tmp_data[ 4 ] &= 0xEF;

    } else {

        tmp_data[ 2 ] &= 0xEF;
        tmp_data[ 4 ] |= 0x10;
    }
    hal_pwm_write( _i2c_address, tmp_data, 5 );
}