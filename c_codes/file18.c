
#include <stdio.h>

long long factorial(int n) {
    long long result = 1;
    int i;

    for (i = 1; i <= n; i++) {
        result = result * i;
    }

    return result;
}

int main() {
    int n;

    printf("Enter a number (0 to 20): ");
    scanf("%d", &n);

    if (n < 0 || n > 20) {
        printf("Please enter a number between 0 and 20.\n");
    } else {
        printf("Factorial of %d = %lld\n", n, factorial(n));
    }

    return 0;
}