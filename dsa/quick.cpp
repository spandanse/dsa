#include <stdio.h>

// Function to swap two elements
void swap(int a, int b, int arr[]) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

// Function to partition the array and return the pivot index
int partition(int low, int high, int arr[]) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(i, j, arr);
        }
    }
    swap(i + 1, high, arr);
    return (i + 1);
}

// Function to perform Quick Sort
void quickSort(int low, int high, int arr[]) {
    if (low < high) {
        // Partitioning index
        int pi = partition(low, high, arr);

        // Separately sort elements before and after partition
        quickSort(low, pi - 1, arr);
        quickSort(pi + 1, high, arr);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main() {
    int arr[100], n, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array: \n");
    printArray(arr, n);

    quickSort(0, n - 1, arr);

    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

