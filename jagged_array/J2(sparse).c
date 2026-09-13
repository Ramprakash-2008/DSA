//jagged array used to represent the spaarse matrix
#include<stdlib.h>
#include<stdio.h>
typedef struct node{
    int data;
    int col;
    struct node* next;
}Node;
typedef struct point{
    int data;
    struct node* col;
    struct point* row;
}Jag;
Node* makeNode(int data,int col){
    Node* t=(Node*)malloc(sizeof(Node));
    t->data=data;t->col=col;t->next=NULL;
    return t;
}
Jag* makeJag(int data){
    Jag* t=(Jag*)malloc(sizeof(Jag));
    t->data=data;t->col=NULL;t->row=NULL;
    return t;
}
/*
Jag* insertrow(Jag* i,int data){
    Jag* t=makeJag(data);
    if(!i) return t;
    while(i->row){
        i=i->row;
    }
    i->row=t;
    return t;
}*/
Jag* insertrow(Jag* i,int data){
    if(!i) return makeJag(0);int j=1;
    Jag* t=i;
    while(t->row){
        t=t->row;j++;
    }
    t->row=makeJag(j);
    return t->row;
}

Node* insertCol(Node* l,int col,int data)//insert element at tail
{
if(!l) return makeNode(data,col);
Node*t =l;
while(t->next)
{
t=t->next;
}
t->next=makeNode(data,col);
return l;
}
void print(Jag* j){
    int i=1;
    while(j){ 
        printf("Row %d:",i);
        Node* p=j->col;
        while(p){ 
            printf("(%d,%d) ",p->col,p->data);
        p=p->next;
        }
        printf("\n");
        j=j->row;
        i++;
    }
}
int** sparsegen(int ro, int c)
{
    int** a = (int**)malloc(ro * sizeof(int*));
    for(int i = 0; i < ro; i++)
    {
        a[i] = (int*)malloc(c * sizeof(int));
    }
    for(int i = 0; i < ro; i++)
    {
        for(int j = 0; j < c; j++)
        {
            a[i][j] = ((rand() % 10) * (rand() % 2)) * (rand() % 2);
        }
    }
    return a;
}
Jag* spartojag(int** a, int ro, int c)
{
    Jag* g = NULL;
    Jag* p = NULL;
    for(int i = 0; i < ro; i++)
    {
        if(!g)
        {
            g = insertrow(g, i + 1);
            p = g;
        }
        else
        {
            p = insertrow(g, i + 1);
        }
        for(int j = 0; j < c; j++)
        {
            if(a[i][j] != 0)
            {
                p->col = insertCol(p->col, j, a[i][j]);
            }
        }
    }
    return g;
}
int** jagtospar(Jag* a,int ro,int c)
{
    Jag* g = a;
    int** b = (int**)malloc(ro * sizeof(int*));
    for(int i = 0; i < ro; i++)
    {
        b[i] = (int*)malloc(c * sizeof(int));
    }
    for(int i = 0; i < ro; i++)
    {
        for(int j = 0; j < c; j++)
        {
            b[i][j] = 0;
        }
    }
    while(g){ 
        Node* p=g->col;
        while(p){ 
            b[g->data][p->col]=p->data;
        p=p->next;
        }
        g=g->row;
    }
    return b;
}
void display_sparse(int** a,int ro,int c){
    printf("Sparse matrix :\n");
    for(int i=0;i<ro;i++){
        for(int j=0;j<c;j++){
            printf("%d\t",a[i][j]);
        }printf("\n");
    }printf("\n");
}
int main()
{
    int ro,c;Jag* j=NULL;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d",&ro,&c);
    int** a=sparsegen( ro, c),**b;
    display_sparse(a,ro,c);
    j=spartojag(a,ro,c);
    b=jagtospar(j,ro,c);
    print(j);
    display_sparse(b,ro,c);
    return 0;
}