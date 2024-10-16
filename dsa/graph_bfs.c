#include <stdio.h>
#define MAXNODES 100
void bfs(int adj[][MAXNODES], int visited[], int start, int numNodes) {
    int q[MAXNODES];
    int rear = -1;
    int front = -1;
    int i;
visited[start] = 1;
    q[++rear] = start;
while (rear != front) {
        start = q[++front];
printf("%d ", start + 1);
 for (i = 0; i<numNodes; i++) {
            if (adj[start][i] && !visited[i]) {
                q[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}
int main() {
    int numNodes, start;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    if (numNodes <= 0) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    int adj[MAXNODES][MAXNODES];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the starting node (1-based): ");
    scanf("%d", &start);

    if (start < 1 || start > numNodes) {
        printf("Invalid starting node.\n");
        return 1;
    }

    start -= 1; // Convert to 0-based index

    int visited[MAXNODES] = {0};

    printf("BFS Traversal: ");
    bfs(adj, visited, start, numNodes);

    return 0;
}