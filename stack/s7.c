//validity of abc.cba.abc true// abc.cba.acd  false
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
int valid(char n[]);
int main() {
	Stack s1,s2,s3;
	int c=0;
	s1=CreateStack();s2=CreateStack();
	char n[20],m[20];
	printf("enter the string :");
	scanf("%s",n);
	int j=0;
	for(int i=0;i<length(n);i++){
		if(n[i]=='.'){i++;
			while(n[i]!='\0'){
				push(&s1,n[i]);i++;}
			break;}
		}	
	int i=0;
	while(!isEmpty(s1)){
    m[i++] = pop(&s1);
	}m[i] = '\0';
	if(valid(n)&&valid(m)){printf("valid");}
	else printf("invalid");}

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
int valid(char n[]){ Stack s1=CreateStack();
for(int i=0;i<length(n);){
	if(n[i]>='A'&& n[i]<='Z'){
		push(&s1,n[i]);i++;}
	
	else if(n[i]=='a'&& n[i]<='z'){
		if(isEmpty(s1)){return 0;}
		else if(n[i]-32==peek(s1)){
			pop_1(&s1);i++;}
		else return 0;
	
	}      	 
	return 1;
	}}
 