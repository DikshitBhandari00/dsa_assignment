# prog_5.c — Undirected Graph (Adjacency Matrix) with BFS & DFS

Description

'prog_5.c' implements an undirected graph using an adjacency matrix and provides
functions to traverse the graph using Breadth-First Search (BFS) and Depth-First
Search (DFS).


Key functions

- 'init_graph(struct Graph *g, int n)' — Initialize an n-vertex graph and
  zero the adjacency matrix.
- 'add_edge(struct Graph *g, int u, int v)' — Add an undirected edge between
  vertices 'u' and 'v'.
- 'print_adj_matrix(struct Graph *g)' — Print adjacency matrix to console.
- 'bfs(struct Graph *g, int s)' — Perform BFS from source 's' and print order.
- 'dfs(struct Graph *g, int s)' — Perform DFS from source 's' (recursive).

Example graph used in the program

Vertices: 0..4
Edges:
- 0-1, 0-2, 1-2, 1-3, 1-4, 2-4

This graph contains cycles and demonstrates both BFS and DFS traversals.


Expected output (one possible output; orders reflect adjacency scanning order):

Adjacency matrix (5 vertices):
0 1 1 0 0 
1 0 1 1 1 
1 1 0 0 1 
0 1 0 0 0 
0 1 1 0 0 

BFS starting at 0: 0 1 2 3 4 
DFS starting at 0: 0 1 2 4 3 

Complexity

- Space: O(n^2) due to adjacency matrix.
- Time: BFS / DFS each O(n + m) where m is number of edges; scanning adjacency
  matrix gives worst-case O(n^2) for each traversal.
