#include <stdio.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX];
int n, m;

// Function to find minimum key vertex not yet included
int minKey(int key[], int visited[]) {
    int min = INT_MAX, min_index = -1;

    for(int i = 1; i <= n; i++) {
        if(!visited[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int main() {
    scanf("%d %d", &n, &m);

    // Initialize graph
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    int u, v, w;

    // Input edges
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected
    }

    int key[MAX];
    int visited[MAX];

    // Initialize
    for(int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0; // start from node 1

    int totalWeight = 0;

    for(int count = 1; count <= n; count++) {
        int u = minKey(key, visited);
        visited[u] = 1;
        totalWeight += key[u];

        // Update adjacent vertices
        for(int v = 1; v <= n; v++) {
            if(graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}