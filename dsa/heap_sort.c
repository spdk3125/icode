#include <stdio.h>
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void heapify(int arr[], int N, int i) {
    int largest = i;  
    int left = 2 * i + 1;  
    int right = 2 * i + 2;  
    if (left < N && arr[left] > arr[largest])
        largest = left;
    if (right < N && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}
void heapSort(int arr[], int N) {
	int i;
    for ( i = N / 2 - 1; i >= 0; i--) {
        heapify(arr, N, i);
    }
    for (i = N - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }}
void printArray(int arr[], int N) {
	int i;
    for ( i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int N;
    printf("Enter the number of elements: ");
    scanf("%d", &N);
    int arr[N],i;
    printf("Enter the elements of the array:\n");
    for ( i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    heapSort(arr, N);
    printf("Sorted array: \n");
    printArray(arr, N);
}
