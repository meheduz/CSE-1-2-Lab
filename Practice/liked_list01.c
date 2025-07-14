#include <stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node *head = NULL, *tail= NULL;

int main(){
    // Create a new node
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = 5;
    newNode->next = NULL;

    // Insert the new node at the end of the list
    if(head == NULL){
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    // Print the linked list
    Node *current = head;
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }

    // delete node from the list

    if(head != NULL){
        Node *temp = head;
        head = head->next;
        free(temp);
    }
    // Print the linked list after deletion
    current = head;
    if(current == NULL) {
        printf("List is empty\n");
    } else {
        while(current != NULL){
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }

    return 0;
}