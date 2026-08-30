#ifndef KEYPAD_INTERFACE
#define KEYPAD_INTERFACE

#include <stdint.h>
#include "../../Common/BitMath.h"
#include "../../Common/Definition.h"
#include "../../Mcal/DIO/DIO_Interface.h"

#include "KeyPad_Private.h"
#include "KeyPad_Config.h"

void KPD_Init();
uint8_t KPD_GetPressedKey(void);
#endif /* KEYPAD_INTERFACE */
