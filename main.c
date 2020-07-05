#include "stm32f4xx.h"
#include "RCC.h"


void configureLedPins(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN_Msk;
	GPIOD->MODER |= (1U<<GPIO_MODER_MODER13_Pos);
	//Turn on the led13 orange
	GPIOD->ODR |= GPIO_ODR_ODR_13;
	
	GPIOD->BSRR |= GPIO_BSRR_BS13_Msk;
	
}

int main()
{ 
	
	 configureLedPins();	

}