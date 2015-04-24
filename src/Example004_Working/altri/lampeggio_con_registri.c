#include "main.h"

__IO uint32_t TimingDelay = 0;
GPIO_InitTypeDef GPIO_InitStructure; // dichiariamo la struttura abilitando il GPIO_LED Clock 

int main(void)
{
  if (SysTick_Config(SystemCoreClock / 1000))
  { 
    while (1)
    {}
  }
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);
  GPIOE->MODER= 1<<18;
  GPIOE->OSPEEDR= 2<<18; 

  /* Infinite loop */
  while (1)
  {
    GPIOE->ODR = 1<<9;
    Delay(500);
    GPIOE->BRR = 1<<9;
     Delay(500); 
  }
}

/**
  * @brief  Inserts a delay time.
  * @param  nTime: specifies the delay time length, in milliseconds.
  * @retval None
  */
void Delay(__IO uint32_t nTime)
{ 
  TimingDelay = nTime;

  while(TimingDelay != 0);
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
