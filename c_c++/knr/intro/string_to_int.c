#include <stdio.h>
#include <string.h>
#include <math.h>

int str_to_num(char str[])
{
    int i = 0, num = 0;
    while (str[i] != '\0')
    {
        int digit = str[i] - '0';
        num += (digit * pow(10, strlen(str) - i - 1));
        i++;
    }

    return num;
}

int main()
{
    int result = str_to_num("123");
    printf("%d", result);

    return 0;
}