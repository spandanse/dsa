	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h> // For isdigit()
	
	#define MAX_SIZE 100
	
	// Global variables
	int stack[MAX_SIZE];
	int top = -1;
	
	// Function to push an integer onto the stack
	void push(int value) {
	    if (top == MAX_SIZE - 1) {
	        printf("Stack overflow\n");
	        exit(1);
	    }
	    top++;
	    stack[top] = value;
	}
	
	// Function to pop an integer from the stack
	int pop() {
	    if (top == -1) {
	        printf("Stack underflow\n");
	        exit(1);
	    }
	    return stack[top--];
	}
	
	// Function to evaluate exponentiation
	int power(int base, int exponent) {
	    int result = 1;
	    for (int i = 0; i < exponent; i++) {
	        result *= base;
	    }
	    return result;
	}
	
	// Function to evaluate a postfix expression
	int evaluatePostfix(char postfix[]) {
	    int i = 0;
	
	    while (postfix[i] != '\0') {
	        if (isdigit(postfix[i])) {
	            push(postfix[i] - '0'); // Convert char to int and push to stack
	        } else {
	            int operand2 = pop();
	            int operand1 = pop();
	            switch (postfix[i]) {
	                case '+':
	                    push(operand1 + operand2);
	                    break;
	                case '-':
	                    push(operand1 - operand2);
	                    break;
	                case '*':
	                    push(operand1 * operand2);
	                    break;
	                case '/':
	                    if (operand2 == 0) {
	                        printf("Division by zero error\n");
	                        exit(1);
	                    }
	                    push(operand1 / operand2);
	                    break;
	                case '^':
	                    push(power(operand1, operand2));
	                    break;
	                default:
	                    printf("Invalid operator\n");
	                    exit(1);
	            }
	        }
	        i++;
	    }
	
	    return pop();
	}
	
	// Main function
	int main() {
	    char postfix[MAX_SIZE];
	
	    printf("Enter postfix expression: ");
	    scanf("%s", postfix);
	
	    int result = evaluatePostfix(postfix);
	
	    printf("Result: %d\n", result);
	
	    return 0;
	}

