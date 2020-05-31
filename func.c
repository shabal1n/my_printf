#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int numSize(long int num);
char* reverse(char hexNumber[]);

char* myItoa(long int num, int base)
{
    char str[numSize(num) + 2];
    int i = 0;
    bool isNegative = false;
    if (num == 0)
    {
        str[i] = '0';
        str[i + 1] = '\0';
        char *final = str;
        return final;
        free(final);
    }
    else if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }

    while (num != 0)
    {
        int rem = num % base;
        if (rem > 9)
        {
            str[i++] = (rem - 10) + 'a';
        }
        else
        {
            str[i++] = rem + '0';
        }
        num = num / base;
    }

    if (isNegative == true)
    {
        str[i++] = '-';
    }
    str[i] = '\0';

    reverse(str);
    char *final = str;

    return final;
    free(final);
}

char* myUtoa(unsigned int n, int size)
{
    char buffer[numSize(n) + 1];
    unsigned int i, counter = 0;

    if (n == 0)
    {
        buffer[counter++] = '0';
    }

    for (; n; n /= 10)
    {
        buffer[counter++] = "0123456789"[n % 10];
    }

    char res[size + 1];

    for (i = 0; i < size; ++i)
    {
        res[i] = buffer[counter - i - 1];
    }

    res[size] = '\0';

    char* ptr = res;

    return ptr;
    free(ptr);
}

int numSize(long int num)
{
    int counter = 0;
    if (num < 0)
    {
        num = -num;
    }
    else if (num == 0)
    {
        counter += 1;
    }

    while (num != 0)
    {
        num /= 10;
        counter++;
    }

    return counter;
}