#include<stdio.h>
#include<stdlib.h>


void inOrder(int *arr,int count,int i)
{
    if(2*i<count) inOrder(arr,count,2*i);
    printf("%5d",arr[i]);
    if(2*i +1 < count) inOrder(arr,count,2*i +1);
}

void preOrder(int *arr,int count,int i)
{
    printf("%5d",arr[i]);
    if(2*i<count) preOrder(arr,count,2*i);
    if(2*i +1 < count) preOrder(arr,count,2*i +1);
}

void postOrder(int *arr,int count,int i)
{
    if(2*i<count) postOrder(arr,count,2*i);
    if(2*i +1 < count) postOrder(arr,count,2*i +1);
    printf("%5d",arr[i]);
}

int main(){
    int arr[100],n=0;
    for(int i=1;i<=10;i++)
    {
        arr[i] = i;
    }
    printf("InOrder\n");
    inOrder(arr,10,1);
    printf("\nPreOrder\n");
    preOrder(arr,10,1);
    printf("\nPostOrder\n");
    postOrder(arr,10,1);
    return 0;
}
