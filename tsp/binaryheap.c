#include <stdio.h>
#include <stdlib.h>

// Max heap structure
typedef struct MaxHeap {
    int *data;
    int size;
    int capacity;
} MaxHeap;

// Function to create a new max heap
MaxHeap *createMaxHeap(int capacity) {
    MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
    heap->data = (int *)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

// Function to insert an element into the max heap
void insert(MaxHeap *heap, int priority) {
    if (heap->size >= heap->capacity) {
        printf("Heap is full. Cannot insert.\n");
        return;
    }

    heap->data[heap->size++] = priority;

    // Max-heapify to maintain heap property
    int i = heap->size - 1;
    while (i > 0 && heap->data[i] > heap->data[(i - 1) / 2]) {
        int temp = heap->data[i];
        heap->data[i] = heap->data[(i - 1) / 2];
        heap->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// In-order traversal (descending order)
void inOrderTraversal(MaxHeap *heap, int index) {
    if (index < heap->size) {
        inOrderTraversal(heap, 2 * index + 1);
        printf("Priority: %d\n", heap->data[index]);
        inOrderTraversal(heap, 2 * index + 2);
    }
}

int main() {
    int capacity;
    printf("Enter the maximum capacity of the job queue: ");
    scanf("%d", &capacity);

    MaxHeap *jobQueue = createMaxHeap(capacity);

    int priority;
    char choice;

    do {
        printf("Enter job priority (positive integer): ");
        scanf("%d", &priority);

        insert(jobQueue, priority);

        printf("Add another job? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nJob Queue (Descending order of priority):\n");
    inOrderTraversal(jobQueue, 0);

    // Free memory (not shown in this simplified example)

    return 0;
}
