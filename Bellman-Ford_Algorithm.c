#include <stdio.h>
#include <limits.h>

#define MAX 100

struct Edge {
    int u, v, w;
};

int main() {
    int n, m, source;
    struct Edge edges[MAX];

    // Input number of vertices and edges
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    // Input edges
    printf("Enter edges (u v w):\n");
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    // Input source vertex
    printf("Enter source vertex: ");
    scanf("%d", &source);

    int dist[MAX];

    // Initialize distances
    for(int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    // Relax edges (n-1) times
    for(int i = 1; i <= n - 1; i++) {
        for(int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycle
    for(int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE detected!\n");
            return 0;
        }
    }

    // Print shortest distances
    printf("Shortest distances from source %d:\n", source);
    for(int i = 0; i < n; i++) {
        if(dist[i] == INT_MAX)
            printf("Vertex %d: INF\n", i);
        else
            printf("Vertex %d: %d\n", i, dist[i]);
    }

    return 0;
}