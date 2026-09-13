// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:
//
// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
#include<stdio.h>
#include<stdlib.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int* n3=(int*)malloc(sizeof(int)*(nums1Size+nums2Size));
    for(int i=0;i<nums1Size;i++){
        n3[i]=nums1[i];
    }
    for(int i=0;i<nums2Size;i++){
        n3[nums1Size+i]=nums2[i];
    }
    for(int i=0;i<nums1Size+nums2Size;i++){
        for(int j=i+1;j<nums1Size+nums2Size;j++){
            if(n3[i]>n3[j]){
                int temp=n3[i];
                n3[i]=n3[j];
                n3[j]=temp;
            }
        }
    }
    if((nums1Size+nums2Size)%2==0){
        return (n3[(nums1Size+nums2Size)/2]+n3[(nums1Size+nums2Size)/2-1])/2.0;
    }
    else{
        return n3[(nums1Size+nums2Size)/2];
    }
}
int main(){
    int n,m;
    printf("enter the size of first array");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements of first array");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("enter the size of second array");
    scanf("%d",&m);
    int b[m];
    printf("enter the elements of second array");
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    printf("%f",findMedianSortedArrays(a,n,b,m));
}