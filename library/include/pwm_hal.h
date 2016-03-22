/****************************************************************************
* Title                 :   PWM CLICK
* Filename              :   pwm_hal.h
* Author                :   MSV
* Origin Date           :   28/01/2016
* Notes                 :   None
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date    Software Version    Initials   Description
*  28/01/16    XXXXXXXXXXX         MSV      Interface Created.
*
*****************************************************************************/
/**
 * @file pwm_hal.h
 * @brief <h3> HAL layer </h3>
 *
 * @par
 * HAL layer for <a href="http://www.mikroe.com">MikroElektronika's</a>
 * PWM click board.
 */
#ifndef PWM_HAL_H
#define PWM_HAL_H
/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/
	
/******************************************************************************
* Typedefs
*******************************************************************************/

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief <h4> HAL Initialization </h4>
 *
 * @par
 * Initialization of HAL layer used to initialize I2C bus and pins needed
 * for proper usage of click board.
 *
 * @param[in] address_id - hardware address
 */
void pwm_hal_init( uint8_t address_id );

/**
 * @brief <h4> PWM Enable </h4>
 *
 * @par
 * Enables the module using
 * @link PWM_EN_PIN @endlink .
 */
void pwm_hal_enable( void );

/**
 * @brief <h4> HAL Write </h4>
 *
 * @par
 * Generic write function adapted for I2C bus.
 *
 * @param[in] command - register address
 * @param[in] buffer - data buffer
 * @param[in] count - data size in bytes
 */
void pwm_hal_write( uint8_t *command,
                    uint8_t *buffer,
                    uint8_t count );

/**
 * @brief <h4> HAL Read </h4>
 *
 * @par
 * Generic read function adapted for I2C bus.
 *
 * @param[in] command - register address
 * @param[out] buffer - data buffer
 * @param[in] count - data size in bytes
 */
void pwm_hal_read( uint8_t *command,
                   uint8_t *buffer,
                   uint8_t count );

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* PWM_HAL_H */
/*** End of File **************************************************************/
