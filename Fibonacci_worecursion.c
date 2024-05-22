#include <stdio.h>

void printFibonacci(int n) {
    int t1 = 0, t2 = 1, nextTerm;

    printf("Fibonacci Series: %d, %d", t1, t2);

    for (int i = 1; i <= n-2; ++i) { // We already printed the first two terms
        nextTerm = t1 + t2;
        printf(", %d", nextTerm);
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Please enter a positive integer greater than 0.\n");
    } else if (n == 1) {
        printf("Fibonacci Series: 0\n");
    } else if (n == 2) {
        printf("Fibonacci Series: 0, 1\n");
    } else {
        printFibonacci(n);
    }

    return 0;
}
