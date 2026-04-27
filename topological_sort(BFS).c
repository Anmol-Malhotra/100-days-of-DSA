#include <stdio.h>
#include <stdlib.h>

// Node structure for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* inDegree;   // in-degree array
};

// Function to create a node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->inDegree = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->inDegree[i] = 0;
    }
    return graph;
}

// Add edge (directed graph)
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // increase in-degree of destination
    graph->inDegree[dest]++;
}

// Queue implementation
struct Queue {
    int items[100];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct Queue* q) {
    return q->rear == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == 99) {
        printf("Queue full\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) return -1;
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

// Kahn's Algorithm for Topological Sort
void topologicalSort(struct Graph* graph) {
    struct Queue* q = createQueue();

    // enqueue all vertices with in-degree 0
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->inDegree[i] == 0) {
            enqueue(q, i);
        }
    }

    int count = 0;
    printf("Topological ordering:\n");

    while (!isEmpty(q)) {
        int current = dequeue(q);
        printf("%d ", current);
        count++;

        // decrease in-degree of neighbors
        struct Node* temp = graph->adjLists[current];
        while (temp) {
            int adjVertex = temp->vertex;
            graph->inDegree[adjVertex]--;
            if (graph->inDegree[adjVertex] == 0) {
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");

    // If count != numVertices, graph has a cycle
    if (count != graph->numVertices) {
        printf("Graph is not a DAG (cycle exists)\n");
    }
}

int main() {
    int n, m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct Graph* graph = createGraph(n);

    printf("Enter edges (u v) for directed graph:\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    topologicalSort(graph);

    return 0;
}