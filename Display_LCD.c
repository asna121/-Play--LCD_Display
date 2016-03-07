/**
    ***********************************************************************
    * @file     Display_LCD.c
    * @author   TIKI
    * @version  V0.1
    * @date     07-March-2016
    * @brief    
    ***********************************************************************
    * 
    *
    *
    *
    *
**/
/* Includes ------------------------------------------------------------------*/
#include "main.h"

#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"
#include "queue.h"

#include "Display_LCD.h"


/* import variable-----------------------------------------------------------*/
extern LTDC_HandleTypeDef LtdcHandle;


/* Private function prototypes ----------------------------------------------*/
static void WW_loop(void *argument);



void display_lcd(void)
{

   xTaskCreate(WW_loop,"USER_Thread", 16 * configMINIMAL_STACK_SIZE, NULL, 0,NULL);


}



static void WW_loop(void *argument)
{
  uint32_t tobuttom = 0;
  uint32_t totop = 0;
    
    while (1)
        
    {
    for (tobuttom = 1; tobuttom < 41; tobuttom++)
    {
      /* move the picture */
      /* reconfigure the layer1 position */
      HAL_LTDC_SetWindowPosition(&LtdcHandle, 0, (tobuttom*4), 0); 
      /* reconfigure the layer2 position */
      HAL_LTDC_SetWindowPosition(&LtdcHandle, 0, (160 - (tobuttom*4)), 1); 
      HAL_Delay(50);
    }
    HAL_Delay(500);
    for (totop = 1; totop < 41; totop++)
    {
      /* move the picture */
      /* reconfigure the layer1 position */
      HAL_LTDC_SetWindowPosition(&LtdcHandle, 0, (160 - (totop*4)), 0); 
      /* reconfigure the layer2 position */
      HAL_LTDC_SetWindowPosition(&LtdcHandle, 0, (totop*4), 1); 
      HAL_Delay(50);
    }
    HAL_Delay(500);
    
	}


}
