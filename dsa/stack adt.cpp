#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        //return;
    }
    top++;
    stack[top] = value;
    printf("Element %d pushed onto the stack\n", value);
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        //return;
    }
    int value = stack[top];
    top--;
    printf("Element %d popped from the stack\n", value);
}

// Function to get the top element of the stack without removing it
void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        //return;
    }
    printf("Top element of the stack: %d\n", stack[top]);
}

// Function to display the elements of the stack
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        //return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// Main function - menu driven program
int main() {
    int choice, data;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push onto the stack: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

   // return 0;
}

