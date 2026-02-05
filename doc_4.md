# prog_4.c — Doubly Linked List (Insert / Delete)

# Doubly Linked List Implementation in C

## Aim
To implement a Doubly Linked List using structure in C and perform the following operations:
- Insert a node after a given node
- Delete a node
- Display the list

---

## Theory

A Doubly Linked List is a linear data structure where each node contains:
- Data
- Pointer to the previous node
- Pointer to the next node

It allows traversal in both forward and backward directions.


## Algorithms

### Insert After a Given Node
1. Create a new node
2. Set new->next = given->next
3. Set new->prev = given
4. If next node exists, update its prev pointer
5. Set given->next = new

---

### Delete a Node
1. If node is head, move head to next
2. Update previous node's next pointer
3. Update next node's prev pointer
4. Free the node

---

### Display List
1. Start from head
2. Traverse using next pointer
3. Print each element

---

## Functions Used

### insertEnd()
Adds node at the end of the list.

### insertAfter()
Inserts a new node after the specified node.

### deleteNode()
Deletes the specified node.

### display()
Prints all elements of the list.

### sample output
Original list:
10 20 30
After insertion:
10 20 25 30
After deletion:
10 25 30


