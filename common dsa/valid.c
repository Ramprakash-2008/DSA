typedef struct Stack{
	char *arr;
	int top;
} Stack;
typedef enum { false,true} bool;
Stack CreateStack() {
	Stack s;
	s.top=0;
	return s;
}
int length(char n[]){int i=0;
    while(n[i]){
        i++;}
        return i;
    }
bool valid(char n[]){ Stack s1=CreateStack(); for(int i=0;i<length(n);i++){
	if(n[i]=='(' || n[i]=='{' || n[i]=='['){
	push(&s1,n[i]);}
	else if(n[i]==')' || n[i]=='}' || n[i]==']'){
		if(isEmpty(s1)){return false;}
		else{
			char c=pop(&s1);
			if((n[i]==')' && c!='(') || (n[i]=='}' && c!='{') || (n[i]==']' && c!='[')){
				return false;
			}
		}
	}
	if(isEmpty(s1)){return true;}
	else{return false;}
}
}
bool isValid(char* s) {
    return valid(s);
}