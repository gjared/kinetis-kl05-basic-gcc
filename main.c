/* ###################################################################
**     Filename    : main.c
**     Project     : kl05-blink-test
**     Processor   : MKL05Z32VLF4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-09-10, 08:41, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "SIM_PDD.h"
#include "PORT_PDD.h"
#include "GPIO_PDD.h"

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
  int i = 0;
  int j = 20;

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.  

  /* Init other stuff */
  SIM_PDD_SetClockGate(SIM_BASE_PTR, SIM_PDD_CLOCK_GATE_PORTA, PDD_ENABLE);

  /* Configure GPIO */
  PORT_PDD_SetPinMuxControl(PORTA_BASE_PTR, 10, PORT_PDD_MUX_CONTROL_ALT1);
  PORT_PDD_SetPinMuxControl(PORTA_BASE_PTR, 11, PORT_PDD_MUX_CONTROL_ALT1);

  /* Set it to on for now */
  GPIO_PDD_SetPortDataOutputMask(FPTA_BASE_PTR, GPIO_PDD_PIN_10);
  GPIO_PDD_ClearPortDataOutputMask(FPTA_BASE_PTR, GPIO_PDD_PIN_11);

  /* Set direction */
  GPIO_PDD_SetPortOutputDirectionMask(FPTA_BASE_PTR, GPIO_PDD_PIN_10 | GPIO_PDD_PIN_11 );

  /* Write your code here */
  for(;;) {

    /* Just some example code to play with debugging */
    i += 1;
    j += 1;

    /* Toggle the pins here */
    GPIO_PDD_TogglePortDataOutputMask(FPTA_BASE_PTR, GPIO_PDD_PIN_10 | GPIO_PDD_PIN_11);

  }

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.4 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
