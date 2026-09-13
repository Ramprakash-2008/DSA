#include <stdio.h>
#include <stdlib.h>

typedef enum { FALSE, TRUE } Bool;

/* Node structure */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* Stack structure */
typedef struct {
    Node *top;
} Stack;

/* Create / initialize stack */
Stack createStack() {
    Stack s;
    s.top = NULL;
    return s;
}

/* Initialize stack */
void initStack(Stack *s) {
    s->top = NULL;
}

/* Check whether stack is empty */
Bool isEmpty(Stack *s) {
    return s->top == NULL;
}

/* Push operation */
Bool push(Stack *s, int val) {
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return FALSE;
    }
    newNode->data = val;
    newNode->next = s->top;
    s->top = newNode;
    return TRUE;
}

/* Pop operation */
Bool pop(Stack *s, int *val) {
    Node *temp;
    if (isEmpty(s)) {
        return FALSE;
    }
    temp = s->top;
    *val = temp->data;
    s->top = temp->next;
    free(temp);
    return TRUE;
}

/* Peek operation */
int peek(Stack *s) {
    if (isEmpty(s)) {
        return -1;
    }
    return s->top->data;
}

/* Display stack */
void display(Stack *s) {
    Node *temp;
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    temp = s->top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Main function */
int main() {
    Stack s;
    int val;

    /* Create stack */
    s = createStack();

    /* Push elements */
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);

    /* Peek */
    printf("Top element = %d\n", peek(&s));

    /* Pop */
    if (pop(&s, &val)) {
        printf("Popped element = %d\n", val);
    }
    display(&s);

    /* Pop again */
    if (pop(&s, &val)) {
        printf("Popped element = %d\n", val);
    }
    display(&s);
    return 0;
}