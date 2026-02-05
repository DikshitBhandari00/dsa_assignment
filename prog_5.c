

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

/* Graph using adjacency matrix */
struct Graph {
    int n; /* number of vertices */
    int adj[MAX_VERTICES][MAX_VERTICES];
};

/* Initialize graph with n vertices (0..n-1) */
void init_graph(struct Graph *g, int n) {
    g->n = n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            g->adj[i][j] = 0;
}

/* Add undirected edge u-v */
void add_edge(struct Graph *g, int u, int v) {
    if (u < 0 || v < 0 || u >= g->n || v >= g->n) return;
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

/* Print adjacency matrix (for debugging / demonstration) */
void print_adj_matrix(struct Graph *g) {
    printf("Adjacency matrix (%d vertices):\n", g->n);
    for (int i = 0; i < g->n; ++i) {
        for (int j = 0; j < g->n; ++j)
            printf("%d ", g->adj[i][j]);
        printf("\n");
    }
}

/* BFS traversal starting from source 's' */
void bfs(struct Graph *g, int s) {
    if (s < 0 || s >= g->n) return;
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[s] = 1;
    queue[rear++] = s;

    printf("BFS starting at %d: ", s);

    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        for (int v = 0; v < g->n; ++v) {
            if (g->adj[u][v] && !visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
    printf("\n");
}

/* Helper for DFS (recursive) */
void dfs_util(struct Graph *g, int u, int visited[]) {
    visited[u] = 1;
    printf("%d ", u);
    for (int v = 0; v < g->n; ++v) {
        if (g->adj[u][v] && !visited[v]) {
            dfs_util(g, v, visited);
        }
    }
}

/* DFS traversal starting from source 's' */
void dfs(struct Graph *g, int s) {
    if (s < 0 || s >= g->n) return;
    int visited[MAX_VERTICES] = {0};
    printf("DFS starting at %d: ", s);
    dfs_util(g, s, visited);
    printf("\n");
}

int main(void) {
    /* Example graph:
     * 0 -- 1 -- 3
     * |    |
     * 2 -- 4
     * and an extra edge 1--2 to show cycles
     * We'll create a graph with 5 vertices (0..4)
     */

    struct Graph g;
    init_graph(&g, 5);

    add_edge(&g, 0, 1);
    add_edge(&g, 0, 2);
    add_edge(&g, 1, 2);
    add_edge(&g, 1, 3);
    add_edge(&g, 1, 4);
    add_edge(&g, 2, 4);

    print_adj_matrix(&g);

    /* Demonstrate traversals */
    bfs(&g, 0); /* expected: 0 1 2 3 4 (or 0 2 1 4 3 depending on adjacency order) */
    dfs(&g, 0); /* expected: one valid DFS order starting at 0 */

    return 0;
}
