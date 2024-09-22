#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    for (int step = 1; step < n; step++) {
        int key = arr[step];
        int j = step - 1;

        // Compare key with each element on the left of it
        // Move sorted elements to the right until we find the correct position for key
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform insertion sort
    insertionSort(arr, n);

    printf("Sorted array in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

