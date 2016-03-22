/****************************************************************************
* Title                 :   PWM CLICK
* Filename              :   pwm_hw.h
* Author                :   MSV
* Origin Date           :   30/01/2016
* Notes                 :   Hardware layer
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date    Software Version    Initials   Description
*  30/01/16     .1                  MSV     Interface Created.
*
*****************************************************************************/
/**
 * @file pwm_hw.c
 * @brief <h3> Hardware Layer </h3>
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include "pwm_hw.h"
/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Private Function Definitions
*******************************************************************************/

/******************************************************************************
* Public Function Definitions
*******************************************************************************/
void pwm_init( uint8_t i2c_dev_addr )
{
    pwm_hal_init( i2c_dev_addr );

    pwm_device_config( true, false, false, false, true, false );
    pwm_set_pre_scale( 0x04 );
    pwm_device_config( true, false, false, false, false, true );
    pwm_output_config( 0x00, true, false, false );
}

void pwm_device_config( bool allcall,
                        bool sub3,
                        bool sub2,
                        bool sub1,
                        bool sleep,
                        bool restart )
{
    uint8_t tmp_cmd = PWM_MODE1;
    uint8_t tmp_data = 0x20;

    tmp_data |= ( sub1 & 0x01 )     << M1_SUB1;
    tmp_data |= ( sub2 & 0x01 )     << M1_SUB2;
    tmp_data |= ( sub3 & 0x01 )     << M1_SUB3;
    tmp_data |= ( sleep & 0x01 )    << M1_SLEEP;
    tmp_data |= ( allcall & 0x01 )  << M1_ALLCALL;
    tmp_data |= ( restart & 0x01 )  << M1_RESTART;

    pwm_hal_write( &tmp_cmd, &tmp_data, 1 );
    Delay_ms( 10 );
}

void pwm_output_config( uint8_t state,
                        bool out,
                        bool och,
                        bool invert )
{
    uint8_t tmp_cmd = PWM_MODE2;
    uint8_t tmp_data = 0x00;

    if( state > 3 )
        return;

    tmp_data |= ( state & 0x03 )    << M2_OUTNE;
    tmp_data |= ( out & 0x01 )      << M2_OUTDRV;
    tmp_data |= ( och & 0x01 )      << M2_OCH;
    tmp_data |= ( invert & 0x01 )   << M2_INVERT;

    pwm_hal_write( &tmp_cmd, &tmp_data, 1 );
    Delay_ms( 10 );
}

void pwm_set_pre_scale( uint8_t pre_scale )
{
    uint8_t tmp_cmd = PWM_PRE_SCALE;
    uint8_t tmp_data = pre_scale;

    if( pre_scale < 0x03 )
        return;

    pwm_hal_write( &tmp_cmd, &tmp_data, 1 );
    Delay_ms( 10 );
}

void pwm_set_channel_raw( uint8_t channel_id,
                          uint16_t raw_offset,
                          uint16_t raw_dc )
{
    uint8_t tmp_cmd = 0;
    uint8_t tmp_data[ 4 ] = { 0 };
    uint16_t tmp_off = 0;

    if( channel_id >15 || raw_offset >PWM_RESOLUTION || raw_dc >PWM_RESOLUTION )
        return;

    tmp_cmd = channel_id * 4 + PWM_CHANNEL;
    tmp_off = ( raw_offset + raw_dc ) % PWM_RESOLUTION;

    tmp_data[ 0 ] = raw_offset & 0x00FF;
    tmp_data[ 1 ] = ( raw_offset & 0x0F00 ) >> 8;
    tmp_data[ 2 ] = tmp_off & 0x00FF;
    tmp_data[ 3 ] = ( tmp_off  & 0x0F00 ) >> 8;

    pwm_hal_write( &tmp_cmd, &tmp_data[ 0 ], 4 );
}

void pwm_set_channel( uint8_t channel_id,
                      uint8_t offset,
                      uint8_t duty_cycle )
{
    uint16_t raw_offset = 0;
    uint16_t raw_dc = 0;

    raw_offset = PWM_RESOLUTION / 100 * offset;
    raw_dc = PWM_RESOLUTION / 100 * duty_cycle;

    pwm_set_channel_raw( channel_id, raw_offset, raw_dc );
}

void pwm_set_all_raw( uint16_t raw_dc )
{
    uint8_t tmp_cmd = PWM_ALL;
    uint8_t tmp_data[ 4 ] = { 0 };

    if( raw_dc > PWM_RESOLUTION )
        return;

    tmp_data[ 0 ] = 0x00;
    tmp_data[ 1 ] = 0x00;
    tmp_data[ 2 ] = raw_dc & 0x00FF;
    tmp_data[ 3 ] = ( raw_dc & 0x0F00 ) >> 8;

    pwm_hal_write( &tmp_cmd, &tmp_data[ 0 ], 4 );
}

void pwm_set_all( uint8_t duty_cycle )
{
    uint16_t raw_dc = 0;

    raw_dc = PWM_RESOLUTION / 100 * duty_cycle;

    pwm_set_all_raw( raw_dc );
}

void pwm_channel_state( uint8_t channel_id,
                        bool state )
{
    uint8_t tmp_cmd = 0;
    uint8_t tmp_data[ 4 ] = { 0 };

    if( channel_id > 15 )
        return;

    tmp_cmd = channel_id * 4 + PWM_CHANNEL;

    pwm_hal_read( &tmp_cmd, &tmp_data, 4 );

    if( state )
    {
        tmp_data[ 1 ] |= 0x10;
        tmp_data[ 3 ] &= 0xEF;

    } else {

        tmp_data[ 1 ] &= 0xEF;
        tmp_data[ 3 ] |= 0x10;
    }

    pwm_hal_write( &tmp_cmd, &tmp_data, 4 );
}

void pwm_all_state( bool state )
{
    uint8_t tmp_cmd = PWM_ALL;
    uint8_t tmp_data[ 4 ] = { 0 };

    pwm_hal_read( &tmp_cmd, &tmp_data, 4 );

    if( state )
    {
        tmp_data[ 1 ] |= 0x10;
        tmp_data[ 3 ] &= 0xEF;

    } else {

        tmp_data[ 1 ] &= 0xEF;
        tmp_data[ 3 ] |= 0x10;
    }

    pwm_hal_write( &tmp_cmd, &tmp_data, 4 );

}
/*************** END OF FUNCTIONS *********************************************/
