#include <stdio.h>

int mygetline(char arr[])
{
    int c, nc = 0;
    while ((c = getchar()) != EOF)
    {
        arr[nc] = c;
        ++nc;

        if (c == '\n')
        {
            arr[nc] = '\0';
            return nc;
        }
    }
    return 0;
}

void reverse(char line[], char reversed[], int len)
{
    int i;

    for (i = 0; i < len; ++i)
    {
        reversed[i] = line[len - 1 - i];
    }

    reversed[i] = '\0';
}

int main()
{
    int nc = 0, longest = 0;
    char line[100], reversed[100];
    while (nc = mygetline(line))
    {
        if (nc > 0)
        {
            reverse(line, reversed, nc);
            printf("%s", reversed);
        }
    }

    return 0;
}