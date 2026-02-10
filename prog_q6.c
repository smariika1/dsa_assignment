#include <stdio.h>

void swap(int* a, int* b) { int t = *a; *a = *b; *b = t; }

void minHeapify(int arr[], int n, int i) {
    int smallest = i, l = 2*i + 1, r = 2*i + 2;
    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i, l = 2*i + 1, r = 2*i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    int arr1[] = {12, 11, 13, 5, 6, 7};
    int arr2[] = {12, 11, 13, 5, 6, 7};
    int n = 6;
    
    printf("Heap Construction\n\n");
    printf("Original: "); printArray(arr1, n);
    
    buildMinHeap(arr1, n);
    printf("Min Heap: "); printArray(arr1, n);
    
    buildMaxHeap(arr2, n);
    printf("Max Heap: "); printArray(arr2, n);
    
    return 0;
}
