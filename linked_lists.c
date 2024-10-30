#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void printList (struct Node* p) {
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
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
    //check if the list is empty
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    // temp point to the element that the head points to
    struct Node* temp = *head;
    // prev is initialy equals to null 
    struct Node* prev = NULL;

    // check if the head is the target node
    if (temp != NULL && temp->data == key) {
        // change the value of head to contain the address of the node before the head node
        *head = temp->next;
        // now the first node is considred deleted because its no longer linked
        return;
    }

    // check if the temp data does not equal to the key then
    // move on to the next
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // reaches the final linked list without finding the key
    if (temp == NULL) {
        printf("Key Not FOUND \n");
    }
    
    //if the temp data equals to the key then we break the link between him and the previous 
    //and we create a link between the prev and the list before the temp
    prev->next = temp->next;

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