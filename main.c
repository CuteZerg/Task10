#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define N 256

int main()
{
    setlocale(LC_ALL, "Rus");
    char copy[N];
    char str[N];
    char last[N];
    char *word;
    int min = 9999;

    strcpy(copy, "");
    printf("¬ведите строку:\n");
    gets(str);
    str[strlen(str)] = '\0';

    word = strtok(str, " ");
    while (word != NULL)
    {
        strcat(copy, word);
        strcat(copy, " ");
        word = strtok(NULL, " ");
    }

    if (copy[strlen(copy) - 2] == '.')
    {
        if (copy[strlen(copy) - 3] == ' ')
            copy[strlen(copy) - 3] = '\0';
        else
            copy[strlen(copy) - 2] = '\0';
    }
    else
        copy[strlen(copy) - 1] = '\0';

    int len = strlen(copy);
    int i;
    for (i = len - 1; i > -1; i--)
        if (copy[i] == ' ')
            break;
    i++;

    for(int j = i; j < len; j++)
        last[j-i] = copy[j];
    last[len-i] = '\0';

    strcpy(str, "");
    printf("\n—лова строки, не совпадающие с последним:\n");
    word = strtok(copy, " ");
    while (word != NULL)
    {
        if (strcmp(word, last))
        {
            strcat(str, word);
            strcat(str, " ");
        }
        word = strtok(NULL, " ");
    }
    str[strlen(str) - 1] = '\0';
    len = strlen(str);
    printf("%s\n", str);

    strcpy(copy, str);
    word = strtok(copy, " ");
    while (word != NULL)
    {
        if (strlen(word) < min)
            min = strlen(word);
        word = strtok(NULL, " ");
    }

    printf("\n—лова с минимальной длиной:\n");
    word = strtok(str, " ");
    while (word != NULL)
    {
        if (strlen(word) == min)
            printf("%s ", word);
        word = strtok(NULL, " ");
    }


    return 0;
}
