#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int ivex;
    int jvex;

    struct Edge *ilink;
    struct Edge *jlink;
} Edge;

typedef struct {
    int V;
    Edge **firstEdge;
} Graph;

Graph* createGraph(int V) {

    Graph *g = (Graph*)malloc(sizeof(Graph));

    g->V = V;

    g->firstEdge =
        (Edge**)malloc(V * sizeof(Edge*));

    for (int i = 0; i < V; i++) {
        g->firstEdge[i] = NULL;
    }

    return g;
}

Edge* createEdge(int u, int v) {

    Edge *e = (Edge*)malloc(sizeof(Edge));

    e->ivex = u;
    e->jvex = v;

    e->ilink = NULL;
    e->jlink = NULL;

    return e;
}