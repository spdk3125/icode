#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 20
int stack[MAX];
int top = -1;
void push(int x) {
    if (top == MAX - 1) {
printf("Stack overflow\n");
exit(1);}
stack[++top] = x;
}
int pop() {
    if (top == -1) {
printf("Stack underflow\n");
exit(1);
    }
    return stack[top--];
}
int main() {
    char exp[MAX];
    char *e;
    int n1, n2, n3, num;
printf("Enter the expression :: ");
    if (scanf("%s", exp) != 1) {
printf("Invalid input\n");
        return 1;
    }
    e = exp;
    while (*e != '\0') {
        if (isdigit(*e)) {
num = *e - '0';  
            push(num);
        } else {
            if (top < 1) {
printf("Error: Invalid expression\n");
                return 1;
            }
             n1 = pop();
            n2 = pop();
            switch (*e) {
                case '+':
                    n3 = n2 + n1;
                    break;
                case '-':
                    n3 = n2 - n1;
                    break;
                case '*':
                    n3 = n2 * n1;
                    break;
                case '/':
                    if (n1 == 0) {
printf("Error: Division by zero\n");
                        return 1;
                    }
                    n3 = n2 / n1;
                    break;
                default:
printf("Error: Unsupported operator %c\n", *e);
                    return 1;
            }
            push(n3);
        }
        e++;
    }
    if (top != 0) {
printf("Error: The expression is incorrect\n");
        return 1;
    }
printf("\nThe result of the expression %s = %d\n\n", exp, pop());
    return 0;
}

