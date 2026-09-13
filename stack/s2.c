//This C program implements a Stack using an array 
// and evaluates a postfix expression containing 
// alphabetic operands.
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 20
typedef enum { False,True} Bool;
typedef struct {
	char val[MAX_SIZE];
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
int length(char n[]);
Bool pop_1(Stack *s);
int av(char letter);
int main() {
	Stack s1;
	s1=CreateStack();
	char n[100];
	printf("enter the string :");
	scanf("%s",n);int i=0,t=0;
while(n[i]!='\0'){
	if(n[i]>='A'&&n[i]<='Z' || n[i]>='a'&&n[i]<='z'){
		push(&s1,n[i]);
	}
	else {
		int a=av(pop(&s1));
		int b=av(pop(&s1));
	switch(n[i]){
		case '+': t=a+b;break;
		case '-': t=a-b;break;
		case '*': t=a*b;break;
		case '/': t=a/b;break;
	 	case '^': t=1;
	 	for (int j = 0; j < b; j++) {
                        t = t * a;
                    }break;
		default: printf("invalid operator\n");}
		push(&s1,(t));
	}i++;
	}
	printf("the result is :%d\n",pop(&s1));}
	int av(char letter) {
    if (letter >= 'a' && letter <= 'z')
        return letter - 'a' + 1;

    if (letter >= 'A' && letter <= 'Z')
        return letter - 'A' + 1;

    return -1;
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
Bool pop_1(Stack *s) {
	if(isEmpty(*s)) {
		return False;
	} int val=0;
	val=s->val[s->top];
	s->top=s->top-1;
	return True;
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
int length(char n[]){int i=0;
    while(n[i]){
        i++;}
        return i;
    }
