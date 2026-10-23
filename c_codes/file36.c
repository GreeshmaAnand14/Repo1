
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *last = NULL;

void insert(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;

    if (last == NULL) {
        newNode->next = newNode;
        last = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    printf("%d inserted.\n", value);
}

void display() {
    if (last == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *head = last->next;
    struct Node *temp = head;

    printf("Circular list: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

void clearList() {
    if (last == NULL) {
        return;
    }

    struct Node *head = last->next;
    last->next = NULL;

    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    last = NULL;
}

int main() {
    int choice, value;

    do {
        printf("\n1. Insert\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");

                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    clearList();
                    return 0;
                }

                insert(value);
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 3);

    clearList();

    return 0;
}
