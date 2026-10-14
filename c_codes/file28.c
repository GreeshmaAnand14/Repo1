
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *tail = NULL;
    struct Node *newNode;
    struct Node *current;
    int n, i, value;

    printf("Enter number of nodes (1-100): ");

    if (scanf("%d", &n) != 1 || n < 1 || n > 100) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter value: ");

        if (scanf("%d", &value) != 1) {
            printf("Invalid input.\n");
            current = head;
            while (current != NULL) {
                struct Node *temp = current;
                current = current->next;
                free(temp);
            }
            return 1;
        }

        newNode = malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            current = head;
            while (current != NULL) {
                struct Node *temp = current;
                current = current->next;
                free(temp);
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

    printf("Linked list: ");

    current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");

    current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
