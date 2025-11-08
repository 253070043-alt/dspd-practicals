#include <stdio.h>
int findkey(int arr[], int key, int n) {
    int s = 0;
    int e = n - 1; 
    int m;
    int i;
    while (s <= e) {
        printf("Printing the search space: ");
        for (i = s; i <= e; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        m = (s + e) / 2;

        if (arr[m] == key) { 
            return m;
        } else if (arr[m] < key) {
            s = m + 1;
        } else {
            e = m - 1;
        }
    }
    return -1; 
}
int main() {
    int arr[100];
    int n;
    int i;
    int key, result;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter the elements of array (in sorted order):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]); 
    }
    printf("Enter the key to search: ");
    scanf("%d", &key);
    result = findkey(arr, key, n);
    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found in the array\n", key);
    }
    return 0;
}
