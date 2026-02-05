# Program 8 — Sorting Algorithm Comparison with Statistics

## Purpose
Generate random integers and compare multiple sorting algorithms by allowing the user to choose which algorithm to use. The program tracks and displays the number of comparisons and swaps performed during sorting.

## Description
The program performs the following tasks:
- Accepts the number of elements (N) from the user.
- Generates N random integers in the range [1, 1000].
- Presents a menu to choose from four sorting algorithms: Bubble Sort, Selection Sort, Insertion Sort, or Merge Sort.
- Sorts the array using the chosen algorithm while counting comparisons and swaps.
- Displays the original array, sorted array, algorithm name, and performance statistics (comparisons and swaps).

## Supported Sorting Algorithms

### 1. Bubble Sort
- Repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.
- Time Complexity: O(n²)
- Space Complexity: O(1)
- Swaps every misplaced element.

### 2. Selection Sort
- Divides the array into sorted and unsorted portions; repeatedly selects the minimum element from the unsorted portion.
- Time Complexity: O(n²)
- Space Complexity: O(1)
- Performs at most (n-1) swaps.

### 3. Insertion Sort
- Builds the sorted array one element at a time by inserting each element into its correct position.
- Time Complexity: O(n²)
- Space Complexity: O(1)
- Performs fewer swaps for nearly sorted data.

### 4. Merge Sort
- Divides the array into halves, recursively sorts them, and merges the sorted halves.
- Time Complexity: O(n log n)
- Space Complexity: O(n)
- Most efficient for large datasets.

## Example Input/Output
```
Enter number of elements: 10
Enter your choice (1-4): 1

--- Original Array ---
543 127 892 341 765 234 891 456 123 678

--- Sorted Array (using Bubble Sort) ---
123 127 234 341 456 543 678 765 891 892

--- Statistics ---
Algorithm: Bubble Sort
Total Comparisons: 45
Total Swaps: 23
```

## Algorithm Details (brief)

### Bubble Sort
- Compare each pair of adjacent elements.
- Swap if the left element is greater than the right.
- Repeat until no swaps occur in a full pass.

### Selection Sort
- Find the minimum element in the unsorted portion.
- Swap it with the first element of the unsorted portion.
- Move the boundary between sorted and unsorted portions.

### Insertion Sort
- For each element, compare it with sorted elements to its left.
- Shift sorted elements right as needed.
- Insert the element in its correct position.

### Merge Sort
- Divide the array into two halves recursively.
- Recursively sort each half.
- Merge the two sorted halves into a single sorted array.

## Complexity Analysis

| Algorithm | Time (Best) | Time (Avg) | Time (Worst) | Space | Stable |
|-----------|------------|-----------|-------------|-------|--------|
| Bubble    | O(n²)      | O(n²)     | O(n²)       | O(1)  | Yes    |
| Selection | O(n²)      | O(n²)     | O(n²)       | O(1)  | No     |
| Insertion | O(n)       | O(n²)     | O(n²)       | O(1)  | Yes    |
| Merge     | O(n log n) | O(n log n)| O(n log n)  | O(n)  | Yes    |

## Notes
- The program uses `srand(time(0))` to seed the random number generator for varied results on each run.
- Comparisons and swaps are counted for all algorithms to provide insight into their efficiency.
- Memory is dynamically allocated for the arrays and freed after use.
- For Merge Sort, a swap operation is counted each time an element is placed from the temporary arrays during the merge process.

## Sample Output (with larger dataset)
```
Enter number of elements: 100
Enter your choice (1-4): 4

--- Original Array ---
[100 random numbers between 1 and 1000]

--- Sorted Array (using Merge Sort) ---
[Sorted: 1, 3, 5, 7, ..., 1000]

--- Statistics ---
Algorithm: Merge Sort
Total Comparisons: 664
Total Swaps: 450
```

## Key Features
- Interactive menu-driven interface
- Dynamic memory allocation for flexibility
- Performance tracking through comparison and swap counting
- Support for arrays of any size (up to system memory limits)
- Clear input validation and error handling for invalid algorithm choices
