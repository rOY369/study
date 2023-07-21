#include <stdio.h>

int getline(char arr[])
{
    int c, nc = 0;
    while ((c = getchar()) != EOF)
    {
        arr[nc] = c;
        ++nc;

        if (c == '\n')
        {
            return nc;
        }
    }
    return 0;
}

void copy(char from[], char to[], int length)
{
    for (int i = 0; i < length; i++)
    {
        to[i] = from[i];
    }
}

int main()
{
    int nc = 0, longest = 0;
    char line[100], longline[100];
    while (nc = getline(line))
    {
        if (nc > longest)
        {
            longest = nc;
            copy(line, longline, longest);
        }
    }
    for (int i = 0; i < longest; i++)
    {
        printf("%c", longline[i]);
    }

    return 0;
}