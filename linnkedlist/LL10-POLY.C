/*
This C program implements polynomial operations 
using a singly linked list. Each node represents 
one term of a polynomial containing:

Coefficient
Exponent
Pointer to the next term

The polynomial terms are maintained in descending 
order of exponents.*/
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
typedef struct term{ 
        int coef, expo;
} TERM;
typedef struct node{
    TERM t;
    struct node* next;
}NODE;
NODE* makeNode(int expo,int coef )
{
    NODE* temp=(NODE*)malloc(sizeof(NODE));
    temp->t=(TERM){coef, expo};temp->next=NULL;
return temp;
}
NODE* inSert(NODE* l,int coef,int expo) {
	if(!l) return makeNode(expo,coef);
	if(l->t.expo==expo) { return l; }
    if(l->t.expo < expo) {
		NODE* t=makeNode(expo,coef);
		t->next=l;
		return t;
	}
	l->next=inSert(l->next,coef,expo);
	return l;
}
NODE* inSort(NODE* l, int coef, int expo)
{
    if (!l)
        return makeNode(expo, coef);

    // Same exponent → combine coefficients
    if (l->t.expo == expo)
    {
        l->t.coef += coef;
        return l;
    }

    // New term has higher exponent → insert at beginning
    if (l->t.expo < expo)
    {
        NODE* t = makeNode(expo, coef);
        t->next = l;
        return t;
    }

    // Continue searching
    l->next = inSort(l->next, coef, expo);

    return l;
}
void display(NODE* l)//display
{
	while(l) {
        if(l->t.expo==0) printf("%d ",l->t.coef);
        else if(l->t.expo==1) printf("%dX ",l->t.coef);
        else if(l->t.coef==1) printf("X^%d ",l->t.expo);
        else
		printf("%dX^%d ",l->t.coef,l->t.expo);
		l=l->next;
        if(l) printf("+ ");
	}
}

NODE* scalar(int coef,NODE* l)// multiply the polynomial with a scalar
{
    NODE* t=l;
    while(t){
        t->t.coef*=coef;
        t=t->next;
    }
    return l;
}
NODE* add(NODE* l1,NODE* l2)// add two polynomials
{
    NODE* result=NULL;
    NODE* t1=l1;
    NODE* t2=l2;
    while(t1 || t2){
        if(t1 && (!t2 || t1->t.expo > t2->t.expo)){
            result=inSort(result,t1->t.coef,t1->t.expo);
            t1=t1->next;
        }
        else if(t2 && (!t1 || t1->t.expo < t2->t.expo)){
            result=inSort(result,t2->t.coef,t2->t.expo);
            t2=t2->next;
        }
        else{
            int sum=t1->t.coef+t2->t.coef;
            if(sum!=0)
                result=inSort(result,sum,t1->t.expo);
            t1=t1->next;
            t2=t2->next;
        }
    }
    
    return result;
}
NODE* sub(NODE* l1,NODE* l2)// add two polynomials
{
    NODE* result=NULL;
    NODE* t1=l1;
    NODE* t2=l2;

    
    while(t1 || t2){
        if(t1 && (!t2 || t1->t.expo > t2->t.expo)){
            result=inSort(result,t1->t.coef,t1->t.expo);
            t1=t1->next;
        }
        else if(t2 && (!t1 || t1->t.expo < t2->t.expo)){
            result=inSort(result,-t2->t.coef,t2->t.expo);
            t2=t2->next;
        }
        else{
            int d=t1->t.coef-t2->t.coef;
            if(d!=0)
                result=inSort(result,d,t1->t.expo);
            t1=t1->next;
            t2=t2->next;
        }
    }
    
    return result;
}
NODE* prod(NODE* l,NODE* l2){

    NODE* result=NULL;
    NODE* t1=l;
    NODE* t2;
    while(t1){
        t2=l2;
        while(t2){
        int coef = t1->t.coef * t2->t.coef;
        int expo = t1->t.expo + t2->t.expo;
        result=inSort(result,coef,expo);
        t2=t2->next;}
        t1=t1->next;
    }
    return result;
}
NODE* getPoly(){
    NODE* l=NULL;
    int n,coef,expo;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the coefficient and exponent of term %d: ",i+1);
        scanf("%d %d",&coef,&expo);
        l=inSort(l,coef,expo);
    }
    
    return l;
}
void displayf(NODE* l){
    printf("The polynomial is: ");
    display(l);
    printf("\n");
}
int main(){
    
    NODE* l=NULL;
    int n,coef,expo;
    /*printf("Enter the number of terms: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the coefficient and exponent of term %d: ",i+1);
        scanf("%d %d",&coef,&expo);
        l=inSort(l,coef,expo);
    }
    printf("The polynomial is: ");
    display(l);
    printf("\n");*/
    printf("Enter the coefficient and exponent of the new term to be inserted: ");
    scanf("%d %d",&coef,&expo);
    l=inSert(l,coef,expo);  
    printf("The updated polynomial is: ");
    display(l);
    printf("\n");
    printf("Enter a scalar to multiply the polynomial with: ");
    scanf("%d",&coef);
    l=scalar(coef,l);
    printf("The scaled polynomial is: ");
    display(l);
    printf("\n");
    NODE* l2=NULL;
    printf("Enter the number of terms for the second polynomial: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the coefficient and exponent of term %d: ",i+1);
        scanf("%d %d",&coef,&expo);
        l2=inSort(l2,coef,expo);
    }
    printf("The second polynomial is: ");
    display(l2);
    printf("\n");
    NODE* sum=add(l,l2);
    printf("The sum of the two polynomials is: ");    
    display(sum);
    printf("\n");
    NODE* product=prod(l,l2);
    printf("The product of the two polynomials is:");
    display(product);
    printf("\n");
    NODE* s=sub(l,l2);
    printf("The subtraction of the two polynomials is:");
    display(s);
    printf("\n");
}





