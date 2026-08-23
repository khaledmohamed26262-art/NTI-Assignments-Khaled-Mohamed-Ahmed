#include <stdio.h>
#include <stdint.h>

/**
 * This program contains the answers to Questions:
 * 6, 24, 30, 31 and 33.
 */

#define BYTE_BITS_COUNT 8U
#define BYTE_MAX_VALUE 255U

#define INTEGER_BITS_COUNT \
    ((unsigned int)(sizeof(unsigned int) * 8U))

unsigned char ReadByte(uint8_t *number)
{
    unsigned int enteredNumber = 0U;

    if ((scanf("%u", &enteredNumber) != 1) ||
        (enteredNumber > BYTE_MAX_VALUE))
    {
        return 0U;
    }

    *number = (uint8_t)enteredNumber;

    return 1U;
}

unsigned char ReadByteBitNumber(uint8_t *bitNumber)
{
    unsigned int enteredBitNumber = 0U;

    if ((scanf("%u", &enteredBitNumber) != 1) ||
        (enteredBitNumber >= BYTE_BITS_COUNT))
    {
        return 0U;
    }

    *bitNumber = (uint8_t)enteredBitNumber;

    return 1U;
}

unsigned char ReadIntegerBitNumber(
    unsigned int *bitNumber)
{
    unsigned int enteredBitNumber = 0U;

    if ((scanf("%u", &enteredBitNumber) != 1) ||
        (enteredBitNumber >= INTEGER_BITS_COUNT))
    {
        return 0U;
    }

    *bitNumber = enteredBitNumber;

    return 1U;
}

void PrintByteInBinary(const uint8_t number)
{
    signed int bitNumber = 0;

    for (bitNumber = 7;
         bitNumber >= 0;
         bitNumber--)
    {
        printf("%u",
               (unsigned int)
               ((number >>
                 (unsigned int)bitNumber) & 1U));
    }
}

void PrintByteResult(const char message[],
                     const uint8_t number)
{
    printf("%s%u (",
           message,
           (unsigned int)number);

    PrintByteInBinary(number);

    printf(")\n");
}

void PrintUnsignedIntegerInBinary(
    const unsigned int number)
{
    signed int bitNumber = 0;

    for (bitNumber =
             (signed int)INTEGER_BITS_COUNT - 1;
         bitNumber >= 0;
         bitNumber--)
    {
        printf("%u",
               (number >>
                (unsigned int)bitNumber) & 1U);
    }
}

void PrintUnsignedIntegerResult(
    const char message[],
    const unsigned int number)
{
    printf("%s%u (", message, number);

    PrintUnsignedIntegerInBinary(number);

    printf(")\n");
}

/* Question 6: Toggle a specific bit in an 8-bit variable. */
uint8_t ToggleSpecificBit(
    const uint8_t number,
    const uint8_t bitNumber)
{
    return (uint8_t)
           (number ^
            (uint8_t)(1U << bitNumber));
}

/* Question 24: Reverse the bits of an 8-bit number. */
uint8_t ReverseByteBits(uint8_t number)
{
    uint8_t reversedNumber = 0U;
    uint8_t bitCounter = 0U;

    for (bitCounter = 0U;
         bitCounter < BYTE_BITS_COUNT;
         bitCounter++)
    {
        reversedNumber =
            (uint8_t)(reversedNumber << 1U);

        reversedNumber =
            (uint8_t)
            (reversedNumber | (number & 1U));

        number = (uint8_t)(number >> 1U);
    }

    return reversedNumber;
}

/*
 * Question 30:
 * Swap the two 4-bit nibbles of an 8-bit number.
 */
uint8_t SwapByteNibbles(const uint8_t number)
{
    return (uint8_t)
           ((number << 4U) |
            (number >> 4U));
}

/* Question 31: Circular shift to the left. */
uint8_t CircularShiftLeft(
    const uint8_t number,
    uint8_t shiftCount)
{
    shiftCount =
        (uint8_t)
        (shiftCount % BYTE_BITS_COUNT);

    if (shiftCount == 0U)
    {
        return number;
    }

    return (uint8_t)
           ((number << shiftCount) |
            (number >>
             (BYTE_BITS_COUNT - shiftCount)));
}

/* Question 31: Circular shift to the right. */
uint8_t CircularShiftRight(
    const uint8_t number,
    uint8_t shiftCount)
{
    shiftCount =
        (uint8_t)
        (shiftCount % BYTE_BITS_COUNT);

    if (shiftCount == 0U)
    {
        return number;
    }

    return (uint8_t)
           ((number >> shiftCount) |
            (number <<
             (BYTE_BITS_COUNT - shiftCount)));
}

/* Question 33: Set a specific bit in an integer. */
unsigned int SetSpecificBit(
    const unsigned int number,
    const unsigned int bitNumber)
{
    return number | (1U << bitNumber);
}

/* Question 33: Clear a specific bit in an integer. */
unsigned int ClearSpecificBit(
    const unsigned int number,
    const unsigned int bitNumber)
{
    return number & ~(1U << bitNumber);
}

int main(void)
{
    signed int selectedQuestion = 0;

    do
    {
        printf("\nBitwise Operations Problems\n");
        printf("6  - Toggle a specific bit\n");
        printf("24 - Reverse bits of an 8-bit number\n");
        printf("30 - Swap the two 4-bit nibbles\n");
        printf("31 - Circular shift\n");
        printf("33 - Set or clear a specific bit\n");
        printf("0  - Exit\n");
        printf("Enter question number: ");

        if (scanf("%d", &selectedQuestion) != 1)
        {
            printf("Invalid input.\n");
            return 1;
        }

        switch (selectedQuestion)
        {
            case 6:
            {
                uint8_t number = 0U;
                uint8_t bitNumber = 0U;
                uint8_t result = 0U;

                printf(
                    "Enter an 8-bit number from 0 to 255: ");

                if (ReadByte(&number) == 0U)
                {
                    printf("Invalid number.\n");
                    break;
                }

                printf(
                    "Enter bit number from 0 to 7: ");

                if (ReadByteBitNumber(&bitNumber) == 0U)
                {
                    printf("Invalid bit number.\n");
                    break;
                }

                result =
                    ToggleSpecificBit(number,
                                      bitNumber);

                PrintByteResult("Original number = ",
                                number);

                PrintByteResult(
                    "Number after toggle = ",
                    result);

                break;
            }

            case 24:
            {
                uint8_t number = 0U;
                uint8_t reversedNumber = 0U;

                printf(
                    "Enter an 8-bit number from 0 to 255: ");

                if (ReadByte(&number) == 0U)
                {
                    printf("Invalid number.\n");
                    break;
                }

                reversedNumber =
                    ReverseByteBits(number);

                PrintByteResult("Original number = ",
                                number);

                PrintByteResult("Reversed number = ",
                                reversedNumber);

                break;
            }

            case 30:
            {
                uint8_t number = 0U;
                uint8_t swappedNumber = 0U;

                printf(
                    "Enter an 8-bit number from 0 to 255: ");

                if (ReadByte(&number) == 0U)
                {
                    printf("Invalid number.\n");
                    break;
                }

                swappedNumber =
                    SwapByteNibbles(number);

                PrintByteResult("Original number = ",
                                number);

                PrintByteResult(
                    "Number after nibble swap = ",
                    swappedNumber);

                break;
            }

            case 31:
            {
                uint8_t number = 0U;
                uint8_t result = 0U;

                unsigned int enteredShiftCount = 0U;
                signed int shiftDirection = 0;

                printf(
                    "Enter an 8-bit number from 0 to 255: ");

                if (ReadByte(&number) == 0U)
                {
                    printf("Invalid number.\n");
                    break;
                }

                printf("1 - Circular shift left\n");
                printf("2 - Circular shift right\n");
                printf("Select direction: ");

                if (scanf("%d", &shiftDirection) != 1)
                {
                    printf("Invalid input.\n");
                    return 1;
                }

                printf("Enter shift count: ");

                if (scanf("%u",
                          &enteredShiftCount) != 1)
                {
                    printf("Invalid input.\n");
                    return 1;
                }

                if (shiftDirection == 1)
                {
                    result =
                        CircularShiftLeft(
                            number,
                            (uint8_t)
                            (enteredShiftCount %
                             BYTE_BITS_COUNT));
                }
                else if (shiftDirection == 2)
                {
                    result =
                        CircularShiftRight(
                            number,
                            (uint8_t)
                            (enteredShiftCount %
                             BYTE_BITS_COUNT));
                }
                else
                {
                    printf(
                        "Invalid shift direction.\n");

                    break;
                }

                PrintByteResult("Original number = ",
                                number);

                PrintByteResult(
                    "Number after circular shift = ",
                    result);

                break;
            }

            case 33:
            {
                unsigned int number = 0U;
                unsigned int bitNumber = 0U;
                unsigned int result = 0U;

                signed int selectedOperation = 0;

                printf("Enter an unsigned integer: ");

                if (scanf("%u", &number) != 1)
                {
                    printf("Invalid number.\n");
                    break;
                }

                printf(
                    "Enter bit number from 0 to %u: ",
                    INTEGER_BITS_COUNT - 1U);

                if (ReadIntegerBitNumber(
                        &bitNumber) == 0U)
                {
                    printf("Invalid bit number.\n");
                    break;
                }

                printf("1 - Set bit\n");
                printf("2 - Clear bit\n");
                printf("Select operation: ");

                if (scanf("%d",
                          &selectedOperation) != 1)
                {
                    printf("Invalid input.\n");
                    return 1;
                }

                if (selectedOperation == 1)
                {
                    result =
                        SetSpecificBit(number,
                                       bitNumber);
                }
                else if (selectedOperation == 2)
                {
                    result =
                        ClearSpecificBit(number,
                                         bitNumber);
                }
                else
                {
                    printf("Invalid operation.\n");
                    break;
                }

                PrintUnsignedIntegerResult(
                    "Original number = ",
                    number);

                PrintUnsignedIntegerResult(
                    "Result = ",
                    result);

                break;
            }

            case 0:
            {
                printf("Program ended.\n");
                break;
            }

            default:
            {
                printf("Invalid question number.\n");
                break;
            }
        }
    }
    while (selectedQuestion != 0);

    return 0;
}