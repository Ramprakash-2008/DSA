/*
This C program implements a Circular Singly Linked List a
nd performs various operations such as insertion, display, 
counting nodes, reversing the list, and finding the preceding 
and succeeding elements.*/
#include<stdio.h>
#include<malloc.h>
typedef struct node{
	int data;
	struct node* next;
}NODE;

void dC(NODE* l)//display
{
	if(l){
		NODE* t=l;
		printf("%d",l->data);
		while(t->next != l){
			t=t->next;
			printf("%5d",t->data);
		}
	}
}

NODE* makeNode(int data,NODE* next )//memory allocation for linked list
{
	NODE* temp=(NODE*)malloc(sizeof(NODE));
	temp->data=data;
	temp->next=next;
	return temp;
}

NODE* insertCir(NODE* l,int data)//insert element at head
{
	if(!l)
	{
		NODE* temp=makeNode(data,NULL);
		temp->next=temp;
		return temp;
	}
	NODE* t=l;
	while(t->next && t->next!=l) t=t->next;
	NODE* temp=makeNode(data,l);
	t->next=temp;
	return l;
	
}
NODE* insert(NODE* l,int data)//insert element at head
{
	if(!l)
	{
		NODE* temp=makeNode(data,NULL);
		temp->next=temp;
		return temp;
	}


	NODE* temp=makeNode(data,l->next);
    l->next=temp;
	return l;
	
}


int countNodes(NODE* l)// count the no of element in linkedlist
{
if(!l) return 0;
int c=0;
NODE* t=l;
while(t && t->next!=l){
c++;
t=t->next;
}
c++;
return c;
}

int search(NODE* l,int data)//return the position of the element in linkedlist ,if not -1
{
if(!l) return 0;
NODE* t=l;
while(t->next!=l){
if(t->data==data)return 1;
t=t->next;
}
return 0;
}

int searchs(NODE* l,int data)//return the position of the element in linkedlist ,if not -1
{

if(!l) return 0;
NODE* t=l;
while(t->next!=l){
if(t->data==data)return (t->next)->data;
t=t->next;
}
return -1;
}

int searchp(NODE* l,int data)//return the position of the element in linkedlist ,if not -1
{
if(!l) return 0;
NODE* t=l;
while(t->next!=l){
if((t->next)->data==data)return t->data;
t=t->next;
}
return -1;
}

NODE* printRev(NODE* l)//print the element in reverse order 
{
    if(!l) return l;
    NODE* t=NULL;NODE* temp=l;
    while(temp->next!=l)temp=temp->next;
    t=makeNode(temp->data,NULL);
    t->next=t;temp=l;
    while(temp->next!=l){
        t=insert(t,temp->data);temp=temp->next;}
        return t;
    
}
/*
NODE* reverse(NODE* l)
{
    NODE *prev = NULL, *cur = l, *next;

    do {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    } while(cur != l);

    l->next = prev;
    return prev;
}
	*/

int main()//main block of code 
{
	NODE* n1=NULL;
	
	int val,n,d;
	printf("enter the no of elements :");
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		printf("enter the element %d :",i+1);
		scanf("%d",&val);
		n1=insertCir(n1,val);
		
	}
    
	dC(n1);
	printf("\ncount : %d\n",countNodes(n1));
	n1=printRev(n1);
	printf("Reverse order :");
	dC(n1);
	printf("\nenter the value to be searched : ");
	scanf("%d",&d);
	
	printf("the preceeding value : %d",searchp(n1,d));

	printf("\nthe succeeding value : %d",searchs(n1,d));
	return 0;



}

