#include <stdio.h>
#include <stdlib.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Target found at index i
        }
    }
    return -1; // Target not found
}

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Target found at index mid
        } else if (arr[mid] < target) {
            left = mid + 1; // Target might be in the right half
        } else {
            right = mid - 1; // Target might be in the left half
        }
    }

    return -1; // Target not found
}

int main() {
    int size, target;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array in ascending order:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    // Linear search
    int linearIndex = linearSearch(arr, size, target);
    if (linearIndex != -1) {
        printf("Target found at index %d using linear search.\n", linearIndex);
    } else {
        printf("Target not found using linear search.\n");
    }

    // Binary search (assuming the array is sorted)
    int binaryIndex = binarySearch(arr, size, target);
    if (binaryIndex != -1) {
        printf("Target found at index %d using binary search.\n", binaryIndex);
    } else {
        printf("Target not found using binary search.\n");
    }

    return 0;
}
