//Your program is intended to check whether a string is a palindrome using both a Queue and a Stack
#include<stdio.h>
#include<stdlib.h>
# define max 20 
typedef struct {
	char val[max];
	int top;
} Stack;
typedef enum{False,True}Bool;
typedef struct{
	char val[max];
	int front,rear;
}Q;

Stack CreateStack();
void copy_s(Stack *s1,Stack *s2);
Bool push(Stack *s,int val);
void print(Stack s);
int pop(Stack *s);
int peek(Stack s);
int length(char n[]);
Bool pop_1(Stack *s);
	

Q createQ(int n){ Q q; 
q.rear=q.front=0;
for(int i=0;i<n;i++){
q.val[i]=0;}
return q;
	}
Bool isEmpty1(Q q){
	return q.front==q.rear;
	}
Bool isFull1(Q q){
	return (q.rear+1)%max==q.front;
	}
Bool insert(Q *q, int v){
    if(isFull1(*q))
        return False;

    q->val[q->rear] = v;
    q->rear = (q->rear + 1) % max;

    return True;
}

char Delete(Q *q){
    if(isEmpty1(*q))
        return '\0';

    char v = q->val[q->front];
    q->front = (q->front + 1) % max;

    return v;
}
int length(char n[]){int i=0;
    while(n[i]){
        i++;}
        return i;
    }
void display(Q q){
	int i = q.front;
	while(i != q.rear){
    printf("%c", q.val[i]);
    i = (i + 1) % max;
}

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
	return s.top==max-1;
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
int validat(char a[]){char z,b;
	Q q=createQ(length(a)+1);
	Stack s=CreateStack();int i=0;
	while(i<length(a)){
	insert(&q,a[i]);
	push(&s,a[i]);i++;}
	while((z=Delete(&q))!='\0'){	
		b=pop(&s);
	if(z!=b){	
		printf("Not equal");return 0;}}
	printf("Equal");
	return 1;}
	
int main(){
	char s[15],v[15];
	printf("enter the string :");
	scanf("%s",s);
	validat(s);

return 0;
}
	