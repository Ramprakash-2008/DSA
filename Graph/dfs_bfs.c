void DFS(Graph *g, int vertex, int visited[]) {

    visited[vertex] = 1;

    printf("%d ", vertex);

    Node *temp = g->adj[vertex];

    while (temp != NULL) {

        int nextVertex = temp->vertex;

        if (visited[nextVertex] == 0) {
            DFS(g, nextVertex, visited);
        }

        temp = temp->next;
    }
}


// BFS
void BFS(Graph *g, int start) {

    int visited[g->V];

    for (int i = 0; i < g->V; i++) {
        visited[i] = 0;
    }

    int queue[g->V];

    int front = 0;
    int rear = 0;

    visited[start] = 1;

    queue[rear++] = start;

    while (front < rear) {

        int vertex = queue[front++];

        printf("%d ", vertex);

        Node *temp = g->adj[vertex];

        while (temp != NULL) {

            int nextVertex = temp->vertex;

            if (visited[nextVertex] == 0) {

                visited[nextVertex] = 1;

                queue[rear++] = nextVertex;
            }

            temp = temp->next;
        }
    }
}
