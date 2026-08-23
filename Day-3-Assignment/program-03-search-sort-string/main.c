#include <stdio.h>

/**
 * This program contains the answers to Questions:
 * 10, 26, 28, 29 and 32.
 */

#define ARRAY_SIZE 5U
#define STRING_SIZE 100U
#define STREAM_SIZE 200U
#define SEARCH_STRING_SIZE 50U

unsigned char ReadArray(signed int array[],
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

void PrintArray(const signed int array[],
                const unsigned char arraySize)
{
    unsigned char index = 0U;

    for (index = 0U; index < arraySize; index++)
    {
        printf("%d ", array[index]);
    }

    printf("\n");
}

unsigned char IsArraySorted(const signed int array[],
                            const unsigned char arraySize)
{
    unsigned char index = 0U;

    for (index = 1U; index < arraySize; index++)
    {
        if (array[index] < array[index - 1U])
        {
            return 0U;
        }
    }

    return 1U;
}

unsigned int GetStringLength(const char string[])
{
    unsigned int length = 0U;

    while (string[length] != '\0')
    {
        length++;
    }

    return length;
}

void CopyString(const char sourceString[],
                char destinationString[])
{
    unsigned int index = 0U;

    do
    {
        destinationString[index] = sourceString[index];
        index++;
    }
    while (sourceString[index - 1U] != '\0');
}

/* Question 10: Iterative binary search. Complexity is O(log n). */
signed int BinarySearchIterative(
    const signed int array[],
    const unsigned char arraySize,
    const signed int searchedNumber)
{
    signed int firstIndex = 0;
    signed int lastIndex = (signed int)arraySize - 1;

    while (firstIndex <= lastIndex)
    {
        signed int middleIndex =
            firstIndex + ((lastIndex - firstIndex) / 2);

        if (array[middleIndex] == searchedNumber)
        {
            return middleIndex;
        }

        if (array[middleIndex] < searchedNumber)
        {
            firstIndex = middleIndex + 1;
        }
        else
        {
            lastIndex = middleIndex - 1;
        }
    }

    return -1;
}

/* Question 10: Recursive binary search. Complexity is O(log n). */
signed int BinarySearchRecursive(
    const signed int array[],
    const signed int firstIndex,
    const signed int lastIndex,
    const signed int searchedNumber)
{
    signed int middleIndex = 0;

    if (firstIndex > lastIndex)
    {
        return -1;
    }

    middleIndex =
        firstIndex + ((lastIndex - firstIndex) / 2);

    if (array[middleIndex] == searchedNumber)
    {
        return middleIndex;
    }

    if (array[middleIndex] < searchedNumber)
    {
        return BinarySearchRecursive(array,
                                     middleIndex + 1,
                                     lastIndex,
                                     searchedNumber);
    }

    return BinarySearchRecursive(array,
                                 firstIndex,
                                 middleIndex - 1,
                                 searchedNumber);
}

/* Question 26: Sort an array using Bubble Sort. */
void BubbleSort(signed int array[],
                const unsigned char arraySize)
{
    unsigned char passNumber = 0U;
    unsigned char index = 0U;
    signed int temporaryNumber = 0;

    for (passNumber = 0U;
         passNumber < (arraySize - 1U);
         passNumber++)
    {
        for (index = 0U;
             index < (arraySize - passNumber - 1U);
             index++)
        {
            if (array[index] > array[index + 1U])
            {
                temporaryNumber = array[index];
                array[index] = array[index + 1U];
                array[index + 1U] = temporaryNumber;
            }
        }
    }
}

/* Question 28: Sort an array using Selection Sort. */
void SelectionSort(signed int array[],
                   const unsigned char arraySize)
{
    unsigned char currentIndex = 0U;
    unsigned char compareIndex = 0U;
    unsigned char minimumIndex = 0U;
    signed int temporaryNumber = 0;

    for (currentIndex = 0U;
         currentIndex < (arraySize - 1U);
         currentIndex++)
    {
        minimumIndex = currentIndex;

        for (compareIndex =
                 (unsigned char)(currentIndex + 1U);
             compareIndex < arraySize;
             compareIndex++)
        {
            if (array[compareIndex] < array[minimumIndex])
            {
                minimumIndex = compareIndex;
            }
        }

        if (minimumIndex != currentIndex)
        {
            temporaryNumber = array[currentIndex];
            array[currentIndex] = array[minimumIndex];
            array[minimumIndex] = temporaryNumber;
        }
    }
}

/* Question 29: Reverse a string using iteration. */
void ReverseStringIterative(char string[])
{
    unsigned int firstIndex = 0U;
    unsigned int lastIndex = GetStringLength(string);
    char temporaryCharacter = '\0';

    if (lastIndex == 0U)
    {
        return;
    }

    lastIndex--;

    while (firstIndex < lastIndex)
    {
        temporaryCharacter = string[firstIndex];
        string[firstIndex] = string[lastIndex];
        string[lastIndex] = temporaryCharacter;

        firstIndex++;
        lastIndex--;
    }
}

/* Question 29: Reverse a string using recursion. */
void ReverseStringRecursive(
    char string[],
    const unsigned int firstIndex,
    const unsigned int lastIndex)
{
    char temporaryCharacter = '\0';

    if (firstIndex >= lastIndex)
    {
        return;
    }

    temporaryCharacter = string[firstIndex];
    string[firstIndex] = string[lastIndex];
    string[lastIndex] = temporaryCharacter;

    ReverseStringRecursive(string,
                           firstIndex + 1U,
                           lastIndex - 1U);
}

/* Question 32: Search for a specific string in a data stream. */
signed int SearchStringInStream(
    const char dataStream[],
    const char searchedString[])
{
    unsigned int streamIndex = 0U;
    unsigned int searchIndex = 0U;
    unsigned int streamLength =
        GetStringLength(dataStream);
    unsigned int searchLength =
        GetStringLength(searchedString);

    if (searchLength == 0U)
    {
        return 0;
    }

    if (searchLength > streamLength)
    {
        return -1;
    }

    for (streamIndex = 0U;
         streamIndex <= (streamLength - searchLength);
         streamIndex++)
    {
        searchIndex = 0U;

        while ((searchIndex < searchLength) &&
               (dataStream[streamIndex + searchIndex] ==
                searchedString[searchIndex]))
        {
            searchIndex++;
        }

        if (searchIndex == searchLength)
        {
            return (signed int)streamIndex;
        }
    }

    return -1;
}

int main(void)
{
    signed int selectedQuestion = 0;

    do
    {
        printf("\nSearch, Sort and String Problems\n");
        printf("10 - Binary search iterative and recursive\n");
        printf("26 - Bubble sort\n");
        printf("28 - Selection sort\n");
        printf("29 - Reverse string iterative and recursive\n");
        printf("32 - Search for a string in a data stream\n");
        printf("0  - Exit\n");
        printf("Enter question number: ");

        if (scanf("%d", &selectedQuestion) != 1)
        {
            printf("Invalid input.\n");
            return 1;
        }

        switch (selectedQuestion)
        {
            case 10:
            {
                signed int array[ARRAY_SIZE] = {0};
                signed int searchedNumber = 0;
                signed int iterativeIndex = -1;
                signed int recursiveIndex = -1;

                printf("Enter 5 sorted array elements: ");

                if (ReadArray(array, ARRAY_SIZE) == 0U)
                {
                    printf("Invalid input.\n");
                    return 1;
                }

                if (IsArraySorted(array, ARRAY_SIZE) == 0U)
                {
                    printf("The array must be sorted.\n");
                    break;
                }

                printf("Enter number to search for: ");

                if (scanf("%d", &searchedNumber) != 1)
                {
                    printf("Invalid input.\n");
                    return 1;
                }

                iterativeIndex =
                    BinarySearchIterative(array,
                                          ARRAY_SIZE,
                                          searchedNumber);

                recursiveIndex =
                    BinarySearchRecursive(
                        array,
                        0,
                        (signed int)ARRAY_SIZE - 1,
                        searchedNumber);

                if (iterativeIndex == -1)
                {
                    printf("Number was not found.\n");
                }
                else
                {
                    printf("Iterative search index = %d\n",
                           iterativeIndex);

                    printf("Recursive search index = %d\n",
                           recursiveIndex);
                }

                printf("Time complexity = O(log n)\n");
                break;
            }

            case 26:
            {
                signed int array[ARRAY_SIZE] = {0};

                printf("Enter 5 array elements: ");

                if (ReadArray(array, ARRAY_SIZE) == 0U)
                {
                    printf("Invalid input.\n");
                    return 1;
                }

                BubbleSort(array, ARRAY_SIZE);

                printf("Array after Bubble Sort: ");
                PrintArray(array, ARRAY_SIZE);
                break;
            }

            case 28:
            {
                signed int array[ARRAY_SIZE] = {0};

                printf("Enter 5 array elements: ");

                if (ReadArray(array, ARRAY_SIZE) == 0U)
                {
                    printf("Invalid input.\n");
                    return 1;
                }

                SelectionSort(array, ARRAY_SIZE);

                printf("Array after Selection Sort: ");
                PrintArray(array, ARRAY_SIZE);
                break;
            }

            case 29:
            {
                char originalString[STRING_SIZE] = {'\0'};
                char iterativeString[STRING_SIZE] = {'\0'};
                char recursiveString[STRING_SIZE] = {'\0'};
                unsigned int stringLength = 0U;

                printf("Enter a string: ");

                if (scanf(" %99[^\n]", originalString) != 1)
                {
                    printf("Invalid input.\n");
                    return 1;
                }

                CopyString(originalString, iterativeString);
                CopyString(originalString, recursiveString);

                ReverseStringIterative(iterativeString);

                stringLength =
                    GetStringLength(recursiveString);

                if (stringLength > 0U)
                {
                    ReverseStringRecursive(
                        recursiveString,
                        0U,
                        stringLength - 1U);
                }

                printf("Iterative reversed string: %s\n",
                       iterativeString);

                printf("Recursive reversed string: %s\n",
                       recursiveString);

                break;
            }

            case 32:
            {
                char dataStream[STREAM_SIZE] = {'\0'};
                char searchedString[SEARCH_STRING_SIZE] = {'\0'};
                signed int foundIndex = -1;

                printf("Enter the data stream: ");

                if (scanf(" %199[^\n]", dataStream) != 1)
                {
                    printf("Invalid input.\n");
                    return 1;
                }

                printf("Enter the string to search for: ");

                if (scanf(" %49[^\n]", searchedString) != 1)
                {
                    printf("Invalid input.\n");
                    return 1;
                }

                foundIndex =
                    SearchStringInStream(dataStream,
                                         searchedString);

                if (foundIndex == -1)
                {
                    printf("String was not found.\n");
                }
                else
                {
                    printf("String was found at index %d.\n",
                           foundIndex);
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