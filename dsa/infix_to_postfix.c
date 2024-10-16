#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPRESSION_LENGTH 100

char stack[MAX_EXPRESSION_LENGTH];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX_EXPRESSION_LENGTH - 1;
}

char peek() {
    if (isEmpty()) {
        printf("Error: Stack is empty!\n");
        return '\0';
    }
    return stack[top];
}

char pop() {
    if (isEmpty()) {
        printf("Error: Stack is empty!\n");
        return '\0';
    }
    return stack[top--];
}

void push(char oper) {
    if (isFull()) {
        printf("Error: Stack is full!\n");
        return;
    }
    stack[++top] = oper;
}

int checkIfOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

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

void convertInfixToPostfix(char* expression) {
    char postfix[MAX_EXPRESSION_LENGTH];
    int i, j = 0;

    for (i = 0; expression[i]; ++i) {
        if (checkIfOperand(expression[i])) {
            postfix[j++] = expression[i];
        } else if (expression[i] == '(') {
            push(expression[i]);
        } else if (expression[i] == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            if (!isEmpty() && peek() == '(') {
                pop(); // Discard the '('
            } else {
                printf("Error: Mismatched parentheses!\n");
                return;
            }
        } else {
            while (!isEmpty() && precedence(expression[i]) <= precedence(peek())) {
                postfix[j++] = pop();
            }
            push(expression[i]);
        }
    }

    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char expression[MAX_EXPRESSION_LENGTH];

    printf("Enter the infix expression: ");
    fgets(expression, MAX_EXPRESSION_LENGTH, stdin);

    size_t len = strlen(expression);
    if (len > 0 && expression[len - 1] == '\n') {
        expression[len - 1] = '\0';
    }

    convertInfixToPostfix(expression);

    return 0;
}