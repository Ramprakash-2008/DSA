/*
Program Description

This C program demonstrates the implementation of a Singly 
Linked List and performs various operations on three 
different linked lists.

Operations Performed
Node Creation – makeNode()
Dynamically allocates memory for a new node.
Initializes the node with data and a NULL next pointer.
Insert at Head – insertHead()
Adds a new node at the beginning of the linked list.
Insert at Tail – insertTail()
Adds a new node at the end of the linked list.
Display – display()
Traverses and displays all elements in the linked list.
Count Nodes – countNodes()
Counts the total number of nodes in the linked list.
Find Position – findpos()
Searches for a given element and returns its position.
Returns -1 if the element is not found.
Find Sum – findSum()
Recursively calculates the sum of all elements in the linked list.
Reverse Display – printRev()
Uses recursion to display the linked list elements in reverse order.*/
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

int countNodes(NODE* l)// count the no of element in linkedlist
{
int c=0;
while(l){
c++;
l=l->next;
}
return c;
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

int findSum(NODE* l)// return sum of the all element in the linkedlist
{
if(!l) return 0;
return l->data+findSum(l->next);
}

void printRev(NODE* l)//print the element in reverse order 
{
if(l) {
printRev(l->next);printf("%5d",l->data);
}
}

int main()//main block of code 
{
int n,m,d;
NODE* l1=makeNode(200),*l2=makeNode(100);
NODE*l3 =NULL;

l1->next=makeNode(500);
l1=insertHead(l1,1000);

printf("LINKED LIST : \n");
printf("\nList1 :");display(l1);printf("\nCount of list1 : %d\n",countNodes(l1));
printf("enter the n value to search:");
scanf("%d",&n);
printf("position of the %d is : %d\n",n,findpos(l1,n));
printf("Sum of the list is %d\n",findSum(l1));
printf("list1 in reverse order:\n");printRev(l1);

l2=insertHead(l2,1000);

printf("\nList2 :");display(l2);printf("\nCount of list1 : %d\n",countNodes(l2));
printf("enter the m value to search:");
scanf("%d",&m);
printf("position of the %d is : %d\n",m,findpos(l2,m));
printf("Sum of the list is %d\n",findSum(l2));
printf("list2 in reverse order:\n");printRev(l2);

l3=insertHead(l3,2000);
l3=insertTail(l3,1000);

printf("\nList3 :");display(l3);printf("\nCount of list1 : %d\n",countNodes(l3));
printf("enter the d value to search:");
scanf("%d",&d);
printf("position of the %d is : %d\n",d,findpos(l3,d));
printf("Sum of the list is %d\n",findSum(l3));
printf("list3 in reverse order:\n");printRev(l3);


return 0;
}

