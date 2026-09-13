/* to find sum of two number which are stored in the reverse order in linkedlist*/
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
NODE* add(NODE* t,NODE* t1){
	NODE* temp=NULL;
	int carry=0,sum=0;
	while(t || t1)
    {
        int a = 0, b = 0;

        if(t)
        {
            a = t->data;
            t = t->next;
        }

        if(t1)
        {
            b = t1->data;
            t1 = t1->next;
        }

        sum = a + b + carry;

        carry = sum / 10;
        sum = sum % 10;

        temp = insertTail(temp, sum);
    }

    if(carry)
        temp = insertTail(temp, carry);

	return temp;
}


