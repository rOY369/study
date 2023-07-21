#include <stdio.h>

#define OUT 0
#define IN 1

int main()
{
    int nw = 0, c, state, nl = 0, nc;

    state = OUT;

    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
        {

            ++nl;
        }
        if ((c == '\n') || (c == '\t') || (c == ' '))
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            nw += 1;
            state = IN;
            printf("\n");
            putchar(c);
        }
        else
        {
            putchar(c);
        }
    }

    printf("Number of characters : %d\n", nc);
    printf("Number of words : %d\n", nw);
    printf("Number of lines : %d\n", nl);

    return 0;
}
