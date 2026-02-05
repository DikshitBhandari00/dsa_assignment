# prog_6.c — Build Min-Heap and Max-Heap from an Unsorted Array

Description

'prog_6.c' reads an unsorted array from standard input and constructs both a
max-heap and a min-heap from the same data using the in-place heap construction
(sift-down / heapify) method. The program prints the original array and the
two resulting heaps represented as arrays.

Key points

- Uses 0-based indexing. For node at index `i`: left child is '2*i + 1', right
  child is '2*i + 2'.
- Heap construction runs in O(n) time by heapifying nodes from 'n/2 - 1' down to
  '0'.
- Space complexity is O(n) for storing arrays; the heap-building is in-place.

Example

Input (user types):

6
3 1 6 5 2 4

Output:

Original array: 3 1 6 5 2 4
Max-heap:       6 5 4 3 2 1
Min-heap:       1 2 4 5 3 6

Notes

- The program prints the heap as a flat array. For clarity, interpret it as a
  binary tree in level order.
- For large sparse heaps or memory-constrained environments, consider alternate
  representations or streaming approaches.

