#include "RCC.h"

void RCC_selectSysClk(u32 sysClk) {
	RCC_regs_t *rcc = ((RCC_regs_t*) RCC_BASE_ADDRESS);

	u32 temp_reg = rcc->CFGR;
	temp_reg &= ~SYS_CLK_MASK;
	temp_reg |= sysClk;
	rcc->CFGR = temp_reg;
}

u32 RCC_getSysClk(void) {
	RCC_regs_t *rcc = ((RCC_regs_t*) RCC_BASE_ADDRESS);
	return rcc->CFGR & STATUS_SYS_CLK_MASK;
}

void RCC_enableHSEbypass(void) {
	RCC_regs_t *rcc = ((RCC_regs_t*) RCC_BASE_ADDRESS);

	u32 temp_reg = rcc->CR;
	temp_reg &= ~HSE_BYPASS_MASK;
	temp_reg |= HSE_BYPASS_MASK;
	rcc->CR = temp_reg;
}
void RCC_disableHSEbypass(void) {
	RCC_regs_t *rcc = ((RCC_regs_t*) RCC_BASE_ADDRESS);
	u32 temp_reg = rcc->CR;

	temp_reg &= ~HSE_BYPASS_MASK;
	rcc->CR = temp_reg;
}

void RCC_enableClk(RCC_Clk_t clk) {
	RCC_regs_t *rcc = ((RCC_regs_t*) RCC_BASE_ADDRESS);
	u32 temp_reg = rcc->CR;

	switch (clk) {
	case RCC_Clk_HSI:
		temp_reg = rcc->CR;
		temp_reg &= ~CLK_HSI;
		temp_reg |= CLK_HSI;
		rcc->CR = temp_reg;
		break;

	case RCC_Clk_HSE:
		temp_reg = rcc->CR;
		temp_reg &= ~CLK_HSE;
		temp_reg |= CLK_HSE;
		rcc->CR = temp_reg;
		break;

	case RCC_Clk_PLL:
		temp_reg = rcc->CR;
		temp_reg &= ~CLK_PLL;
		temp_reg |= CLK_PLL;
		rcc->CR = temp_reg;
		break;

	case RCC_Clk_LSE:
		temp_reg = rcc->BDCR;
		temp_reg &= ~CLK_LSE;
		temp_reg |= CLK_LSE;
		rcc->BDCR = temp_reg;
		break;

	case RCC_Clk_LSI:
		temp_reg = rcc->CSR;
		temp_reg &= ~CLK_LSI;
		temp_reg |= CLK_LSI;
		rcc->CSR = temp_reg;
		break;
	}

}
void RCC_disableClk(RCC_Clk_t clk) {
	RCC_regs_t *rcc = ((RCC_regs_t*) RCC_BASE_ADDRESS);
	u32 temp_reg = rcc->CR;

	switch (clk) {
	case RCC_Clk_HSI:
		temp_reg = rcc->CR;
		temp_reg &= ~CLK_HSI;
		rcc->CR = temp_reg;
		break;

	case RCC_Clk_HSE:
		temp_reg = rcc->CR;
		temp_reg &= ~CLK_HSE;
		rcc->CR = temp_reg;
		break;

	case RCC_Clk_PLL:
		temp_reg = rcc->CR;
		temp_reg &= ~CLK_PLL;
		rcc->CR = temp_reg;
		break;

	case RCC_Clk_LSE:
		temp_reg = rcc->BDCR;
		temp_reg &= ~CLK_LSE;
		rcc->BDCR = temp_reg;
		break;

	case RCC_Clk_LSI:
		temp_reg = rcc->CSR;
		temp_reg &= ~CLK_LSI;
		rcc->CSR = temp_reg;
		break;
	}
}

u32 RCC_getClkStatus(RCC_Clk_t clk) {
	RCC_regs_t *rcc = ((RCC_regs_t*) RCC_BASE_ADDRESS);
	u32 clk_status = 0;

	switch (clk) {
	case RCC_Clk_HSI:
		clk_status = rcc->CR & STATUS_CLK_HSI;
		break;

	case RCC_Clk_HSE:
		clk_status = rcc->CR & STATUS_CLK_HSI;
		break;

	case RCC_Clk_PLL:
		clk_status = rcc->CR & STATUS_CLK_HSI;
		break;

	case RCC_Clk_LSE:
		clk_status = rcc->CR & STATUS_CLK_HSI;
		break;

	case RCC_Clk_LSI:
		clk_status = rcc->CR & STATUS_CLK_HSI;
		break;
	}

	return clk_status;
}

/*
 * These Functions are used to configure the PLL clocks outputs according to the formulas:
 • f(VCO clock) = f(PLL clock input) × (PLLN / PLLM)
 • f(PLL general clock output (PllClk)) = f(VCO clock) / PLLP
 • f(USB OTG FS, SDIO, RNG clock output (Pll48Ck)) = f(VCO clock) / PLLQ
 */
RCC_errorState_t RCC_configPll(u32 PLL_SRC, u32 PLLM, u32 PLLN) {
	RCC_errorState_t errorState = RCC_Nok;
	RCC_regs_t *rcc = ((RCC_regs_t*) RCC_BASE_ADDRESS);
	u32 tempReg = rcc->PLLCFGR;

	if ((PLL_SRC != PLLSRC_HSI) || (PLL_SRC != PLLSRC_HSE)) {
		errorState = RCC_InvalidParameter;
	} else if ((PLLM < PLLM_VALID_RANGE_START || PLLM > PLLM_VALID_RANGE_END)) {
		errorState = RCC_InvalidParameter;
	} else if ((PLLN < PLLN_VALID_RANGE_START || PLLN > PLLN_VALID_RANGE_END)) {
		errorState = RCC_InvalidParameter;
	} else {
		errorState = RCC_Ok;
		tempReg &= ~PLLSRC_MASK;
		tempReg |= PLL_SRC;

		tempReg &= ~PLLM_MASK;
		tempReg |= PLLM_VALID_VALUE(PLLM);

		tempReg &= ~ PLLN_MASK;
		tempReg |= PLLN_VALID_VALUE(PLLN);

		rcc->PLLCFGR = tempReg;
	}

	return errorState;
}

RCC_errorState_t RCC_configPllClk(u32 PLLP) {
	RCC_errorState_t errorState = RCC_Nok;
	RCC_regs_t *rcc = ((RCC_regs_t*) RCC_BASE_ADDRESS);
	u32 tempReg = rcc->PLLCFGR;

	if ((PLLP != 2 || PLLP != 4 || PLLP != 6 || PLLP != 8)) {
		errorState = RCC_InvalidParameter;
	} else {
		errorState = RCC_Ok;
		tempReg &= ~PLLP_MASK;
		tempReg |= PLLP_EQUTION(PLLP);
		rcc->PLLCFGR = tempReg;
	}
	return errorState;
}

RCC_errorState_t RCC_configPll48Ck(u32 PLLQ) {
	RCC_errorState_t errorState = RCC_Nok;
	RCC_regs_t *rcc = ((RCC_regs_t*) RCC_BASE_ADDRESS);
	u32 tempReg = rcc->PLLCFGR;

	if ((PLLQ < PLLQ_VALID_RANGE_START || PLLQ > PLLQ_VALID_RANGE_END)) {
		errorState = RCC_InvalidParameter;
	} else {
		errorState = RCC_Ok;
		tempReg &= ~PLLQ_MASK;
		tempReg |= PLLQ_VALID_VALUE(PLLQ);
		rcc->PLLCFGR = tempReg;
	}
	return errorState;
}

RCC_errorState_t RCC_configPllI2SClk(u32 I2S_SRC, u32 PLLI2SN, u32 PLLI2SR) {
	RCC_errorState_t errorState = RCC_Nok;
	RCC_regs_t *rcc = ((RCC_regs_t*) RCC_BASE_ADDRESS);
	u32 tempReg = rcc->PLLI2SCFGR;

	if ((I2S_SRC != I2SSRC_PLLI2S) || (I2S_SRC != I2SSRC_EXT_CLK)) {
		errorState = RCC_InvalidParameter;
	} else if ((PLLI2SN < PLLI2SN_VALID_RANGE_START
			|| PLLI2SN > PLLI2SN_VALID_RANGE_END)) {
		errorState = RCC_InvalidParameter;
	} else if ((PLLI2SR < PLLI2SR_VALID_RANGE_START
			|| PLLI2SR > PLLI2SR_VALID_RANGE_END)) {
		errorState = RCC_InvalidParameter;
	} else {
		errorState = RCC_Ok;
		tempReg &= ~I2SSRC_MASK;
		tempReg |= I2S_SRC;

		tempReg &= ~PLLI2SN_MASK;
		tempReg |= PLLI2SN_VALID_VALUE(PLLI2SN);

		tempReg &= ~ PLLI2SR_MASK;
		tempReg |= PLLI2SR_VALID_VALUE(PLLI2SR);

		rcc->PLLI2SCFGR = tempReg;
	}

	return errorState;
}

void RCC_enableAHB1_Peripheral(u32 peripheral) {
	RCC_regs_t *rcc = ((RCC_regs_t*) RCC_BASE_ADDRESS);
	rcc->AHB1ENR |= peripheral;
}

void RCC_enableAHB2_Peripheral(u32 peripheral) {
	RCC_regs_t *rcc = ((RCC_regs_t*) RCC_BASE_ADDRESS);
	rcc->AHB2ENR |= peripheral;
}

void RCC_enableAPB1_Peripheral(u32 peripheral) {
	RCC_regs_t *rcc = ((RCC_regs_t*) RCC_BASE_ADDRESS);
	rcc->APB1ENR |= peripheral;
}

void RCC_enableAPB2_Peripheral(u32 peripheral) {
	RCC_regs_t *rcc = ((RCC_regs_t*) RCC_BASE_ADDRESS);
	rcc->APB2ENR |= peripheral;
}

void RCC_disableAHB1_Peripheral(u32 peripheral) {
	RCC_regs_t *rcc = ((RCC_regs_t*) RCC_BASE_ADDRESS);
	rcc->AHB1ENR &= ~peripheral;
}

void RCC_disableAHB2_Peripheral(u32 peripheral) {
	RCC_regs_t *rcc = ((RCC_regs_t*) RCC_BASE_ADDRESS);
	rcc->AHB2ENR &= ~peripheral;
}

void RCC_disableAPB1_Peripheral(u32 peripheral) {
	RCC_regs_t *rcc = ((RCC_regs_t*) RCC_BASE_ADDRESS);
	rcc->APB1ENR &= ~peripheral;
}

void RCC_disableAPB2_Peripheral(u32 peripheral) {
	RCC_regs_t *rcc = ((RCC_regs_t*) RCC_BASE_ADDRESS);
	rcc->APB2ENR &= ~peripheral;
}

void RCC_configAHBprescaler(u32 prescale_value)
{
	RCC_regs_t *rcc = ((RCC_regs_t*) RCC_BASE_ADDRESS);
	u32 tempReg = rcc->CFGR;
	tempReg &= ~AHB_PRESCALER_MASK;
	tempReg |= prescale_value;
	rcc->CFGR = tempReg;
}

void RCC_configAPB1prescaler(u32 prescale_value)
{
	RCC_regs_t *rcc = ((RCC_regs_t*) RCC_BASE_ADDRESS);
	u32 tempReg = rcc->CFGR;
	tempReg &= ~APB1_PRESCALER_MASK;
	tempReg |= prescale_value;
	rcc->CFGR = tempReg;
}

void RCC_configAPB2prescaler(u32 prescale_value)
{
	RCC_regs_t *rcc = ((RCC_regs_t*) RCC_BASE_ADDRESS);
	u32 tempReg = rcc->CFGR;
	tempReg &= ~APB2_PRESCALER_MASK;
	tempReg |= prescale_value;
	rcc->CFGR = tempReg;
}

