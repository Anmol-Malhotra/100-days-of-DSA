#include <stdio.h>
#include <limits.h>

#define MAX 100

int n, m;
int graph[MAX][MAX];

// Function to find vertex with minimum distance (acts like priority queue)
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Dijkstra Algorithm
void dijkstra(int src) {
    int dist[MAX];
    int visited[MAX];

    // Initialize distances
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    // Find shortest path
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print result
    for (int i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }
}

int main() {
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    int u, v, w;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);

        // Undirected graph
        graph[u][v] = w;
        graph[v][u] = w;

        // For directed graph, comment above and use:
        // graph[u][v] = w;
    }

    int src;
    scanf("%d", &src);

    dijkstra(src);

    return 0;
}