/* MODE1_bits */
#define PCA9685_RESTART     0x80
#define PCA9685_EXTCLK      0x40
#define PCA9685_AI          0x20
#define PCA9685_SLEEP       0x10
#define PCA9685_SUB1        0x08
#define PCA9685_SUB2        0x04
#define PCA9685_SUB3        0x02
#define PCA9685_ALLCALL     0x01

/* MODE2_bits */
#define PCA9685_INVRT       0x10
#define PCA9685_OCH         0x08
#define PCA9685_OUTDRV      0x04
#define PCA9685_OUTNE1      0x02
#define PCA9685_OUTNE0      0x01

/* SLAVE ADDRESS */
#define I2C_ADDRESS         0x40

/* MODE1_REG ADDRESS */
#define MODE1_REG           0x00

/* MODE2_REG ADDRESS*/
#define MODE2_REG           0x01

/* PRE_SCALE REG ADDRESS */
#define PRE_SCALE           0xFE

/* In comments below you can find defined each channel registers, also on right
 * side u can find in comment name of that register from PCA9685 datasheet.
 */

// CH0 REG ADDRESS //
#define CH0_ON_L            0x06    //LED0_ON_L
#define CH0_ON_H            0x07    //LED0_ON_H
#define CH0_OFF_L           0x08    //LED0_OFF_L
#define CH0_OFF_H           0x09    //LED0_OFF_H

// CH1 REG ADDRESS //
#define CH1_ON_L            0x0A    //LED1_ON_L
#define CH1_ON_H            0x0B    //LED1_ON_H
#define CH1_OFF_L           0x0C    //LED1_OFF_L
#define CH1_OFF_H           0x0D    //LED1_OFF_H

// CH2 REG ADDRESS //
#define CH2_ON_L            0x0E    //LED2_ON_L
#define CH2_ON_H            0x0F    //LED2_ON_H
#define CH2_OFF_L           0x10    //LED2_OFF_L
#define CH2_OFF_H           0x11    //LED2_OFF_H

// CH3 REG ADDRESS //
#define CH3_ON_L            0x12    //LED3_ON_L
#define CH3_ON_H            0x13    //LED3_ON_H
#define CH3_OFF_L           0x14    //LED3_OFF_L
#define CH3_OFF_H           0x15    //LED3_OFF_H

// CH4 REG ADDRESS //
#define CH4_ON_L            0x16    //LED4_ON_L
#define CH4_ON_H            0x17    //LED4_ON_H
#define CH4_OFF_L           0x18    //LED4_OFF_L
#define CH4_OFF_H           0x19    //LED4_OFF_H

// CH5 REG ADDRESS //
#define CH5_ON_L            0x1A    //LED5_ON_L
#define CH5_ON_H            0x1B    //LED5_ON_H
#define CH5_OFF_L           0x1C    //LED5_OFF_L
#define CH5_OFF_H           0x1D    //LED5_OFF_H

// CH6 REG ADDRESS //
#define CH6_ON_L            0x1E    //LED6_ON_L
#define CH6_ON_H            0x1F    //LED6_ON_H
#define CH6_OFF_L           0x20    //LED6_OFF_L
#define CH6_OFF_H           0x21    //LED6_OFF_H

// CH7 REG ADDRESS //
#define CH7_ON_L            0x22    //LED7_ON_L
#define CH7_ON_H            0x23    //LED7_ON_H
#define CH7_OFF_L           0x24    //LED7_OFF_L
#define CH7_OFF_H           0x25    //LED7_OFF_H

// CH8 REG ADDRESS //
#define CH8_ON_L            0x26    //LED8_ON_L
#define CH8_ON_H            0x27    //LED8_ON_H
#define CH8_OFF_L           0x28    //LED8_OFF_L
#define CH8_OFF_H           0x29    //LED8_OFF_H

// CH9 REG ADDRESS //
#define CH9_ON_L            0x2A    //LED9_ON_L
#define CH9_ON_H            0x2B    //LED9_ON_H
#define CH9_OFF_L           0x2C    //LED9_OFF_L
#define CH9_OFF_H           0x2D    //LED9_OFF_H

// CH10 REG ADDRESS //
#define CH10_ON_L           0x2E   //LED10_ON_L
#define CH10_ON_H           0x2F   //LED10_ON_H
#define CH10_OFF_L          0x30   //LED10_OFF_L
#define CH10_OFF_H          0x31   //LED10_OFF_H

// CH11 REG ADDRESS //
#define CH11_ON_L           0x32   //LED11_ON_L
#define CH11_ON_H           0x33   //LED11_ON_H
#define CH11_OFF_L          0x34   //LED11_OFF_L
#define CH11_OFF_H          0x35   //LED11_OFF_H

// CH12 REG ADDRESS //
#define CH12_ON_L           0x36   //LED12_ON_L
#define CH12_ON_H           0x37   //LED12_ON_H
#define CH12_OFF_L          0x38   //LED12_OFF_L
#define CH12_OFF_H          0x39   //LED12_OFF_H

// CH13 REG ADDRESS //
#define CH13_ON_L           0x3A   //LED13_ON_L
#define CH13_ON_H           0x3B   //LED13_ON_H
#define CH13_OFF_L          0x3C   //LED13_OFF_L
#define CH13_OFF_H          0x3D   //LED13_OFF_H

// CH14 REG ADDRESS //
#define CH14_ON_L           0x3E   //LED14_ON_L
#define CH14_ON_H           0x3F   //LED14_ON_H
#define CH14_OFF_L          0x40   //LED14_OFF_L
#define CH14_OFF_H          0x41   //LED14_OFF_H

// CH15 REG ADDRESS //
#define CH15_ON_L           0x42   //LED15_ON_L
#define CH15_ON_H           0x43   //LED15_ON_H
#define CH15_OFF_L          0x44   //LED15_OFF_L
#define CH15_OFF_H          0x45   //LED15_OFF_H

// ALL_CH REG ADDRESS //
#define ALL_CH_ON_L         0xFA    //ALL_LED_ON_L
#define ALL_CH_ON_H         0xFB    //ALL_LED_ON_H
#define ALL_CH_OFF_L        0xFC    //ALL_LED_OFF_L
#define ALL_CH_OFF_H        0xFD    //ALL_LED_OFF_H

#define MAX_PWM           4096

// Initialization
void pwm_init();

// Set all channels
// 12 bit pwm value max ( 4096 )
void pwm_set_all( unsigned int duty );

// Sets desired duty on desired channel
void pwm_set_channel( unsigned int duty, char channel );
void pwm_set_frequency( unsigned int value );
