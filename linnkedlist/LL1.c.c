/*This C program implements a Sorted Singly Linked List. 
It inserts elements automatically in ascending order, 
displays them in both ascending and descending order, 
and deletes a specified element.*/
#include<malloc.h>
#include<stdio.h>
typedef struct node {
	int data;
	struct node*next;
} NODE;
NODE* makeNode(int data,NODE* next )//memory allocation for linked list
{
	NODE* temp=(NODE*)malloc(sizeof(NODE));
	temp->data=data;
	temp->next=next;
	return temp;
}


void desprint(NODE* l) {
	if(l) {
		desprint(l->next);
		printf("%5d",l->data);
	}
}
void display(NODE* l)//display
{
	while(l) {
		printf("%5d",l->data);
		l=l->next;
	}
}
int main() {
	NODE* n1=NULL;
	int val,n,d;
	printf("enter the no of elements :");
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		printf("enter the element %d :",i+1);
		scanf("%d",&val);
		n1=inSort(n1,val);
	}
	printf("Ascending Order : ");
	display(n1);
	printf("\n");
	printf("Descending Order: ");
	desprint(n1);
	printf("\nEnter the element to be deleted : ");
	scanf("%d",&d);
	n1=delSort(n1,d);
	printf("List after deleted element %d :\n",d);
	display(n1);
	return 0;

}
