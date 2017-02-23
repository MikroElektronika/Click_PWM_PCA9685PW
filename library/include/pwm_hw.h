/**
 * @file pwm_hw.h
 * @brief <h3> Hardware Layer </h3>
 *
 * @par
 * Low level functions for
 * <a href="http://www.mikroe.com">MikroElektronika's</a> PWM click
 * board.
 */

/**
 * @page LIB_INFO Library Info
 * @date 15 Mar 2016
 * @author Milos Vidojevic
 * @copyright GNU Public License
 * @version 1.0.0 - Initial testing and verification
 */

/**
 * @page TEST_CFG Test Configurations
 *
 * ### Test configuration 1 : ###
 * @par
 * - <b>MCU</b> :             STM32F107VC
 * - <b>Dev. Board</b> :      EasyMx PRO v7
 * - <b>Oscillator</b> :      72 Mhz internal
 * - <b>Ext. Modules</b> :    PWM Click
 * - <b>SW</b> :              MikroC PRO for ARM 4.7.1
 *
 * ### Test configuration 2 : ###
 * @par
 * - <b>MCU</b> :             PIC32MX795F512L
 * - <b>Dev. Board</b> :      EasyPIC Fusion v7
 * - <b>Oscillator</b> :      80 Mhz internal
 * - <b>Ext. Modules</b> :    PWM Click
 * - <b>SW</b> :              MikroC PRO for PIC32 3.6.0
 *
 * ### Test configuration 3 : ###
 * @par
 * - <b>MCU</b> :             FT900Q
 * - <b>Dev. Board</b> :      EasyFT90x v7
 * - <b>Oscillator</b> :      100 Mhz internal
 * - <b>Ext. Modules</b> :    PWM Click
 * - <b>SW</b> :              MikroC PRO for FT90x 1.2.1
 *
 * ### Test configuration 4 : ###
 * @par
 * - <b>MCU</b> :             PIC18F87K22
 * - <b>Dev. Board</b> :      EasyPIC PRO v7
 * - <b>Oscillator</b> :      64 Mhz external
 * - <b>Ext. Modules</b> :    PWM Click
 * - <b>SW</b> :              MikroC PRO for PIC 6.6.2
 *
 * ### Test configuration 5 : ###
 * @par
 * - <b>MCU</b> :             dsP33FJ256GP710A
 * - <b>Dev. Board</b> :      EasyPIC Fusion v7
 * - <b>Oscillator</b> :      8 Mhz internal
 * - <b>Ext. Modules</b> :    PWM Click
 * - <b>SW</b> :              MikroC PRO for dsPIC 6.2.1
 *
 * ### Test configuration 6 : ###
 * @par
 * - <b>MCU</b> :             ATMEGA32
 * - <b>Dev. Board</b> :      EasyAVR v7
 * - <b>Oscillator</b> :      8 Mhz external
 * - <b>Ext. Modules</b> :    PWM Click
 * - <b>SW</b> :              MikroC PRO for AVR 6.1.1
 */

/**
 * @page SCH Schematic
 * ![Schematic](sch.jpg)
 */

/**
 * @mainpage
 * ![The Click](pwm_click.png)
 * ### General Description ###
 * @par
 * The PCA9685 is an I 2 C-bus controlled 16-channel LED controller optimized
 * for Red/Green/Blue/Amber (RGBA) color backlighting applications. Each LED
 * output has its own 12-bit resolution (4096 steps) fixed frequency individual
 * pwm controller that operates at a programmable frequency from a typical of
 * 24 Hz to 1526 Hz with a duty cycle that is adjustable from 0 % to 100 % to
 * allow the LED to be set to a specific brightness value. All outputs are set
 * to the same pwm frequency.
 *
 * @par
 * Each LED output can be off or on (no pwm control), or set at its individual
 * pwm controller value. The LED output driver is programmed to be either
 * open-drain with a 25 mA current sink capability at 5 V or totem pole with a
 * 25 mA sink, 10 mA source capability at 5 V. The PCA9685 operates with a
 * supply voltage range of 2.3 V to 5.5 V and the inputs and outputs are 5.5 V
 * tolerant. LEDs can be directly connected to the LED output
 * (up to 25 mA, 5.5 V) or controlled with external drivers and a minimum
 * amount of discrete components for larger current or higher voltage LEDs.
 *
 * ### Features ###
 * @par
 * - 16 LED drivers. Each output programmable at:
 *      + Off
 *      + On
 *      + Programmable LED brightness
 *      + Programmable LED turn-on time to help reduce EMI
 * - 1 MHz Fast-mode Plus compatible I2C-bus interface with 30 mA high drive
 *   capability on SDA output for driving high capacitive buses
 * - 4096-step (12-bit) linear programmable brightness per LED output varying
 *   from fully off (default) to maximum brightness
 * - LED output frequency (all LEDs) typically varies from 24 Hz to 1526 Hz
 *   (Default of 1Eh in PRE_SCALE register results in a 200 Hz refresh rate
 *   with oscillator clock of 25 MHz.)
 * - Sixteen totem pole outputs (sink 25 mA and source 10 mA at 5 V) with
 *   software programmable open-drain LED outputs selection (default at totem
 *   pole). No input function.
 * - Output state change programmable on the Acknowledge or the STOP Command to
 *   update outputs byte-by-byte or all at the same time (default to ‘Change on
 *   STOP’).
 * - Active LOW Output Enable (OE) input pin. LEDn outputs programmable to
 *   logic 1, logic 0 (default at power-up) or ‘high-impedance’ when OE is HIGH.
 * - 6 hardware address pins allow 62 PCA9685 devices to be connected to the
 *   same I2C-bus
 * - Toggling OE allows for hardware LED blinking
 * - 4 software programmable I 2 C-bus addresses (one LED All Call address and
 *   three LED Sub Call addresses) allow groups of devices to be addressed at
 *   the same time in any combination (for example, one register used for
 *   ‘All Call’ so that all the PCA9685s on the I2C-bus can be addressed at the
 *   same time and the second register used for three different addresses so
 *   that 1 ⁄ 3 of all devices on the bus can be addressed at the same time in
 *   a group). Software enable and disable for these I 2 C-bus address.
 * - Software Reset feature (SWRST General Call) allows the device to be reset
 *   through the I2C-bus
 * - 25 MHz typical internal oscillator requires no external components
 * - External 50 MHz (max.) clock input
 * - Internal power-on reset
 * - Noise filter on SDA/SCL inputs
 * - Edge rate control on outputs
 * - No output glitches on power-up
 * - Supports hot insertion
 * - Low standby current
 * - Operating power supply voltage range of 2.3 V to 5.5 V
 * - 5.5 V tolerant inputs
 * - +85 C to -85 C operation
 *
 * ### Applications ###
 * @par
 * - RGB or RGBA LED drivers
 * - LED status information
 * - LED displays
 * - LCD backlights
 * - Keypad backlights for cellular phones or handheld devices
 */
#ifndef PWM_HW_H
#define PWM_HW_H
/******************************************************************************
* Includes
*******************************************************************************/
#include <stdbool.h>
#include "pwm_hal.h"

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
/**
 * PWM period time resolution */
#define PWM_RESOLUTION                                  4096

/**
 * @name PWM Click Registers
 ******************************************************************************/
///@{
/** Pre_scale register */
#define PWM_PRE_SCALE                                   0xFE
/** Mode 1 register */
#define PWM_MODE1                                       0x00
/** Mode 2 register */
#define PWM_MODE2                                       0x01
/** Channel configuration registers */
#define PWM_CHANNEL                                     0x06
/** All channels configuration registers */
#define PWM_ALL                                         0xFA
///@}

/**
 * @name Mode register 1 bits
 ******************************************************************************/
///@{
/** LED all-call */
#define M1_ALLCALL                                          0
/** Sub-address 3 */
#define M1_SUB3                                             1
/** Sub-address 2 */
#define M1_SUB2                                             2
/** Sub-address 1 */
#define M1_SUB1                                             3
/** Sleep mode */
#define M1_SLEEP                                            4
/** Increment state */
#define M1_AI                                               5
/** External clock */
#define M1_EXTCLK                                           6
/** Restart logic */
#define M1_RESTART                                          7
///@}
/**
 * @name Mode register 2
 ******************************************************************************/
///@
/** Output drivers */
#define M2_OUTNE                                            0
/** Outputs structure */
#define M2_OUTDRV                                           2
/** Outputs change moment */
#define M2_OCH                                              3
/** Output logic inversion */
#define M2_INVERT                                           4
///@}
/**
 * @name Functions
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief <h4> HW Layer Initialization </h4>
 *
 * @par
 * Prepares library for usage and sets needed values to default.
 *
 * @param[in] i2c_dev_addr
 *
 * @note
 * This function must be called first.
 *
 * Example :
 * @code
 *
 * @endcode
 */
void pwm_click_init( uint8_t i2c_address );

void pwm_click_enable( bool state );

/**
 * @brief <h4> Device Configuration </h4>
 *
 * @par
 * Configures the device using mode register 1
 *
 * @param[in] allcall
 * - true ( Device responds to LED All Call I2C-bus address )
 * - false ( PCA9685 does not respond to LED All Call I2C-bus address )
 * @param[in] sub3
 * - true ( Device responds to I2C-bus subaddress 3 )
 * - false ( Device does not respond to I2C-bus subaddress 3 )
 * @param[in] sub2
 * - true ( Device responds to I2C-bus subaddress 2 )
 * - false ( Device does not respond to I2C-bus subaddress 2 )
 * @param[in] sub1
 * - true ( Device responds to I2C-bus subaddress 1 )
 * - false ( Device does not respond to I2C-bus subaddress 1 )
 * @param[in] sleep
 * - true ( Normal mode )
 * - false ( Low power mode. Oscillator off )
 * @param[in] restart
 * - true ( Restart disabled )
 * - false ( Restart enabled )
 */
void pwm_device_config( bool allcall,
                        bool sub3,
                        bool sub2,
                        bool sub1,
                        bool sleep,
                        bool restart );

/**
 * @brief <h4> Outputs Configration </h4>
 *
 * @par
 * Configures the device outputs using mode register 2
 *
 * @param[in] state
 * @param[in] out
 * @param[in] och
 * @param[in] invert
 */
void pwm_output_config( uint8_t state,
                        bool out,
                        bool och,
                        bool invert );

/**
 * @brief <h4> Software reset </h4>
 *
 * @par
 * The Software Reset Call (SWRST Call) allows all the devices in the I2C-bus
 * to be reset to the power-up state value through a specific formatted I2C-bus
 * command. To be performed correctly, it implies that the I 2 C-bus is
 * functional and that there is no device hanging the bus.
 */
void pwm_soft_reset( void );

/**
 * @brief <h4> Pre Scale Value </h4>
 *
 * @par
 * Sets the pre scale value for all channels.
 *
 * @note
 * pre_scale = |round| ( 25 MHz / ( 4096 * frequency ) ) - 1
 *
 * @param[in] prescale ( 0x03 ~ 0xFF )
 */
void pwm_set_pre_scale( uint8_t pre_scale );

/**
 * @brief <h4> PWM set channel </h4>
 *
 * @par
 * Sets start offset and duty cycle for channel.
 * This function uses raw 12 bit values for offset and duty cycle.
 *
 * @note
 * Use this function in case you need better precision
 *
 * @param[in] channel_id ( 0 ~ 15 )
 * @param[in] raw_offset ( 0 ~ 4095 )
 * @param[in] raw_dc     ( 0 ~ 4095 )
 */
void pwm_set_channel_raw( uint8_t channel_id,
                          uint16_t raw_offset,
                          uint16_t raw_dc );

/**
 * @brief <h4> PWM set channel </h4>
 *
 * @par
 * Sets the offset and duty cycle for channel with period percentage.
 *
 * @param[in] channel_id ( 0 ~ 15 )
 * @param[in] offset     ( 0 ~ 100 )
 * @param[in] duty_cycle ( 0 ~ 100 )
 */
void pwm_set_channel( uint8_t channel_id,
                      uint8_t offset,
                      uint8_t duty_cycle );

/**
 * @brief <h4> PWM set all channels </h4>
 *
 * @par
 * Sets same duty cycle on all channels.
 * This function uses raw 12 bit value for duty cycle.
 *
 * @note
 * Use this function in case you need better precision
 *
 * @param[in] raw_dc ( 0 ~ 4095 )
 */
void pwm_set_all_raw( uint16_t raw_dc );

/**
 * @brief <h4> PWM set channel </h4>
 *
 * @par
 * Sets the duty cycle for channel with period percentage.
 *
 * @param[in] duty_cycle ( 0 ~ 100 )
 */
void pwm_set_all( uint8_t duty_cycle );

/**
 * @brief <h4> Power on the channel </h4>
 *
 * @par
 * Change the channel state.
 *
 * @param[in] channel_id ( 0 ~ 15 )
 * @param[in] state
 * - true - ON
 * - false - OFF
 */
void pwm_channel_state( uint8_t channel_id,
                        bool state );

/**
 * @brief <h4> Power on all channels </h4>
 *
 * @par
 * Change the state of all channels.
 *
 * @param[in] state
 * - true - ON
 * - false - OFF
 */
void pwm_all_state( bool state );

#ifdef __cplusplus
} // extern "C"
#endif
#endif /* PWM_HW_H */
///@}
/*** End of File **************************************************************/