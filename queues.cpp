#include <iostream>
#include <cstdlib>
using namespace std;

// FIFO - first in first out
// the first element in the queue is the only element that have permission to leave or be deleted

struct Queue {
    int size;
    int front;
    int rear;
    int* Q;
};

bool isFull (struct Queue q) {
    return q.rear == q.size - 1;
} 

bool isEmpty (struct Queue q) {
    return q.rear == -1 || q.rear == q.front;
}

void createQueue (struct Queue* q, int size) {
    q->front = -1;
    q->rear = -1;
    q->Q = (int*) malloc(size * sizeof(int));
}

void enqueue (struct Queue* q, int value) {
    if (isFull(*q)) {
        cout << "Queue is Full" << endl;
        return;
    }    
    q->rear++;
    q->Q[q->rear] = value;
}

int dequeue (struct Queue* q) {
    if (isEmpty(*q)) {
        cout << "Queue is Empty" << endl;
        return - 1;
    }
    q->front++;
    int value = q->Q[q->front];
    return value;
}

void showElements(struct Queue* q) {
    if (isEmpty(*q)) {
        cout << "Queue is Empty" << endl;
        return;
    }
    for (int i = (q->front + 1); i <= q->rear; i++) {
        cout << q->Q[i] << " - ";
    }
    cout << endl;
}


int main () {
    return 0;
}