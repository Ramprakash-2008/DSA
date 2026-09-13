//This C program creates two singly linked lists and 
// combines their elements into a third linked list
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
NODE* add(NODE* p,NODE* q){
NODE* w=NULL;
while(p){
	w=insertTail(w,p->data);
	p=p->next;
}
while(q){
	w=insertTail(w,q->data);
	q=q->next;

}
return w;
}

int main()//main block of code 
{
int q,p,n1,n2;
NODE* l1=NULL,*l2=NULL,*l3 =NULL;
printf("Enter the no of element list1:");
scanf("%d",&q);
printf("Enter the elements of list: ");
scanf("%d",&n1);
l1=insertHead(l1,n1);
for(int i=0;i<(q-1);i++){
n1=0;
scanf("%d",&n1);
l1=insertTail(l1,n1);}
printf("List1 :");
display(l1);printf("\n");
printf("Enter the no of element list1:");
scanf("%d",&p);
printf("Enter the elements of list: ");
scanf("%d",&n2);
l2=insertHead(l2,n2);
for(int i=0;i<(p-1);i++){
n2=0;
scanf("%d",&n2);
l2=insertTail(l2,n2);}
printf("List2 :");
display(l2);
printf("\n");
l3=add(l1,l2);
printf("LIST3 :");
display(l3);
return 0;
}

