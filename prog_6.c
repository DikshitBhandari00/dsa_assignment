

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000


static void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify_down_max(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify_down_max(arr, n, largest);
    }
}

void heapify_down_min(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify_down_min(arr, n, smallest);
    }
}


void build_max_heap(int arr[], int n) {
   
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify_down_max(arr, n, i);
}


void build_min_heap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify_down_min(arr, n, i);
}


void print_arr(const char *label, int arr[], int n) {
    printf("%s", label);
    for (int i = 0; i < n; ++i)
        printf(" %d", arr[i]);
    printf("\n");
}

int main(void) {
    int n;
    int arr[MAX];

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
        fprintf(stderr, "Invalid number of elements (1..%d).\n", MAX);
        return 1;
    }

    printf("Enter %d integers separated by spaces: ", n);
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Invalid input.\n");
            return 1;
        }
    }

    
    int maxh[MAX], minh[MAX];
    for (int i = 0; i < n; ++i) {
        maxh[i] = arr[i];
        minh[i] = arr[i];
    }

    build_max_heap(maxh, n);
    build_min_heap(minh, n);

    print_arr("Original array:", arr, n);
    print_arr("Max-heap:", maxh, n);
    print_arr("Min-heap:", minh, n);

    return 0;
}
