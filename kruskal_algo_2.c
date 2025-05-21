#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void unionSets(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

int compareEdges(const void *a, const void *b) {
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

void kruskalsAlgorithm(Edge edges[], int V, int E) {
    int parent[V], rank[V];

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    qsort(edges, E, sizeof(Edge), compareEdges);

    Edge result[V];
    int e = 0, i = 0;

    while (e < V - 1 && i < E) {
        Edge next = edges[i++];
        int x = find(parent, next.u);
        int y = find(parent, next.v);

        if (x != y) {
            result[e++] = next;
            unionSets(parent, rank, x, y);
        }
    }

    printf("Edge \tWeight\n");
    for (i = 0; i < e; i++)
        printf("%d - %d \t%d\n", result[i].u, result[i].v, result[i].w);
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    Edge edges[E];

    printf("Enter each edge as: <u> <v> <weight>\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    kruskalsAlgorithm(edges, V, E);

    return 0;
}
