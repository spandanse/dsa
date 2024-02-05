#include <stdio.h>

// Function to perform linear search and print the result
void linearSearch(int arr[], int n, int key) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element %d found at index %d\n", key, i);
            found = 1;
            break; // Exit loop once element is found
        }
    }
    if (!found)
        printf("Element %d not found in the array\n", key);
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter the key to search for: ");
    scanf("%d", &key);

    linearSearch(arr, n, key);

    return 0;
}

