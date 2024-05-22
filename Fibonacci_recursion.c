#include <stdio.h>

// Function to compute the nth Fibonacci number using recursion
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int terms, i;

    // Prompt the user to enter the number of terms
    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    // Print the Fibonacci series
    printf("Fibonacci Series: ");
    for (i = 0; i < terms; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}
