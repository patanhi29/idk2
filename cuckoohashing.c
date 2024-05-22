#include <stdio.h>
#include <stdlib.h>
#define SIZE 11

// Function pointer type for hash functions
typedef int (*HashFunction)(int);

// Structure representing a hash table
typedef struct {
    int *table1;
    int *table2;
    int size;
    HashFunction hash1;
    HashFunction hash2;
} CuckooHashTable;

// Function prototypes
int hash1(int key);
int hash2(int key);
CuckooHashTable *createHashTable(int size, HashFunction hash1, HashFunction hash2);
void destroyHashTable(CuckooHashTable *hashTable);
int insert(CuckooHashTable *hashTable, int key);
int lookup(CuckooHashTable *hashTable, int key);
void rehash(CuckooHashTable *hashTable, int *keys, int numKeys);
void printHashTable(CuckooHashTable *hashTable);

// Custom hash functions
int customHash1(int key);
int customHash2(int key);

int main() {
    int numKeys;
    printf("Enter the number of keys: ");
    scanf("%d", &numKeys);

    // Create hash table with custom hash functions
    CuckooHashTable *hashTable = createHashTable(SIZE, customHash1, customHash2);
    int keys[numKeys];

    printf("Enter the keys:\n");
    for (int i = 0; i < numKeys; i++) {
        scanf("%d", &keys[i]);
    }

    // Insert keys into the hash table
    for (int i = 0; i < numKeys; i++) {
        if (!insert(hashTable, keys[i])) {
            printf("Failed to insert key: %d\n", keys[i]);
        }
    }

    // Print the contents of the hash table

    printHashTable(hashTable);



    // Check if keys are present in the hash table

    // Clean up
    destroyHashTable(hashTable);

    return 0;
}

// Hash function 1
int hash1(int key) {
    return key % SIZE;
}

// Hash function 2
int hash2(int key) {
    return (key / SIZE) % SIZE;
}

// Create a new hash table
CuckooHashTable *createHashTable(int size, HashFunction hash1, HashFunction hash2) {
    CuckooHashTable *hashTable = (CuckooHashTable *)malloc(sizeof(CuckooHashTable));
    hashTable->table1 = (int *)calloc(size, sizeof(int));
    hashTable->table2 = (int *)calloc(size, sizeof(int));
    hashTable->size = size;
    hashTable->hash1 = hash1;
    hashTable->hash2 = hash2;
    return hashTable;
}

// Destroy a hash table and free memory
void destroyHashTable(CuckooHashTable *hashTable) {
    free(hashTable->table1);
    free(hashTable->table2);
    free(hashTable);
}

// Insert a key into the hash table
int insert(CuckooHashTable *hashTable, int key) {
    if (lookup(hashTable, key)) {
        return 0; // Key already exists
    }

    int index = hashTable->hash1(key);
    if (hashTable->table1[index] == 0) {
        hashTable->table1[index] = key;
        return 1; // Insert successful
    }

    int evictedKey = hashTable->table1[index];
    hashTable->table1[index] = key;

    // Move the evicted key to the other table
    index = hashTable->hash2(evictedKey);
    if (hashTable->table2[index] == 0) {
        hashTable->table2[index] = evictedKey;
        return 1; // Insert successful
    }

    // Rehash if insertion into the second table fails
    rehash(hashTable, &evictedKey, 1);
    return insert(hashTable, evictedKey);
}

// Look up a key in the hash table
int lookup(CuckooHashTable *hashTable, int key) {
    int index1 = hashTable->hash1(key);
    int index2 = hashTable->hash2(key);
    return hashTable->table1[index1] == key || hashTable->table2[index2] == key;
}

// Rehash function
void rehash(CuckooHashTable *hashTable, int *keys, int numKeys) {
    // Double the size of the hash tables
    int newSize = hashTable->size * 2;
    hashTable->table1 = (int *)realloc(hashTable->table1, newSize * sizeof(int));
    hashTable->table2 = (int *)realloc(hashTable->table2, newSize * sizeof(int));
    for (int i = 0; i < numKeys; i++) {
        insert(hashTable, keys[i]);
    }
}

// Custom hash function 1
int customHash1(int key) {
    // Implement your custom hash function here
    // For example:
    // return key % SIZE;
    return key % 11;
}

// Custom hash function 2
int customHash2(int key) {
    // Implement your custom hash function here
    // For example:
    // return (key / SIZE) % SIZE;
    return (key / 11) % 11;
}

// Print the contents of the hash table
void printHashTable(CuckooHashTable *hashTable) {
    printf("Index\tTable 1\tTable 2\n");
    for (int i = 0; i < hashTable->size; i++) {
        printf("%d\t%d\t%d\n", i, hashTable->table1[i], hashTable->table2[i]);
    }
}

