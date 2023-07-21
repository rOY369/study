#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

unsigned long long sum_A_value = 0, sum_B_value = 0, sum_Ai_value = 0, sum_Bj_value = 0;

unsigned long long compute_sum()
{
    return ((sum_Ai_value % 998244353) * (sum_B_value % 998244353) + (sum_A_value % 998244353) * (sum_Bj_value % 998244353)) % 998244353;
}

void compute_constants(long N, long M, int *A, int *B)
{
    sum_A_value = 0, sum_B_value = 0, sum_Ai_value = 0, sum_Bj_value = 0;

    for (long k = 0; k < N; k++)
    {
        unsigned long long val = A[k];
        sum_A_value += val;
        sum_Ai_value += (k + 1) * val;
    }

    for (long k = 0; k < M; k++)
    {
        unsigned long long val = B[k];
        sum_B_value += val;
        sum_Bj_value += (k + 1) * val;
    }
}

void update_constants(long sum_A_change, long sum_B_change, long sum_Ai_change, long sum_Bj_change)
{

    sum_A_value += sum_A_change;
    sum_B_value += sum_B_change;
    sum_Ai_value += sum_Ai_change;
    sum_Bj_value += sum_Bj_change;
}

void swap(int N, int M, int *A, int *B, int q_type, long i, long j)
{

    --i;
    --j;
    if (q_type == 1)
    {

        long temp = A[i];
        A[i] = B[j];
        update_constants(-temp, -B[j], -((i + 1) * temp), -((j + 1) * B[j]));

        B[j] = temp;

        update_constants(A[i], B[j], ((i + 1) * A[i]), ((j + 1) * B[j]));
    }
    else if (q_type == 2)
    {
        long temp = A[i];
        A[i] = A[j];
        update_constants(-temp, 0, -((i + 1) * temp), 0);
        update_constants(-A[j], 0, -((j + 1) * A[j]), 0);

        A[j] = temp;

        update_constants(A[i], 0, ((i + 1) * A[i]), 0);
        update_constants(A[j], 0, ((j + 1) * A[j]), 0);
    }
    else if (q_type == 3)
    {
        long temp = B[i];
        B[i] = B[j];
        update_constants(0, -temp, 0, -((i + 1) * temp));
        update_constants(0, -B[j], 0, -((j + 1) * B[j]));

        B[j] = temp;

        update_constants(0, B[i], 0, ((i + 1) * B[i]));
        update_constants(0, B[j], 0, ((j + 1) * B[j]));
    }
}

unsigned long long *array_queries(int N, int M, int *A, int *B, int Q, int **queries, int *out_n)
{
    if (N < 0 || N > 100000 || M < 0 || M > 100000 || Q < 1 || Q > 100000)
    {
        *out_n = 0;
        return NULL;
    }

    *out_n = Q + 1;

    compute_constants(N, M, A, B);

    unsigned long long *result = (unsigned long long *)malloc(sizeof(unsigned long long) * (*out_n));

    result[0] = compute_sum();

    for (int i = 1; i <= Q; i++)
    {
        int qtype = queries[i - 1][0];
        int swap_i = queries[i - 1][1];
        int swap_j = queries[i - 1][2];

        swap(N, M, A, B, qtype, swap_i, swap_j);
        result[i] = compute_sum();
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

        unsigned long long *out_ = array_queries(N, M, A, B, Q, queries, &out_n);
        printf("%llu", out_[0]);
        for (int i_out_ = 1; i_out_ < out_n; i_out_++)
            printf(" %llu", out_[i_out_]);
        free(out_);
        free(queries);
        printf("\n");
    }
}