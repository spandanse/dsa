#include <stdio.h>

// Function to perform selection sort
void selectionSort(int arr[], int n) 
{
    int i, j, min;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in unsorted array
        min = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;

        // Swap the found minimum element with the first element
        int t = arr[min];
        arr[min] = arr[i];
        arr[i] = t;
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main() {
    int arr[100], n, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array: \n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

