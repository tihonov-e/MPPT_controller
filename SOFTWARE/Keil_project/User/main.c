/*
===============================================================================
 Name        : main.c
 Author      : Eugene
 Version     :
 Copyright   : (C) Copyright
 Description : main definition
===============================================================================
*/


#include "stm32f30x.h"
#define F_CPU 72000000UL

/* Private typedef -----------------------------------------------------------*/
// Задаем структуру параметров порта
GPIO_InitTypeDef GPIO_InitStructure;
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
uint32_t i=0; //Для задердки

/* Private function prototypes -----------------------------------------------*/
void GPIO_init ();	//GPIO init and settings
void delay (int i);

int main () {
	
	// Настраиваем тактирование. Через функцию из CMSIS. Все настройки прописаны в файле system_stm32f10x.c
	// У меня там задана частота 72Мгц с тактированием от кварца на 12Мгц
	SystemInit();


	// Подаем такты на порт GPIOВ
	RCC_AHBPeriphClockCmd (RCC_AHBPeriph_GPIOC , ENABLE);
 
	//Заполняем поля структуры нашими параметрами
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;	// Режим "Выход"
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;	// выход push-pull
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;		// 14 вывод порта
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;		// вывод не подтянут
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_1;	// Скорость fast

	GPIO_Init(GPIOC, &GPIO_InitStructure);		// Применяем настроки на порт C

	/* Infinite loop */
	while(1)
			{
				GPIO_SetBits(GPIOC,GPIO_Pin_14);		// Установить бит
				delay (300000);	
				GPIO_ResetBits(GPIOC,GPIO_Pin_14);		// Сбросить бит
				delay (300000);
			}
 }


 
 
 
/* Assert макросы ---------------------------------------------------------*/

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
     ex: printf("Wrong parameters value: file %s on line %drn", file, line) */
 
  /* Infinite loop */
  while (1)
  {
  }
}
#endif 
/*-----------------------------------------------------------------------*/



/* Private function definition-------------------------------------------*/

//Задержка в попугаях
void delay (int i)
	{
		int t = 0;
		for (t = 0; t < i; t++) {}
	};




/*****************************END OF FILE****/
