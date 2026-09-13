/*
This C program creates a Singly Linked List and converts 
the elements stored in the linked list into a single number.
Each node contains one digit, and the digits are combined 
sequentially to form a number.*/
#include<stdio.h>
#include<malloc.h>
typedef struct node{
	int data;
	struct node* next;
}NODE;



NODE* makeNode(int data,NODE* next )//memory allocation for linked list
{
	NODE* temp=(NODE*)malloc(sizeof(NODE));
	temp->data=data;
	temp->next=next;
	return temp;
}
NODE* insertHead(NODE* l,int data)//insert element at head
{
NODE* temp=makeNode(data,NULL);temp->next=l;
return temp;
}


NODE* insertTail(NODE* l,int data)//insert element at tail
{
if(!l) return makeNode(data,NULL);
NODE*t =l;
while(t->next)
{
t=t->next;
}
t->next=makeNode(data,NULL);
return l;
}

void display(NODE* l)//display
{
while(l){
printf("%5d",l->data);
l=l->next;}
}


int main()//main block of code 
{
	NODE* n1=NULL;
	n1=get(n1);
	printf("The number : %d",larg(n1));
	return 0;



}

