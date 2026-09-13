/*
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1]*/
#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int*  result =(int *)malloc(2 * sizeof(int));
    for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]== target){
                result[0]=i;

                result[1]=j;
                *returnSize=2;
                printf("[%d,%d]",result[0],result[1]);
                return result;
            }
        }
    } 
    *returnSize=0;
    free(result);
    return NULL;   
}
int main(){
int *arr,n,m;
    printf("enter the size of array :");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
     printf("enter the sum number :");
    scanf("%d",&m);int *result=(int*)2;
    twoSum(arr,n,m,result);
   free(arr);
}
