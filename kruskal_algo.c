#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100
#define MAX_VERTICES 100

typedef struct{
    int src;
    int des;
    int weight;
}Edge;

typedef struct{
    int V;
    int E;
    Edge edges[MAX_EDGES];
}Graph;

typedef struct{
    int parent;
    int rank;
}Subset;

int CompareEdges(const void *a, const void *b){
    return ((Edge *)a)->weight-((Edge *)b)->weight;
}

int find(Subset subsets[], int i){
    if(subsets[i].parent!=i){
        subsets[i].parent=find(subsets,subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

void KruskalMST(Graph *graph) {
    Edge result[MAX_VERTICES]; // Store the resultant MST
    int e = 0, i = 0; // Count of edges in MST

    // Sort edges by increasing weight
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), CompareEdges);

    // Allocate memory for subsets
    Subset subsets[MAX_VERTICES];
    for (int v = 0; v < graph->V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Pick the smallest edges one by one
    while (e < graph->V - 1 && i < graph->E) {
        Edge next_edge = graph->edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.des);

        if (x != y) { // No cycle
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    printf("Kruskal's MST:\n");
    for (i = 0; i < e; i++)
        printf("%d -- %d == %d\n", result[i].src, result[i].des, result[i].weight);
}


int main() {
    Graph graph;
    graph.V = 4;
    graph.E = 5;

    graph.edges[0] = (Edge){0, 1, 10};
    graph.edges[1] = (Edge){0, 2, 6};
    graph.edges[2] = (Edge){0, 3, 5};
    graph.edges[3] = (Edge){1, 3, 15};
    graph.edges[4] = (Edge){2, 3, 4};

    KruskalMST(&graph);

    return 0;
}


