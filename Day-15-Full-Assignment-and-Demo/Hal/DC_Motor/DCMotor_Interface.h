#ifndef DC_MOTOR_INTERFACE
#define DC_MOTOR_INTERFACE

#include <stdint.h>

#include "../../Common/Definition.h"
#include "../../Mcal/DIO/DIO_Interface.h"

#include "DCMotor_Private.h"
#include "DCMotor_Config.h"

void DCMotor_Init(void);

void DCMotor_RotateClockwise(void);

void DCMotor_RotateCounterClockwise(void);

void DCMotor_Stop(void);

#endif /* DC_MOTOR_INTERFACE */