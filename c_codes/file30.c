
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *tail = NULL;
    struct Node *current;
    struct Node *previous;
    struct Node *newNode;
    int n, value, i, found = 0;

    printf("Enter number of nodes (0-100): ");

    if (scanf("%d", &n) != 1 || n < 0 || n > 100) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter value: ");

        if (scanf("%d", &value) != 1) {
            printf("Invalid input.\n");
            while (head != NULL) {
                current = head;
                head = head->next;
                free(current);
            }
            return 1;
        }

        newNode = malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            while (head != NULL) {
                current = head;
                head = head->next;
                free(current);
            }
            return 1;
        }

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        }

        tail = newNode;
    }

    printf("Enter value to delete: ");

    if (scanf("%d", &value) != 1) {
        printf("Invalid input.\n");
        while (head != NULL) {
            current = head;
            head = head->next;
            free(current);
        }
        return 1;
    }

    current = head;
    previous = NULL;

    while (current != NULL) {
        if (current->data == value) {
            found = 1;

            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }

            free(current);
            break;
        }

        previous = current;
        current = current->next;
    }

    if (!found) {
        printf("Value not found.\n");
    }

    printf("Updated list: ");

    current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    while (head != NULL) {
        current = head;
        head = head->next;
        free(current);
    }

    return 0;
}
