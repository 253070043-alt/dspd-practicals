#include <stdio.h>
#include <stdlib.h>
struct Edge {
    int src, dest, weight;
};
struct Set {
    int parent;
    int rank;
};
int find(struct Set set[], int i) {
    if (set[i].parent != i)
        set[i].parent = find(set, set[i].parent);
    return set[i].parent;
}
void Union(struct Set set[], int x, int y) {
    int xroot = find(set, x);
    int yroot = find(set, y);
    if (set[xroot].rank < set[yroot].rank)
        set[xroot].parent = yroot;
    else if (set[xroot].rank > set[yroot].rank)
        set[yroot].parent = xroot;
    else {
        set[yroot].parent = xroot;
        set[xroot].rank++;
    }
}
int compareEdges(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

void kruskalMST(struct Edge edges[], int V, int E) {
    struct Edge *result = (struct Edge *)malloc(V * sizeof(struct Edge));
    int e = 0, i = 0;
    qsort(edges, E, sizeof(edges[0]), compareEdges);
    struct Set *set = (struct Set *)malloc(V * sizeof(struct Set));
    int v;
    for (v = 0; v < V; v++) {
        set[v].parent = v;
        set[v].rank = 0;
    }
    while (e < V - 1 && i < E) {
        struct Edge next = edges[i++];
        int x = find(set, next.src);
        int y = find(set, next.dest);
        if (x != y) {
            result[e++] = next;
            Union(set, x, y);
        }
    }
    printf("\nEdges in the Minimum Spanning Tree (MST):\n");
    int totalWeight = 0;
    for (i = 0; i < e; i++) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        totalWeight += result[i].weight;
    }
    printf("Total weight of MST: %d\n", totalWeight);
    free(result);
    free(set);
}
int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    struct Edge *edges = (struct Edge *)malloc(E * sizeof(struct Edge));
    printf("Enter edges (source destination weight):\n");
    int i;
    for (i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    kruskalMST(edges, V, E);
    free(edges);
    return 0;
}

