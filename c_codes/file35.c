
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted into queue.\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node *temp = front;

    printf("Removed: %d\n", temp->data);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

void display() {
    struct Node *temp = front;

    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue (front to rear): ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void clearQueue() {
    while (front != NULL) {
        struct Node *temp = front;
        front = front->next;
        free(temp);
    }

    rear = NULL;
}

int main() {
    int choice, value;

    do {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
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
                    clearQueue();
                    return 0;
                }

                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    clearQueue();

    return 0;
}
