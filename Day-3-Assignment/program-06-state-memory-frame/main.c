#include <stdio.h>
#include <stdint.h>

/**
 * This program contains the answers to Questions:
 * 14-A, 14-B and 25.
 */

#define DATA_BYTES_COUNT 8U
#define SUM_BYTES_COUNT 2U

#define FRAME_SIZE \
    (DATA_BYTES_COUNT + SUM_BYTES_COUNT)

#define BYTE_MAX_VALUE 255U

/* Question 14-A: Count function calls. */
unsigned int GetFunctionCallCount(void)
{
    static unsigned int callCount = 0U;

    callCount++;

    return callCount;
}

/* Question 14-B: Display the system Endianness. */
void DisplaySystemEndianness(void)
{
    uint16_t testNumber = 0x1234U;

    const unsigned char *firstByteAddress =
        (const unsigned char *)&testNumber;

    printf("Test number = 0x%04X\n",
           (unsigned int)testNumber);

    printf("First byte in memory = 0x%02X\n",
           (unsigned int)firstByteAddress[0]);

    printf("Second byte in memory = 0x%02X\n",
           (unsigned int)firstByteAddress[1]);

    if (firstByteAddress[0] == 0x34U)
    {
        printf("This system uses Little Endian.\n");
    }
    else if (firstByteAddress[0] == 0x12U)
    {
        printf("This system uses Big Endian.\n");
    }
    else
    {
        printf("Unknown byte order.\n");
    }
}

unsigned char ReadDataBytes(uint8_t dataBytes[])
{
    uint8_t index = 0U;
    unsigned int enteredNumber = 0U;

    for (index = 0U;
         index < DATA_BYTES_COUNT;
         index++)
    {
        if ((scanf("%u", &enteredNumber) != 1) ||
            (enteredNumber > BYTE_MAX_VALUE))
        {
            return 0U;
        }

        dataBytes[index] =
            (uint8_t)enteredNumber;
    }

    return 1U;
}

uint16_t CalculateDataSummation(
    const uint8_t dataBytes[])
{
    uint8_t index = 0U;
    uint16_t dataSummation = 0U;

    for (index = 0U;
         index < DATA_BYTES_COUNT;
         index++)
    {
        dataSummation =
            (uint16_t)
            (dataSummation + dataBytes[index]);
    }

    return dataSummation;
}

/*
 * Question 25:
 * Send 8 data bytes, followed by the summation
 * stored in two bytes.
 */
void SendFrame(const uint8_t dataBytes[],
               uint8_t sentFrame[])
{
    uint8_t index = 0U;

    uint16_t dataSummation =
        CalculateDataSummation(dataBytes);

    for (index = 0U;
         index < DATA_BYTES_COUNT;
         index++)
    {
        sentFrame[index] = dataBytes[index];
    }

    /*
     * Store the high byte of the summation
     * at frame index 8.
     */
    sentFrame[DATA_BYTES_COUNT] =
        (uint8_t)(dataSummation >> 8U);

    /*
     * Store the low byte of the summation
     * at frame index 9.
     */
    sentFrame[DATA_BYTES_COUNT + 1U] =
        (uint8_t)(dataSummation & 0x00FFU);
}

/*
 * Question 25:
 * Receive the frame and check its summation.
 */
unsigned char ReceiveAndValidateFrame(
    const uint8_t receivedFrame[])
{
    uint16_t calculatedSummation =
        CalculateDataSummation(receivedFrame);

    uint16_t receivedSummation =
        (uint16_t)
        (((uint16_t)
          receivedFrame[DATA_BYTES_COUNT] << 8U) |
         receivedFrame[DATA_BYTES_COUNT + 1U]);

    if (calculatedSummation ==
        receivedSummation)
    {
        return 1U;
    }

    return 0U;
}

void PrintFrame(const uint8_t frame[])
{
    uint8_t index = 0U;

    printf("Frame bytes: ");

    for (index = 0U;
         index < FRAME_SIZE;
         index++)
    {
        printf("%02X ",
               (unsigned int)frame[index]);
    }

    printf("\n");
}

int main(void)
{
    signed int selectedQuestion = 0;

    do
    {
        printf("\nState, Memory and Frame Problems\n");
        printf("14 - Function call count and Endianness\n");
        printf("25 - Send and validate a data frame\n");
        printf("0  - Exit\n");
        printf("Enter question number: ");

        if (scanf("%d", &selectedQuestion) != 1)
        {
            printf("Invalid input.\n");
            return 1;
        }

        switch (selectedQuestion)
        {
            case 14:
            {
                signed int selectedOperation = 0;

                printf("1 - Count function calls\n");
                printf("2 - Detect system Endianness\n");
                printf("Select operation: ");

                if (scanf("%d",
                          &selectedOperation) != 1)
                {
                    printf("Invalid input.\n");
                    return 1;
                }

                if (selectedOperation == 1)
                {
                    unsigned int numberOfCalls = 0U;
                    unsigned int callNumber = 0U;

                    printf("Enter number of calls: ");

                    if ((scanf("%u",
                               &numberOfCalls) != 1) ||
                        (numberOfCalls == 0U))
                    {
                        printf(
                            "Invalid number of calls.\n");

                        break;
                    }

                    for (callNumber = 1U;
                         callNumber <= numberOfCalls;
                         callNumber++)
                    {
                        printf(
                            "Function call count = %u\n",
                            GetFunctionCallCount());
                    }
                }
                else if (selectedOperation == 2)
                {
                    DisplaySystemEndianness();
                }
                else
                {
                    printf("Invalid operation.\n");
                }

                break;
            }

            case 25:
            {
                uint8_t dataBytes[DATA_BYTES_COUNT] =
                    {0U};

                uint8_t sentFrame[FRAME_SIZE] =
                    {0U};

                unsigned int corruptionChoice = 0U;

                printf(
                    "Enter 8 data bytes from 0 to 255: ");

                if (ReadDataBytes(dataBytes) == 0U)
                {
                    printf("Invalid data byte.\n");
                    break;
                }

                SendFrame(dataBytes, sentFrame);

                printf("Sent frame:\n");
                PrintFrame(sentFrame);

                printf("Data summation = %u\n",
                       (unsigned int)
                       CalculateDataSummation(
                           dataBytes));

                printf(
                    "Change a data byte to test an error?\n");

                printf("0 - No\n");
                printf("1 - Yes\n");
                printf("Select: ");

                if ((scanf("%u",
                           &corruptionChoice) != 1) ||
                    (corruptionChoice > 1U))
                {
                    printf("Invalid choice.\n");
                    break;
                }

                if (corruptionChoice == 1U)
                {
                    unsigned int byteIndex = 0U;
                    unsigned int newByteValue = 0U;

                    printf(
                        "Enter data byte index from 0 to 7: ");

                    if ((scanf("%u",
                               &byteIndex) != 1) ||
                        (byteIndex >=
                         DATA_BYTES_COUNT))
                    {
                        printf("Invalid byte index.\n");
                        break;
                    }

                    printf(
                        "Enter new value from 0 to 255: ");

                    if ((scanf("%u",
                               &newByteValue) != 1) ||
                        (newByteValue >
                         BYTE_MAX_VALUE))
                    {
                        printf("Invalid byte value.\n");
                        break;
                    }

                    sentFrame[byteIndex] =
                        (uint8_t)newByteValue;

                    printf(
                        "Received frame after change:\n");

                    PrintFrame(sentFrame);
                }

                if (ReceiveAndValidateFrame(
                        sentFrame) == 1U)
                {
                    printf(
                        "Frame received correctly.\n");
                }
                else
                {
                    printf(
                        "Frame contains an error.\n");
                }

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