
#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0;
int rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue is full.\n");
    } else {
        queue[++rear] = value;
        printf("%d inserted into queue.\n", value);
    }
}

void dequeue() {
    if (front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Removed element: %d\n", queue[front]);
        front++;
    }
}

void display() {
    int i;

    if (front > rear) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    return 1;
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
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}
