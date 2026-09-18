/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.*/
#include<stdlib.h>
#include<stdio.h>
int** create2DArray(int rows, int cols) {
    int** arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }
    return arr;
}
int* create1DArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    return arr;
}
void intialize1DArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]); // Initialize with values from user input
    }
}
void display1DArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void intialize2DArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]); // Initialize with values from user input
        }
    }
}
void display2DArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
void sortArray(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **threesum=create2DArray(numsSize, 3); 
    sortArray(nums,numsSize); 
    int count=0,a=0;
    *returnColumnSizes = create1DArray(numsSize);
    for(int i=0;i<numsSize;i++){
        a=(i-1)<0?0:(i-1);
        if(i > 0 && nums[i] == nums[a])
            continue;
        else{
        for(int j=i+1;j<numsSize;j++){
            if(j > i+1 && nums[j] == nums[j-1])
                continue;
            for(int k=j+1;k<numsSize;k++){
                
                if(nums[i]+nums[j]+nums[k]==0){
    
                    threesum[count][0]=nums[i];
                    threesum[count][1]=nums[j];    
                    threesum[count][2]=nums[k];
                     (*returnColumnSizes)[count]=3;
                    count++;
                    while(k + 1 < numsSize && nums[k] == nums[k + 1])
                        k++;
                }
            }
           
        }}

    }
    *(returnSize)=count;
    return threesum;
}


int main(){
    int n,returnSize=0;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int* arr = create1DArray(n),**b=create2DArray(n,0),**c=create2DArray(n,3);;
    intialize1DArray(arr, n);
    sortArray(arr, n);
    display1DArray(arr, n);
    c=threeSum(arr, n, &returnSize, b);
    display2DArray(c, returnSize, 3);
    free(arr);
    for(int i=0;i<returnSize;i++){  
        free(c[i]);
    }
    free(c);
    free(b);

return 0;
}
/*
optimized solution 
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    // Sort the array
    sortArray(nums, numsSize);

    // Maximum possible number of answers
    int **ans = malloc((numsSize )*(numsSize-1)* sizeof(int*));

    *returnColumnSizes = malloc((numsSize )*(numsSize-1) * sizeof(int));

    int count = 0;

    for (int i = 0; i < numsSize - 2; i++) {

        // Skip duplicate first values
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        // Since array is sorted, no possible answer
        // if nums[i] is already greater than 0
        if (nums[i] > 0)
            break;

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {

            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {

                ans[count] = malloc(3 * sizeof(int));

                ans[count][0] = nums[i];
                ans[count][1] = nums[left];
                ans[count][2] = nums[right];

                (*returnColumnSizes)[count] = 3;

                count++;

                // Skip duplicate left values
                while (left < right &&
                       nums[left] == nums[left + 1])
                    left++;

                // Skip duplicate right values
                while (left < right &&
                       nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            }

            else if (sum < 0) {
                left++;
            }

            else {
                right--;
            }
        }
    }

    *returnSize = count;

    return ans;
}*/