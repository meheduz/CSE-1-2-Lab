#include <stdio.h>
#include <stdlib.h>

#define FOUND 1
#define NOT_FOUND 0

// Node structure
typedef struct node {
    int data;
    struct node *next;
} Node;

// Global pointers to manage the circular linked list
Node *head = NULL;
Node *tail = NULL;

// Insert a node at the end
void insert(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory Allocation Failed!\n");
        return;
    }

    newNode->data = value;

    if (head == NULL) {
        head = tail = newNode;
        newNode->next = newNode;  // Point to self for circular behavior
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }

    printf("%d Inserted!\n", value);
}

// Delete a node by value
void delete(int value) {
    if (head == NULL) {
        printf("Empty List!\n");
        return;
    }

    Node *current = head;
    Node *previous = tail;
    int found = NOT_FOUND;

    // Only one node
    if (head == tail && head->data == value) {
        free(head);
        head = tail = NULL;
        printf("%d Deleted!\n", value);
        return;
    }

    // Traverse and find
    do {
        if (current->data == value) {
            found = FOUND;

            if (current == head) {
                head = head->next;
                tail->next = head;
            } else if (current == tail) {
                tail = previous;
                tail->next = head;
            } else {
                previous->next = current->next;
            }

            free(current);
            printf("%d Deleted!\n", value);
            return;
        }

        previous = current;
        current = current->next;
    } while (current != head);

    if (!found)
        printf("%d Not Found to delete!\n", value);
}

// Search a node by value
void search(int value) {
    if (head == NULL) {
        printf("Empty List!\n");
        return;
    }

    Node *current = head;
    int found = NOT_FOUND;

    do {
        if (current->data == value) {
            found = FOUND;
            break;
        }
        current = current->next;
    } while (current != head);

    if (found)
        printf("%d Found!\n", value);
    else
        printf("%d Not Found!\n", value);
}

// Print the list
void print() {
    if (head == NULL) {
        printf("Nothing to Print!\n");
        return;
    }

    printf("Linked List: ");
    Node *current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// Main function to test the code
int main() {
    print();
    delete(2023);
    search(1971);

    insert(5);
    insert(15);
    print();

    insert(56);
    search(15);

    insert(25);
    print();

    search(1952);
    delete(15);
    print();

    search(15);
    delete(404);
    print();

    insert(100);
    print();

    search(100);
    print();

    delete(5);
    print();

    delete(100);
    print();

    return 0;
}