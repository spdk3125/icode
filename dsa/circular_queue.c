#include<stdio.h>
#include<stdlib.h>
struct queue {
    int data;
    struct queue* next;
};
struct queue* front, *rear;
void enqueue(int x) {
    struct queue* NN;
    NN = (struct queue*)malloc(sizeof(struct queue));
    NN->data = x;
    NN->next = NULL;
    if (front == NULL && rear == NULL)
        front = rear = NN;
    else {
        rear->next = NN;
        rear = NN;
    }
}
void dequeue() {
    int x;
    struct queue* temp;
    if (front == NULL && rear == NULL)
printf("The queue is underflow\n");
    else {
        x = front->data;
        temp = front;
        if (front == rear)
            front = rear = NULL;
else
            front = front->next;
        free(temp);
printf("The dequeued value is %d\n", x);
  }
}
void display(struct queue* front) {
printf("Queue elements: ");
    while (front != NULL) {
printf("%d ", front->data);
        front = front->next;
    }
printf("\n");
}
int main() {
    front = rear = NULL;
    int choice, x;
    while (1) {
printf("1. Enqueue\n");
printf("2. Dequeue\n");
printf("3. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
        switch (choice) {
            case 1:
printf("Enter element to enqueue: ");
scanf("%d", &x);
                enqueue(x);
                display(front);
                break;
            case 2:
dequeue();
                display(front);
                break;
            case 3:
exit(0);
        }
    }
    return 0;
}
