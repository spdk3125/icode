#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(Queue *queue) {
    return queue->front == -1;
}

int isFull(Queue *queue) {
    return queue->rear == MAX_QUEUE_SIZE - 1;
}

void enqueue(Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->items[queue->rear] = item;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }

    int item = queue->items[queue->front];
    if (queue->front == queue->rear) {
        initializeQueue(queue);
    } else {
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    }

    return item;
}

void displayQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = queue->front; i != queue->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("%d ", queue->items[i]);
    }
    printf("%d\n", queue->items[queue->rear]);
}

int main() {
    Queue printQueue;
    initializeQueue(&printQueue);

    int documentId;
    char choice;

    do {
        printf("Enter document ID: ");
        scanf("%d", &documentId);
        enqueue(&printQueue, documentId);

        printf("Do you want to enter another document? (y/n): ");
        scanf(" %c", &choice); // Note the space before %c to consume any newline characters

    } while (choice == 'y' || choice == 'Y');

    // Simulate printing
    while (!isEmpty(&printQueue)) {
        int printedDocument = dequeue(&printQueue);
        printf("Printing document %d\n", printedDocument);
        // Simulate printing time (e.g., sleep for a few seconds)
    }

    return 0;
}
