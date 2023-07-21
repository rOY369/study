#include <stdio.h>

int main()
{
    int nwhite, nother, c, count[10];
    for (int i = 0; i < 10; i++)
    {
        count[i] = 0;
    }
    while ((c = getchar()) != EOF)
    {
        if ((c == '\n') || (c == '\t') || (c == ' '))
        {
            ++nwhite;
        }
        else if ((c >= '0') && (c <= '9'))
        {
            ++count[c - '0'];
        }
        else
        {
            ++nother;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d : %d\n", i, count[i]);
    }

    return 0;
}
