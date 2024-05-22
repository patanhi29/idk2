#include <stdio.h>

// Recursive Fibonacci function
int fibonacciRecursive(int n) {
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Iterative Fibonacci function
int fibonacciIterative(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    int prev = 0, curr = 1;
    for (int i = 2; i <= n; ++i) {
        int next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Displaying Fibonacci series using recursion
    printf("Fibonacci Series (Recursive):");
    for (int i = 0; i < n; ++i) {
        printf(" %d", fibonacciRecursive(i));
    }
    printf("\n");

    // Displaying Fibonacci series using iteration
    printf("Fibonacci Series (Iterative):");
    for (int i = 0; i < n; ++i) {
        printf(" %d", fibonacciIterative(i));
    }
    printf("\n");

    return 0;
}

