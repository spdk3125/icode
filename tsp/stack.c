#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 100
#define MAX_HISTORY_SIZE 100

typedef struct {
    char url[MAX_URL_LENGTH];
} Page;

typedef struct {
    Page pages[MAX_HISTORY_SIZE];
    int top; 
} Stack;

void initializeStack(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, const char* url) {
    if (s->top < MAX_HISTORY_SIZE - 1) {
        strcpy(s->pages[++s->top].url, url);
    }
}

char* pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->pages[s->top--].url;
    }
    return NULL;
}

int main() {
    Stack backHistory, forwardHistory;
    initializeStack(&backHistory);
    initializeStack(&forwardHistory);

    char input[MAX_URL_LENGTH];
    char* currentUrl = NULL;

    do {
        printf("Enter a URL (or 'exit' to quit): ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        
        push(&backHistory, input);
        currentUrl = input;

        printf("Current page: %s\n", currentUrl);

        
        char action;
        printf("Press 'b' for back, 'f' for forward: ");
        scanf(" %c", &action);

        if (action == 'b') {
            char* prevUrl = pop(&backHistory);
            if (prevUrl) {
                push(&forwardHistory, currentUrl);
                currentUrl = prevUrl;
            } else {
                printf("No previous page.\n");
            }
        } else if (action == 'f') {
            char* nextUrl = pop(&forwardHistory);
            if (nextUrl) {
                push(&backHistory, currentUrl);
                currentUrl = nextUrl;
            } else {
                printf("No forward page.\n");
            }
        }
    } while (1);

    printf("Exiting browser history navigation.\n");

    return 0;
}
