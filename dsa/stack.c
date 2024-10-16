#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int count = 0;

struct stack {
  int items[MAX];
  int top;
};
typedef struct stack st;

void createEmptyStack(st *s) {
  s->top = -1;
}

int isfull(st *s) {
  return s->top == MAX - 1;
}

int isempty(st *s) {
  return s->top == -1;
}

void push(st *s, int newitem) {
  if (isfull(s)) {
    printf("STACK FULL\n");
  } else {
    s->top++;
    s->items[s->top] = newitem;
    count++;
  }
}

void pop(st *s) {
  if (isempty(s)) {
    printf("\nSTACK EMPTY\n");
  } else {
    printf("Item popped = %d\n", s->items[s->top]);
    s->top--;
    count--;
  }
}

void peek(st *s) {
  if (isempty(s)) {
  printf("\nSTACK EMPTY\n");
  } else {
    printf("%d",s->items[s->top]);
  }
  
}

int size(st *s) {
  return s->top + 1;
}

void printStack(st *s) {
  printf("Stack: ");
  for (int i = 0; i <= s->top; i++) {
    printf("%d ", s->items[i]);
  }
  printf("\n");
}

int main() {
  int ch, item;
  st *s = (st *)malloc(sizeof(st));

  createEmptyStack(s);

  do {
    printf("\nStack Operations:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Size\n");
    printf("5. Print Stack\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch (ch) {
      case 1:
        printf("Enter the item to push: ");
        scanf("%d", &item);
        push(s, item);
        break;
      case 2:
        pop(s);
        break;
      case 3:
        peek(s);
        break;
      case 4:
        printf("Stack size: %d\n", size(s));
        break;
      case 5:
        printStack(s);
        break;
      case 6:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice, please try again.\n");
    }
  } while (ch != 6);

  free(s); 
  return 0;
}

