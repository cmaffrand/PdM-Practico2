/*=============================================================================
 * Authors: Carlos Maffrand 	<carlosmaffrand5@gmail.com>
 *			Hernan Gomez Molino	<hernangomezmolino@gmail.com>
 * Date: 2021/07/07
 *===========================================================================*/

#include "sapi.h"
#include "teclas.h"

bool_t leerTecla (gpioMap_t tecla)
{
	bool_t ret_val;

   if ((tecla == TEC1) || (tecla == TEC2) || (tecla == TEC3) || (tecla == TEC4)) {
	   ret_val = gpioRead( tecla );
   }
   else {
   // No se puede leer ninguna tecla.
   ret_val     = 1;
   printf("\n Error: Se intentó presionar una tecla no permitida");
   }

	return ret_val;
}
