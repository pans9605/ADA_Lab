#include <stdio.h>
#define INF 9999

// Function to find the vertex with the minimum distance
int minDistance(int dist[], int visited[], int V) {
    int min = INF, min_index;
    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

// Dijkstra’s algorithm implementation
void dijkstra(int V, int graph[V][V], int src) {
    int dist[V], visited[V];

    // Initialize distances and visited array
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        visited[u] = 1;

        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print the shortest distances
    printf("\nVertex \t Distance from Source %d\n", src);
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int V;

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[V][V];

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (0 if no edge, weight otherwise):\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    int src;
    printf("Enter the source vertex (0 to %d): ", V - 1);
    scanf("%d", &src);

    dijkstra(V, graph, src);
    return 0;
}
