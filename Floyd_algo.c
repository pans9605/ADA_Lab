#include <stdio.h>

#define INF 99999  // A large number to represent infinity
#define V 4        // Number of vertices in the graph

// Function to implement Floyd’s algorithm
void floydWarshall(int graph[V][V]) {
    int dist[V][V];

    // Step 1: Initialize dist matrix with graph matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Step 2: Update distances using intermediate vertices
    for (int k = 0; k < V; k++) {           // Pick all vertices as intermediate
        for (int i = 0; i < V; i++) {       // Pick all source vertices
            for (int j = 0; j < V; j++) {   // Pick all destination vertices
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];  // Update if shorter path found
            }
        }
    }

    // Step 3: Print the final shortest distance matrix
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = {
        {0,   5,  INF, 10},
        {INF, 0,   3,  INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    floydWarshall(graph);  // Call the function
    return 0;
}
