#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void printList (struct Node* p) {
    while (p != NULL) {
        printf("%d -> ", (*p).data);
        p = (*p).next;
    }
    printf("Null Pointer \n");
};

void insertAtFront(struct Node** head, int newData) {
    // Allocate memory for new node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    
    // Set the data and next pointer
    (*newNode).data = newData;
    (*newNode).next = *head;
    
    // changing the adress that the head holds to the newNode address
    *head = newNode;
};

int sumList(struct Node* p) {
    int sum = 0;
    while ( p != NULL) {
        sum += (*p).data;
        p = (*p).next;
    }
    return sum;
}

void deleteNode (struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp != NULL && (*temp).data == key) {
        *head = (*temp).next;
        //delete the temp node
        return;
    }

    while (temp != NULL && (*temp).data != key) {
        prev = temp;
        temp = (*temp).next;
    }

    if (temp == NULL) {
        printf("Key Not FOUND \n");
    }
    
    (*prev).next = (*temp).next;

}


int main () {
    struct Node* head = NULL;
    insertAtFront(&head, 10);
    insertAtFront(&head, 20);
    insertAtFront(&head, 30);
    deleteNode(&head, 30);
    printList(head);
    int sum = sumList(head);
    printf("%d", sum);
    return 0;
}