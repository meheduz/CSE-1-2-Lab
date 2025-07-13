#include <stdio.h>
#include <stdlib.h>

#define FOUND 1
#define NOT_FOUND 0

// Node structure
typedef struct node {
    int data;               // Holds the value
    struct node *next;      // Points to next node
} NODE;

// Global pointers for the first and last node
NODE *head = NULL;
NODE *tail = NULL;

// Insert a new node at the end
void insert(int value) {
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        // First node in the list
        head = tail = newNode;
    } else {
        // Append at the end
        tail->next = newNode;
        tail = newNode;
    }

    if (newNode != NULL)
        printf("%d Inserted!\n", value);
    else
        printf("Insertion Failed!!!\n");
}

// Delete a node by value
void delete(int value) {
    if (head == NULL) {
        printf("Empty List!\n");
        return;
    }

    // Case: delete from head
    if (head->data == value) {
        NODE *temp = head;
        head = head->next;
        free(temp);
        printf("%d Deleted!\n", value);

        // If list becomes empty, reset tail
        if (head == NULL)
            tail = NULL;
        return;
    }

    // Case: delete from middle or end
    NODE *current = head;
    NODE *previous = NULL;
    int found = NOT_FOUND;

    while (current != NULL) {
        if (current->data == value) {
            found = FOUND;
            if (previous != NULL)
                previous->next = current->next;

            // If deleting last node
            if (current == tail)
                tail = previous;

            free(current);
            break;
        }

        previous = current;
        current = current->next;
    }

    if (found)
        printf("%d Deleted!\n", value);
    else
        printf("%d Not Found to delete!\n", value);
}

// Search for a value in the list
void search(int value) {
    if (head == NULL) {
        printf("Empty List!\n");
        return;
    }

    NODE *current = head;
    int found = NOT_FOUND;

    while (current != NULL) {
        if (current->data == value) {
            found = FOUND;
            break;
        }
        current = current->next;
    }

    if (found)
        printf("%d Found!\n", value);
    else
        printf("%d Not Found!\n", value);
}

// Print all values in the list
void print() {
    if (head == NULL) {
        printf("Nothing to Print!");
    } else {
        printf("Linked List: ");
        NODE *current = head;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
    }
    printf("\n");
}

// Driver code
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