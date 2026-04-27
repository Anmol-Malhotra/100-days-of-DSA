#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

// Structure for adjacency list node
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Structure for adjacency list
typedef struct {
    Node* head;
} AdjList;

// Structure for graph
typedef struct {
    int V;
    AdjList* array;
} Graph;

// Structure for min-heap node
typedef struct {
    int vertex;
    int dist;
} HeapNode;

// Structure for min-heap
typedef struct {
    int size;
    int capacity;
    int* pos;
    HeapNode** array;
} MinHeap;

// Utility function to create a new adjacency list node
Node* newNode(int v, int w) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = v;
    node->weight = w;
    node->next = NULL;
    return node;
}

// Utility function to create a graph
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (AdjList*)malloc(V * sizeof(AdjList));
    for (int i = 0; i < V; i++)
        graph->array[i].head = NULL;
    return graph;
}

// Add edge to graph
void addEdge(Graph* graph, int u, int v, int w) {
    Node* node = newNode(v, w);
    node->next = graph->array[u].head;
    graph->array[u].head = node;

    // For undirected graph, add reverse edge
    // Comment out if directed
    // node = newNode(u, w);
    // node->next = graph->array[v].head;
    // graph->array[v].head = node;
}

// Utility function to create a new heap node
HeapNode* newHeapNode(int v, int dist) {
    HeapNode* heapNode = (HeapNode*)malloc(sizeof(HeapNode));
    heapNode->vertex = v;
    heapNode->dist = dist;
    return heapNode;
}

// Utility function to create a min-heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->pos = (int*)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (HeapNode**)malloc(capacity * sizeof(HeapNode*));
    return minHeap;
}

// Swap two heap nodes
void swapHeapNode(HeapNode** a, HeapNode** b) {
    HeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Heapify at index
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size &&
        minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;

    if (right < minHeap->size &&
        minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        HeapNode* smallestNode = minHeap->array[smallest];
        HeapNode* idxNode = minHeap->array[idx];

        minHeap->pos[smallestNode->vertex] = idx;
        minHeap->pos[idxNode->vertex] = smallest;

        swapHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}

// Extract minimum node
HeapNode* extractMin(MinHeap* minHeap) {
    if (minHeap->size == 0)
        return NULL;

    HeapNode* root = minHeap->array[0];
    HeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    minHeap->pos[root->vertex] = minHeap->size - 1;
    minHeap->pos[lastNode->vertex] = 0;

    minHeap->size--;
    minHeapify(minHeap, 0);

    return root;
}

// Decrease distance value of a vertex
void decreaseKey(MinHeap* minHeap, int v, int dist) {
    int i = minHeap->pos[v];
    minHeap->array[i]->dist = dist;

    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
        minHeap->pos[minHeap->array[i]->vertex] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->vertex] = i;
        swapHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Check if a vertex is in min-heap
int isInMinHeap(MinHeap* minHeap, int v) {
    return minHeap->pos[v] < minHeap->size;
}

// Dijkstra’s algorithm
void dijkstra(Graph* graph, int src) {
    int V = graph->V;
    int dist[V];

    MinHeap* minHeap = createMinHeap(V);

    for (int v = 0; v < V; v++) {
        dist[v] = INF;
        minHeap->array[v] = newHeapNode(v, dist[v]);
        minHeap->pos[v] = v;
    }

    minHeap->array[src] = newHeapNode(src, 0);
    minHeap->pos[src] = src;
    dist[src] = 0;
    minHeap->size = V;

    while (minHeap->size != 0) {
        HeapNode* minNode = extractMin(minHeap);
        int u = minNode->vertex;

        Node* crawl = graph->array[u].head;
        while (crawl != NULL) {
            int v = crawl->vertex;

            if (isInMinHeap(minHeap, v) && dist[u] != INF &&
                crawl->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + crawl->weight;
                decreaseKey(minHeap, v, dist[v]);
            }
            crawl = crawl->next;
        }
    }

    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Graph* graph = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(graph, u - 1, v - 1, w); // converting to 0-based index
    }

    int source;
    scanf("%d", &source);

    dijkstra(graph, source - 1);

    return 0;
}
