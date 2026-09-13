//Your code is trying to validate a string in the format:
// part1.part2.part3 where all three parts should be identical  
// using quene  .
#include<stdio.h>
#include<stdlib.h>
# define max 50 	
typedef enum{False,True}Bool;
typedef struct{
	char val[max];
	int front,rear;
}Q;

Q createQ(int n){ Q q; 
q.rear=q.front=0;
for(int i=0;i<max;i++){
q.val[i]=0;}
return q;
	}
Bool isEmpty(Q q){
	return q.front==q.rear;
	}
Bool isFull(Q q){
	return (q.rear+1)%max==q.front;
	}
Bool insert(Q *q,char v){
	if(isFull(*q)) return False;
	q->val[q->rear]=v;
	q->rear=(q->rear+1)%max;
	return True;
	}
char Delete(Q *q){
	if(isEmpty(*q)) return-1;
	char v=q->val[q->front];
	q->front=(q->front+1)%max;
	
	return v;
	}
int length(char n[]){int i=0;
    while(n[i]){
        i++;}
        return i;
    }
void display(Q q,int n){
	for(int i=0;i<n;i++){
	printf("%c",q.val[i]);
	}
}
int validate(char a[]){	
	Q q=createQ(length(a)+1);
	Q q1=createQ(length(a)+1);
	int i=0;
	while(a[i]!='.'){
		insert(&q,a[i]);i++;
	}
	i++;
	while(a[i]!='.'){
		insert(&q1,a[i]);
		i++;
	}
	i++;
	while(!(isEmpty(q))&&!(isEmpty(q1))){
		if(Delete(&q)!=a[i] || Delete(&q1)!=a[i]){
			return 0;
		}
		i++;
	}
	if(!(isEmpty(q) )|| !(isEmpty(q1))){
		return 0;
	}
	if(a[i]!='\0'){
		return 0;
	}
	return 1;
}	
int main(){
	char s[25];
	printf("enter the string :");
	scanf("%s",s);
	
	if(validate(s)){
	printf("valid");
	}
	else printf("not valid");
return 0;
}
	