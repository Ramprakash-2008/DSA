#include <stdio.h>
#include <stdlib.h>
int existsInArray(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return 1;
        }
    }
    return 0;
}
void inorder(int a[],int n,int i){
  if(2*i<n) inorder(a,n,2*i);
  printf("%d ",a[i]);
  if((2*i+1)<n) inorder(a,n,2*i+1);
    }
void preorder(int a[],int n,int i){
  
  printf("%d ",a[i]);
  if(2*i<n) preorder(a,n,2*i);
  if((2*i+1)<n) preorder(a,n,2*i+1);
    }
    void postorder(int a[],int n,int i){
  if(2*i<n) postorder(a,n,2*i);
  if((2*i+1)<n) postorder(a,n,2*i+1);
  printf("%d ",a[i]);
  
    }
int main(){
    int a[20],y[20],u=0;
    a[0]=0;
    for(int i=1;i<=10;i++){
        a[i]=i;//rand()%100;
    }
    /*for(int i=0;i<20;i++)
    if (!existsInArray(y,u, a[i])) {
            y[u++] = a[i];
        }
    
    for(int i=0;i<u;i++){
        printf("%d ",y[i]);
    }*/
    printf("Array elements : ");
     for(int i=1;i<10;i++){
        printf("%d ",a[i]);
    }
    printf("\nInorder        : ");
    inorder(a,10,1);
    printf("\nPreorder       : ");
    preorder(a,10,1);
    printf("\nPostorder      : ");
    postorder(a,10,1);
    return 0;
}