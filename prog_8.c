#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global counters for comparisons and swaps
long long comparisons = 0;
long long swaps = 0;

// Bubble Sort
void bubbleSort(int arr[], int n) {
    comparisons = 0;
    swaps = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    comparisons = 0;
    swaps = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            // Swap
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
            swaps++;
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    comparisons = 0;
    swaps = 0;
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

// Merge function for Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    
    int* leftArr = (int*)malloc(leftSize * sizeof(int));
    int* rightArr = (int*)malloc(rightSize * sizeof(int));
    
    for (int i = 0; i < leftSize; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < rightSize; i++)
        rightArr[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    
    while (i < leftSize && j < rightSize) {
        comparisons++;
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
            swaps++;
        }
    }
    
    while (i < leftSize) {
        arr[k++] = leftArr[i++];
    }
    
    while (j < rightSize) {
        arr[k++] = rightArr[j++];
    }
    
    free(leftArr);
    free(rightArr);
}

// Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Wrapper for Merge Sort to reset counters
void mergeSortWrapper(int arr[], int n) {
    comparisons = 0;
    swaps = 0;
    mergeSort(arr, 0, n - 1);
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Copy array
void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid input! Number of elements must be positive.\n");
        return 1;
    }
    
    // Allocate memory for original and working arrays
    int* original = (int*)malloc(n * sizeof(int));
    int* working = (int*)malloc(n * sizeof(int));
    
    // Initialize random seed
    srand(time(0));
    
    // Generate random integers in range [1, 1000]
    for (int i = 0; i < n; i++) {
        original[i] = (rand() % 1000) + 1;
    }
    
    printf("\n--- Original Array ---\n");
    printArray(original, n);
    
    // Menu for sorting algorithm selection
    printf("\nChoose sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("Enter your choice (1-4): ");
    
    int choice;
    scanf("%d", &choice);
    
    // Copy original array to working array
    copyArray(original, working, n);
    
    // Perform sorting based on choice
    char* algorithmName;
    
    switch (choice) {
        case 1:
            algorithmName = "Bubble Sort";
            bubbleSort(working, n);
            break;
        case 2:
            algorithmName = "Selection Sort";
            selectionSort(working, n);
            break;
        case 3:
            algorithmName = "Insertion Sort";
            insertionSort(working, n);
            break;
        case 4:
            algorithmName = "Merge Sort";
            mergeSortWrapper(working, n);
            break;
        default:
            printf("Invalid choice!\n");
            free(original);
            free(working);
            return 1;
    }
    
    printf("\n--- Sorted Array (using %s) ---\n", algorithmName);
    printArray(working, n);
    
    printf("\n--- Statistics ---\n");
    printf("Algorithm: %s\n", algorithmName);
    printf("Total Comparisons: %lld\n", comparisons);
    printf("Total Swaps: %lld\n", swaps);
    
    // Free allocated memory
    free(original);
    free(working);
    
    return 0;
}
