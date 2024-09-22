#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

// Graph representation using adjacency list
struct Graph {
    int V; // Number of vertices
    int adjList[MAX_VERTICES][MAX_VERTICES];
};

// Function to create a graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph->adjList[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int v, int w) {
    graph->adjList[v][w] = 1;
    graph->adjList[w][v] = 1; // For undirected graph
}

// Function to perform DFS traversal
void DFS(struct Graph* graph, int start, int visited[]) {
    visited[start] = 1;
    printf("%d ", start);

    for (int i = 0; i < graph->V; i++) {
        if (graph->adjList[start][i] == 1 && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

int main() {
    int V, E;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    struct Graph* graph = createGraph(V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    int visited[MAX_VERTICES] = {0};
    printf("DFS traversal starting from vertex 0:\n");
    DFS(graph, 0, visited);

    return 0;
}
