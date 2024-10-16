#include <stdio.h>
#include <stdlib.h>
#define MAX_EDGES 100
#define MAX_VERTICES 10
typedef struct {
    int src, dest, weight;
} Edge;
typedef struct {
    Edge edges[MAX_EDGES];
    int edgeCount;
} Graph;
int find(int parent[], int i) {
    if (parent[i] == -1) {
        return i;
} return find(parent, parent[i]);
}
void unionSets(int parent[], int x, int y) {
    parent[x] = y;
}
int compareEdges(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}
void kruskalMST(Graph *graph) {
    int parent[MAX_VERTICES];
    int mstWeight = 0;
    for (int i = 0; i< MAX_VERTICES; i++) {
        parent[i] = -1;
    }
qsort(graph->edges, graph->edgeCount, sizeof(graph->edges[0]), compareEdges);
printf("Edge \tWeight\n");
    for (int i = 0; i< graph->edgeCount; i++) {
        int x = find(parent, graph->edges[i].src);
        int y = find(parent, graph->edges[i].dest);
if (x != y) {
printf("%d - %d \t%d\n", graph->edges[i].src, graph->edges[i].dest, graph->edges[i].weight);
mstWeight += graph->edges[i].weight;
unionSets(parent, x, y);}
    }printf("Total Weight of MST: %d\n", mstWeight);
}
int main() {
    Graph graph;
graph.edgeCount = 0;
    int numEdges;
printf("Enter the number of edges: ");
scanf("%d", &numEdges);
printf("Enter each edge in the format (srcdest weight):\n");
    for (int i = 0; i<numEdges; i++) {
scanf("%d %d %d", &graph.edges[i].src, &graph.edges[i].dest, &graph.edges[i].weight);
graph.edgeCount++;
    }
kruskalMST(&graph);
    return 0;
}











