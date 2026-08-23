#include <stdio.h>

/**
 * This program contains the answers to Questions:
 * 9, 11, 12, 15, 16, 18, 27-A and 27-B.
 */

#define ARRAY_SIZE 5U
#define CHAR_ARRAY_SIZE 10U
#define LARGE_ARRAY_SIZE 101U
#define UNIQUE_NUMBERS_COUNT 100U
#define MOVE_ARRAY_SIZE 9U

unsigned char ReadSignedArray(signed int array[],
                              const unsigned char arraySize)
{
    unsigned char index = 0U;

    for (index = 0U; index < arraySize; index++)
    {
        if (scanf("%d", &array[index]) != 1)
        {
            return 0U;
        }
    }

    return 1U;
}

unsigned char ReadUnsignedCharArray(unsigned char array[],
                                    const unsigned char arraySize)
{
    unsigned char index = 0U;
    unsigned int enteredNumber = 0U;

    for (index = 0U; index < arraySize; index++)
    {
        if ((scanf("%u", &enteredNumber) != 1) ||
            (enteredNumber > 255U))
        {
            return 0U;
        }

        array[index] = (unsigned char)enteredNumber;
    }

    return 1U;
}

void PrintSignedArray(const signed int array[],
                      const unsigned char arraySize)
{
    unsigned char index = 0U;

    for (index = 0U; index < arraySize; index++)
    {
        printf("%d ", array[index]);
    }

    printf("\n");
}

void PrintUnsignedCharArray(const unsigned char array[],
                            const unsigned char arraySize)
{
    unsigned char index = 0U;

    for (index = 0U; index < arraySize; index++)
    {
        printf("%u ", (unsigned int)array[index]);
    }

    printf("\n");
}

/* Question 9: Copy unique char numbers using one loop O(n). */
unsigned char CopyUniqueCharNumbers(const unsigned char sourceArray[],
                                    unsigned char destinationArray[],
                                    const unsigned char arraySize)
{
    unsigned char numberFound[256] = {0U};
    unsigned char sourceIndex = 0U;
    unsigned char destinationSize = 0U;

    for (sourceIndex = 0U; sourceIndex < arraySize; sourceIndex++)
    {
        if (numberFound[sourceArray[sourceIndex]] == 0U)
        {
            destinationArray[destinationSize] = sourceArray[sourceIndex];
            destinationSize++;
            numberFound[sourceArray[sourceIndex]] = 1U;
        }
    }

    return destinationSize;
}

/* Question 11: Get the most repeated element in an array. */
signed int GetMostRepeatedElement(const signed int array[],
                                  const unsigned char arraySize)
{
    unsigned char currentIndex = 0U;
    unsigned char compareIndex = 0U;
    unsigned char currentCount = 0U;
    unsigned char maximumCount = 0U;
    signed int mostRepeatedElement = array[0];

    for (currentIndex = 0U; currentIndex < arraySize; currentIndex++)
    {
        currentCount = 0U;

        for (compareIndex = 0U; compareIndex < arraySize; compareIndex++)
        {
            if (array[currentIndex] == array[compareIndex])
            {
                currentCount++;
            }
        }

        if (currentCount > maximumCount)
        {
            maximumCount = currentCount;
            mostRepeatedElement = array[currentIndex];
        }
    }

    return mostRepeatedElement;
}

/* Question 12: Return the average of an array. */
double GetArrayAverage(const signed int array[],
                       const unsigned char arraySize)
{
    unsigned char index = 0U;
    signed long long int summation = 0;

    for (index = 0U; index < arraySize; index++)
    {
        summation += array[index];
    }

    return (double)summation / arraySize;
}

/* Question 15: Find the repeated number in an unsorted array of size 101. */
signed int FindRepeatedNumber(const signed int array[],
                              const unsigned char arraySize)
{
    unsigned char index = 0U;
    signed long int actualSummation = 0;
    signed long int expectedSummation = 0;

    for (index = 0U; index < arraySize; index++)
    {
        actualSummation += array[index];
    }

    expectedSummation =
        ((signed long int)UNIQUE_NUMBERS_COUNT *
         (UNIQUE_NUMBERS_COUNT + 1U)) / 2L;

    return (signed int)(actualSummation - expectedSummation);
}

/* Question 16: Remove duplicated numbers from an array. */
unsigned char RemoveDuplicatedNumbers(signed int array[],
                                      unsigned char arraySize)
{
    unsigned char currentIndex = 0U;
    unsigned char compareIndex = 0U;
    unsigned char shiftIndex = 0U;

    for (currentIndex = 0U; currentIndex < arraySize; currentIndex++)
    {
        compareIndex = (unsigned char)(currentIndex + 1U);

        while (compareIndex < arraySize)
        {
            if (array[currentIndex] == array[compareIndex])
            {
                for (shiftIndex = compareIndex;
                     shiftIndex < (arraySize - 1U);
                     shiftIndex++)
                {
                    array[shiftIndex] = array[shiftIndex + 1U];
                }

                arraySize--;
            }
            else
            {
                compareIndex++;
            }
        }
    }

    return arraySize;
}

/* Question 18: Get maximum and minimum values and their indexes. */
void GetMaxMinAndIndexes(const signed int array[],
                         const unsigned char arraySize,
                         signed int *maximumNumber,
                         unsigned char *maximumIndex,
                         signed int *minimumNumber,
                         unsigned char *minimumIndex)
{
    unsigned char index = 0U;

    *maximumNumber = array[0];
    *minimumNumber = array[0];
    *maximumIndex = 0U;
    *minimumIndex = 0U;

    for (index = 1U; index < arraySize; index++)
    {
        if (array[index] > *maximumNumber)
        {
            *maximumNumber = array[index];
            *maximumIndex = index;
        }

        if (array[index] < *minimumNumber)
        {
            *minimumNumber = array[index];
            *minimumIndex = index;
        }
    }
}

/* Question 27-A: Compare two arrays containing the same elements. */
unsigned char CompareArrayElements(const signed int firstArray[],
                                   const signed int secondArray[],
                                   const unsigned char arraySize)
{
    unsigned char matchedElements[ARRAY_SIZE] = {0U};
    unsigned char firstIndex = 0U;
    unsigned char secondIndex = 0U;
    unsigned char elementFound = 0U;

    for (firstIndex = 0U; firstIndex < arraySize; firstIndex++)
    {
        elementFound = 0U;

        for (secondIndex = 0U; secondIndex < arraySize; secondIndex++)
        {
            if ((matchedElements[secondIndex] == 0U) &&
                (firstArray[firstIndex] == secondArray[secondIndex]))
            {
                matchedElements[secondIndex] = 1U;
                elementFound = 1U;
                break;
            }
        }

        if (elementFound == 0U)
        {
            return 0U;
        }
    }

    return 1U;
}

/* Question 27-B: Move a specified number to the end of an array. */
void MoveNumberToArrayEnd(signed int array[],
                          const unsigned char arraySize,
                          const signed int number)
{
    unsigned char readIndex = 0U;
    unsigned char writeIndex = 0U;
    unsigned char repeatedCount = 0U;

    for (readIndex = 0U; readIndex < arraySize; readIndex++)
    {
        if (array[readIndex] == number)
        {
            repeatedCount++;
        }
        else
        {
            array[writeIndex] = array[readIndex];
            writeIndex++;
        }
    }

    while (repeatedCount > 0U)
    {
        array[writeIndex] = number;
        writeIndex++;
        repeatedCount--;
    }
}

int main(void)
{
    signed int selectedQuestion = 0;

    do
    {
        printf("\nArray Operations Problems\n");
        printf("9  - Copy unique char numbers using O(n)\n");
        printf("11 - Get most repeated element\n");
        printf("12 - Get array average\n");
        printf("15 - Find repeated number in array of size 101\n");
        printf("16 - Remove duplicated numbers\n");
        printf("18 - Get maximum and minimum with indexes\n");
        printf("27 - Two array operations\n");
        printf("0  - Exit\n");
        printf("Enter question number: ");

        if (scanf("%d", &selectedQuestion) != 1)
        {
            printf("Invalid input.\n");
            return 1;
        }

        switch (selectedQuestion)
        {
            case 9:
            {
                unsigned char sourceArray[CHAR_ARRAY_SIZE] = {0U};
                unsigned char destinationArray[CHAR_ARRAY_SIZE] = {0U};
                unsigned char destinationSize = 0U;

                printf("Enter 10 numbers from 0 to 255: ");

                if (ReadUnsignedCharArray(sourceArray,
                                          CHAR_ARRAY_SIZE) == 0U)
                {
                    printf("Invalid input.\n");
                    return 1;
                }

                destinationSize =
                    CopyUniqueCharNumbers(sourceArray,
                                         destinationArray,
                                         CHAR_ARRAY_SIZE);

                printf("Array without repeated numbers: ");
                PrintUnsignedCharArray(destinationArray, destinationSize);

                break;
            }

            case 11:
            {
                signed int array[ARRAY_SIZE] = {0};

                printf("Enter array elements: ");

                if (ReadSignedArray(array, ARRAY_SIZE) == 0U)
                {
                    printf("Invalid input.\n");
                    return 1;
                }

                printf("Most repeated element = %d\n",
                       GetMostRepeatedElement(array, ARRAY_SIZE));

                break;
            }

            case 12:
            {
                signed int array[ARRAY_SIZE] = {0};

                printf("Enter array elements: ");

                if (ReadSignedArray(array, ARRAY_SIZE) == 0U)
                {
                    printf("Invalid input.\n");
                    return 1;
                }

                printf("Average = %.2f\n",
                       GetArrayAverage(array, ARRAY_SIZE));

                break;
            }

            case 15:
            {
                signed int array[LARGE_ARRAY_SIZE] = {0};
                unsigned char index = 0U;

                for (index = 0U;
                     index < UNIQUE_NUMBERS_COUNT;
                     index++)
                {
                    array[index] =
                        (signed int)
                        (((unsigned int)index * 37U) % 100U) + 1;
                }

                array[100] = 37;

                printf("Repeated number = %d\n",
                       FindRepeatedNumber(array, LARGE_ARRAY_SIZE));

                break;
            }

            case 16:
            {
                signed int array[ARRAY_SIZE] = {0};
                unsigned char newArraySize = 0U;

                printf("Enter array elements: ");

                if (ReadSignedArray(array, ARRAY_SIZE) == 0U)
                {
                    printf("Invalid input.\n");
                    return 1;
                }

                newArraySize =
                    RemoveDuplicatedNumbers(array, ARRAY_SIZE);

                printf("Array without duplicated numbers: ");
                PrintSignedArray(array, newArraySize);

                break;
            }

            case 18:
            {
                signed int array[ARRAY_SIZE] = {0};
                signed int maximumNumber = 0;
                signed int minimumNumber = 0;
                unsigned char maximumIndex = 0U;
                unsigned char minimumIndex = 0U;

                printf("Enter array elements: ");

                if (ReadSignedArray(array, ARRAY_SIZE) == 0U)
                {
                    printf("Invalid input.\n");
                    return 1;
                }

                GetMaxMinAndIndexes(array,
                                    ARRAY_SIZE,
                                    &maximumNumber,
                                    &maximumIndex,
                                    &minimumNumber,
                                    &minimumIndex);

                printf("Maximum = %d at index %u\n",
                       maximumNumber,
                       (unsigned int)maximumIndex);

                printf("Minimum = %d at index %u\n",
                       minimumNumber,
                       (unsigned int)minimumIndex);

                break;
            }

            case 27:
            {
                signed int selectedOperation = 0;

                printf("1 - Compare two arrays\n");
                printf("2 - Move a number to the array end\n");
                printf("Select operation: ");

                if (scanf("%d", &selectedOperation) != 1)
                {
                    printf("Invalid input.\n");
                    return 1;
                }

                if (selectedOperation == 1)
                {
                    signed int firstArray[ARRAY_SIZE] = {0};
                    signed int secondArray[ARRAY_SIZE] = {0};

                    printf("Enter first array elements: ");

                    if (ReadSignedArray(firstArray, ARRAY_SIZE) == 0U)
                    {
                        printf("Invalid input.\n");
                        return 1;
                    }

                    printf("Enter second array elements: ");

                    if (ReadSignedArray(secondArray, ARRAY_SIZE) == 0U)
                    {
                        printf("Invalid input.\n");
                        return 1;
                    }

                    if (CompareArrayElements(firstArray,
                                             secondArray,
                                             ARRAY_SIZE) == 1U)
                    {
                        printf("Arrays contain the same elements.\n");
                    }
                    else
                    {
                        printf("Arrays contain different elements.\n");
                    }
                }
                else if (selectedOperation == 2)
                {
                    signed int array[MOVE_ARRAY_SIZE] =
                        {1, 2, 5, 7, 1, 1, 3, 1, 7};

                    signed int number = 0;

                    printf("Original array: ");
                    PrintSignedArray(array, MOVE_ARRAY_SIZE);

                    printf("Enter number to move: ");

                    if (scanf("%d", &number) != 1)
                    {
                        printf("Invalid input.\n");
                        return 1;
                    }

                    MoveNumberToArrayEnd(array,
                                         MOVE_ARRAY_SIZE,
                                         number);

                    printf("Array after moving number: ");
                    PrintSignedArray(array, MOVE_ARRAY_SIZE);
                }
                else
                {
                    printf("Invalid operation.\n");
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