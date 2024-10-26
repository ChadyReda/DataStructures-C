#include <stdio.h>
#include <stdlib.h>


int main () {

    // method 1 
    // can be changed only in compile time

    int A[2][3] = {
        {0, 1, 3},
        {2, 4, 6}
    };

    printf("Static Array: \n");


    for (int i = 0; i < 2; i++) {
        for (int e = 0; e < 3; e++) {
            printf("%d ", A[i][e]);
        }
        printf("\n");
    }

    // method 2 
    // we know the numbers of rows but not the columns in compile time
    
    int* B[3];
    int n;
    printf("Enter number of columns: ");
    scanf("%d", &n);

    B[0] = (int*) malloc(n * sizeof(int));
    B[1] = (int*) malloc(n * sizeof(int));
    B[2] = (int*) malloc(n * sizeof(int));
    B[0][0] = 1;

    for (int i = 0 ; i < 3 ; i++) {
        for (int e = 0 ; e < n ; e++) {
            printf("%d ", B[i][e]);
        }
        printf("\n");
    }
    
    // method 3
    // we use this method when we dont know nether the number of rows or columns

    int** C;
    int x;
    int y;
    
    printf("Enter Rows and Columns: \n");
    scanf("%d", &x);
    scanf("%d", &y);

    C = (int**) malloc(x * sizeof(int*));
    C[0] = (int*) malloc(y * sizeof(int));
    C[1] = (int*) malloc(y * sizeof(int));
    C[2] = (int*) malloc(y * sizeof(int));

    printf("Enter Matrix Elements: \n");
    for (int i = 0; i < x; i++) {
        for (int j = 0 ; j < y; j++) {
            printf("Enter Element A[%d][%d]: ", i , j);
            scanf("%d", &C[i][j]);
        }
        printf("\n");
    }

    printf("You Entred: \n");

    for (int i = 0 ; i < x ; i++) {
        for (int j = 0; j < y; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Freeing allocated memory
    for (int i = 0; i < x; i++) {
        free(C[i]);
    }


    return 0;
}