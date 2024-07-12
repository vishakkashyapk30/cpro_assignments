#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "matrix.h"

Matrix *create_matrix(int r, int c)
{
    Matrix *m = (Matrix *)malloc(sizeof(Matrix));
    m->num_rows = r;
    m->num_cols = c;
    m->data = (long long int **)calloc(r, sizeof(long long int *));

    for (int i = 0; i < r; i++)
        m->data[i] = (long long int *)calloc(c, sizeof(long long int));

    return m;
}

void destroy_matrix(Matrix *m)
{
    for (int i = 0; i < m->num_rows; i++)
        free(m->data[i]);

    free(m->data);

    free(m);
}

Matrix *add_matrix(Matrix *A, Matrix *B)
{
    Matrix *sum;

    if (A->num_rows != B->num_rows || A->num_cols != B->num_cols)
        return NULL;

    sum = create_matrix(A->num_rows, A->num_cols);
    for (int i = 0; i < sum->num_rows; i++)
    {
        for (int j = 0; j < sum->num_cols; j++)
            sum->data[i][j] = A->data[i][j] + B->data[i][j];
    }

    return sum;
}

Matrix *mult_matrix(Matrix *A, Matrix *B)
{
    Matrix *mult;
    // Assuming A*B takes place always
    if (A->num_cols != B->num_rows)
        return NULL;

    mult = create_matrix(A->num_rows, B->num_cols);
    for (int i = 0; i < mult->num_rows; i++)
    {
        for (int j = 0; j < mult->num_cols; j++)
        {
            mult->data[i][j] = 0;
            for (int k = 0; k < A->num_cols; k++)
                mult->data[i][j] += A->data[i][k] * B->data[k][j];
        }
    }

    return mult;
}

Matrix *scalar_mult_matrix(long long int s, Matrix *M)
{
    Matrix *scalar_mult;

    scalar_mult = create_matrix(M->num_rows, M->num_cols);
    for (int i = 0; i < M->num_rows; i++)
    {
        for (int j = 0; j < M->num_cols; j++)
            scalar_mult->data[i][j] = s * M->data[i][j];
    }

    return scalar_mult;
}

Matrix *transpose_matrix(Matrix *A)
{
    Matrix *transpose;

    transpose = create_matrix(A->num_cols, A->num_rows);
    for (int i = 0; i < A->num_rows; i++)
    {
        for (int j = 0; j < A->num_cols; j++)
            transpose->data[j][i] = A->data[i][j];
    }

    return transpose;
}

// To check if determinant operation is possible or not
bool is_square_matrix(Matrix *m)
{
    if (m->num_rows == m->num_cols)
        return true;
    else
        return false;
}

long long int determinant(Matrix *M)
{
    if (M->num_rows == 1)
        return M->data[0][0];

    if (M->num_rows == 2)
        return M->data[0][0] * M->data[1][1] - M->data[0][1] * M->data[1][0];

    long long int det = 0;
    for (int i = 0; i < M->num_rows; i++)
    {
        Matrix *minor = create_matrix(M->num_rows - 1, M->num_cols - 1);
        for (int j = 1; j < M->num_rows; j++)
        {
            int col_track = 0;
            for (int k = 0; k < M->num_cols; k++)
            {
                if (k != i)
                {
                    minor->data[j - 1][col_track] = M->data[j][k];
                    col_track++;
                }
            }
        }
        if (i % 2 == 0)
            det += 1 * M->data[0][i] * determinant(minor);
        else
            det += (-1) * M->data[0][i] * determinant(minor);

        destroy_matrix(minor);
    }
    return det;
}

void print_matrix(Matrix *m)
{
    printf("%d %d\n", m->num_rows, m->num_cols);

    for (int i = 0; i < m->num_rows; i++)
    {
        for (int j = 0; j < m->num_cols; j++)
        {
            printf("%lld ", m->data[i][j]);
        }
        printf("\n");
    }
}

Matrix *read_matrix_from_file(char *filename)
{
    FILE *fp;
    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("ERROR: COULD NOT OPEN FILE FOR READING\n");
        return NULL;
    }

    int r, c;
    fscanf(fp, "%d %d", &r, &c);

    Matrix *m = create_matrix(r, c);
    for (int i = 0; i < m->num_rows; i++)
    {
        for (int j = 0; j < m->num_cols; j++)
            fscanf(fp, "%lld", &m->data[i][j]);
    }

    fclose(fp);
    return m;
}

void write_matrix_to_file(Matrix *m, char *filename)
{
    FILE *fp;
    fp = fopen(filename, "w");

    if (m == NULL)
        printf("ERROR: INVALID ARGUMENT\n");

    else
    {
        fprintf(fp, "%d %d\n", m->num_rows, m->num_cols);

        for (int i = 0; i < m->num_rows; i++)
        {
            for (int j = 0; j < m->num_cols; j++)
                fprintf(fp, "%lld ", m->data[i][j]);

            fprintf(fp, "\n");
        }
    }

    fclose(fp);
}