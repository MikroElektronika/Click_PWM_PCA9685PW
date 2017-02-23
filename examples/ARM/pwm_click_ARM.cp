#line 1 "E:/git/MikroE/Click_PWM_PCA9685PW/examples/ARM/pwm_click_ARM.c"
#line 1 "e:/git/mikroe/click_pwm_pca9685pw/library/include/pwm_hw.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdbool.h"



 typedef char _Bool;
#line 1 "e:/git/mikroe/click_pwm_pca9685pw/library/include/pwm_hal.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 23 "e:/git/mikroe/click_pwm_pca9685pw/library/include/pwm_hal.h"
void hal_pwm_delay( uint16_t ms );
#line 31 "e:/git/mikroe/click_pwm_pca9685pw/library/include/pwm_hal.h"
int hal_pwm_init( void );
#line 43 "e:/git/mikroe/click_pwm_pca9685pw/library/include/pwm_hal.h"
int hal_pwm_write
(
 uint8_t i2c_address,
 uint8_t *buffer,
 uint16_t count
);
#line 64 "e:/git/mikroe/click_pwm_pca9685pw/library/include/pwm_hal.h"
int hal_pwm_read
(
 uint8_t i2c_address,
 uint8_t *buffer,
 uint16_t count
);
#line 83 "e:/git/mikroe/click_pwm_pca9685pw/library/include/pwm_hal.h"
int hal_pwm_transfer
(
 uint8_t i2c_address,
 uint8_t* input,
 uint16_t in_count,
 uint8_t* output,
 uint16_t out_count
);
#line 241 "e:/git/mikroe/click_pwm_pca9685pw/library/include/pwm_hw.h"
void pwm_click_init( uint8_t i2c_address );

void pwm_click_enable(  _Bool  state );
#line 270 "e:/git/mikroe/click_pwm_pca9685pw/library/include/pwm_hw.h"
void pwm_device_config(  _Bool  allcall,
  _Bool  sub3,
  _Bool  sub2,
  _Bool  sub1,
  _Bool  sleep,
  _Bool  restart );
#line 288 "e:/git/mikroe/click_pwm_pca9685pw/library/include/pwm_hw.h"
void pwm_output_config( uint8_t state,
  _Bool  out,
  _Bool  och,
  _Bool  invert );
#line 302 "e:/git/mikroe/click_pwm_pca9685pw/library/include/pwm_hw.h"
void pwm_soft_reset( void );
#line 315 "e:/git/mikroe/click_pwm_pca9685pw/library/include/pwm_hw.h"
void pwm_set_pre_scale( uint8_t pre_scale );
#line 331 "e:/git/mikroe/click_pwm_pca9685pw/library/include/pwm_hw.h"
void pwm_set_channel_raw( uint8_t channel_id,
 uint16_t raw_offset,
 uint16_t raw_dc );
#line 345 "e:/git/mikroe/click_pwm_pca9685pw/library/include/pwm_hw.h"
void pwm_set_channel( uint8_t channel_id,
 uint8_t offset,
 uint8_t duty_cycle );
#line 361 "e:/git/mikroe/click_pwm_pca9685pw/library/include/pwm_hw.h"
void pwm_set_all_raw( uint16_t raw_dc );
#line 371 "e:/git/mikroe/click_pwm_pca9685pw/library/include/pwm_hw.h"
void pwm_set_all( uint8_t duty_cycle );
#line 384 "e:/git/mikroe/click_pwm_pca9685pw/library/include/pwm_hw.h"
void pwm_channel_state( uint8_t channel_id,
  _Bool  state );
#line 397 "e:/git/mikroe/click_pwm_pca9685pw/library/include/pwm_hw.h"
void pwm_all_state(  _Bool  state );
#line 3 "E:/git/MikroE/Click_PWM_PCA9685PW/examples/ARM/pwm_click_ARM.c"
sbit PWM_EN_PIN at GPIOC_ODR.B2;

void system_init()
{
#line 18 "E:/git/MikroE/Click_PWM_PCA9685PW/examples/ARM/pwm_click_ARM.c"
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

 pwm_channel_state( 3,  0  );
 while( 1 );
}
