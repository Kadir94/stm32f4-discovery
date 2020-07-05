#include "stm32f4xx.h" 
#include "RCC.h"
int main()
{
	
unsigned int temp =0;
unsigned int temp1 =0;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN_Msk;
	GPIOD->MODER |= GPIO_MODER_MODER15_0 |GPIO_MODER_MODER14_0 |GPIO_MODER_MODER13_0 |GPIO_MODER_MODER12_0 ;
	GPIOD->OTYPER &= ~GPIO_OTYPER_OT13_Msk |~GPIO_OTYPER_OT14_Msk;
	GPIOD->PUPDR  |=(0x02U<< GPIO_PUPDR_PUPD13_Pos)|(0x2UL << GPIO_PUPDR_PUPD14_Pos);
	GPIOD ->OSPEEDR |=(3U<<GPIO_OSPEEDR_OSPEED13_Pos)|(3U << GPIO_OSPEEDR_OSPEED14_Pos);
	GPIOD->ODR |= GPIO_ODR_ODR_13|GPIO_ODR_ODR_14;
	GPIOD->BSRR |= GPIO_BSRR_BS13_Msk|GPIO_BSRR_BS14_Msk;
	
	 SysTick->LOAD = 0x1F000;
	 SysTick->CTRL &= ~SysTick_CTRL_COUNTFLAG_Msk;
	 SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
	

	 while(1) 
    {
			if(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) //if flag is set
				{  
					SysTick->CTRL &=~ SysTick_CTRL_COUNTFLAG_Msk;//clear the flag
			    if (temp>=10){//every 1sec toggle
			    GPIOD->ODR ^= GPIO_ODR_ODR_13;//toggle the orange LED
				  temp=0;
				  }
					temp++;
				
					if(temp1>=200){//every 10 sec toggle
					      GPIOD->ODR ^= GPIO_ODR_ODR_14;//toggle the RED LED
				  temp1=0;
					}
			     temp1++;
			 
		    }
		 
   }
	
}

		


