#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int V;
    int **mat;
} Graph;
Graph* createGraph(int V)
{
    Graph *g = malloc(sizeof(Graph));
    g->V = V;
    // Allocate rows
    g->mat = malloc(V * sizeof(int*));
    // Allocate columns
    for (int i = 0; i < V; i++)
    {
        g->mat[i] = calloc(V, sizeof(int));
    }
    return g;
}

void addEdge(Graph *g, int u, int v)
{
    g->mat[u][v] = 1;
    g->mat[v][u] = 1;
}

void display(Graph *g)
{
    for (int i = 0; i < g->V; i++)
    {
        for (int j = 0; j < g->V; j++)
            printf("%d ", g->mat[i][j]);
        printf("\n");
    }
}

void freeGraph(Graph *g)
{
    for (int i = 0; i < g->V; i++)
        free(g->mat[i]);
    free(g->mat);
    free(g);
}

int main()
{
    Graph *g = createGraph(3);

    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);

    display(g);

    freeGraph(g);

    return 0;
}