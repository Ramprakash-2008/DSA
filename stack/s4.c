//print reverse string using pop
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 20
typedef enum { False,True} Bool;
typedef struct {
	char val[MAX_SIZE];
	int top;
} Stack;
Stack CreateStack();
int copy_s(Stack *s1,Stack *s2);
Bool isEmpty(Stack s);
Bool isFull(Stack s);
Bool push(Stack *s,int val);
void print(Stack s);
void postfix(char a[]);
int count(Stack s);
int pop(Stack *s);
int peek(Stack s);
int length(char n[]);
int main() {
	Stack s1,s2,s3;
	s1=CreateStack();s2=CreateStack();
	char n[20];
	printf("enter the string :");
	scanf("%s",n);
        for(int i=0;i<length(n);i++){
	push(&s2,n[i]);}
	postfix(n);
	//print(s2);
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
		char t=(char)pop(&s);
		printf("%c",t);
}printf("\n");
}
int copy_s(Stack *s1,Stack *s2){
    Stack s3;int c=0;
    s3=CreateStack();
    while(!isEmpty(*s1)){
		c++;
        push(&s3,pop(s1));
    }
    while(!isEmpty(s3)){
        int t=pop(&s3);
        push(s2,t);
        push(s1,t);
    }
	return c;
}
int length(char n[]){int i=0;
    while(n[i]){
        i++;}
        return i;
    }
int ISP(char ch)
{
    if(ch == '(')
        return 1;
    if(ch == '^')
        return 6;
    if(ch == '*' || ch == '/')
        return 5;
    if(ch == '+' || ch == '-')
        return 3;

    return 0;
}

int ICP(char ch)
{
    if(ch == '(')
        return 8;
    if(ch == '^')
        return 7;
    if(ch == '*' || ch == '/')
        return 4;
    if(ch == '+' || ch == '-')
        return 2;

    return 0;
}
void postfix(char a[]){
	Stack s=CreateStack();
	for(int i=0;i<length(a);i++){
		if(a[i]=='(') push(&s,a[i]);
		else if(a[i]==')') {
			while(peek(s)!='(')
			{
				printf("%c",pop(&s));
			}
			pop(&s);}

		else if(a[i]=='+' || a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='^'){
			while(!(isEmpty(s))&& (ISP(peek(s))>=ICP(a[i]))){
				printf("%c",pop(&s));
			}
			push(&s,a[i]);
		}
		else printf("%c",a[i]);
       	}
		printf("\n");
}
