#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    long comparisons;
    long swaps;
} Stats;

void swap(int* a, int* b, Stats* s) {
    int t = *a; *a = *b; *b = t;
    s->swaps++;
}

void bubbleSort(int arr[], int n, Stats* s) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++) {
            s->comparisons++;
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1], s);
        }
}

void selectionSort(int arr[], int n, Stats* s) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            s->comparisons++;
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        if (minIdx != i) swap(&arr[i], &arr[minIdx], s);
    }
}

void insertionSort(int arr[], int n, Stats* s) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && (s->comparisons++, arr[j] > key)) {
            arr[j + 1] = arr[j];
            s->swaps++;
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r, Stats* s) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        s->comparisons++;
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSortUtil(int arr[], int l, int r, Stats* s) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortUtil(arr, l, m, s);
        mergeSortUtil(arr, m + 1, r, s);
        merge(arr, l, m, r, s);
    }
}

void mergeSort(int arr[], int n, Stats* s) {
    mergeSortUtil(arr, 0, n - 1, s);
}

void printArray(int arr[], int n) {
    int limit = n < 20 ? n : 20;
    for (int i = 0; i < limit; i++) printf("%d ", arr[i]);
    if (n > 20) printf("...");
    printf("\n");
}


int main() {
    int n, choice;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    int* original = (int*)malloc(n * sizeof(int));
    
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        original[i] = rand() % 1000 + 1;
    
    printf("\nChoose sorting algorithm:\n");
    printf("1. Bubble Sort\n2. Selection Sort\n");
    printf("3. Insertion Sort\n4. Merge Sort\n");
    printf("Choice: ");
    scanf("%d", &choice);
    
    for (int i = 0; i < n; i++) arr[i] = original[i];
    
    printf("\nBefore sorting: ");
    printArray(arr, n);
    
    Stats stats = {0, 0};
    clock_t start = clock();
    
    switch(choice) {
        case 1: bubbleSort(arr, n, &stats); break;
        case 2: selectionSort(arr, n, &stats); break;
        case 3: insertionSort(arr, n, &stats); break;
        case 4: mergeSort(arr, n, &stats); break;
        default: printf("Invalid choice\n"); return 1;
    }
    
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("After sorting:  ");
    printArray(arr, n);
    
    printf("\nStatistics:\n");
    printf("Comparisons: %ld\n", stats.comparisons);
    printf("Swaps: %ld\n", stats.swaps);
    printf("Time: %.6f seconds\n", time_taken);
    
    free(arr);
    free(original);
    return 0;
}
