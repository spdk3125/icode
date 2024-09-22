#include <stdio.h>

// Function to perform bucket sort
void bucketSort(float arr[], int n) {
    // Create an array of buckets (here, we assume 10 buckets)
    const int numBuckets = 10;
    float buckets[numBuckets][n];
    int bucketSize[numBuckets] = {0}; // Initialize bucket sizes to 0

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = (int)(arr[i] * numBuckets);
        buckets[index][bucketSize[index]] = arr[i];
        bucketSize[index]++;
    }

    // Sort elements within each bucket (using insertion sort)
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 1; j < bucketSize[i]; j++) {
            float key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Gather sorted elements from buckets
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < bucketSize[i]; j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float arr[n];
    printf("Enter %d floating-point numbers (between 0 and 1):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    // Perform bucket sort
    bucketSort(arr, n);

    printf("Sorted array in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}

