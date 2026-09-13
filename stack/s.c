//copy operation for a stack while preserving the original stack.
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
typedef enum { False,True} Bool;
typedef struct {
	int val[MAX_SIZE];
	int top;
} Stack;
Stack CreateStack();
void copy_s(Stack *s1,Stack *s2);
Bool isEmpty(Stack s);
Bool isFull(Stack s);
Bool push(Stack *s,int val);
void print(Stack s);
int pop(Stack *s);
int peek(Stack s);
int main() {
	Stack s1,s2,s3;
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
		copy_s(&s1,&s3);
		printf("copied stack :");
		print(s3);
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
void copy_s(Stack *s1,Stack *s2){
    Stack s3;
    s3=CreateStack();
    while(!isEmpty(*s1)){
        push(&s3,pop(s1));
    }
    while(!isEmpty(s3)){
        int t=pop(&s3);
        push(s2,t);
        push(s1,t);
    }
}