#include "lacore.h"

int main(int argc, unsigned char *argv[]) 
{
    int r,c;

    float values[2 * 2] = {2,1.2, 1.2,1};

    // create image
    matrix_t *mat = matrix_create(float, 2, 2, 1, values);
    matrix_t *eigValues = matrix_create(float);
    matrix_t *eigvectors = matrix_create(float);

    // compute the eigenvalues and eigenvectors of input matrix
    eig(mat, eigValues, eigvectors);

    // print input/eigen values
    printf("Input Values:\n");
    for (r = 0; r < rows(mat); r++)
    {
        for (c = 0; c < cols(mat); c++)
        {
            // create color gradient
            printf("%6.2f ", atf(mat, r, c));
        }
        printf("\n");
    }
    printf("----------------------------\n");

    // print eigen values
    printf("Eigen Values:\n");
    if (eigValues != NULL)
    {
        for (r = 0; r < rows(eigValues); r++)
        {
            for (c = 0; c < cols(eigValues); c++)
            {
                // create color gradient
                printf("%6.2f ", atf(eigValues, r, c));
            }
            printf("\n");
        }
        // clean allocated memory
        matrix_free(&eigValues);
    }
    printf("----------------------------\n");

    printf("Eigen Vectors:\n");
    if (eigvectors != NULL)
    {
        // print eigen vectors
        for (r = 0; r < rows(eigvectors); r++)
        {
            for (c = 0; c < cols(eigvectors); c++)
            {
                // create color gradient
                printf("%6.2f ", atf(eigvectors, r, c));
            }
            printf("\n");
        }
        matrix_free(&eigvectors);
    }

    // clean the area allocated by the main
    matrix_free(&mat);

    return 0;
}