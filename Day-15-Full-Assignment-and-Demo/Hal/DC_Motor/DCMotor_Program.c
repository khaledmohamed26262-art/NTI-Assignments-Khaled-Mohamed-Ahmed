#include "DCMotor_Interface.h"

void DCMotor_Init(void)
{
    DIO_DirectionSelectforPin(DC_MOTOR_IN1_GROUP,
                              DC_MOTOR_IN1_PIN,
                              DIO_Outputfor1Pin);

    DIO_DirectionSelectforPin(DC_MOTOR_IN2_GROUP,
                              DC_MOTOR_IN2_PIN,
                              DIO_Outputfor1Pin);

    DCMotor_Stop();
}

void DCMotor_RotateClockwise(void)
{
    DIO_WritePin(DC_MOTOR_IN1_GROUP,
                 DC_MOTOR_IN1_PIN,
                 DIO_Highfor1Pin);

    DIO_WritePin(DC_MOTOR_IN2_GROUP,
                 DC_MOTOR_IN2_PIN,
                 DIO_Lowfor1Pin);
}

void DCMotor_RotateCounterClockwise(void)
{
    DIO_WritePin(DC_MOTOR_IN1_GROUP,
                 DC_MOTOR_IN1_PIN,
                 DIO_Lowfor1Pin);

    DIO_WritePin(DC_MOTOR_IN2_GROUP,
                 DC_MOTOR_IN2_PIN,
                 DIO_Highfor1Pin);
}

void DCMotor_Stop(void)
{
    DIO_WritePin(DC_MOTOR_IN1_GROUP,
                 DC_MOTOR_IN1_PIN,
                 DIO_Lowfor1Pin);

    DIO_WritePin(DC_MOTOR_IN2_GROUP,
                 DC_MOTOR_IN2_PIN,
                 DIO_Lowfor1Pin);
}