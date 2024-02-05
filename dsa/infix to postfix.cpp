#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // For isalnum()

#define MAX_SIZE 100

// Global variables
char stack[MAX_SIZE];
int top = -1;

// Function to push a character onto the stack
void push(char value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    top++;
    stack[top] = value;
}

// Function to pop a character from the stack
char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Function to get the top element of the stack without removing it
char peek() {
    return stack[top];
}

// Function to check if the stack is empty
int isEmpty() {
    return (top == -1);
}

// Function to check if the given character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to get the precedence of an operator
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {
            push(infix[i]);
            i++;
        } else if (infix[i] == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            if (!isEmpty() && peek() != '(') {
                printf("Invalid expression\n");
                exit(1);
            } else {
                pop(); // Discard '(' from the stack
            }
            i++;
        } else if (isOperator(infix[i])) {
            while (!isEmpty() && precedence(infix[i]) <= precedence(peek())) {
                postfix[j++] = pop();
            }
            push(infix[i]);
            i++;
        } else {
            printf("Invalid character in the expression\n");
            exit(1);
        }
    }

    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

// Main function
int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

