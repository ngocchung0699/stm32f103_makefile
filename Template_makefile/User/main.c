#include "main.h"

volatile uint32_t tim = 0;
int main(void)
{
	SystemInit();
	SysTick_Init();
	GPIO_Config(GPIOA, GPIO_Mode_Out_PP, GPIO_Pin_0);
	tim = Micros();
	while (1)
	{
		if (Micros() - tim < 100)
		{
			GPIO_Enable(GPIOA, GPIO_Pin_0);
		}
		if (Micros() - tim > 100)
		{
			GPIO_Disable(GPIOA, GPIO_Pin_0);
		}
		if (Micros() - tim >= 200)
		{
			tim = Micros();
		}
	}
}
