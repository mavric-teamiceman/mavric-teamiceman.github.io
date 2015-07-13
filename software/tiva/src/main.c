/*
 * Iceman - 2015
 */

/* FreeRTOS.org includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#include "inc/hw_types.h"
#include "inc/hw_nvic.h"
#include "inc/hw_memmap.h"
#include "inc/tm4c1294ncpdt.h"
#include "driverlib/rom.h" //For ROM functions
#include "driverlib/sysctl.h" //For peripheral enabling
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/pwm.h"
#include "driverlib/rom_map.h"
#include "utils/uartstdio.h"

#include "motor.h"
#include "sound.h"
#include "sonar.h"
#include "bumper.h"
#include "temperature.h"
#include "smell.h"
#include "inertial.h"
#include "cliff.h"
#include "control.h"
#include "voltage_level.h"

void vFanDriverTask();
int xFanDriverInit();


//0 means Awesome, nonzero means FAIL!!
int xSystemInit()
{
	SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R12 |SYSCTL_RCGCGPIO_R11 | SYSCTL_RCGCGPIO_R10 | SYSCTL_RCGCGPIO_R9 |
			SYSCTL_RCGCGPIO_R5 | SYSCTL_RCGCGPIO_R4 | SYSCTL_RCGCGPIO_R3 | SYSCTL_RCGCGPIO_R2 |
			SYSCTL_RCGCGPIO_R1 | SYSCTL_RCGCGPIO_R0;  //Enable port N and E
	SYSCTL_RCGCPWM_R = SYSCTL_RCGCPWM_R0;

	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC1);

	// Do a dummy read to insert a few cycles after enabling the peripheral.
	int fooVar = SYSCTL_RCGCGPIO_R;
	fooVar = SYSCTL_RCGCGPIO_R;

	ROM_PWMClockSet(PWM0_BASE, PWM_SYSCLK_DIV_8);

	ROM_IntMasterEnable(); //Enable interrupts

	//Initialize driver modules
	xSoundDriverInit();
	xMotorDriverInit();
	xFanDriverInit();
	xSonarInit();
	xVoltageDriverInit();
	xInitializeCliffDriver();
	xInitializeBumperDriver();
	xInitializeInterboard();
	xInitializeInertialDriver();
	xInitializeSmellDriver();
	xInitializeInertialDriver();
	return 0;
}

/*-----------------------------------------------------------*/

int main( void )
{

	xSystemInit();

	/* Task Prototype. */
	//	xTaskCreate(vTaskName,		/* Pointer to the function that implements the task. */
	//			   "Task ID",	/* Text name for the task.  This is to facilitate debugging only. */
	//			   taskStackSize,		/* Stack depth in word. */
	//			   NULL,		/* We are not using the task parameter. */
	//			   taskPriority,			/* This task will run at priority 3. */
	//			   NULL );		/* We are not using the task handle. */

	//Sensor poll tasks
	xTaskCreate(vTempDriverTask, "Temp", 240, NULL, 1, NULL);
	xTaskCreate(vBumperDriverTask, "Bumpers", 240, NULL, 1, NULL);
	xTaskCreate(vSoundDriverTask, "Sound", 240, NULL, 1, NULL);
	xTaskCreate(vInertialDriverTask, "Accelerometer", 240, NULL, 1, NULL);
	xTaskCreate(vSmellDriverTask, "Light Driver", 240, NULL, 1,	 NULL );
	xTaskCreate(vVoltageDriverTask, "Battery Level", 240, NULL, 1, NULL);

	//Executive tasks
	xTaskCreate(vInterboardTask, "Interboard", 240, NULL, 3, NULL);
	xTaskCreate(vControlTask, "Brain Stem?", 240, NULL, 3, NULL);

	//Actuator control tasks
	xTaskCreate(vFanDriverTask, "Fan", 200, NULL, 1, NULL);
	xTaskCreate(vSonarTask,	"Sonar Driver", 450 ,NULL, 2, NULL);
	xTaskCreate(vMotorTask,	"Motor Driver",	280, NULL, 1, NULL );


	/* Start the scheduler so our tasks start executing. */
	vTaskStartScheduler();

	for( ;; ); //Should never be reached
	return 0;
}

/*--------------------------Fan Driver----------------------------------*/

uint8_t fanSpeed;

xSemaphoreHandle fanSem;

int xFanDriverInit()
{
	fanSpeed = 100;
	ROM_GPIOPinTypePWM(GPIO_PORTF_AHB_BASE, GPIO_PIN_1);
	ROM_GPIOPinConfigure(GPIO_PF1_M0PWM1);

	PWM0_0_GENB_R = 0x8C;
	ROM_PWMGenConfigure(PWM0_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_GEN_NO_SYNC);
	ROM_PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, 256);
	ROM_PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, 100);

	ROM_PWMGenEnable(PWM0_BASE, PWM_GEN_0);

	PWM0_0_CTL_R |= 0x5;
	PWM0_ENABLE_R |= 0x2;

	vSemaphoreCreateBinary(fanSem);

	return 0;
}

void vSetFanSpeed(uint8_t speed)
{
	fanSpeed = (speed);
	xSemaphoreGive(fanSem);
}

void vFanDriverTask()
{
	for (;;)
	{
		xSemaphoreTake(fanSem, portMAX_DELAY);
		ROM_PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, fanSpeed);
	}
}

/*-----------------------------------------------------------*/


void vApplicationMallocFailedHook( void )
{
	GPIO_PORTN_DATA_R ^= 0x01;
	/* This function will only be called if an API call to create a task, queue
	or semaphore fails because there is too little heap RAM remaining. */
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( xTaskHandle *pxTask, signed char *pcTaskName )
{
	GPIO_PORTN_DATA_R ^= 0x01;
	/* This function will only be called if a task overflows its stack.  Note
	that stack overflow checking does slow down the context switch
	implementation. */
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{
	GPIO_PORTN_DATA_R ^= 0x01;
	/* This example does not use the idle hook to perform any processing. */
}
/*-----------------------------------------------------------*/

void vApplicationTickHook( void )
{
	/* This example does not use the tick hook to perform any processing. */
}


/*-------------------Where Code Goes to Die---------------------*/
//
//int xConfigureLightDriver()
//{
//	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R11 | SYSCTL_RCGCGPIO_R0;
//	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER3);
//	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER4);
//
//	//Enable CCP pins
//	ROM_GPIOPinConfigure(GPIO_PA6_T3CCP0);
//	ROM_GPIOPinConfigure(GPIO_PM5_T4CCP1);
//	ROM_GPIOPinTypeTimer(GPIO_PORTA_BASE, GPIO_PIN_6);
//	ROM_GPIOPinTypeTimer(GPIO_PORTM_BASE, GPIO_PIN_5);
//
//	TIMER3_CFG_R = 0x04;	//Set as two 16-bit counters
//	TIMER4_CFG_R = 0x04;
//
//	TIMER3_TAMR_R = 0x07;	//Set subTimer A for Edge Time mode
//	TIMER4_TBMR_R = 0x07;	//Set subTimer B for Edge Time mode
//
//	TIMER3_TAPR_R = 0xFF; //Set prescalers
//	TIMER4_TBPR_R = 0xFF;
//
//	TIMER3_TAV_R = 0x0;
//	TIMER4_TBV_R = 0x0;
//
//	TIMER4_CTL_R |= (0x1 << 10); //Configure subTimer B to set on falling edge
//
//	TIMER3_CTL_R |= (1); //Enable timers a & b
//	TIMER4_CTL_R |= (1 << 8);
//
//	return 0;
//}
//
//int getLightIntensity()
//{
//	taskENTER_CRITICAL(); //Start Critical Section
//	int a = TIMER3_TAR_R, b = TIMER4_TBR_R;
//	taskEXIT_CRITICAL(); //Start Critical Section
//	int deltaCycles = abs(a - b);
//	//If the difference is too great, assume that the counter reset between measurements
//	if (deltaCycles > 0x7FFFFF) deltaCycles = 0xFFFFFF - deltaCycles;
//	int freq = 120000000 / deltaCycles;
//	return freq;
//}
//
//void vLightTask()
//{
//	for (;;)
//	{
//		//xSemaphoreTake(pollLightSem, portMAX_DELAY);
//		//	UARTprintf("\nLight: %d\t%d\n", getLightIntensity(),(int)(35.45*log(getLightIntensity()) - 243));
//		int val = ((int)(35.45*log(getLightIntensity()) - 243));
//		val = (val < 0 ? 0 : val);
//		val = (val > 255 ? 255 : val);
//		UARTprintf("Light: %03d\n", val);
//		vTaskDelay(250);
//		//outputBuffer.light = val;
//	}
//}


//void ConfigureUART(void)
//{
//	//
//	// Enable the GPIO Peripheral used by the UART.
//	//
//	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
//	ROM_SysCtlPeripheralSleepEnable(SYSCTL_PERIPH_GPIOA);
//
//	//
//	// Enable UART0.
//	//
//	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
//	ROM_SysCtlPeripheralSleepEnable(SYSCTL_PERIPH_UART0);
//
//	//
//	// Configure GPIO Pins for UART mode.
//	//
//	ROM_GPIOPinConfigure(GPIO_PA0_U0RX);
//	ROM_GPIOPinConfigure(GPIO_PA1_U0TX);
//	ROM_GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
//
//	//
//	// Initialize the UART for console I/O.
//	//
//	UARTStdioConfig(0, 9600, MAP_SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
//			SYSCTL_OSC_MAIN | SYSCTL_USE_PLL |
//			SYSCTL_CFG_VCO_480), 120000000));
//}
//
//void vMoveMotorTask()
//{
//	int k;
//	for (;;)
//	{
//		vSetMotorSpeed(0x4F, 0, 0x4F, 0);
//		vTaskDelay(100);
//		for (k = 0; k < 8; k++)
//		{
//			if (outputBuffer.dists[k] < 255)
//			{
//				vSetMotorSpeed(0x4F, 1, 0x4F, 0);
//				vTaskDelay(1000);
//				break;
//			}
//		}
//	}
//}


