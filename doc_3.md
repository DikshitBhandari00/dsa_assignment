# Program 3 — Reverse Traversal of a Singly Linked List ✅

## Purpose
Provide a simple implementation that demonstrates normal and reverse traversal of a singly linked list. The reverse traversal is implemented using recursion and the program prints list elements in both forward and reverse order.

## Description
- The program defines a basic `Node` structure with `int data` and a `next` pointer.
- Functions:
  - `insert(Node** head, int value)` — insert a new node at the end.
  - `display(Node* head)` — print nodes from head to tail (normal traversal).
  - `reverseTraversal(Node* head)` — print nodes from tail to head using recursion.
- The `main()` function inserts a few sample values, prints the list normally, then prints it in reverse.


## Sample output
```
Normal Traversal:
10 -> 20 -> 30 -> 40 -> NULL

Reverse Traversal:
40 -> 30 -> 20 -> 10 -> NULL
```

## Algorithm & Complexity
- Insert at end: O(n) per insertion (no tail pointer maintained).
- Normal traversal: O(n) time, O(1) extra space.
- Reverse traversal (recursion): O(n) time, O(n) call stack space due to recursion.



