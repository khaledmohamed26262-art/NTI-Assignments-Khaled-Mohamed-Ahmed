#ifndef COMMON_BITMATH_H
#define COMMON_BITMATH_H

#include <stdint.h>

#define SetBit(Reg, BitNo) \
    ((Reg) |= (uint8_t)(1U << (BitNo)))

#define ClearBit(Reg, BitNo) \
    ((Reg) &= (uint8_t)(~(uint8_t)(1U << (BitNo))))

#define ToggleBit(Reg, BitNo) \
    ((Reg) ^= (uint8_t)(1U << (BitNo)))

#define ReadBit(Reg, BitNo) \
    (((Reg) >> (BitNo)) & 0x01U)

#endif