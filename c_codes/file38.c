
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node *insert(struct Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        struct Node *child = insert(root->left, value);
        if (child != NULL) {
            root->left = child;
        }
    } else if (value > root->data) {
        struct Node *child = insert(root->right, value);
        if (child != NULL) {
            root->right = child;
        }
    } else {
        printf("Duplicate value ignored.\n");
    }

    return root;
}

void inorder(struct Node *root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int search(struct Node *root, int key) {
    if (root == NULL) {
        return 0;
    }

    if (root->data == key) {
        return 1;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

void freeTree(struct Node *root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct Node *root = NULL;
    int n, value, key;

    printf("How many values? ");

    if (scanf("%d", &n) != 1 || n < 0 || n > 1000) {
        printf("Invalid number of values.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");

        if (scanf("%d", &value) != 1) {
            printf("Invalid input.\n");
            freeTree(root);
            return 1;
        }

        root = insert(root, value);
    }

    printf("\nInorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Enter value to search: ");

    if (scanf("%d", &key) != 1) {
        printf("Invalid input.\n");
        freeTree(root);
        return 1;
    }

    if (search(root, key)) {
        printf("%d found in the BST.\n", key);
    } else {
        printf("%d not found in the BST.\n", key);
    }

    freeTree(root);
    return 0;
}
