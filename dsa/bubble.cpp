#include <stdio.h>

// Function to perform modified bubble sort
void BubbleSort(int arr[], int n) {
    int i, j, t;
    int flag; // Flag to indicate whether any swap occurred in the last pass

    // Traverse through all array elements
    for (i = 0; i < n-1; i++) {
        flag = 0; // Initialize swapped to 0 for each pass

        // Last i elements are already in place, so no need to check them
        for (j = 0; j < n-i-1; j++) {
            // Traverse the array from 0 to n-i-1
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j+1]) {
                t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
                flag = 1; // Set swapped flag to 1 if any swap occurs
            }
        }

        // If no two elements were swapped by the inner loop, then the array is already sorted
        if (flag == 0)
            break;
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
int main() 
{
    int arr[100], n, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array: \n");
    printArray(arr, n);

    BubbleSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

