#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
typedef struct {
    char stk[MAX];
    int top;
} Stack;
void initStack(Stack* s) {
    s->top = -1;
}
int isFull(Stack* s) {
    return s->top == (MAX - 1);
}
int isEmpty(Stack* s) {
    return s->top == -1;
}
void push(Stack* s, char item) {
    if (isFull(s)) {
        printf("Stack is Full\n");
    } else {
        s->stk[++s->top] = item;
    }
}
char pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is Empty\n");
        return '\0'; 
    } else {
        return s->stk[s->top--];
    }
}
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}
int isBalanced(char* exp) {
    Stack s;
    initStack(&s);
    int i;
    for ( i = 0; i<strlen(exp); i++) {
        char ch = exp[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            push(&s, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (isEmpty(&s) || !isMatchingPair(pop(&s), ch)) {
                return 0; 
            }
        }
    }
   return isEmpty(&s); 
}
int main() {
    char exp[MAX];
    printf("\n. Enter a string:");
    scanf("%s", exp);
    if (isBalanced(exp)) {
        printf("\n. All Parentheses matched\n");
    } else {
        printf("\n. Parentheses mismatch!\n");
    }
}

