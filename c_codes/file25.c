
#include <stdio.h>
#include <string.h>

int main() {
    char first[100];
    char second[100];

    printf("Enter the first word: ");
    scanf("%99s", first);

    printf("Enter the second word: ");
    scanf("%99s", second);

    if (strcmp(first, second) == 0) {
        printf("Both strings are equal.\n");
    } else {
        printf("The strings are different.\n");
    }

    return 0;
}