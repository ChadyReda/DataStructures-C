#include <stdlib.h>
#include <stdio.h>

typedef struct Matrix {
    int A[10];
    int n; //size
} Matrix;



// this function will save up to 60% of memory to store a diagonal matrice
void set(Matrix* m, int i, int j, int x) {
    if (i == j) {
        m->A[i] = x;
    }
}

//transfer array into a diagonal matrice
int get(Matrix* m, int i, int j) {
    if (i == j) {
        return m->A[i];
    }
    return 0;
}

void display_Matrix(Matrix* m) {
    int i, j;
    for (i = 0; i < m->n; i++) {
        for (j = 0; j < m->n; j++) {
            if (i == j) {
                printf("%d", m->A[i]);
            } else {
                printf("%d", 0);
            }
        }
        printf("\n");
    }
}

int main () {
    // diagonal matrices
    Matrix m;
    m.n = 4;
    set(&m, 1, 1, 3);
    set(&m, 2, 2, 9);
    set(&m, 3, 3, 1);
    set(&m, 4, 4, 6);
    display_Matrix(&m);
    return 0;
}