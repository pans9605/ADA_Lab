#include <stdio.h>
#define MAX 100

void dfs(int v, int n, int adj[MAX][MAX], int visited[MAX], int stack[MAX], int *top) {
    visited[v] = 1;
    for (int i = 0; i < n; i++)
        if (adj[v][i] && !visited[i])
            dfs(i, n, adj, visited, stack, top);
    stack[++(*top)] = v;
}

void topologicalSort(int n, int adj[MAX][MAX]) {
    int visited[MAX] = {0}, stack[MAX], top = -1;
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i, n, adj, visited, stack, &top);
    while (top >= 0)
        printf("%d ", stack[top--]);
}

int main() {
    int n, edges, u, v, adj[MAX][MAX] = {0};
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &edges);
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
    printf("Topological Order: ");
    topologicalSort(n, adj);
    return 0;
}
