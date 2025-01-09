#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

// Define the Record structure
typedef struct {
    int id;                 // Integer field for sorting
    char name[20];          // Name field
    float value;            // Value field
} Record;

// Function prototypes
void printRecords(const Record *records, int size);
int compareById(const void *a, const void *b);
int compareByName(const void *a, const void *b);
int compareByValue(const void *a, const void *b);
void sortRecords(Record *records, int size, int (*comparator)(const void *, const void *));

int main() {
    // Dynamically allocate memory for an array of records
    Record *records = malloc(SIZE * sizeof(Record));

    // Initialize records with sample data
    if (records) { // Check if memory allocation was successful
        records[0] = (Record){3, "Alice", 9.5};
        records[1] = (Record){1, "Bob", 5.7};
        records[2] = (Record){4, "Charlie", 8.2};
        records[3] = (Record){2, "David", 6.3};
        records[4] = (Record){5, "Eve", 7.9};

        printf("Before sorting:\n");
        printRecords(records, SIZE);

        // Sort by ID
        printf("\nSorting by ID:\n");
        sortRecords(records, SIZE, compareById);
        printRecords(records, SIZE);

        // Sort by Name
        printf("\nSorting by Name:\n");
        sortRecords(records, SIZE, compareByName);
        printRecords(records, SIZE);

        // Sort by Value
        printf("\nSorting by Value:\n");
        sortRecords(records, SIZE, compareByValue);
        printRecords(records, SIZE);

        // Free dynamically allocated memory
        free(records);
    } else {
        printf("Memory allocation failed!\n");
    }

    return 0;
}

// Function to print an array of records
void printRecords(const Record *records, int size) {
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Name: %s, Value: %.2f\n", records[i].id, records[i].name, records[i].value);
    }
}

// Comparison function to sort by ID
int compareById(const void *a, const void *b) {
    return ((Record *)a)->id - ((Record *)b)->id;
}

// Comparison function to sort by Name (lexicographically)
int compareByName(const void *a, const void *b) {
    return strcmp(((Record *)a)->name, ((Record *)b)->name);
}

// Comparison function to sort by Value
int compareByValue(const void *a, const void *b) {
    if (((Record *)a)->value < ((Record *)b)->value) return -1;
    if (((Record *)a)->value > ((Record *)b)->value) return 1;
    return 0;
}

// Generic sorting function using qsort from the C standard library
void sortRecords(Record *records, int size, int (*comparator)(const void *, const void *)) {
    qsort(records, size, sizeof(Record), comparator);
}
