#include <stdio.h>

/**
 * This program contains the answers to Questions:
 * 1, 2, 3, 8, 34, 35 and 36.
 */

#define ARRAY_SIZE 5U
#define RESULT_SIZE 2U

typedef struct
{
    signed long long int summation;
    signed long long int multiplication;
} OperationResults;

unsigned char ReadArray(signed int array[], const unsigned char arraySize)
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

/**
 * Question 1: C function to swap two pointers.
 *
 */
void SwapPointers(signed int **firstPointer, signed int **secondPointer)
{
    signed int *temporaryPointer = *firstPointer;

    *firstPointer = *secondPointer;
    *secondPointer = temporaryPointer;
}

/* Question 2: C function to swap two variables. */
void SwapVariables(signed int *firstNumber, signed int *secondNumber)
{
    signed int temporaryNumber = *firstNumber;

    *firstNumber = *secondNumber;
    *secondNumber = temporaryNumber;
}

/* Question 3: C function to swap two arrays. */
void SwapArrays(signed int firstArray[],
                signed int secondArray[],
                const unsigned char arraySize)
{
    unsigned char index = 0U;
    signed int temporaryNumber = 0;

    for (index = 0U; index < arraySize; index++)
    {
        temporaryNumber = firstArray[index];
        firstArray[index] = secondArray[index];
        secondArray[index] = temporaryNumber;
    }
}

/* Question 8: C function to print array elements using pointer. */
void PrintArrayUsingPointer(const signed int *array,
                            const unsigned char arraySize)
{
    unsigned char index = 0U;

    for (index = 0U; index < arraySize; index++)
    {
        printf("%d ", *(array + index));
    }

    printf("\n");
}

/* Question 34 - First way: Return results using pointers. */
void CalculateUsingPointers(const signed int firstNumber,
                            const signed int secondNumber,
                            signed long long int *summation,
                            signed long long int *multiplication)
{
    *summation = (signed long long int)firstNumber + secondNumber;
    *multiplication = (signed long long int)firstNumber * secondNumber;
}

/* Question 34 - Second way: Return results using array. */
void CalculateUsingArray(const signed int firstNumber,
                         const signed int secondNumber,
                         signed long long int results[])
{
    results[0] = (signed long long int)firstNumber + secondNumber;
    results[1] = (signed long long int)firstNumber * secondNumber;
}

/* Question 34 - Third way: Return results using structure. */
OperationResults CalculateUsingStructure(const signed int firstNumber,
                                         const signed int secondNumber)
{
    OperationResults results = {0, 0};

    results.summation = (signed long long int)firstNumber + secondNumber;
    results.multiplication =
        (signed long long int)firstNumber * secondNumber;

    return results;
}

/* Question 35: Swap two arrays in a reversed pattern. */
void SwapArraysReversed(signed int firstArray[],
                        signed int secondArray[],
                        const unsigned char arraySize)
{
    unsigned char index = 0U;
    unsigned char reversedIndex = 0U;
    signed int temporaryNumber = 0;

    for (index = 0U; index < arraySize; index++)
    {
        reversedIndex = (unsigned char)(arraySize - 1U - index);

        temporaryNumber = firstArray[index];
        firstArray[index] = secondArray[reversedIndex];
        secondArray[reversedIndex] = temporaryNumber;
    }
}

/* Question 36: C function to reverse an array. */
void ReverseArray(signed int array[], const unsigned char arraySize)
{
    unsigned char index = 0U;
    signed int temporaryNumber = 0;

    for (index = 0U; index < (arraySize / 2U); index++)
    {
        temporaryNumber = array[index];
        array[index] = array[arraySize - 1U - index];
        array[arraySize - 1U - index] = temporaryNumber;
    }
}

int main(void)
{
    signed int selectedQuestion = 0;

    do
    {
        printf("\nPointers and Swap Problems\n");
        printf("1  - Swap two pointers\n");
        printf("2  - Swap two variables\n");
        printf("3  - Swap two arrays\n");
        printf("8  - Print array using pointer\n");
        printf("34 - Return summation and multiplication in three ways\n");
        printf("35 - Swap two arrays in reversed pattern\n");
        printf("36 - Reverse an array\n");
        printf("0  - Exit\n");
        printf("Enter question number: ");

        if (scanf("%d", &selectedQuestion) != 1)
        {
            printf("Invalid input.\n");
            return 1;
        }

        switch (selectedQuestion)
        {
            case 1:
            {
                signed int firstNumber = 0;
                signed int secondNumber = 0;
                signed int *firstPointer = &firstNumber;
                signed int *secondPointer = &secondNumber;

                printf("Enter two numbers: ");

                if (scanf("%d %d", &firstNumber, &secondNumber) != 2)
                {
                    return 1;
                }

                printf("Before Swap: %d %d\n",
                       *firstPointer,
                       *secondPointer);

                SwapPointers(&firstPointer, &secondPointer);

                printf("After Swap: %d %d\n",
                       *firstPointer,
                       *secondPointer);
                break;
            }

            case 2:
            {
                signed int firstNumber = 0;
                signed int secondNumber = 0;

                printf("Enter two numbers: ");

                if (scanf("%d %d", &firstNumber, &secondNumber) != 2)
                {
                    return 1;
                }

                printf("Before Swap: %d %d\n",
                       firstNumber,
                       secondNumber);

                SwapVariables(&firstNumber, &secondNumber);

                printf("After Swap: %d %d\n",
                       firstNumber,
                       secondNumber);
                break;
            }

            case 3:
            {
                signed int firstArray[ARRAY_SIZE] = {0};
                signed int secondArray[ARRAY_SIZE] = {0};

                printf("Enter first array elements: ");

                if (ReadArray(firstArray, ARRAY_SIZE) == 0U)
                {
                    return 1;
                }

                printf("Enter second array elements: ");

                if (ReadArray(secondArray, ARRAY_SIZE) == 0U)
                {
                    return 1;
                }

                SwapArrays(firstArray, secondArray, ARRAY_SIZE);

                printf("First array after Swap: ");
                PrintArrayUsingPointer(firstArray, ARRAY_SIZE);

                printf("Second array after Swap: ");
                PrintArrayUsingPointer(secondArray, ARRAY_SIZE);
                break;
            }

            case 8:
            {
                signed int array[ARRAY_SIZE] = {0};

                printf("Enter array elements: ");

                if (ReadArray(array, ARRAY_SIZE) == 0U)
                {
                    return 1;
                }

                printf("Array elements: ");
                PrintArrayUsingPointer(array, ARRAY_SIZE);
                break;
            }

            case 34:
            {
                signed int firstNumber = 0;
                signed int secondNumber = 0;
                signed long long int pointerSummation = 0;
                signed long long int pointerMultiplication = 0;
                signed long long int arrayResults[RESULT_SIZE] = {0};
                OperationResults structureResults = {0, 0};

                printf("Enter two numbers: ");

                if (scanf("%d %d", &firstNumber, &secondNumber) != 2)
                {
                    return 1;
                }

                CalculateUsingPointers(firstNumber,
                                       secondNumber,
                                       &pointerSummation,
                                       &pointerMultiplication);

                CalculateUsingArray(firstNumber,
                                    secondNumber,
                                    arrayResults);

                structureResults =
                    CalculateUsingStructure(firstNumber, secondNumber);

                printf("Using Pointers: Sum = %lld, Multiplication = %lld\n",
                       pointerSummation,
                       pointerMultiplication);

                printf("Using Array: Sum = %lld, Multiplication = %lld\n",
                       arrayResults[0],
                       arrayResults[1]);

                printf("Using Structure: Sum = %lld, Multiplication = %lld\n",
                       structureResults.summation,
                       structureResults.multiplication);
                break;
            }

            case 35:
            {
                signed int firstArray[ARRAY_SIZE] = {0};
                signed int secondArray[ARRAY_SIZE] = {0};

                printf("Enter first array elements: ");

                if (ReadArray(firstArray, ARRAY_SIZE) == 0U)
                {
                    return 1;
                }

                printf("Enter second array elements: ");

                if (ReadArray(secondArray, ARRAY_SIZE) == 0U)
                {
                    return 1;
                }

                SwapArraysReversed(firstArray,
                                   secondArray,
                                   ARRAY_SIZE);

                printf("First array after reversed Swap: ");
                PrintArrayUsingPointer(firstArray, ARRAY_SIZE);

                printf("Second array after reversed Swap: ");
                PrintArrayUsingPointer(secondArray, ARRAY_SIZE);
                break;
            }

            case 36:
            {
                signed int array[ARRAY_SIZE] = {0};

                printf("Enter array elements: ");

                if (ReadArray(array, ARRAY_SIZE) == 0U)
                {
                    return 1;
                }

                ReverseArray(array, ARRAY_SIZE);

                printf("Reversed array: ");
                PrintArrayUsingPointer(array, ARRAY_SIZE);
                break;
            }

            case 0:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid question number.\n");
                break;
        }
    }
    while (selectedQuestion != 0);

    return 0;
}