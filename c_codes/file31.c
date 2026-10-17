
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *tail = NULL;
    struct Node *newNode, *current, *temp;
    int n, i, value, position;

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
                temp = head;
                head = head->next;
                free(temp);
            }
            return 1;
        }

        newNode = malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            while (head != NULL) {
                temp = head;
                head = head->next;
                free(temp);
            }
            return 1;
        }

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else
            tail->next = newNode;

        tail = newNode;
    }

    printf("Enter value to insert: ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid input.\n");
        while (head != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }
        return 1;
    }

    printf("Enter position (1 to %d): ", n + 1);
    if (scanf("%d", &position) != 1 ||
        position < 1 || position > n + 1) {
        printf("Invalid position.\n");
        while (head != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }
        return 1;
    }

    newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        while (head != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }
        return 1;
    }

    newNode->data = value;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        current = head;

        for (i = 1; i < position - 1; i++)
            current = current->next;

        newNode->next = current->next;
        current->next = newNode;
    }

    printf("Updated list: ");
    current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
