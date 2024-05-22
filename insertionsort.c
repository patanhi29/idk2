// tc :
// Best :O(n)
// Average: O(n^2)
// Worst: O(n^2)

// sc : O(1)

#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i;

    // Prompt user to enter the number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Prompt user to enter the elements of the array
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the array before sorting
    printf("Array before sorting: ");
    printArray(arr, n);

    // Perform insertion sort
    insertionSort(arr, n);

    // Print the array after sorting
    printf("Array after sorting: ");
    printArray(arr, n);

    return 0;
}
