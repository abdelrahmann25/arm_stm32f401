#ifndef RCC_H_
#define RCC_H_

/* Define standard types for 8-bit unsigned and signed integers */
typedef unsigned char u8;
typedef signed char s8;

/* Define standard types for 16-bit unsigned and signed integers */
typedef unsigned short int u16;
typedef signed short int s16;

/* Define standard types for 32-bit unsigned and signed integers */
typedef unsigned int u32;
typedef signed int s32;

/* Define a NULL pointer constant */
#define NULLPTR ((void *)0)


/*************** RCC Base Address ***********/
#define RCC_BASE_ADDRESS ((u32)0x40023800)
/********************************************/

/********************* CLOCKs Enable Masks ********************/
/** In RCC_CR **/
#define CLK_HSI            ((u32)0x00000001)   // HSI ON/OFF bit
#define STATUS_CLK_HSI     ((u32)0x00000002)   // HSI Ready bit

#define CLK_HSE            ((u32)0x00010000)   // HSE ON/OFF bit
#define STATUS_CLK_HSE     ((u32)0x00020000)   // HSE Ready bit
#define HSE_BYPASS_MASK    ((u32)0x00040000)   // HSE Bypass bit

#define CLK_PLL            ((u32)0x01000000)   // PLL ON/OFF bit
#define STATUS_CLK_PLL     ((u32)0x02000000)   // PLL Ready bit

/** In RCC_BDCR **/
#define CLK_LSE            ((u32)0x00000001)   // LSE ON/OFF
#define STATUS_CLK_LSE     ((u32)0x00000002)   // LSE Ready bit
#define LSE_BYPASS_MASK    ((u32)0x00000004)   // LSE Bypass bit

/** In RCC_CSR **/
#define CLK_LSI            ((u32)0x00000001)   // LSI ON/OFF
#define STATUS_CLK_LSI     ((u32)0x00000002)   // LSI Ready bit

/***************************************************************/


/**************** Select System Clocks Masks ************/
/** In RCC_CFGR **/
#define SYS_CLK_MASK			((u32)0x02)
#define SYS_CLK_HSI				((u32)0x00)
#define SYS_CLK_HSE				((u32)0x01)
#define SYS_CLK_PLL				((u32)0x02)

#define STATUS_SYS_CLK_MASK		((u32)0x0C)
#define STATUS_SYS_CLK_HSI		((u32)0x00)
#define STATUS_SYS_CLK_HSE		((u32)0x04)
#define STATUS_SYS_CLK_PLL		((u32)0x08)
/********************************************************/

/*************** Main PLL Configuration Masks ****************/

/** RCC_PLLCFGR **/
/**** Common Parameters (Source, M, and N) ****/
#define PLLSRC_MASK					((u32)0x400000)
#define PLLSRC_HSI					((u32)0x0)
#define PLLSRC_HSE					((u32)0x400000)

#define PLLM_MASK					((u32)0X1F)
#define PLLM_VALID_RANGE_START 		((u32)2)
#define PLLM_VALID_RANGE_END 		((u32)63)
#define PLLM_VALID_VALUE(VALUE)		((u32)VALUE)
#define PLLM_CHECK(M_VALUE) 		((M_VALUE >= 2 && M_VALUE <= 63)? (u32)M_VALUE : RCC_InvalidParameter)

#define PLLN_MASK					((u32)0x7FC0)
#define PLLN_VALID_RANGE_START 		((u32)192)
#define PLLN_VALID_RANGE_END 		((u32)432)
#define PLLN_VALID_VALUE(VALUE)		((u32)VALUE<<6)
#define PLLN_CHECK(N_VALUE) 				((N_VALUE >= 192 && N_VALUE <= 432)? (u32)N_VALUE<<6 : RCC_InvalidParameter)
/****************************************************************************************************************/
/**** PLLCLK Configuration Masks ****/
#define PLLP_MASK    				((u32)0x30000)
#define PLLP_VALID_RANGE_START 		((u32)2)
#define PLLP_VALID_RANGE_END 		((u32)8)
#define PLLP_VALID_VALUE(VALUE)		((u32)VALUE<<16)
#define PLLP_EQUTION(VALID_VALUE)	(((((u32)VALID_VALUE)/2)-1)<<16)
#define PLLP_CHECK(P_VALUE) 				((P_VALUE == 2 || P_VALUE == 4 || P_VALUE == 6 || P_VALUE == 8)? ((((u32)P_VALUE)/2)-1)<<16 : RCC_InvalidParameter)
/************************************/

/**** PLL48CK Configuration Masks ****/
#define PLLQ_MASK    				((u32)0XF000000)  // Bits 27:24
#define PLLQ_VALID_RANGE_START 		((u32)2)
#define PLLQ_VALID_RANGE_END 		((u32)15)
#define PLLQ_VALID_VALUE(VALUE)		((u32)VALUE<<24)
#define PLLQ(Q_VALUE) 				((Q_VALUE >= 2 && Q_VALUE <= 15)? (u32)Q_VALUE<<24 : RCC_InvalidParameter)
/*************************************/

/**** PLLI2S Configuration Masks ****/
/** RCC_PLLI2SCFGR **/
#define I2SSRC_MASK					((u32)0x800000)
#define I2SSRC_PLLI2S				((u32)0x0)
#define I2SSRC_EXT_CLK				((u32)0x800000)

/** RCC_PLLI2SCFGR **/
#define PLLI2SN_MASK				((u32)0x7FC0)
#define PLLI2SN_VALID_RANGE_START	((u32)192)
#define PLLI2SN_VALID_RANGE_END		((u32)432)
#define PLLI2SN_VALID_VALUE(VALUE)	((u32)VALUE<<6)
#define PLLI2SN(I2SN_VALUE) 		((I2SN_VALUE >= 192 && I2SN_VALUE <= 432)? (u32)I2SN_VALUE<<6 : RCC_InvalidParameter)

#define PLLI2SR_MASK				((u32)70000000)
#define PLLI2SR_VALID_RANGE_START	((u32)2)
#define PLLI2SR_VALID_RANGE_END		((u32)7)
#define PLLI2SR_VALID_VALUE(VALUE)	((u32)VALUE<<28)
#define PLLI2SR(I2SR_VALUE) 		((I2SR_VALUE >= 2 && I2SR_VALUE <= 7)? (u32)I2SR_VALUE<<28 : RCC_InvalidParameter)
/************************************/
/********************************************************/


/**************** AHB1 Peripherals Masks ****************/
/** In RCC_AHB1ENR **/
#define AHB1_DMA2     ((u32)0x00400000)   // (1U << 22)
#define AHB1_DMA1     ((u32)0x00200000)   // (1U << 21)
#define AHB1_CRC      ((u32)0x00001000)   // (1U << 12)
#define AHB1_GPIOH    ((u32)0x00000080)   // (1U << 7)
#define AHB1_GPIOE    ((u32)0x00000010)   // (1U << 4)
#define AHB1_GPIOD    ((u32)0x00000008)   // (1U << 3)
#define AHB1_GPIOC    ((u32)0x00000004)   // (1U << 2)
#define AHB1_GPIOB    ((u32)0x00000002)   // (1U << 1)
#define AHB1_GPIOA    ((u32)0x00000001)   // (1U << 0)

/********************************************************/

/**************** AHB2 Peripherals Masks ****************/
/** In RCC_AHB2ENR **/
#define AHB2_OTGFS		((u32)0x80)
/********************************************************/

/**************** APB1 Peripherals Masks ****************/
/** In RCC_APB1ENR **/
#define APB1_PWR       ((u32)0x10000000)   // (1U << 28)
#define APB1_I2C3      ((u32)0x00800000)   // (1U << 23)
#define APB1_I2C2      ((u32)0x00400000)   // (1U << 22)
#define APB1_I2C1      ((u32)0x00200000)   // (1U << 21)
#define APB1_USART2    ((u32)0x00020000)   // (1U << 17)
#define APB1_SPI3      ((u32)0x00008000)   // (1U << 15)
#define APB1_SPI2      ((u32)0x00004000)   // (1U << 14)
#define APB1_WWDG      ((u32)0x00000800)   // (1U << 11)
#define APB1_TIM5      ((u32)0x00000008)   // (1U << 3)
#define APB1_TIM4      ((u32)0x00000004)   // (1U << 2)
#define APB1_TIM3      ((u32)0x00000002)   // (1U << 1)
#define APB1_TIM2      ((u32)0x00000001)   // (1U << 0)
/********************************************************/

/**************** APB2 Peripherals Masks ****************/
/** In RCC_APB2ENR **/
#define APB2_TIM11      ((u32)0x00040000)   // (1U << 18)
#define APB2_TIM10      ((u32)0x00020000)   // (1U << 17)
#define APB2_TIM9       ((u32)0x00010000)   // (1U << 16)
#define APB2_SYSCFG     ((u32)0x00004000)   // (1U << 14)
#define APB2_SPI4       ((u32)0x00002000)   // (1U << 13)
#define APB2_SPI1       ((u32)0x00001000)   // (1U << 12)
#define APB2_SDIO       ((u32)0x00000800)   // (1U << 11)
#define APB2_ADC1       ((u32)0x00000100)   // (1U << 8)
#define APB2_USART6     ((u32)0x00000020)   // (1U << 5)
#define APB2_USART1     ((u32)0x00000010)   // (1U << 4)
#define APB2_TIM1       ((u32)0x00000001)   // (1U << 0)
/********************************************************/

/***************** AHB Prescaler Masks ******************/
/** In RCC_CFGR **/
// AHB prescaler valid options
#define AHB_PRESCALER_MASK	  ((u32)0xF0) // AHB prescaler divided by 1: system clock not divided
#define AHB_PRESCALER_DIV2    ((u32)0x00000080) // AHB prescaler divided by 2: system clock divided by 2
#define AHB_PRESCALER_DIV4    ((u32)0x00000090) // AHB prescaler divided by 4: system clock divided by 4
#define AHB_PRESCALER_DIV8    ((u32)0x000000A0) // AHB prescaler divided by 8: system clock divided by 8
#define AHB_PRESCALER_DIV16   ((u32)0x000000B0) // AHB prescaler divided by 16: system clock divided by 16
#define AHB_PRESCALER_DIV64   ((u32)0x000000C0) // AHB prescaler divided by 64: system clock divided by 64
#define AHB_PRESCALER_DIV128  ((u32)0x000000D0) // AHB prescaler divided by 128: system clock divided by 128
#define AHB_PRESCALER_DIV256  ((u32)0x000000E0) // AHB prescaler divided by 256: system clock divided by 256
#define AHB_PRESCALER_DIV512  ((u32)0x000000F0) // AHB prescaler divided by 512: system clock divided by 512
/********************************************************/

/***************** APB Low speed Prescaler (APB1) Masks ******************/
/** In RCC_CFGR **/
#define APB1_PRESCALER_MASK    ((u32)0x1C00) // APB1 prescaler not divided: APB1 clock not divided
#define APB1_PRESCALER_DIV2    ((u32)0x00001000) // APB1 prescaler divided by 2
#define APB1_PRESCALER_DIV4    ((u32)0x00001400) // APB1 prescaler divided by 4
#define APB1_PRESCALER_DIV8    ((u32)0x00001800) // APB1 prescaler divided by 8
#define APB1_PRESCALER_DIV16   ((u32)0x00001C00) // APB1 prescaler divided by 16
/********************************************************/

/***************** APB High speed prescaler (APB2) Masks ******************/
/** In RCC_CFGR **/
#define APB2_PRESCALER_MASK    ((u32)0xE000) // APB2 prescaler not divided: APB2 clock not divided
#define APB2_PRESCALER_DIV2    ((u32)0x00008000) // APB2 prescaler divided by 2
#define APB2_PRESCALER_DIV4    ((u32)0x0000A000) // APB2 prescaler divided by 4
#define APB2_PRESCALER_DIV8    ((u32)0x0000C000) // APB2 prescaler divided by 8
#define APB2_PRESCALER_DIV16   ((u32)0x0000E000) // APB2 prescaler divided by 16
/********************************************************/

typedef enum{
	RCC_Clk_HSI,
	RCC_Clk_HSE,
	RCC_Clk_PLL,
	RCC_Clk_LSI,
	RCC_Clk_LSE
}RCC_Clk_t;

typedef enum{
	RCC_Ok,
	RCC_Nok,
	RCC_InvalidParameter,
	RCC_NullPtr,
}RCC_errorState_t;


typedef struct {
    volatile u32 CR;          // RCC clock control register
    volatile u32 PLLCFGR;     // RCC PLL configuration register
    volatile u32 CFGR;        // RCC clock configuration register
    volatile u32 CIR;         // RCC clock interrupt register
    volatile u32 AHB1RSTR;    // RCC AHB1 peripheral reset register
    volatile u32 AHB2RSTR;    // RCC AHB2 peripheral reset register
    volatile u32 RESERVED0[2];   // Reserved, do not use
    volatile u32 APB1RSTR;    // RCC APB1 peripheral reset register
    volatile u32 APB2RSTR;    // RCC APB2 peripheral reset register
    volatile u32 RESERVED1[2]; // Reserved, do not use
    volatile u32 AHB1ENR;     // RCC AHB1 peripheral clock enable register
    volatile u32 AHB2ENR;     // RCC AHB2 peripheral clock enable register
    volatile u32 RESERVED2[2]; // Reserved, do not use

    volatile u32 APB1ENR;     // RCC APB1 peripheral clock enable register
    volatile u32 APB2ENR;     // RCC APB2 peripheral clock enable register
    volatile u32 RESERVED3[2]; // Reserved, do not use
    volatile u32 AHB1LPENR;   // RCC AHB1 peripheral clock enable in low power mode register
    volatile u32 AHB2LPENR;   // RCC AHB2 peripheral clock enable in low power mode register
    volatile u32 RESERVED4[2]; // Reserved, do not use
    volatile u32 APB1LPENR;   // RCC APB1 peripheral clock enable in low power mode register
    volatile u32 APB2LPENR;   // RCC APB2 peripheral clock enable in low power mode register
    volatile u32 RESERVED5[2]; // Reserved, do not use
    volatile u32 BDCR;        // RCC Backup domain control register
    volatile u32 CSR;         // RCC clock control & status register
    volatile u32 RESERVED6[2]; // Reserved, do not use
    volatile u32 SSCGR;       // RCC spread spectrum clock generation register
    volatile u32 PLLI2SCFGR;  // RCC PLLI2S configuration register
    volatile u32 RESERVED7;   // Reserved, do not use
    volatile u32 DCKCFGR;    // RCC Dedicated Clock Configuration Register
} RCC_regs_t;



void RCC_selectSysClk(u32 sysClk);
u32 RCC_getSysClk(void);

void RCC_enableHSEbypass(void);
void RCC_disableHSEbypass(void);

void RCC_enableClk(RCC_Clk_t clk);
void RCC_disableClk(RCC_Clk_t clk);

u32 RCC_getClkStatus(RCC_Clk_t clk);

/*
 * These Functions are used to configure the PLL clocks outputs according to the formulas:
	• f(VCO clock) = f(PLL clock input) × (PLLN / PLLM)
	• f(PLL general clock output (PllClk)) = f(VCO clock) / PLLP
	• f(USB OTG FS, SDIO, RNG clock output (Pll48Ck)) = f(VCO clock) / PLLQ
*/
RCC_errorState_t RCC_configPll(u32 PLL_SRC, u32 PLLM, u32 PLLN);
RCC_errorState_t RCC_configPllClk(u32 PLLP);
RCC_errorState_t RCC_configPll48Ck(u32 PLLQ);
RCC_errorState_t RCC_configPllI2SClk(u32 I2S_SRC, u32 PLLI2SN, u32 PLLI2SR);


void RCC_enableAHB1_Peripheral(u32 peripheral);
void RCC_enableAHB2_Peripheral(u32 peripheral);
void RCC_enableAPB1_Peripheral(u32 peripheral);
void RCC_enableAPB2_Peripheral(u32 peripheral);

void RCC_disableAHB1_Peripheral(u32 peripheral);
void RCC_disableAHB2_Peripheral(u32 peripheral);
void RCC_disableAPB1_Peripheral(u32 peripheral);
void RCC_disableAPB2_Peripheral(u32 peripheral);

void RCC_configAHBprescaler(u32 prescale_value);
void RCC_configAPB1prescaler(u32 prescale_value);
void RCC_configAPB2prescaler(u32 prescale_value);



#endif
