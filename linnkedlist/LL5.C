//This C program creates a Singly Linked List and checks 
// whether the elements in the list are arranged in 
// increasing (ascending) order.
#include<stdio.h>
#include<malloc.h>
typedef struct node{
int data;
struct node* next;}NODE;

void display(NODE* l)//display
{
while(l){
printf("%5d",l->data);
l=l->next;}
}

NODE* makeNode(int data )//memory allocation for linked list
{
NODE* temp=(NODE*)malloc(sizeof(NODE));
temp->data=data;temp->next=NULL;
return temp;
}

NODE* insertHead(NODE* l,int data)//insert element at head
{
NODE* temp=makeNode(data);temp->next=l;
return temp;
}

NODE* insertTail(NODE* l,int data)//insert element at tail
{
if(!l) return makeNode(data);
NODE*t =l;
while(t->next)
{
t=t->next;
}
t->next=makeNode(data);
return l;
}



int findpos(NODE* l,int data)//return the position of the element in linkedlist ,if not -1
{
int p=1;
while(l){
if(l->data==data)return p;
l=l->next;
p++;
}
return -1;
}
int inc(NODE* p){
if(p->data >(p->next)->data){
return 0;}
else if(!p->next->next){
return 1;
}
else return inc(p->next);
}

int main()//main block of code 
{
int q,n1;
NODE* l1=NULL,*l2=NULL,*l3 =NULL;
printf("Enter the no of element l1:");
scanf("%d",&q);
printf("Enter the elements of list1: ");
scanf("%d",&n1);
l1=insertHead(l1,n1);
for(int i=0;i<(q-1);i++){
n1=0;
scanf("%d",&n1);
l1=insertTail(l1,n1);}
printf("List1 :");
display(l1);
if(inc(l1)){
printf("List is in increasing order ");}
else printf("List is not in increasing order ");
return 0;
}

