#include <stdlib.h>
#include <string.h>

char* reverse(char hexNumber[]);

char* myHex(int number, int size)
{
    char hexNumber[size + 1];
    int i = 0;

    while (number != 0)
    {
        int tmp = 0;
        tmp = number % 16;

        if (tmp < 10)
        {
            hexNumber[i] = tmp + 48;
            i++;
        }
        else
        {
            hexNumber[i] = tmp + 55;
            i++;
        }

        number = number / 16;
    }

    hexNumber[i] = '\0';

    reverse(hexNumber);

    char* ptr = hexNumber;
    return ptr;
    free(ptr);
}

char* longHex(long* decimal, int size)
{
    long q, r;
    int i, j = 0;
    char hexadecimal[size + 1];
    q = *decimal;

    while (q != 0)
    {
        r = q % 16;
        if (r < 10)
        {
            hexadecimal[j++] = 48 + r;
        }
        else
        {
            hexadecimal[j++] = 55 + r;
        }

        q = q / 16;
    }

    int tmp = 0;
    int f = 0;
    int k = strlen(hexadecimal) - 1;

    while (f < k)
    {
        tmp = hexadecimal[f];
        hexadecimal[f] = hexadecimal[k];
        hexadecimal[k] = tmp;
        f++;
        k--;
    }

    for (int i = 0; i <= strlen(hexadecimal); i++)
    {
        if (hexadecimal[i] >= 65 && hexadecimal[i] <= 90)
        {
            hexadecimal[i] = hexadecimal[i] + 32;
        }
    }
    hexadecimal[size ] = '\0';
    char* final = hexadecimal;
    return final;
    free(final);
}

char* myNegativeHex(unsigned int number, int size)
{
    char hexNumber[size + 1];
    int i = 0;

    while (number != 0)
    {
        int tmp = 0;
        tmp = number % 16;

        if (tmp < 10)
        {
            hexNumber[i] = tmp + 48;
            i++;
        }
        else
        {
            hexNumber[i] = tmp + 55;
            i++;
        }

        number = number / 16;
    }

    hexNumber[i] = '\0';

    reverse(hexNumber);

    char* ptr = hexNumber;
    return ptr;
    free(ptr);
}

char* reverse(char hexNumber[])
{
    int f = 0;
    int j = strlen(hexNumber) - 1;
    char temp;

    while (f < j)
    {
        temp = hexNumber[f];
        hexNumber[f] = hexNumber[j];
        hexNumber[j] = temp;
        f++;
        j--;
    }
    return hexNumber;
}