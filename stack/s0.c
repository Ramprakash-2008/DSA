/*
This C program demonstrates the basic operations of a 
Stack using an array and separates randomly generated 
numbers into odd and even stacks.*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
typedef enum { False,True} Bool;
typedef struct {
	int val[MAX_SIZE];
	int top;
} Stack;
Stack CreateStack();
Bool isEmpty(Stack s);
Bool isFull(Stack s);
Bool push(Stack *s,int val);
void print(Stack s);
int pop(Stack *s);
int peek(Stack s);
int main() {
	Stack s1,s2;
	s1=CreateStack();s2=CreateStack();
	int n=0;printf("enter the n value :");
	scanf("%d",&n);
        for(int i=0;i<n;i++){int t=rand()%10;
		if(t%2!=0){push(&s1,t);}
		else push(&s2,t);}
		printf("stack 1:");
		print(s1);
		printf("stack 2:");
		print(s2);
	return 0;
}
Stack CreateStack() {
	Stack s;
	s.top=0;
	return s;
}
Bool isEmpty(Stack s) {
	return s.top==0;
}
Bool isFull(Stack s) {
	return s.top==MAX_SIZE-1;
}
Bool push(Stack *s,int val) {
	if(isFull(*s)) {
		return False;
	}
	s->top=s->top+1;
	s->val[s->top]=val;
	return True;
}
int pop(Stack *s) {
	if(isEmpty(*s)) {
		return -1;
	} int val=0;
	val=s->val[s->top];
	s->top=s->top-1;
	return val;
}
int peek(Stack s) {
	if(isEmpty(s))return -9999;
	return s.val[s.top];
}
void print(Stack s) {
	while(!isEmpty(s)) {
		int t=(int)pop(&s);
		printf("%d\t",t);
}printf("\n");
}
