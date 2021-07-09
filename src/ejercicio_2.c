/*=============================================================================
 * Authors: Carlos Maffrand 	<carlosmaffrand5@gmail.com>
 *			Hernan Gomez Molino	<hernangomezmolino@gmail.com>
 * Date: 2021/07/07
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "sapi.h"
#include "teclas.h"
#include "led.h"
#include "secuencia.h"
#include "ejercicio_2.h"


/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

gpioMap_t secuencia[] = {LEDB, LED1, LED2, LED3};
const uint8_t ultimoLed = sizeof(secuencia)/sizeof(gpioMap_t);
tick_t tiempos[]={500, 500, 500, 3000};
delay_t NonBlockingDelay;

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main( void )
{
	 // Inicializar y configurar la plataforma
	   boardConfig();

	   // Inicializar las variables y estructuras del retardo no bloqueante.
	   delayInit( &NonBlockingDelay, tiempos[0]);

	   // Crear varias variables
	   gpioMap_t * psecuencia = secuencia;
	   bool_t dirValueFlag    = FALSE;
	   tick_t * ptiempos = tiempos;

   // Mensaje de inició del programa
   printf("Secuencia Comenzada\n");
   // ----- Repeat for ever -------------------------
   while( true ) {

	   // Chequeo del delay no bloquenate.
	   if (delayRead(&NonBlockingDelay) == TRUE) {
			activarSecuencia(psecuencia, dirValueFlag, ptiempos);
		}
	   // Si no se cumple el delay pooling de botones.
		 else {
			if (leerTecla( TEC1 ) == OFF) dirValueFlag = TRUE;
			if (leerTecla( TEC4 ) == OFF) dirValueFlag = FALSE;
		 }
   }
   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   return 0;
}






