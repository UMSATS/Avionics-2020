#ifndef DATA_LOGGING_H
#define DATA_LOGGING_H
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
// UMSATS 2018-2020
//
// Repository:
//  UMSATS/Avionics-2019
//
// File Description:
//  Header file for the data logging module. This uses the flash memory interface to log data to memory.
//
// History
// 2019-04-09 by Joseph Howarth
// - Created.
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
// INCLUDES
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <string.h> 				// For memcpy
#include "cmsis_os.h"				//For delay and queues
#include "flash.h"					//For flash memory functions
#include "pressure_sensor_bmp3.h"	//For bmp reading struct
#include "sensorAG.h"				//For imu_reading struct
#include "configuration.h"


//-------------------------------------------------------------------------------------------------------------------------------------------------------------
// DEFINITIONS AND MACROS
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
#define DATA_BUFFER_SIZE	256			//Matches flash memory page size.
#define TIME_RESOLUTION		DATA_RATE
#define ACC_TYPE 			0x8000
#define GYRO_TYPE			0x4000
#define PRES_TYPE			0x2000
#define	TEMP_TYPE			0x1000

#define	ACC_LENGTH	6		//Length of a accelerometer measurement in bytes.
#define	GYRO_LENGTH	6		//Length of a gyroscope measurement in bytes.
#define	PRES_LENGTH	3		//Length of a pressure measurement in bytes.
#define	TEMP_LENGTH	3		//Length of a temperature measurement in bytes.


//-------------------------------------------------------------------------------------------------------------------------------------------------------------
// ENUMS AND ENUM TYPEDEFS
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

typedef enum{

	BUFFER_A = 0,
	BUFFER_B = 1

} BufferSelection_t;

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
// STRUCTS AND STRUCT TYPEDEFS
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

typedef struct{

	FlashStruct_t * flash_ptr;
	UART_HandleTypeDef * uart;

	//Queues
	QueueHandle_t IMU_data_queue;	//For holding accelerometer and gyroscope readings.
	QueueHandle_t PRES_data_queue;	//For holding pressure and temp. readings.

}LoggingStruct_t;


typedef struct{

			uint8_t  data[20];

}Measurement_t;
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
//  This task logs data measurements to the flash memory.
//
//	Should be passed a populated LoggingStruct as the parameter.
//	The flash should be initialized before this task is started.
//
// Returns:
//
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
void loggingTask(void * params);

#endif // DATA_LOGGING_H
