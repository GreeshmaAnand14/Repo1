
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *current;
    int n, i, value;

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
        newNode->next = head;
        head = newNode;
    }

    printf("Enter value to insert at the beginning: ");
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
    newNode->next = head;
    head = newNode;

    printf("Updated linked list: ");
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
