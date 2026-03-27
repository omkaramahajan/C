#include <stdio.h>
#include <math.h>

#define SIZE 10

// Division Method
int divisionMethod(int key) {
    return key % SIZE;
}

// Mid-Square Method
int midSquareMethod(int key) {
    int square = key * key;

    int digits = 0, temp = square;
    while(temp > 0) {
        digits++;
        temp /= 10;
    }

    int mid = digits / 2;
    int divisor = pow(10, mid - 1);

    int middle = (square / divisor) % 100; // extract middle 2 digits
    return middle % SIZE;
}

// Digit Folding Method
int digitFoldingMethod(int key) {
    int sum = 0;
    while(key > 0) {
        sum += key % 100;  // take 2 digits at a time
        key /= 100;
    }
    return sum % SIZE;
}

// Insert with collision check
void insert(int table[], int index, int key) {
    if(table[index] == -1) {
        table[index] = key;
        printf("Key %d inserted at index %d\n", key, index);
    } else {
        printf("Collision occurred for key %d at index %d (already occupied by %d)\n",
               key, index, table[index]);
    }
}

// Display table
void display(int table[]) {
    for(int i = 0; i < SIZE; i++) {
        if(table[i] == -1)
            printf("[%d] -> NULL\n", i);
        else
            printf("[%d] -> %d\n", i, table[i]);
    }
}

int main() {
    int n, keys[100];

    printf("Enter number of values: ");
    scanf("%d", &n);

    printf("Enter %d keys:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }

    // Hash tables
    int divTable[SIZE], midTable[SIZE], foldTable[SIZE];

    // Initialize tables
    for(int i = 0; i < SIZE; i++) {
        divTable[i] = midTable[i] = foldTable[i] = -1;
    }

    // Division Method
    printf("\n--- Division Method ---\n");
    for(int i = 0; i < n; i++) {
        int index = divisionMethod(keys[i]);
        insert(divTable, index, keys[i]);
    }
    printf("Hash Table:\n");
    display(divTable);

    // Mid-Square Method
    printf("\n--- Mid-Square Method ---\n");
    for(int i = 0; i < n; i++) {
        int index = midSquareMethod(keys[i]);
        insert(midTable, index, keys[i]);
    }
    printf("Hash Table:\n");
    display(midTable);

    // Digit Folding Method
    printf("\n--- Digit Folding Method ---\n");
    for(int i = 0; i < n; i++) {
        int index = digitFoldingMethod(keys[i]);
        insert(foldTable, index, keys[i]);
    }
    printf("Hash Table:\n");
    display(foldTable);

    return 0;
}
