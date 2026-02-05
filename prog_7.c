/*
 * prog_7.c
 * Program: Dijkstra's Shortest Paths (from single source)
 * Description: Reads a weighted directed/undirected graph from stdin and finds
 *              shortest distances (and paths) from a given source vertex to
 *              all other vertices using Dijkstra's algorithm (O(n^2) version).
 *
 * Build (Windows, GCC/MinGW):
 *   gcc prog_7.c -o prog_7
 * Run:
 *   prog_7.exe
 *
 * Input format (example):
 *   n m    # n = number of vertices (0..n-1), m = number of edges
 *   u v w  # repeat m times: edge from u to v with weight w
 *   s      # source vertex
 *
 * Example (undirected graph with 5 nodes):
 *   5 6
 *   0 1 10
 *   0 3 5
 *   1 2 1
 *   3 1 3
 *   3 2 9
 *   3 4 2
 *   0
 *
 * Output:
 *   Vertex  Distance  Path
 *   0       0         0
 *   1       8         0 -> 3 -> 1
 *   2       9         0 -> 3 -> 1 -> 2
 *   3       5         0 -> 3
 *   4       7         0 -> 3 -> 4
 *
 * Notes:
 * - This implementation uses an adjacency matrix internally and the plain
 *   O(n^2) Dijkstra algorithm. For large sparse graphs, an adjacency list
 *   with a binary heap (priority queue) provides better performance.
 * - Negative edge weights are not supported.
 *
 * Author: Student
 * Date: 2026-02-05
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX / 4

/* Print path from source to v using parent[] recursively */
void print_path(int parent[], int v) {
    if (v < 0) return;
    if (parent[v] == -1) {
        printf("%d", v);
    } else {
        print_path(parent, parent[v]);
        printf(" -> %d", v);
    }
}

/* Dijkstra's algorithm (O(n^2)) using adjacency matrix */
void dijkstra(int n, int adj[MAX][MAX], int src, int dist[], int parent[]) {
    int visited[MAX] = {0};

    for (int i = 0; i < n; ++i) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[src] = 0;

    for (int iter = 0; iter < n; ++iter) {
        /* Pick unvisited vertex with smallest dist */
        int u = -1;
        int best = INF;
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && dist[i] < best) {
                best = dist[i];
                u = i;
            }
        }

        if (u == -1) break; /* remaining vertices are unreachable */
        visited[u] = 1;

        /* Relax edges u -> v */
        for (int v = 0; v < n; ++v) {
            if (adj[u][v] != INF && !visited[v]) {
                int alt = dist[u] + adj[u][v];
                if (alt < dist[v]) {
                    dist[v] = alt;
                    parent[v] = u;
                }
            }
        }
    }
}

int main(void) {
    int n, m;
    int adj[MAX][MAX];

    printf("Enter n m (vertices edges): ");
    if (scanf("%d %d", &n, &m) != 2) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }
    if (n <= 0 || n > MAX) {
        fprintf(stderr, "n must be between 1 and %d\n", MAX);
        return 1;
    }

    /* Initialize adjacency matrix with INF (no edge) */
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            adj[i][j] = (i == j) ? 0 : INF;

    printf("Enter %d edges (u v w)\n", m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        if (scanf("%d %d %d", &u, &v, &w) != 3) {
            fprintf(stderr, "Invalid edge input\n");
            return 1;
        }
        if (u < 0 || u >= n || v < 0 || v >= n) {
            fprintf(stderr, "Vertex indices must be in 0..%d\n", n-1);
            return 1;
        }
        /* If multiple edges are provided, keep the smallest weight */
        if (w < adj[u][v]) adj[u][v] = w;
        if (w < adj[v][u]) adj[v][u] = w; /* treat graph undirected by default */
    }

    int src;
    printf("Enter source vertex: ");
    if (scanf("%d", &src) != 1 || src < 0 || src >= n) {
        fprintf(stderr, "Invalid source\n");
        return 1;
    }

    int dist[MAX], parent[MAX];
    dijkstra(n, adj, src, dist, parent);

    printf("\nVertex  Distance  Path\n");
    for (int v = 0; v < n; ++v) {
        if (dist[v] >= INF/2) {
            printf("%d       INF       unreachable\n", v);
        } else {
            printf("%d       %d       ", v, dist[v]);
            print_path(parent, v);
            printf("\n");
        }
    }

    return 0;
}
