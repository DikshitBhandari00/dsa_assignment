# prog_7.c — Dijkstra's Shortest Paths (Single Source)

Description

`prog_7.c` reads a weighted graph (treated as undirected by default) and
computes shortest paths from a single source vertex to all other vertices using
Dijkstra's algorithm. The implementation uses an adjacency matrix and the
classic O(n^2) selection-based Dijkstra.

Input format

- First line: `n m` where `n` is number of vertices (0..n-1) and `m` is number of
  edges.
- Next `m` lines: `u v w` representing an edge between `u` and `v` with weight
  `w`. The program keeps the smallest weight if multiple edges are provided.
- Final line: `s` — the source vertex.

Example

Input:

5 6
0 1 10
0 3 5
1 2 1
3 1 3
3 2 9
3 4 2
0

Output:

Vertex  Distance  Path
0       0         0
1       8         0 -> 3 -> 1
2       9         0 -> 3 -> 1 -> 2
3       5         0 -> 3
4       7         0 -> 3 -> 4

Complexity

- Time: O(n^2) due to linear search for the next vertex in each of n iterations.
- Space: O(n^2) for the adjacency matrix.


