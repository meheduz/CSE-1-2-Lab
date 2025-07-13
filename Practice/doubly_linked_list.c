#include <stdio.h>
#include <stdlib.h>

#define FOUND 1
#define NOT_FOUND 0

// Node structure
typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} NODE;

// Global pointers for first and last
NODE *head = NULL, *tail = NULL;

// Insert node at the end
void insert(int value) {
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = value;
    newNode->prev = newNode->next = NULL;

    if (head == NULL) {
        // First node
        head = tail = newNode;
    } else {
        // Append to tail
        tail->next = newNode;
        newNode->prev = tail;
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

    if (head->data == value) {
        // Delete from beginning
        NODE *temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL; // List became empty
        free(temp);
        printf("%d Deleted!\n", value);
    }
    else if (tail->data == value) {
        // Delete from end
        NODE *temp = tail;
        tail = tail->prev;
        if (tail != NULL)
            tail->next = NULL;
        else
            head = NULL;
        free(temp);
        printf("%d Deleted!\n", value);
    }
    else {
        // Delete from middle
        NODE *current = head;
        int found = NOT_FOUND;

        while (current != NULL) {
            if (current->data == value) {
                found = FOUND;
                current->prev->next = current->next;
                current->next->prev = current->prev;
                free(current);
                break;
            }
            current = current->next;
        }

        if (found)
            printf("%d Deleted!\n", value);
        else
            printf("%d Not Found to delete!\n", value);
    }
}

// Forward search
void search_forward(int value) {
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

// Backward search
void search_backward(int value) {
    if (tail == NULL) {
        printf("Empty List!\n");
        return;
    }

    NODE *current = tail;
    int found = NOT_FOUND;

    while (current != NULL) {
        if (current->data == value) {
            found = FOUND;
            break;
        }
        current = current->prev;
    }

    if (found)
        printf("%d Found!\n", value);
    else
        printf("%d Not Found!\n", value);
}

// Print list forward
void print_forward() {
    if (head == NULL) {
        printf("Nothing to Print!");
    } else {
        printf("Forward: ");
        NODE *current = head;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
    }
    printf("\n");
}

// Print list backward
void print_backward() {
    if (tail == NULL) {
        printf("Nothing to Print!");
    } else {
        printf("Backward: ");
        NODE *current = tail;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->prev;
        }
    }
    printf("\n");
}

// Main function
int main() {
    print_forward();
    print_backward();

    delete(2023); // Try to delete non-existing
    search_forward(1971); // Not found

    insert(5);
    insert(15);
    print_forward();
    print_backward();

    insert(56);
    search_backward(15);
    insert(25);
    print_forward();
    print_backward();

    search_forward(1952);
    delete(15);
    print_forward();
    print_backward();

    search_backward(15);
    delete(404);
    print_forward();
    print_backward();

    insert(100);
    print_forward();
    print_backward();

    search_forward(100);
    print_forward();
    print_backward();

    delete(5);
    print_forward();
    print_backward();

    delete(100);
    print_forward();
    print_backward();

    search_backward(25);

    return 0;
}