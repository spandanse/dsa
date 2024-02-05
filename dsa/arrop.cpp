#include <stdio.h>

#define MAX_SIZE 100

int array[MAX_SIZE];
int size = 0;

void displayArray() {
    if (size == 0) {
        printf("Array is empty\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insertFront(int element) {
    if (size == MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    for (int i = size; i > 0; i--) {
        array[i] = array[i - 1];
    }
    array[0] = element;
    size++;
    printf("Element inserted at the front successfully.\n");
}

void insertEnd(int element) {
    if (size == MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    array[size] = element;
    size++;
    printf("Element inserted at the end successfully.\n");
}

void insertPosition(int element, int position) {
    if (position < 0 || position > size) {
        printf("Invalid position.\n");
        return;
    }
    if (size == MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    for (int i = size; i > position; i--) {
        array[i] = array[i - 1];
    }
    array[position] = element;
    size++;
    printf("Element inserted at position %d successfully.\n", position);
}

void deleteFront() {
    if (size == 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
    printf("Element deleted from the front successfully.\n");
}

void deleteEnd() {
    if (size == 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }
    size--;
    printf("Element deleted from the end successfully.\n");
}

void deletePosition(int position) {
    if (position < 0 || position >= size) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = position; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
    printf("Element deleted from position %d successfully.\n", position);
}

int main() {
    int choice, element, position;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert at specific position\n");
        printf("4. Delete from front\n");
        printf("5. Delete from end\n");
        printf("6. Delete from specific position\n");
        printf("7. Display array\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert at front: ");
                scanf("%d", &element);
                insertFront(element);
                break;
            case 2:
                printf("Enter element to insert at end: ");
                scanf("%d", &element);
                insertEnd(element);
                break;
            case 3:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertPosition(element, position);
                break;
            case 4:
                deleteFront();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deletePosition(position);
                break;
            case 7:
                displayArray();
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 8.\n");
        }
    } while (choice != 8);

    return 0;
}

