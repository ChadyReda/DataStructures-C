#include <iostream>
#include <cstdlib> // for malloc
using namespace std;

// LIFO - last in first out

struct Stack {
    int capacity;
    int top;
    int* S;
};

bool isEmpty (struct Stack st) {
    return st.top == -1;
}

bool isFull (struct Stack st) {
    return st.top == st.capacity -1;
}

void createStack(struct Stack* st, int capacity) {
    st->capacity = capacity;
    st->top = -1;
    st->S = (int*) malloc(capacity * sizeof(int));
}

void appendToStack(struct Stack* st, int Element) {
    if (!isFull(*st)) {
        st->top++;
        st->S[st->top] = Element;
    } else {
        cout << "Stack overflow" << endl;
    }
}

int popFromStack(struct Stack* st) {
    if (isEmpty(*st)) {
        cout << "Stack underflow" << endl;
        return -1;
    }
    else {
        int value = st->S[st->top];
        st->top--;
        return value;
    }
}

void displayStack(struct Stack* st) {
    
    if (isEmpty(*st)) {
        cout << "Stack is empty" << endl;
        return;
    }

    for (int i = st->top; i >= 0; i--) {
        cout << st->S[i] << " ";
    }
    
    cout << endl;
}


int main () {
    struct Stack newStack;
    createStack(&newStack, 5);
    appendToStack(&newStack, 10);
    appendToStack(&newStack, 20);
    appendToStack(&newStack, 30);
    displayStack(&newStack);
    popFromStack(&newStack);
    displayStack(&newStack);
    free(newStack.S);
    return 0;
}