#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = (low - 1),j;     
    for ( j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);  
        }  }
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void printArray(int arr[], int size) {
	int i;
    for ( i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int N,i;
    printf("Enter the number of elements: ");
    scanf("%d", &N);
    int arr[N];
    printf("Enter the elements of the array:\n");
    for ( i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Unsorted array: ");
    printArray(arr, N);
    quickSort(arr, 0, N - 1);
    printf("Sorted array: ");
    printArray(arr, N);
    return 0;
}
