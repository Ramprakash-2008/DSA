#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

typedef struct
{
    int V;
    Node **adj;
} Graph;

Node* createNode(int v)
{
    Node *newNode = malloc(sizeof(Node));

    newNode->vertex = v;
    newNode->next = NULL;

    return newNode;
}

Graph* createGraph(int V)
{
    Graph *g = malloc(sizeof(Graph));

    g->V = V;

    // Allocate array of pointers
    g->adj = malloc(V * sizeof(Node*));

    for (int i = 0; i < V; i++)
        g->adj[i] = NULL;

    return g;
}

void addEdge(Graph *g, int u, int v)
{
    Node *newNode;

    // u -> v
    newNode = createNode(v);
    newNode->next = g->adj[u];
    g->adj[u] = newNode;

    // v -> u
    newNode = createNode(u);
    newNode->next = g->adj[v];
    g->adj[v] = newNode;
}

void display(Graph *g)
{
    for (int i = 0; i < g->V; i++)
    {
        Node *temp = g->adj[i];

        printf("%d -> ", i);

        while (temp != NULL)
        {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }

        printf("\n");
    }
}

void freeGraph(Graph *g)
{
    for (int i = 0; i < g->V; i++)
    {
        Node *temp = g->adj[i];

        while (temp != NULL)
        {
            Node *next = temp->next;
            free(temp);
            temp = next;
        }
    }

    free(g->adj);
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