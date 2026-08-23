#include <stdio.h>

/**
 * This program contains the answers to Questions:
 * 4, 13, 17, 19, 20, 21, 22 and 23.
 */

#define UNSIGNED_CHAR_MAX_VALUE 255U
#define MAX_FIBONACCI_TERMS 94U

/* Question 4: Multiply two integer numbers. */
signed long long int MultiplyTwoIntegers(
    const signed int firstNumber,
    const signed int secondNumber)
{
    return (signed long long int)firstNumber * secondNumber;
}

/* Question 13: Print Fibonacci series without recursion. */
void PrintFibonacciSeries(const unsigned char numberOfTerms)
{
    unsigned char termNumber = 0U;
    unsigned long long int firstNumber = 0ULL;
    unsigned long long int secondNumber = 1ULL;
    unsigned long long int nextNumber = 0ULL;

    for (termNumber = 0U;
         termNumber < numberOfTerms;
         termNumber++)
    {
        printf("%llu ", firstNumber);

        if ((unsigned int)termNumber + 1U < numberOfTerms)
        {
            nextNumber = firstNumber + secondNumber;
            firstNumber = secondNumber;
            secondNumber = nextNumber;
        }
    }

    printf("\n");
}

/*
 * Question 17:
 * This function returns unsigned char as requested.
 * Overflow happens if the correct result is greater than 255.
 */
unsigned char AddUnsignedCharNumbers(
    const unsigned char firstNumber,
    const unsigned char secondNumber)
{
    return (unsigned char)(firstNumber + secondNumber);
}

/* Question 17: Safe solution using a larger return data type. */
unsigned short int AddUnsignedCharNumbersSafely(
    const unsigned char firstNumber,
    const unsigned char secondNumber)
{
    return (unsigned short int)firstNumber + secondNumber;
}

/* Question 19: Check whether a number is prime. */
unsigned char IsPrimeNumber(const signed int number)
{
    signed int divisor = 0;

    if (number < 2)
    {
        return 0U;
    }

    for (divisor = 2;
         divisor <= (number / divisor);
         divisor++)
    {
        if ((number % divisor) == 0)
        {
            return 0U;
        }
    }

    return 1U;
}

/* Question 20: Count zeros and ones in binary. */
void CountBinaryZerosAndOnes(
    unsigned int number,
    unsigned char *zerosCount,
    unsigned char *onesCount)
{
    *zerosCount = 0U;
    *onesCount = 0U;

    if (number == 0U)
    {
        *zerosCount = 1U;
        return;
    }

    while (number > 0U)
    {
        if ((number & 1U) == 1U)
        {
            (*onesCount)++;
        }
        else
        {
            (*zerosCount)++;
        }

        number >>= 1U;
    }
}

/* Question 21: Return maximum input since the first call. */
signed int GetMaximumInputSinceFirstCall(
    const signed int enteredNumber)
{
    static signed int maximumNumber = 0;
    static unsigned char firstCall = 1U;

    if ((firstCall == 1U) ||
        (enteredNumber > maximumNumber))
    {
        maximumNumber = enteredNumber;
        firstCall = 0U;
    }

    return maximumNumber;
}

/* Question 22: Return maximum zeros between two ones. */
unsigned char GetMaximumZerosBetweenOnes(
    unsigned int number)
{
    unsigned char oneWasFound = 0U;
    unsigned char currentZeros = 0U;
    unsigned char maximumZeros = 0U;

    while (number > 0U)
    {
        if ((number & 1U) == 1U)
        {
            if ((oneWasFound == 1U) &&
                (currentZeros > maximumZeros))
            {
                maximumZeros = currentZeros;
            }

            oneWasFound = 1U;
            currentZeros = 0U;
        }
        else if (oneWasFound == 1U)
        {
            currentZeros++;
        }

        number >>= 1U;
    }

    return maximumZeros;
}

/* Question 23: Return the sum of the digits of an integer. */
unsigned int GetDigitsSummation(const signed int number)
{
    signed long long int positiveNumber = number;
    unsigned int digitsSummation = 0U;

    if (positiveNumber < 0)
    {
        positiveNumber = -positiveNumber;
    }

    while (positiveNumber > 0)
    {
        digitsSummation +=
            (unsigned int)(positiveNumber % 10);

        positiveNumber /= 10;
    }

    return digitsSummation;
}

int main(void)
{
    signed int selectedQuestion = 0;

    do
    {
        printf("\nNumber Operations Problems\n");
        printf("4  - Multiply two integer numbers\n");
        printf("13 - Fibonacci series without recursion\n");
        printf("17 - Add two unsigned char numbers\n");
        printf("19 - Check if a number is prime\n");
        printf("20 - Count binary zeros and ones\n");
        printf("21 - Maximum input since first call\n");
        printf("22 - Maximum zeros between two ones\n");
        printf("23 - Sum the digits of an integer\n");
        printf("0  - Exit\n");
        printf("Enter question number: ");

        if (scanf("%d", &selectedQuestion) != 1)
        {
            printf("Invalid input.\n");
            return 1;
        }

        switch (selectedQuestion)
        {
            case 4:
            {
                signed int firstNumber = 0;
                signed int secondNumber = 0;

                printf("Enter first integer: ");

                if (scanf("%d", &firstNumber) != 1)
                {
                    printf("Invalid input.\n");
                    return 1;
                }

                printf("Enter second integer: ");

                if (scanf("%d", &secondNumber) != 1)
                {
                    printf("Invalid input.\n");
                    return 1;
                }

                printf("Multiplication = %lld\n",
                       MultiplyTwoIntegers(firstNumber,
                                           secondNumber));

                break;
            }

            case 13:
            {
                unsigned int enteredTerms = 0U;

                printf("Enter number of terms from 1 to 94: ");

                if ((scanf("%u", &enteredTerms) != 1) ||
                    (enteredTerms == 0U) ||
                    (enteredTerms > MAX_FIBONACCI_TERMS))
                {
                    printf("Invalid number of terms.\n");
                    break;
                }

                printf("Fibonacci series: ");

                PrintFibonacciSeries(
                    (unsigned char)enteredTerms);

                break;
            }

            case 17:
            {
                unsigned int firstInput = 0U;
                unsigned int secondInput = 0U;
                unsigned char overflowResult = 0U;
                unsigned short int safeResult = 0U;

                printf("Enter first number from 0 to 255: ");

                if ((scanf("%u", &firstInput) != 1) ||
                    (firstInput > UNSIGNED_CHAR_MAX_VALUE))
                {
                    printf("Invalid input.\n");
                    break;
                }

                printf("Enter second number from 0 to 255: ");

                if ((scanf("%u", &secondInput) != 1) ||
                    (secondInput > UNSIGNED_CHAR_MAX_VALUE))
                {
                    printf("Invalid input.\n");
                    break;
                }

                overflowResult =
                    AddUnsignedCharNumbers(
                        (unsigned char)firstInput,
                        (unsigned char)secondInput);

                safeResult =
                    AddUnsignedCharNumbersSafely(
                        (unsigned char)firstInput,
                        (unsigned char)secondInput);

                printf("Unsigned char result = %u\n",
                       (unsigned int)overflowResult);

                printf("Safe result = %u\n",
                       (unsigned int)safeResult);

                if (safeResult > UNSIGNED_CHAR_MAX_VALUE)
                {
                    printf("Overflow occurred because unsigned "
                           "char maximum is 255.\n");
                }
                else
                {
                    printf("No overflow occurred.\n");
                }

                break;
            }

            case 19:
            {
                signed int enteredNumber = 0;

                printf("Enter an integer: ");

                if (scanf("%d", &enteredNumber) != 1)
                {
                    printf("Invalid input.\n");
                    return 1;
                }

                if (IsPrimeNumber(enteredNumber) == 1U)
                {
                    printf("%d is a prime number.\n",
                           enteredNumber);
                }
                else
                {
                    printf("%d is not a prime number.\n",
                           enteredNumber);
                }

                break;
            }

            case 20:
            {
                unsigned int enteredNumber = 0U;
                unsigned char zerosCount = 0U;
                unsigned char onesCount = 0U;

                printf("Enter an unsigned integer: ");

                if (scanf("%u", &enteredNumber) != 1)
                {
                    printf("Invalid input.\n");
                    return 1;
                }

                CountBinaryZerosAndOnes(enteredNumber,
                                        &zerosCount,
                                        &onesCount);

                printf("Zeros count = %u\n",
                       (unsigned int)zerosCount);

                printf("Ones count = %u\n",
                       (unsigned int)onesCount);

                break;
            }

            case 21:
            {
                unsigned int numberOfCalls = 0U;
                unsigned int callNumber = 0U;

                printf("Enter number of function calls: ");

                if ((scanf("%u", &numberOfCalls) != 1) ||
                    (numberOfCalls == 0U))
                {
                    printf("Invalid number of calls.\n");
                    break;
                }

                for (callNumber = 1U;
                     callNumber <= numberOfCalls;
                     callNumber++)
                {
                    signed int enteredNumber = 0;

                    printf("Enter number for call %u: ",
                           callNumber);

                    if (scanf("%d", &enteredNumber) != 1)
                    {
                        printf("Invalid input.\n");
                        return 1;
                    }

                    printf("Maximum since first call = %d\n",
                           GetMaximumInputSinceFirstCall(
                               enteredNumber));
                }

                break;
            }

            case 22:
            {
                unsigned int enteredNumber = 0U;

                printf("Enter an unsigned integer: ");

                if (scanf("%u", &enteredNumber) != 1)
                {
                    printf("Invalid input.\n");
                    return 1;
                }

                printf("Maximum zeros between two ones = %u\n",
                       (unsigned int)
                       GetMaximumZerosBetweenOnes(
                           enteredNumber));

                break;
            }

            case 23:
            {
                signed int enteredNumber = 0;

                printf("Enter an integer: ");

                if (scanf("%d", &enteredNumber) != 1)
                {
                    printf("Invalid input.\n");
                    return 1;
                }

                printf("Digits summation = %u\n",
                       GetDigitsSummation(enteredNumber));

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