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
}

// Function to perform topological sort
void topologicalSort(struct Graph* graph) {
    int visited[MAX_VERTICES] = {0};
    int stack[MAX_VERTICES];
    int top = -1;

    // Function to perform DFS and push vertices onto the stack
    void DFSUtil(int v) {
        visited[v] = 1;

        for (int i = 0; i < graph->V; i++) {
            if (graph->adjList[v][i] == 1 && !visited[i]) {
                DFSUtil(i);
            }
        }

        stack[++top] = v;
    }

    // Start DFS from vertices with no incoming edges
    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            DFSUtil(i);
        }
    }

    // Print the sorted vertices
    while (top >= 0) {
        printf("%d ", stack[top--]);
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

    printf("Topological sort:\n");
    topologicalSort(graph);

    return 0;
}
