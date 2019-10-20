#ifndef STARTUP_TASK_H
#define STARTUP_TASK_H
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
// UMSATS 2018-2020
//
// Repository:
//  UMSATS/Avionics-2019
//
// File Description:
//  Header file for the startup task. This task is the first to run.
//
// History
// 2019-04-19 by Joseph Howarth
// - Created.
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
// INCLUDES
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "cmsis_os.h"
#include "configuration.h"
#include "flash.h"
#include "stm32f4xx_hal_uart_io.h"
#include "hardwareDefs.h"

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
// DEFINITIONS AND MACROS
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
// ENUMS AND ENUM TYPEDEFS
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
// STRUCTS AND STRUCT TYPEDEFS
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

typedef struct{

	  TaskHandle_t loggingTask_h ;
	  TaskHandle_t bmpTask_h ;
	  TaskHandle_t imuTask_h ;
	  TaskHandle_t xtractTask_h;
	  TaskHandle_t timerTask_h;

	  Flash * flash_ptr;
	  UART_HandleTypeDef * huart_ptr;
	  configData_t * flightCompConfig;

}startParams;
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
// TYPEDEFS
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
// CONSTANTS
//-------------------------------------------------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------------------------------------------------------------
// FUNCTION PROTOTYPES
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
// Description:
//  This function will be the first task to run when the flight computer is powered on.
//
//As of right now, if S2 is not pressed the task will wait for an amount of time specified in the configuration
//	header file, and will then erase the flash memory and start the IMU, BMP and data logging
//	tasks.
//
//	If S2 is pressed then the xtract task will be started.
//
//	Should be passed a populated startParams struct as the parameter.
//
// Returns:
//
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
void vTask_starter(void * pvParams);

#endif // TEMPLATE_H
