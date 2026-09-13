#include <stdio.h>
#include <stdlib.h>

typedef enum { FALSE, TRUE } Bool;

/* Node */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* Queue */
typedef struct {
    Node *front;
    Node *rear;
} Queue;

/* Create queue */
Queue createQueue() {
    Queue q;
    q.front = NULL;
    q.rear = NULL;
    return q;
}

/* Initialize queue */
void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

/* Check whether queue is empty */
Bool isEmpty(Queue *q) {
    return q->front == NULL;
}

/* Enqueue */
Bool enqueue(Queue *q, int val) {
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return FALSE;
    }
    newNode->data = val;
    newNode->next = NULL;

    /* If queue is empty */
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    return TRUE;
}

/* Dequeue */
Bool dequeue(Queue *q, int *val) {
    Node *temp;
    if (isEmpty(q)) {
        return FALSE;
    }
    temp = q->front;
    *val = temp->data;
    q->front = temp->next;

    /* If queue becomes empty */
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return TRUE;
}

/* Peek */
int peek(Queue *q) {
    if (isEmpty(q)) {
        return -1;
    }
    return q->front->data;
}

/* Display */
void display(Queue *q) {
    Node *temp;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Main */
int main() {
    Queue q;
    int val;
    q = createQueue();
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);
    printf("Front element = %d\n", peek(&q));
    if (dequeue(&q, &val)) {
        printf("Dequeued element = %d\n", val);
    }
    display(&q);
    if (dequeue(&q, &val)) {
        printf("Dequeued element = %d\n", val);
    }
    display(&q);
    return 0;
}