#include <stdio.h>
#include <stdbool.h>

#define ROWS 11
#define COLS 3

int hashTable[ROWS][COLS]; // Initialize all elements to 0

int hashFunction(int value) {
    return value % ROWS;
}

void insert(int value) {
    int index = hashFunction(value);
    for (int col = 0; col < COLS; col++) {
        if (hashTable[index][col] == 0) { // Check for 0 instead of -1
            hashTable[index][col] = value;
            printf("Inserted %d at address (%d, %d)\n", value, index, col);
            return;
        }
    }

    // If all slots are full, perform linear probing
    int originalIndex = index;
    int col = 0;
    do {
        index = (index + 1) % ROWS;
        for (col = 0; col < COLS; col++) { // Corrected loop condition
            if (hashTable[index][col] == 0) {
                hashTable[index][col] = value;
                printf("Inserted %d at address (%d, %d)\n", value, index, col);
                return;
            }
        }
    } while (index != originalIndex);

    printf("HashTable is full. Could not insert %d.\n", value);
}

void printHashTable() {
    printf("\nHash Table:\n");
    for (int i = 0; i < ROWS; i++) {
        printf("Index %d:", i);
        for (int j = 0; j < COLS; j++) {
            if (hashTable[i][j] == 0) {
                printf(" %d", -1);
            } else {
                printf(" %d", hashTable[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    // Initialize hashTable to 0
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            hashTable[i][j] = 0;
        }
    }

    int choice, value;
    while (true) {
        printf("\nLinear Probing Hashing Operations:\n");
        printf("1. Insert\n");
        printf("2. Print Hash Table\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printHashTable();
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
