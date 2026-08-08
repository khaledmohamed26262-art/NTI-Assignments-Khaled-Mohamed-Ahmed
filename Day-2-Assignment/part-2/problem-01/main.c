#include <stdio.h>

int main()
{
    char EnteredAlphabet = '\0';

    printf("Enter an alphabet: ");
    scanf(" %c", &EnteredAlphabet);

    if (EnteredAlphabet == 'a' || EnteredAlphabet == 'e' || EnteredAlphabet == 'i' || EnteredAlphabet == 'o' || EnteredAlphabet == 'u')
    {
        printf("%c is a vowel.\n", EnteredAlphabet);
    }
    else
    {
        printf("%c is a consonant.\n", EnteredAlphabet);
    }

    return 0;
}