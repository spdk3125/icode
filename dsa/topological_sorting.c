#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int n; 
int adj[MAX][MAX]; 
int visited[MAX]; 
int stack[MAX]; 
int top = -1;
void dfs(int v) {
    visited[v] = 1;
   for (int i = 0; i< n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
    stack[++top] = v; }
void topologicalSort() {
    for (int i = 0; i< n; i++) {
        visited[i] = 0; // Initialize visited array
    }
   for (int i = 0; i< n; i++) {
 if (!visited[i]) {
            dfs(i); 
        }
    }
   printf("The topological order is: ");
    while (top != -1) {
        printf("%d ", stack[top--] + 1); 
    }
    printf("\n");}
int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
   printf("Enter the adjacency matrix:\n");
    for (int i = 0; i< n; i++) {
        printf("Enter row %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    topologicalSort();
    return 0;
}

