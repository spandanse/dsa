	#include <stdio.h>
	#include <stdlib.h>
	
	// Define a structure for a node in the linked list
	struct Node {
	    int data;
	    struct Node* next;
	};
	
	// Function to create a new node
	struct Node* createNode(int data) {
	    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	    newNode->data = data;
	    newNode->next = NULL;
	    return newNode;
	}
	
	// Function to insert a node at the beginning of the linked list
	void insertAtBeginning(struct Node** headRef, int data) {
	    struct Node* newNode = createNode(data);
	    newNode->next = *headRef;
	    *headRef = newNode;
	}
	
	// Function to insert a node at the end of the linked list
	void insertAtEnd(struct Node** headRef, int data) {
	    struct Node* newNode = createNode(data);
	    if (*headRef == NULL) {
	        *headRef = newNode;
	        return;	
	    }
	    struct Node* temp = *headRef;
	    while (temp->next != NULL)
	        temp = temp->next;
	    temp->next = newNode;
	}
	
	// Function to insert a node at a specified position in the linked list
	void insertAtPosition(struct Node** headRef, int data, int position) {
	    if (position < 1) {
	        printf("Invalid position!\n");
	        return;
	    }
	    if (position == 1) {
	        insertAtBeginning(headRef, data);
	        return;
	    }
	    struct Node* newNode = createNode(data);
	    struct Node* temp = *headRef;
	    for (int i = 1; i < position - 1 && temp != NULL; i++)
	        temp = temp->next;
	    if (temp == NULL) {
	        printf("Invalid position!\n");
	        return;
	    }
	    newNode->next = temp->next;
	    temp->next = newNode;
	}
	
	// Function to delete a node from the beginning of the linked list
	void deleteFromBeginning(struct Node** headRef) {
	    if (*headRef == NULL) {
	        printf("List is empty!\n");
	        return;
	    }
	    struct Node* temp = *headRef;
	    *headRef = (*headRef)->next;
	    free(temp);
	}
	
	// Function to delete a node from the end of the linked list
	void deleteFromEnd(struct Node** headRef) {
	    if (*headRef == NULL) {
	        printf("List is empty!\n");
	        return;
	    }
	    if ((*headRef)->next == NULL) {
	        free(*headRef);
	        *headRef = NULL;
	        return;
	    }
	    struct Node* temp = *headRef;
	    while (temp->next->next != NULL)
	        temp = temp->next;
	    free(temp->next);
	    temp->next = NULL;
	}
	
	// Function to delete a node from a specified position in the linked list
	void deleteFromPosition(struct Node** headRef, int position) {
	    if (*headRef == NULL) {
	        printf("List is empty!\n");
	        return;
	    }
	    if (position < 1) {
	        printf("Invalid position!\n");
	        return;
	    }
	    if (position == 1) {
	        deleteFromBeginning(headRef);
	        return;
	    }
	    struct Node* temp = *headRef;
	    struct Node* prev = NULL;
	    for (int i = 1; i < position && temp != NULL; i++) {
	        prev = temp;
	        temp = temp->next;
	    }
	    if (temp == NULL) {
	        printf("Invalid position!\n");
	        return;
	    }
	    prev->next = temp->next;
	    free(temp);
	}
	
	// Function to display the linked list
	void display(struct Node* head) {
	    struct Node* temp = head;
	    if (temp == NULL) {
	        printf("List is empty!\n");
	        return;
	    }
	    printf("Linked list: ");
	    while (temp != NULL) {
	        printf("%d ", temp->data);
	        temp = temp->next;
	    }
	    printf("\n");
	}
	
	// Function to search for an element in the linked list
	void search(struct Node* head, int key) {
	    struct Node* temp = head;
	    int position = 1;
	    while (temp != NULL && temp->data != key) {
	        temp = temp->next;
	        position++;
	    }
	    if (temp == NULL)
	        printf("%d not found in the list\n", key);
	    else
	        printf("%d found at position %d\n", key, position);
	}
	
	// Main function - menu driven program
	int main() {
	    struct Node* head = NULL;
	    int choice, data, position, key;
	
	    while (1) {
	        printf("\nLinked List Operations:\n");
	        printf("1. Insert at beginning\n");
	        printf("2. Insert at end\n");
	        printf("3. Insert at position\n");
	        printf("4. Delete from beginning\n");
	        printf("5. Delete from end\n");
	        printf("6. Delete from position\n");
	        printf("7. Display\n");
	        printf("8. Search\n");
	        printf("9. Exit\n");
	        printf("Enter your choice: ");
	        scanf("%d", &choice);
	
	        switch (choice) {
	            case 1:
	                printf("Enter data to insert at beginning: ");
	                scanf("%d", &data);
	                insertAtBeginning(&head, data);
	                break;
	            case 2:
	                printf("Enter data to insert at end: ");
	                scanf("%d", &data);
	                insertAtEnd(&head, data);
	                break;
	            case 3:
	                printf("Enter data to insert: ");
	                scanf("%d", &data);
	                printf("Enter position: ");
	                scanf("%d", &position);
	                insertAtPosition(&head, data, position);
	                break;
	            case 4:
	                deleteFromBeginning(&head);
	                break;
	            case 5:
	                deleteFromEnd(&head);
	                break;
	            case 6:
	                printf("Enter position to delete: ");
	                scanf("%d", &position);
	                deleteFromPosition(&head, position);
	                break;
	            case 7:
	                display(head);
	                break;
	            case 8:
	                printf("Enter element to search: ");
	                scanf("%d", &key);
	                search(head, key);
	                break;
	            case 9:
	                exit(0);
	            default:
	                printf("Invalid choice!\n");
	        }
	    }
	
	    return 0;
	}

