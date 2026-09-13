//w.w.w  verification using quene
#include<stdio.h>
#include<stdlib.h>
typedef enum{ false,true}BOOL;
typedef struct {
	char a[100];
	int rear,front;
	}Q;
void init(Q *q){
	q->rear=q->front=0;}
	
BOOL isempty(Q q){
	return q.rear==q.front;
	}
BOOL isfull(Q q){
	return (q.rear+1)%100==q.front;
	}
BOOL insert(Q *q,char c){
	if(isfull(*q)) return false;
	q->a[q->rear]=c;
	q->rear=(q->rear+1)%100;

	return true;
}
char d(Q *q){char c;
	if(isempty(*q)) return '\0';
	c=q->a[q->front];
	q->front=q->front +1;
	return c;
}
int length(char* s){
	int c=0;
	while(s[c]!='\0'){
	c++;}
	return c;
}
int validate(char* s){
	Q q,q1,q2,q3;
	init(&q);init(&q1);init(&q2);init(&q3);
	for(int i=0;i<length(s);){
		while(s[i]!='.'){
			insert(&q,s[i]);insert(&q3,s[i]);i++;
			}
		i++;
		while(s[i]!='.'){
			insert(&q1,s[i]);i++;}
		i++;
		while(s[i]!='\0'){
			insert(&q2,s[i]);i++;}
		i++;}
		while(!isempty(q)&&!isempty(q1)&&!isempty(q2)&&!isempty(q3)){
			if(d(&q)!=d(&q1) || d(&q3)!=d(&q2)){ return 0;}
			}
		if(!isempty(q) || !isempty(q1) || !isempty(q2) || !isempty(q3)){return 0;}
		else return 1;

}
		
int main(){
	char *z=(char*)malloc(25*sizeof(char));
	printf("enter the string:");
	scanf("%s",z);	
	printf("%d",validate(z));
}



