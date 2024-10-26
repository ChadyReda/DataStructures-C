#include <stdio.h>

int main () {
    
    int A[] = {2, 4, 9, 8, 6};

    printf("%d\n", A);
    printf("%d\n", &A[0]);
    printf("%d\n", A[0]);
    printf("%d\n", *A);

    // *A == A[0]
    //  A == &A[0]

    for (int i = 0 ; i < 5 ; i++) {
        printf("%d --> %d\n", &A[i], *&A[i]);
        printf("%d --> %d\n", A + 1, *(A + i));
    }

    int* p = A; 
    int *p = A;
    p++; // Valid
    // A++; Invalid

    return 0;
}