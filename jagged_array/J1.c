//This C program demonstrates the implementation of a Jagged Array using Linked Lists.
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
Node* makeNode(int data){
    Node* t=(Node*)malloc(sizeof(Node));
    t->data=data;t->next=NULL;
    return t;
}
Jag* makeJag(int data){
    Jag* t=(Jag*)malloc(sizeof(Jag));
    t->data=data;t->col=NULL;t->row=NULL;
    return t;
}
Jag* insertrow(Jag* i,int data){
    Jag* t=makeJag(data);
    if(!i) return t;
    while(i->row){
        i=i->row;
    }
    i->row=t;
    return t;
}

Node* insertCol(Node* l,int data)//insert element at tail
{
if(!l) return makeNode(data);
Node*t =l;
while(t->next)
{
t=t->next;
}
t->next=makeNode(data);
return l;
}
void print(Jag* j){
    int i=1;
    while(j){ 
        printf("Row %d:",i);
        Node* p=j->col;
        while(p){ 
            printf("%d ",p->data);
        p=p->next;
        }
        printf("\n");
        j=j->row;
        i++;
    }
}
int main()
{
    Jag* g = NULL, *p = NULL;int r=5;
    for(int i=0;i<r;i++){
        if(!g){
            g=insertrow(g,i+1);
            p=g;
        }
        else p=insertrow(g,i+1);
        int c=rand()%10;
        for(int j=0;j<=c;j++){
            p->col=insertCol(p->col,rand()%1000);
        }
    }
    print(g);
    return 0;
}