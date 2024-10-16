#include <stdio.h>
#include <stdlib.h>
#define MAX 100  
int heap[MAX];
int heapSize = 0;
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void heapifyUp(int index) {
    int parent = (index - 1) / 2;
    if (index && heap[parent] > heap[index]) {
        swap(&heap[parent], &heap[index]);
        heapifyUp(parent);
    }}
void heapifyDown(int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;
    if (leftChild < heapSize && heap[leftChild] < heap[smallest]) {
        smallest = leftChild;
    }
    if (rightChild < heapSize && heap[rightChild] < heap[smallest]) {
        smallest = rightChild;
    }
    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }}
void insert(int value) {
    if (heapSize == MAX) {
        printf("Priority queue is full!\n");
        return;
    }
    heap[heapSize] = value;
    heapSize++;
    heapifyUp(heapSize - 1);
    printf("%d inserted into the priority queue.\n", value);
}
int extractMin() {
    if (heapSize == 0) {
        printf("Priority queue is empty!\n");
        return -1;
    }
    int min = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapifyDown(0);
    return min;
}
void displayHeap() {
    if (heapSize == 0) {
        printf("Priority queue is empty!\n");
        return;
    }
    printf("Priority Queue (Min-Heap): ");
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}
int main() {
    int choice, value;
    while (1) {
        printf("\n1. Insert\n2. Extract Min\n3. Display Priority Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                value = extractMin();
                if (value != -1) {
                    printf("Extracted Min: %d\n", value);
                }
                break;
            case 3:
                displayHeap();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
    
        }   
    }
}
