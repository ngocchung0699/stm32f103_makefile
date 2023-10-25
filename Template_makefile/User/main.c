#include "main.h"
#include "systick.h"
#include "gpio.h"

int main(void)
{
	SystemInit();
	SysTick_Init();

	GPIO_Config(GPIOC, GPIO_Mode_Out_PP, GPIO_Pin_13);
	while (1)
	{
		Delay_ms(100);
		GPIO_Enable(GPIOC, GPIO_Pin_13);
		Delay_ms(100);
		GPIO_Disable(GPIOC, GPIO_Pin_13);
	}
}
