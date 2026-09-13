//This C program evaluates a postfix (Reverse Polish Notation) 
// expression using a stack implemented with a linked list.
// This C program evaluates a postfix (Reverse Polish Notation)
//  expression using a stack implemented with a linked list.
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 30
typedef enum{FALSE,TRUE}Bool;
typedef struct node{
int data; struct node *next;
}NODE;
typedef struct{NODE *top;}Stack;

NODE* makeNode(int data,NODE *next)
{
    NODE *t=(NODE*)malloc(sizeof(NODE));
    t->data=data;t->next=next;
    return t;
}
NODE* makeNode1()
{
    NODE *t=(NODE*)malloc(sizeof(NODE));
    return t;
}
Stack createStack()
{
    Stack s;s.top=NULL;
    return s;
}

Bool isEmpty(Stack *s)
{
    return(s->top==NULL);
}
Bool push(Stack *s,int val)
{
    NODE * new=makeNode(val,s->top);
    if(new == NULL) return FALSE;
    s->top=new;
    return TRUE;
}
Bool pop(Stack *s,int *val)
{
    if(isEmpty(s)) return FALSE;
    NODE *tem=s->top;
    *val=tem->data;
    s->top=tem->next;
    free(tem);
    return TRUE;
}
int peek(Stack *s)
{
    if(isEmpty(s)) return -9999;return s->top->data;
}
void disp(Stack s)
{
    NODE *tem;
    if(isEmpty(&s))
    {
        printf("\nStack is empty\n");return;
    }
    tem=s.top;
    while(tem!=NULL)
    {
        printf("%d",tem->data);
        tem=tem->next;
    }
    printf("\n");
}
int main()
{
    Stack s = createStack();

    char arr[100];
    int i = 0;
    int ch1, ch2, res;

    printf("Enter the string: ");
    scanf("%s", arr);

    while(arr[i])
    {
        if(arr[i] >= '0' && arr[i] <= '9')
        {
            push(&s, arr[i] - '0');
        }

        else if(arr[i] == '+' ||
                arr[i] == '-' ||
                arr[i] == '*' ||
                arr[i] == '/' ||
                arr[i] == '%')
        {
            pop(&s, &ch1);
            pop(&s, &ch2);

            if(arr[i] == '+')
                res = ch2 + ch1;

            else if(arr[i] == '-')
                res = ch2 - ch1;

            else if(arr[i] == '*')
                res = ch2 * ch1;

            else if(arr[i] == '/')
                res = ch2 / ch1;

            else
                res = ch2 % ch1;

            push(&s, res);
        }

        i++;
    }

    pop(&s, &res);

    printf("%d", res);

    return 0;
}