#include "nc_systick.h"

volatile uint64_t Timing;

/**
 * @brief  This function sets the system clock.
 * @param  None
 * @retval None
 */
void SysTick_Init()
{
    Timing = 0;
    SysTick_Config(SystemCoreClock / 1000000);
}

/**
 * @brief  This function create a time delay micro seconds.
 * @param  None
 * @retval None
 */
void Delay_us(uint32_t us)
{
    uint64_t TimingDelay = Micros();
    while (Micros() - TimingDelay < us)
    {
    }
}

/**
 * @brief  This function create a time delay milli seconds.
 * @param  None
 * @retval None
 */
void Delay_ms(uint16_t ms)
{
    Delay_us(ms * 1000);
}

/**
 * @brief  This function get current time micro seconds.
 * @param  None
 * @retval Current time
 */
uint64_t Micros()
{
    return Timing;
}

/**
 * @brief  This function get current time milli seconds.
 * @param  None
 * @retval Current time
 */
uint64_t Millis()
{
    uint64_t time = (uint64_t) Timing / 1000;
    return time;
}


