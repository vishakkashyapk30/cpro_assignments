#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "matrix.h"

#define MAX_FILE_NAME_SIZE 5000
#define MAX_OPERATION_NAME_SIZE 50

void history_matrix(char *operation, int code)
{
    FILE *FP = fopen("mx_history", "a");

    if (FP == NULL)
        printf("ERROR: INVALID ARGUMENT\n");

    if (strcmp(operation, "history") == 0)
        fprintf(FP, "LOG::%s\n", operation);
    else
        fprintf(FP, "LOG::%s %d\n", operation, code);

    fclose(FP);
}

int main()
{
    int q;
    scanf("%d", &q);

    for (int i = 1; i <= q; i++)
    {
        char str[MAX_OPERATION_NAME_SIZE];
        int ch;
        scanf("%s", str);

        if (strcmp(str, "history") == 0)
        {
            history_matrix(str, 0);
            FILE *FP = fopen("mx_history", "r");

            if (FP == NULL)
                printf("ERROR: INVALID ARGUMENT\n");

            char c;
            while ((c = fgetc(FP)) != EOF)
                printf("%c", c);
            
            fclose(FP);
        }

        else
        {
            scanf("%d", &ch);//ch can be 0 or 1
            history_matrix(str, ch);

            if ((strcmp(str, "add_matrix") == 0))
            {
                if (ch == 0)
                {
                    int n1, m1;
                    scanf("%d %d", &n1, &m1);
                    Matrix *A;
                    A = create_matrix(n1, m1);
                    for (int i = 0; i < n1; i++)
                    {
                        for (int j = 0; j < m1; j++)
                            scanf("%lld", &A->data[i][j]);
                    }

                    int n2, m2;
                    scanf("%d %d", &n2, &m2);
                    Matrix *B;
                    B = create_matrix(n2, m2);
                    for (int i = 0; i < n2; i++)
                    {
                        for (int j = 0; j < m2; j++)
                            scanf("%lld", &B->data[i][j]);
                    }

                    if (add_matrix(A, B) == NULL)
                        printf("ERROR: INVALID ARGUMENT\n");
                    else
                        print_matrix(add_matrix(A, B));

                    destroy_matrix(A);
                    destroy_matrix(B);
                }

                else if (ch == 1)
                {
                    char strinp1[MAX_FILE_NAME_SIZE], strinp2[MAX_FILE_NAME_SIZE], strout[MAX_FILE_NAME_SIZE];
                    scanf("%s", strinp1);
                    scanf("%s", strinp2);
                    scanf("%s", strout);

                    Matrix *A = read_matrix_from_file(strinp1);
                    Matrix *B = read_matrix_from_file(strinp2);

                    write_matrix_to_file(add_matrix(A, B), strout);

                    destroy_matrix(A);
                    destroy_matrix(B);
                }

                else
                    printf("ERROR: INVALID CODE (ENTER 0 OR 1)\n");
            }

            else if ((strcmp(str, "mult_matrix") == 0))
            {
                if (ch == 0)
                {
                    int n1, m1;
                    scanf("%d %d", &n1, &m1);
                    Matrix *A;
                    A = create_matrix(n1, m1);
                    for (int i = 0; i < n1; i++)
                    {
                        for (int j = 0; j < m1; j++)
                            scanf("%lld", &A->data[i][j]);
                    }

                    int n2, m2;
                    scanf("%d %d", &n2, &m2);
                    Matrix *B;
                    B = create_matrix(n2, m2);
                    for (int i = 0; i < n2; i++)
                    {
                        for (int j = 0; j < m2; j++)
                            scanf("%lld", &B->data[i][j]);
                    }

                    if (mult_matrix(A, B) == NULL)
                        printf("ERROR: INVALID ARGUMENT\n");

                    else
                        print_matrix(mult_matrix(A, B));

                    destroy_matrix(A);
                    destroy_matrix(B);
                }

                else if (ch == 1)
                {
                    char strinp1[MAX_FILE_NAME_SIZE], strinp2[MAX_FILE_NAME_SIZE], strout[MAX_FILE_NAME_SIZE];
                    scanf("%s", strinp1);
                    scanf("%s", strinp2);
                    scanf("%s", strout);

                    Matrix *A = read_matrix_from_file(strinp1);
                    Matrix *B = read_matrix_from_file(strinp2);

                    write_matrix_to_file(mult_matrix(A, B), strout);

                    destroy_matrix(A);
                    destroy_matrix(B);
                }

                else
                    printf("ERROR: INVALID CODE (ENTER 0 OR 1)\n");
            }

            else if ((strcmp(str, "scalar_mult_matrix") == 0))
            {
                if (ch == 0)
                {
                    long long int s;
                    scanf("%lld", &s);

                    int n, m;
                    scanf("%d %d", &n, &m);

                    Matrix *M;
                    M = create_matrix(n, m);
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < m; j++)
                            scanf("%lld", &M->data[i][j]);
                    }

                    if (scalar_mult_matrix(s, M) == NULL)
                        printf("ERROR: INVALID ARGUMENT\n");

                    else
                        print_matrix(scalar_mult_matrix(s, M));

                    destroy_matrix(M);
                }

                else if (ch == 1)
                {
                    long long int s;
                    scanf("%lld", &s);

                    char strinp[MAX_FILE_NAME_SIZE], strout[MAX_FILE_NAME_SIZE];
                    scanf("%s", strinp);
                    scanf("%s", strout);

                    Matrix *M = read_matrix_from_file(strinp);

                    write_matrix_to_file(scalar_mult_matrix(s, M), strout);

                    destroy_matrix(M);
                }

                else
                    printf("ERROR: INVALID CODE (ENTER 0 OR 1)\n");
            }

            else if ((strcmp(str, "transpose_matrix") == 0))
            {
                if (ch == 0)
                {
                    int n, m;
                    scanf("%d %d", &n, &m);

                    Matrix *A;
                    A = create_matrix(n, m);
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < m; j++)
                            scanf("%lld", &A->data[i][j]);
                    }

                    if (transpose_matrix(A) == NULL)
                        printf("ERROR: INVALID ARGUMENT\n");

                    else
                        print_matrix(transpose_matrix(A));

                    destroy_matrix(A);
                }

                else if (ch == 1)
                {
                    char strinp[MAX_FILE_NAME_SIZE], strout[MAX_FILE_NAME_SIZE];
                    scanf("%s", strinp);
                    scanf("%s", strout);

                    Matrix *A = read_matrix_from_file(strinp);

                    write_matrix_to_file(transpose_matrix(A), strout);

                    destroy_matrix(A);
                }

                else
                    printf("ERROR: INVALID CODE (ENTER 0 OR 1)\n");
            }

            else if ((strcmp(str, "determinant") == 0))
            {
                if (ch == 0)
                {
                    int n, m;
                    scanf("%d %d", &n, &m);

                    Matrix *M;
                    M = create_matrix(n, m);
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < m; j++)
                            scanf("%lld", &M->data[i][j]);
                    }

                    if (is_square_matrix(M) == false)
                        printf("ERROR: INVALID ARGUMENT\n");

                    else
                        printf("%lld\n", determinant(M));

                    destroy_matrix(M);
                }

                else if (ch == 1)
                {
                    char strinp[MAX_FILE_NAME_SIZE];
                    scanf("%s", strinp);

                    Matrix *M = read_matrix_from_file(strinp);

                    if (is_square_matrix(M) == false)
                        printf("ERROR: INVALID ARGUMENT\n");

                    else
                        printf("%lld\n", determinant(M));

                    destroy_matrix(M);
                }

                else
                    printf("ERROR: INVALID CODE (ENTER 0 OR 1)\n");
            }

            else printf("ERROR: INVALID OPERATION NAME\n");
        }
    }
    
    return 0;
}