#include <stdio.h>
#include <time.h>

// Function to heapify a subtree rooted at index i in array of size n
void heapify(int arr[], int n, int i) {
    int largest = i;           // Assume root is the largest
    int left = 2*i + 1;        // Left child index
    int right = 2*i + 2;       // Right child index

    if (left < n && arr[left] > arr[largest])
        largest = left;        // Left child is larger than root

    if (right < n && arr[right] > arr[largest])
        largest = right;       // Right child is larger than current largest

    if (largest != i) {
        // Swap arr[i] and arr[largest]
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Heap Sort main function
void heapSort(int arr[], int n) {
    // Step 1: Build max heap (rearrange array)
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Extract elements one by one from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root (max) to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Measure start time
    clock_t start = clock();

    heapSort(arr, n);  // Call heap sort

    // Measure end time
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Print sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nTime taken: %f seconds\n", time_taken);
    return 0;
}
