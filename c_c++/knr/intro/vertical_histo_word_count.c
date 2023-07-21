#include <stdio.h>

#define OUT 0
#define IN 1

void init_array(int[], int, int);
void print_array(int[], int);
void print_histogram(int[], int);
int max(int[], int);

void init_array(int arr[], int n, int c)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = c;
    }
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
}

int max(int arr[], int n)
{

    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

void print_histogram(int arr[], int n)
{
    int maxwordlen = max(arr, n);

    for (int row = 0; row < maxwordlen; row++)
    {
        printf("\n");
        for (int column = 1; column < n; column++)
        {
            if (maxwordlen - arr[column] <= row)
            {
                printf("*  ");
            }
            else
            {
                printf("   ");
            }
        }
    }

    printf("\n");
    for (int i = 1; i < n; i++)
    {
        printf("%d  ", i);
    }
}

int main()
{
    int wordlen = 0, c, state = OUT;
    int maxwordlen = 10;
    int histogram[maxwordlen + 2];

    init_array(histogram, maxwordlen + 2, 0);

    while ((c = getchar()) != EOF)
    {
        if ((c == '\n') || (c == '\t') || (c == ' '))
        {
            if (wordlen > maxwordlen)
            {
                ++histogram[maxwordlen + 1];
            }
            else
            {
                ++histogram[wordlen];
            }
            wordlen = 0;
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            ++wordlen;
        }
        else
        {
            ++wordlen;
        }
    }

    print_histogram(histogram, maxwordlen + 2);

    return 0;
}
