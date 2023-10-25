#include "gpio.h"

void GPIO_Config(GPIO_TypeDef *GPIOx, uint8_t GPIO_Mode, uint16_t GPIO_Pin)
{
    /* Check the parameters */
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(GPIO_Pin));

    if (GPIOx == GPIOA)
    {
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    }
    else if (GPIOx == GPIOB)
    {
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    }
    else if (GPIOx == GPIOC)
    {
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    }
    else if (GPIOx == GPIOD)
    {
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
    }
    else if (GPIOx == GPIOE)
    {
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
    }
    else if (GPIOx == GPIOF)
    {
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);
    }
    else if (GPIOx == GPIOG)
    {
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG, ENABLE);
    }

    GPIO_InitTypeDef gpioInit;

    gpioInit.GPIO_Mode = GPIO_Mode;
    gpioInit.GPIO_Pin = GPIO_Pin;
    gpioInit.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOx, &gpioInit);
}

/**
 * @brief  Sets the selected data port bits.
 * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
 * @param  GPIO_Pin: specifies the port bits to be written.
 *   This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
 * @retval None
 */
void GPIO_Enable(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    /* Check the parameters */
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(GPIO_Pin));

    GPIOx->BSRR = GPIO_Pin;
}

/**
 * @brief  Clears the selected data port bits.
 * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
 * @param  GPIO_Pin: specifies the port bits to be written.
 *   This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
 * @retval None
 */
void GPIO_Disable(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    /* Check the parameters */
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(GPIO_Pin));

    GPIOx->BRR = GPIO_Pin;
}

/**
 * @brief  Toggles the specified GPIO pin
 * @param  GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 * @param  GPIO_Pin: Specifies the pins to be toggled.
 * @retval None
 */
void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    uint32_t odr;

    /* Check the parameters */
    assert_param(IS_GPIO_PIN(GPIO_Pin));

    /* get current Output Data Register value */
    odr = GPIOx->ODR;

    /* Set selected pins that were at low level, and reset ones that were high */
    GPIOx->BSRR = ((odr & GPIO_Pin) << 16u) | (~odr & GPIO_Pin);
}

/**
 * @brief  Locks GPIO Pins configuration registers.
 * @note   The locking mechanism allows the IO configuration to be frozen. When the LOCK sequence
 *         has been applied on a port bit, it is no longer possible to modify the value of the port bit until
 *         the next reset.
 * @param  GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 * @param  GPIO_Pin: specifies the port bit to be locked.
 *         This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
 * @retval None
 */
void GPIO_Lock(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
}

/**
 * @brief  Reads the specified input port pin.
 * @param  GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 * @param  GPIO_Pin: specifies the port bit to read.
 *         This parameter can be GPIO_PIN_x where x can be (0..15).
 * @retval The input port pin value.
 */
uint8_t GPIO_Read(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    BitAction status;

    /* Check the parameters */
    assert_param(IS_GPIO_PIN(GPIO_Pin));

    if ((GPIOx->IDR & GPIO_Pin) != (uint8_t)RESET)
    {
        status = Bit_SET;
    }
    else
    {
        status = Bit_RESET;
    }
    return status;
}

/**
 * @brief  Sets or clears the selected data port bit.
 *
 * @note   This function uses GPIOx_BSRR register to allow atomic read/modify
 *         accesses. In this way, there is no risk of an IRQ occurring between
 *         the read and the modify access.
 *
 * @param  GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 * @param  GPIO_Pin: specifies the port bit to be written.
 *          This parameter can be one of GPIO_PIN_x where x can be (0..15).
 * @param  PinState: specifies the value to be written to the selected bit.
 *          This parameter can be one of the GPIO_PinState enum values:
 *            @arg GPIO_PIN_RESET: to clear the port pin
 *            @arg GPIO_PIN_SET: to set the port pin
 * @retval None
 */
void GPIO_Write_Pin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, uint8_t Status)
{
    /* Check the parameters */
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
    assert_param(IS_GPIO_BIT_ACTION(BitVal));

    if (Status != Bit_RESET)
    {
        GPIOx->BSRR = GPIO_Pin;
    }
    else
    {
        GPIOx->BRR = GPIO_Pin;
    }
}
