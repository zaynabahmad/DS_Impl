#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// Function prototypes
void push(char stack[], int *top, char item);
char pop(char stack[], int *top);
int precedence(char ch);
void infix_to_postfix(char infix[], char postfix[]);

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    // Read infix expression
    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    // Convert infix to postfix
    infix_to_postfix(infix, postfix);

    // Print postfix expression
    printf("Postfix expression: %s", postfix);

    return 0;
}

// Function to push an item onto the stack
void push(char stack[], int *top, char item) {
    if (*top == MAX_SIZE - 1) {
        printf("Error: Stack overflow\n");
        exit(1);
    }
    stack[++(*top)] = item;
}

// Function to pop an item from the stack
char pop(char stack[], int *top) {
    if (*top == -1) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    return stack[(*top)--];
}

// Function to return the precedence of an operator
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

// Function to convert infix expression to postfix
void infix_to_postfix(char infix[], char postfix[]) {
    char stack[MAX_SIZE];
    int top = -1;
    int i, j;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(stack, &top, ch);
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop(stack, &top);
            }
            if (top == -1) {
                printf("Error: Mismatched parentheses\n");
                exit(1);
            }
            pop(stack, &top);  // Discard the '('
        } else {
            while (top != -1 && precedence(ch) <= precedence(stack[top])) {
                postfix[j++] = pop(stack, &top);
            }
            push(stack, &top, ch);
        }
    }

    // Pop any remaining operators from the stack and add to the postfix expression
    while (top != -1) {
        if (stack[top] == '(') {
            printf("Error: Mismatched parentheses\n");
            exit(1);
        }
        postfix[j++] = pop(stack, &top);
    }
    postfix[j] = '\0';
}
