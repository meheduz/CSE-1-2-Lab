#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // First node
    head->data = 10;
    head->prev = NULL;
    head->next = second;

    // Second node
    second->data = 20;
    second->prev = head;
    second->next = third;

    // Third node
    third->data = 30;
    third->prev = second;
    third->next = NULL;

    // Forward print
    printf("Forward: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    // Backward print
    printf("\nBackward: ");
    temp = third;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }

    return 0;
}