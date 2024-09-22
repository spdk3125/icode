#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_SIZE 100

// Function to check if a character is an operand
int isOperand(char ch) {
    return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Function to check precedence of operators
int precedence(char ch) {
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

// Function to convert infix expression to postfix
char *infixToPostfix(char *infix) {
    char *postfix = (char *)malloc(sizeof(char) * MAX_SIZE);
    int top = -1, i, j = 0;
    char stack[MAX_SIZE];

    for (i = 0; i < strlen(infix); i++) {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top == -1 && stack[top] != '(') {
                printf("Invalid expression: Mismatched parentheses\n");
                return NULL;
            } else {
                top--;
            }
        } else if (infix[i] != ' ') { // Skip whitespace
            while (top != -1 && precedence(infix[i]) <= precedence(stack[top])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }

    while (top != -1) {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';

    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(char *postfix) {
    int stack[MAX_SIZE], top = -1, i;

    for (i = 0; i < strlen(postfix); i++) {
        if (isOperand(postfix[i])) {
            int num = postfix[i] - '0';
            stack[++top] = num;
        } else {
            int op1 = stack[top--];
            int op2 = stack[top--];
            switch (postfix[i]) {
                case '+':
                    stack[++top] = op1 + op2;
                    break;
                case '-':
                    stack[++top] = op1 - op2;
                    break;
                case '*':
                    stack[++top] = op1 * op2;
                    break;
                case '/':
                    if (op2 == 0) {
                        printf("Error: Division by zero\n");
                        return -1;
                    }
                    stack[++top] = op1 / op2;
                    break;
                case '^':
                    stack[++top] = pow(op1, op2);
                    break;
                default:
                    printf("Invalid operator: %c\n", postfix[i]);
                    return -1;
            }
        }
    }

    return stack[top];
}

int main() {
    char infix[MAX_SIZE];
    int choice;

    do {
        printf("Enter an infix expression: ");
        fgets(infix, MAX_SIZE, stdin);
        infix[strlen(infix) - 1] = '\0';

        char *postfix = infixToPostfix(infix);
        if (postfix != NULL) {
            printf("Postfix expression: %s\n", postfix);
            int result = evaluatePostfix(postfix);
            if (result != -1) {
                printf("Result: %d\n", result);
            }
        }

        printf("Do you want to continue? (1 for yes, 0 for no): ");
        scanf("%d", &choice);
        getchar(); // Consume newline character
    } while (choice == 1);

    return 0;
}