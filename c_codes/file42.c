
#include <stdio.h>

#define SIZE 10
#define EMPTY -1

int table[SIZE];

// Initialize hash table
void initialize() {
    for (int i = 0; i < SIZE; i++) {
        table[i] = EMPTY;
    }
}

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert key
void insert(int key) {
    int index = hash(key);

    for (int i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (table[pos] == key) {
            printf("Key already exists.\n");
            return;
        }

        if (table[pos] == EMPTY) {
            table[pos] = key;
            printf("%d inserted at index %d\n", key, pos);
            return;
        }
    }

    printf("Hash table is full!\n");
}

// Search key
void search(int key) {
    int index = hash(key);

    for (int i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (table[pos] == EMPTY) {
            break;
        }

        if (table[pos] == key) {
            printf("Key found at index %d\n", pos);
            return;
        }
    }

    printf("Key not found.\n");
}

// Display table
void display() {
    printf("\nHash Table:\n");

    for (int i = 0; i < SIZE; i++) {
        if (table[i] == EMPTY)
            printf("[%d] : EMPTY\n", i);
        else
            printf("[%d] : %d\n", i, table[i]);
    }
}

int main() {
    int choice, key;

    initialize();

    while (1) {
        printf("\n--- HASH TABLE MENU ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);

                if (key < 0 || key == EMPTY) {
                    printf("Enter a non-negative key.\n");
                } else {
                    insert(key);
                }
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);

                if (key < 0 || key == EMPTY) {
                    printf("Invalid key.\n");
                } else {
                    search(key);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}
