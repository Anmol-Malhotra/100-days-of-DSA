#include <stdio.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    int adj[MAX][MAX] = {0};

    int u, v;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // For undirected graph:
        adj[u][v] = 1;
        adj[v][u] = 1;

        // If directed graph is required, comment the above line and use only:
        // adj[u][v] = 1;
    }

    // Print adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}