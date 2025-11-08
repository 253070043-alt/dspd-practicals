#include <stdio.h>
#define SIZE 7
int main() {
    int hashTable[SIZE];
    int i, key, index, n;
    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;
    printf("Enter number of keys to insert: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter key %d: ", i + 1);
        scanf("%d", &key);
        index = key % SIZE;
        while (hashTable[index] != -1) {
            index = (index + 1) % SIZE;
        }
        hashTable[index] = key;
    }
    printf("\nFinal Hash Table:\n");
    for (i = 0; i < SIZE; i++)
        printf("Slot %d -> %d\n", i, hashTable[i]);
    return 0;
}
