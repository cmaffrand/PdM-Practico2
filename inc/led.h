/*=============================================================================
 * Authors: Carlos Maffrand 	<carlosmaffrand5@gmail.com>
 *			Hernan Gomez Molino	<hernangomezmolino@gmail.com>
 * Date: 2021/07/09
 *===========================================================================*/

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef __LED_H__
#define __LED_H__

/*=====[Inclusions of public function dependencies]==========================*/

#include <stdint.h>
#include <stddef.h>

/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/

/*=====[Prototypes (declarations) of public functions]=======================*/

bool_t encenderLed( gpioMap_t led );
bool_t apagarLeds(void);

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __LED_H__ */
