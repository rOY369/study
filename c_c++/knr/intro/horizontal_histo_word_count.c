#include <stdio.h>

#define OUT 0
#define IN 1

void init_array(int[], int, int);
void print_array(int[], int);
void print_histogram(int[], int);

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

void print_histogram(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {

        if (arr[i] > 0)
        {
            printf("\n%d : ", i);
            for (int j = 0; j < arr[i]; j++)
            {
                printf("*");
            }
        }
    }
}

int main()
{
    int wordlen = 0, c, state = OUT;
    int maxwordlen = 50;
    int histogram[maxwordlen];

    init_array(histogram, maxwordlen, 0);

    while ((c = getchar()) != EOF)
    {
        if ((c == '\n') || (c == '\t') || (c == ' '))
        {
            ++histogram[wordlen];
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

    print_histogram(histogram, maxwordlen);

    return 0;
}
