#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

int func(int N, int M, int *A, int *B)
{
    int result = 0;

    // time complexity = O(NM)
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            result += (A[i] * B[j] * (i + j + 2));
        }
    }

    return result;
}

void swap(int *A, int *B, int q_type, int i, int j)
{
    --i;
    --j;
    if (q_type == 1)
    {
        int temp = A[i];
        A[i] = B[j];
        B[j] = temp;
    }
    else if (q_type == 2)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    else if (q_type == 3)
    {
        int temp = B[i];
        B[i] = B[j];
        B[j] = temp;
    }
}

int *array_queries(int N, int M, int *A, int *B, int Q, int **queries, int *out_n)
{
    *out_n = Q + 1;
    int *result = (int *)malloc(sizeof(int) * (*out_n));

    result[0] = func(N, M, A, B);

    // time complexity = O(QMN)
    for (int i = 1; i <= Q; i++)
    {

        swap(A, B, queries[i - 1][0], queries[i - 1][1], queries[i - 1][2]);
        result[i] = func(N, M, A, B);
    }

    return result;
}

int main()
{
    int out_n;
    int T;
    scanf("%d", &T);
    for (int t_i = 0; t_i < T; t_i++)
    {
        int N;
        scanf("%d", &N);
        int M;
        scanf("%d", &M);
        int i_A;
        int *A = (int *)malloc(sizeof(int) * (N));
        for (i_A = 0; i_A < N; i_A++)
            scanf("%d", &A[i_A]);
        int i_B;
        int *B = (int *)malloc(sizeof(int) * (M));
        for (i_B = 0; i_B < M; i_B++)
            scanf("%d", &B[i_B]);
        int Q;
        scanf("%d", &Q);
        int i_queries, j_queries;
        int **queries = (int **)malloc((Q) * sizeof(int *));
        for (i_queries = 0; i_queries < Q; i_queries++)
        {
            queries[i_queries] = (int *)malloc((3) * sizeof(int));
        }
        for (i_queries = 0; i_queries < Q; i_queries++)
        {
            for (j_queries = 0; j_queries < 3; j_queries++)
            {
                scanf("%d", &queries[i_queries][j_queries]);
            }
        }

        int *out_ = array_queries(N, M, A, B, Q, queries, &out_n);
        printf("%d", out_[0]);
        for (int i_out_ = 1; i_out_ < out_n; i_out_++)
            printf(" %d", out_[i_out_]);
        printf("\n");
    }
}