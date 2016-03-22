#PWM click#
##By [MikroElektronika](http://www.mikroe.com)
![PWM_click](http://www.mikroe.com/img/news/2015/03/pwm_click_banner_news.png)
### Installation
If installing from package, [Package manager](http://www.mikroe.com/package-manager/) required to install to your IDE.

PWM click is a simple solution for controlling 16 PWM outputs through a single I2C interface. 
You can use it to control anything from a simple LED strip to a complex robot with a multitude of moving parts. 
The click board™ carries the PCA9685PW IC. The board has an additional set of pins that allow you to connect 
up to seven PWM clicks together (using three jumpers to specify a different I2C address for each one). 
This will allow you to get a total of 112 pwm outputs on a single I2C line. 
PWM click is designed to use either a 3.3V or 5V power supply.

### Example
```
#include "pwm_hw.h"

sbit PWM_EN_PIN at GPIOC_ODR.B2;

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
    
    pwm_set_all( 33 );
    pwm_channel_state( 3, false );
}
```
