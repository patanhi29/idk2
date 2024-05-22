//merge sort
tc : o(nlogn)
sc : o(n)
#include <stdio.h>
#include <stdlib.h>
void Merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int size1 = mid - left + 1;
    int size2 = right - mid;
 int Left[size1], Right[size2];
   for (i = 0; i < size1; i++)
        Left[i] = arr[left + i];
 for (j = 0; j < size2; j++)
        Right[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < size1 && j < size2) {
        if (Left[i] <= Right[j]) {
            arr[k] = Left[i];
            i++;
        } else {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        arr[k] = Left[i];
        i++;
        k++;
    }

    while (j < size2) {
        arr[k] = Right[j];
        j++;
        k++;
    }
}

void Merge_Sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        Merge_Sort(arr, left, mid);
        Merge_Sort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

void displayArray(int arr[], int size) {
    printf("The array is: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void displaySortedArray(int arr[], int size) {
    Merge_Sort(arr, 0, size - 1);
    printf("The sorted array is: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Display given array\n");
        printf("2. Display sorted array\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayArray(arr, size);
                break;
            case 2:
                displaySortedArray(arr, size);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
