#include <stdio.h>
#define SIZE 5

void enQueue(int);
void deQueue();
void display();

int items[SIZE], head = -1, tail = -1;

int main() {
    int ch,item;
do {
    printf("\nStack Operations:\n");
    printf("1. enQueue\n");
    printf("2. deQueue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch (ch) {
      case 1:
        printf("Enter the item to enQueue: ");
        scanf("%d", &item);
        enQueue(item);
        break;
      case 2:
        deQueue();
        break;
      case 3:
        display();
        break;
      case 4:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice, please try again.\n");
    }
  } while (ch != 4);

  return 0;
}

void enQueue(int value) {
    if (tail == SIZE - 1)
        printf("\nCannot insert element; the queue is already full.");
    else {
        if (head == -1)
            head = 0;
        tail++;
        items[tail] = value;
        printf("\nInserted -> %d", value);
    }
}

void deQueue() {
    if (head == -1)
        printf("\nCannot dequeue; the queue is empty.");
    else {
        printf("\nDeleted: %d", items[head]);
        head++;
        if (head > tail)
            head = tail = -1;
    }
}


void display() {
    if (tail == -1)
        printf("\nQueue is empty!");
    else {
        printf("\nQueue elements are:\n");
        for (int i = head; i <= tail; i++)
            printf("%d  ", items[i]);
    }
    printf("\n");
}
