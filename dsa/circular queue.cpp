#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Adjust the size as needed

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Function to add an element to the rear of the queue (enqueue)
void enqueue(int value) {
    if ((rear + 1) % MAX_SIZE == front) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = value;
    printf("Element %d enqueued to the queue\n", value);
}

// Function to remove an element from the front of the queue (dequeue)
void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    int dequeuedElement = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    printf("Element %d dequeued from the queue\n", dequeuedElement);
}

// Function to get the front element of the queue without removing it
void peek() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element of the queue: %d\n", queue[front]);
}

// Function to display the elements of the queue
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    do {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);
    printf("\n");
}

// Main function - menu driven program
int main() {
    int choice, data;

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
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

    return 0;
}

