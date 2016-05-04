![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

![PWM_click](http://www.mikroe.com/img/news/2015/03/pwm_click_banner_news.png)

---

[Product Page](http://www.mikroe.com/click/pwm/)

[Learn Page](http://learn.mikroe.com/pwm-digital-signal-analog-soul/)

---

### Description
PWM click is a simple solution for controlling 16 PWM outputs through a single I2C interface. 
You can use it to control anything from a simple LED strip to a complex robot with a multitude of moving parts. 
The click board™ carries the PCA9685PW IC. The board has an additional set of pins that allow you to connect 
up to seven PWM clicks together (using three jumpers to specify a different I2C address for each one). 
This will allow you to get a total of 112 pwm outputs on a single I2C line. 
PWM click is designed to use either a 3.3V or 5V power supply.

---

### Example

#### Configuration
* MCU:             STM32F107VC
* Dev.Board:       EasyMx Pro v7
* Oscillator:      72 Mhz internal
* Ext. Modules:    SHT Click
* SW:              MikroC PRO for ARM 4.7.0

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
