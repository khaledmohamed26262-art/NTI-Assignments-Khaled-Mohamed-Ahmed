#ifndef MCAL_DIO_INTERFACE_H
#define MCAL_DIO_INTERFACE_H

#include <stdint.h>

#define GroupA 0U
#define GroupB 1U
#define GroupC 2U
#define GroupD 3U

#define Input  0U
#define Output 1U

#define Low  0U
#define High 1U

void DIO_DirectionSelectorPin(
    const uint8_t GroupName,
    const uint8_t PinNo,
    const uint8_t DirectionState);

void DIO_DirectionSelectorGroup(
    const uint8_t GroupName,
    const uint8_t DirectionState);

void DIO_WritePin(
    const uint8_t GroupName,
    const uint8_t PinNo,
    const uint8_t OutputValue);

void DIO_WriteGroup(
    const uint8_t GroupName,
    const uint8_t OutputValue);

void DIO_ReadPin(
    const uint8_t GroupName,
    const uint8_t PinNo,
    uint8_t *InputState);

void DIO_TogglePin(
    const uint8_t GroupName,
    const uint8_t PinNo);

#endif