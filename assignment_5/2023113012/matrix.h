typedef struct Matrix
{
    int num_rows;
    int num_cols;
    long long int **data;
} Matrix;

Matrix *create_matrix(int r, int c);

void destroy_matrix(Matrix *m);

Matrix *add_matrix(Matrix *A, Matrix *B);

Matrix *mult_matrix(Matrix *A, Matrix *B);

Matrix *scalar_mult_matrix(long long int s, Matrix *M);

Matrix *transpose_matrix(Matrix *A);

bool is_square_matrix(Matrix *m);//To check if determinant operation is possible or not

long long int determinant(Matrix *M);

void print_matrix(Matrix *m);

Matrix *read_matrix_from_file(char *filename);

void write_matrix_to_file(Matrix *m, char *filename);