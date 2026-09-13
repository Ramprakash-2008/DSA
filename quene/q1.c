//This C program attempts to validate a string abc.abc (str.str) using queues.
#include<stdio.h>
#include<stdlib.h>
# define max 20 	
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
Bool insert(Q *q,int v){
	if(isFull(*q)) return False;
	q->val[q->rear]=v;
	q->rear=(q->rear+1)%max;
	return True;
	}
char Delete(Q *q){
	if(isEmpty(*q)) return '\0';
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
	int i = q.front;
	while(i != q.rear){
    printf("%c", q.val[i]);
    i = (i + 1) % max;
}

}
int validat(char a[]){	int d=0,c=0;
	Q q1=createQ(length(a)+1);
	Q q2=createQ(length(a)+1);
	for(int i=0;i<length(a);i++){	
	if(a[i]!='.'){
	insert(&q1,a[i]);d++;}	
	else{i++;
	while(i<length(a)){
	insert(&q2,a[i]);c++;
	i++;}	
	}}
	while((!isEmpty(q1))&&(!isEmpty(q2))){
		if(Delete(&q1)!=Delete(&q2)){return 0;}c--;}
//display(q,length(a));
if((isEmpty(q1))&&(isEmpty(q2))){
return 1;}
else return 0;
}
	
int main(){
	char s[15];
	printf("enter the string :");
	scanf("%s",s);
	if(validat(s)){
	printf("valid");
	}
	else printf("not valid");
return 0;
}
	