#include <stdio.h>
#define Max_Size 101

int A[Max_Size];
int top = -1;

void push(int x) {
    if (top == Max_Size - 1) {
        printf("Error: stack overflow\n");
        return;
    }
    A[++top] = x;
}

void pop() {
    if (top == -1) {
        printf("Error: stack underflow\n");
        return;
    }
    top--;
}

int Top() {
    return A[top];
}

int Print() {
    for(int i = 0; i <= top; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main () {
    push(8);
    push(6);
    Print();
    pop();
    Print();
}