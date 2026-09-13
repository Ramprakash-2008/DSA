//This C program validates a string using two Queue comparisons 
// and one Stack comparison to validate str.str.rts 
typedef struct {
	char val[max];
	int top;
} Stack;
typedef enum{False,True}Bool;
typedef struct{
	char val[max];
	int front,rear;
}Q;



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
Bool insert(Q *q,int v){
	if(isFull1(*q)) return False;
	q->val[q->rear]=v;
	q->rear=(q->rear+1)%max;
	return True;
	}
char Delete(Q *q){
	if(isEmpty1(*q)) return '\0';
	char v=q->val[q->front];
	q->front=(q->front+1)%max;
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
Bool push(Stack *s,char val) {
	if(isFull(*s)) {
		return False;
	}
	s->top=s->top+1;
	s->val[s->top]=val;
	return True;
}
char pop(Stack *s) {
	if(isEmpty(*s)) {
		return -1;
	} char val=0;
	val=s->val[s->top];
	s->top=s->top-1;
	return val;
}
Bool pop_1(Stack *s) {
	if(isEmpty(*s)) {
		return False;
	} char val=0;
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
int validate(char a[]){	
	Q q=createQ(length(a)+1);
	Q q1=createQ(length(a)+1);
	Q q3=createQ(length(a)+1);
	Stack q2=CreateStack();
	int i=0;
	while(a[i]!='.'){
		insert(&q,a[i]);
		insert(&q3,a[i]);
		i++;
	}
	i++;
	while(a[i]!='.'){
		insert(&q1,a[i]);
		i++;
	}
	i++;
	while(a[i]!='\0'){
		push(&q2,a[i]);
		i++;
	}

	while(!(isEmpty1(q))&&!(isEmpty1(q1))&&!(isEmpty(q2))&&!(isEmpty1(q3))){
		if(Delete(&q)!=Delete(&q1) || (Delete(&q3)!=pop(&q2))){
			return 0;
		}
		
	}
	if(!(isEmpty1(q) )|| !(isEmpty1(q1))|| !(isEmpty1(q3) )|| !(isEmpty(q2))){
		return 0;
	}
	if(a[i]!='\0'){
		return 0;
	}
	return 1;
}	
int main(){
	char s[15],v[15];
	printf("enter the string :");
	scanf("%s",s);
	printf("%d",validate(s));

return 0;
}
	