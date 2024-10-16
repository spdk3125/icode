#include <stdio.h>
#include <stdbool.h>
#define MAX_NODES 20
void dfs(int graph[MAX_NODES][MAX_NODES], bool visited[], int node, int numNodes) {
    visited[node] = true;
    printf("%d ", node);
    for (int i = 0; i<numNodes; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(graph, visited, i, numNodes);
        }
    }
}

int main() {
    int graph[MAX_NODES][MAX_NODES];
    bool visited[MAX_NODES] = {false};
    int numNodes;
printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
printf("Enter the adjacency matrix:\n");
    for (int i = 0; i<numNodes; i++) {
        for (int j = 0; j <numNodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int startNode;
    printf("Enter the starting node (0 to %d): ", numNodes - 1);
    scanf("%d", &startNode);
printf("Depth First Search starting from node %d:\n", startNode);
    dfs(graph, visited, startNode, numNodes);

    return 0;
}
