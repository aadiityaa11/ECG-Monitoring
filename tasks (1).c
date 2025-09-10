/*******************************************************************************
 System Tasks File

  File Name:
    tasks.c

  Summary:
    This file contains source code necessary to maintain system's polled tasks.

  Description:
    This file contains source code necessary to maintain system's polled tasks.
    It implements the "SYS_Tasks" function that calls the individual "Tasks"
    functions for all polled MPLAB Harmony modules in the system.

  Remarks:
    This file requires access to the systemObjects global data structure that
    contains the object handles to all MPLAB Harmony module objects executing
    polled in the system.  These handles are passed into the individual module
    "Tasks" functions to identify the instance of the module to maintain.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "configuration.h"
#include "definitions.h"
#include "sys_tasks.h"

#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "app_ble_sensor.h"

// *****************************************************************************
// *****************************************************************************
// Section: RTOS "Tasks" Routine
// *****************************************************************************
// *****************************************************************************
/* Handle for the APP_Tasks. */
TaskHandle_t xAPP_Tasks;

static void lAPP_Tasks(  void *pvParameters  )
{   
    while(true)
    {
        APP_Tasks();
    }
}

#define TASK_BLE_STACK_SIZE (2 *1024 / sizeof(portSTACK_TYPE))
#define TASK_BLE_PRIORITY (tskIDLE_PRIORITY + 3)




// *****************************************************************************
// *****************************************************************************
// Section: System "Tasks" Routine
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void SYS_Tasks ( void )

  Remarks:
    See prototype in system/common/sys_module.h.
*/
void SYS_Tasks ( void )
{
    /* Maintain system services */
    


    /* Maintain Device Drivers */
    

    /* Maintain Middleware & Other Libraries */
    
    if (xTaskCreate(BM_Task,     "BLE", TASK_BLE_STACK_SIZE, NULL  , TASK_BLE_PRIORITY, NULL) != pdPASS)
        while (1);

        
        
    /* Maintain the application's state machine. */
        /* Create OS Thread for APP_Tasks. */
    (void) xTaskCreate((TaskFunction_t) lAPP_Tasks,
                "APP_Tasks",
                1280,
                NULL,
                1,
                &xAPP_Tasks);

    
    
    
    /* Start RTOS Scheduler. */
    
     /**********************************************************************
     * Create all Threads for APP Tasks before starting FreeRTOS Scheduler *
     ***********************************************************************/
    vTaskStartScheduler(); /* This function never returns. */

}

/*******************************************************************************
 End of File
 */




/**/
/**/
/* NEW CODE ADDED */
/**/
/**/


// Timer callback function to update time
void led_handler(TimerHandle_t xTimer) {
    APP_LED_TIMER();    // Code present in app_ble_sensor.c
//    SERCOM0_USART_Write((uint8_t *)"Hello World 2\r\n",13);
}

void vTimeClockTask(void *pvParameters) {    
    TimerHandle_t xTimer = xTimerCreate("ClockTimer", pdMS_TO_TICKS(2000), pdTRUE, (void *)0, led_handler);
    xTimerStart(xTimer, 0);
    
    // Task loop
    while(1) {
    // SERCOM0_USART_Write((uint8_t *)"Hello World\r\n",13);
    }
}

void LED_TIMER_TASK ( void ){
    xTaskCreate(vTimeClockTask, "TimeClockTask", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL);
        
    // Start the scheduler
    vTaskStartScheduler();
}