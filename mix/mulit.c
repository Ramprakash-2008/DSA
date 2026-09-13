#include <stdio.h>
#include <stdlib.h>
typedef enum { False,True} Bool;
//BINARY TREE AND ITS FUNCTIONALITY
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} BT;
BT *makeBT(int x)
{
    BT *temp = (BT *)malloc(sizeof(BT));

    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
int maxNode(BT* t){
    if(!t) return 0;
    if(!t->right) return t->data;
    return maxNode(t->right);
}
int minNode(BT* t){
    if(!t) return 0;
    if(!t->left) return t->data;
    return minNode(t->left);
}

BT * isert(BT *t, int data)

{

    if(!t)

        return makeBT(data);

    if(t->data>data)

        t->left = isert(t->left,data);

    if(t->data<data)

        t->right = isert(t->right,data);

    return t;

}

void search(BT *root, int key,int* c)
{   
    if (root == NULL)
        return ;
    if (root->data == key){
        return ;}
    *c=*c+1;
    if(root->data>key){
        return search(root->left,key,c);
    }
    return search(root->right,key,c);
}

/* Inorder - Left Root Right */
void inorder(BT *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

//LINKEDLIST AND ITS FUNCTIONALITY

typedef struct n{
int data;
struct n* next;}NODE;

void display(NODE* l)//display
{
printf("LINKEDLIST :\n");
while(l){
printf("%5d",l->data);
l=l->next;}
}

NODE* makeLL(int data )//memory allocation for linked list
{
NODE* temp=(NODE*)malloc(sizeof(NODE));
temp->data=data;temp->next=NULL;
return temp;
}


NODE* insertTail(NODE* l,int data)//insert element at tail
{
if(!l) return makeLL(data);
NODE*t =l;
while(t->next)
{
t=t->next;
}
t->next=makeLL(data);
return l;
}

int countNodes(NODE* l)// count the no of element in linkedlist
{
int c=0;
while(l){
c++;
l=l->next;
}
return c;
}

int findpos(NODE* l,int data)//return the position of the element in linkedlist ,if not -1
{
int p=1;
while(l){
if(l->data==data)return p;
l=l->next;
p++;
}
return -1;
}
int searchL(NODE* l,int data){
    int d=0;
    if(!l) return 0;
    while(l){
        if(l->data==data) break;
        l=l->next;d++;
    }
    return d;
}


//AVL TREE AND ITS FUNCTIONALITY
typedef struct av{
int key;
int height;
struct av* l;
struct av* r;
}AVL;
AVL *makeAT(int x)
{
    AVL *temp = (AVL*)malloc(sizeof(AVL));
    temp->height=1;
    temp->key = x;
    temp->l = NULL;
    temp->r = NULL;

    return temp;
}

int max(int a,int b){
return (a>b)?a:b;
}
int height(AVL* n){
if(n==NULL){
return 0;}
return n->height;
}
int getBalance(AVL* n){
if(n==NULL){
return 0;}
return height(n->l)-height(n->r);
}

AVL* leftrotate(AVL* x){
AVL* y=x->r;
AVL* t=y->l;
y->l=x;
x->r=t;
x->height=1+max(height(x->l),height(y->r));
y->height=1+max(height(x->l),height(y->r));
return y;
}
AVL* rightrotate(AVL* y){
AVL* x=y->l;
AVL* t=x->r;
x->r=y;
y->l=t;
x->height=1+max(height(x->l),height(y->r));
y->height=1+max(height(x->l),height(y->r));
return x;
}
AVL* insertAT(AVL* root,int key){
if(root==NULL){
return makeAT(key);
}
if(key<root->key){
root->l=insertAT(root->l,key);}
else if(key>root->key){
root->r=insertAT(root->r,key);}
else return root;

root->height=1+max(height(root->l),height(root->r));
int b=getBalance(root);
if(b>1 && key<root->l->key){
return rightrotate(root);}
if(b>1 && key>root->l->key){
root->l=leftrotate(root->l);
return rightrotate(root);
}
if(b<-1 && key<root->r->key){
root->r=rightrotate(root->r);
return leftrotate(root);
}
if(b<-1 && key>root->r->key){
return leftrotate(root);
}
return root;
}
void order(AVL *root)
{
    if (root == NULL)
        return;
    order(root->l);

    printf("%d ", root->key);

    order(root->r);
}
void searchAVL(AVL*root, int key,int* c)
{   
    if (root == NULL)
        return ;
    if (root->key == key){
        return ;}
    *c=*c+1;
    if(root->key>key){
        return searchAVL(root->l,key,c);
    }
    return searchAVL(root->r,key,c);
}
//ARRAY AND ITS FUNCTIONALITY
void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n){
    int i, j;
   
    int swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
            swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (swapped==0)
            break;
    }

}
void printArr(int q[],int n){
    printf("Array elements :\n");
for(int i=0;i<n;i++){
	printf("%d, ",q[i]);
}
printf("\n");
}

int existsInArray(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return 1;
        }
    }
    return 0;
}
int searchA(int arr[], int size, int value) {
    int c=0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            break;
        }
        c++;
    }
    return c;
}
int searchSA(int arr[], int size, int value) {
    int l=0,h=size-1;int c=0;
    while(l<=h){
        c++;
        int m=l+(h-l)/2;
        if(arr[m]==value){
            return c;
        }
        else if(arr[m]<value){
            l=m+1;}
        else h=m-1;
        
    }

    return c;
}
void randomG(int z[],int n,int m){
    for(int i=0;i<n;i++){
	z[i]=rand()%m;}

}
int main(){
int z[4000],y[4000],x[4000],u=0;
int UA=0,SA=0,L=0,AL=0,B=0;
NODE* LL=NULL;
BT* tree=NULL;
AVL* a=NULL;
randomG(z,4000,10000);
for(int i=0;i<4000;i++)
    if (!existsInArray(y,u, z[i])) {
            y[u++] = z[i];
        }
//printArr(y,u);
for(int i=0;i<u;i++){
    x[i]=y[i];
}
bubbleSort(y,u);
//printArr(y,u);
for(int i=0;i<u;i++){
LL=insertTail(LL,y[i]);
}
//display(LL);
for(int i=0;i<u;i++){
tree=isert(tree,y[i]);
}
//printf("\nBINARY TREE :\n");
//inorder(tree);
for(int i=0;i<u;i++){
a=insertAT(a,y[i]);
}
//printf("\nAVL TREE :\n");
//order(a);
for(int i=0;i<50000;i++){
  SA+=searchSA(y,u,rand()%10000);
}
SA/=50000;
printf("The unsuccessfully count in Sorted Array :%d",SA);
for(int i=0;i<50000;i++){
  UA+=searchA(x,u,rand()%10000);
}
UA/=50000;
printf("\nThe unsuccessfully count in UnSorted Array:%d",UA);
for(int i=0;i<50000;i++){
  L+=searchL(LL,rand()%10000);
}
L/=50000;
printf("\nThe unsuccessfully count in linked list:%d",L);
for(int i=0;i<50000;i++){
int c=0;
search(tree,rand()%10000,&c);
B+=c;
}
B/=50000;
printf("\nThe unsuccessfully count in BinaryTree:%d",B);
for(int i=0;i<50000;i++){
    int v=0;
  searchAVL(a,rand()%10000,&v);
  AL+=v;
}
AL/=50000;
printf("\nThe unsuccessfully count in AVLTree:%d",AL);
return 0;
}
