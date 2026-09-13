/*
This C program:

Dynamically allocates memory for a matrix.
Accepts matrix elements from the user.
Counts the non-zero elements.
Converts the normal matrix into 3-tuple sparse matrix representation:
Row index
Column index
Value
Finds the transpose of the sparse matrix by swapping row and column positions.
Displays both the sparse matrix and its transpose.

⚠️ Your pasted code has a few brace/semicolon errors near the end. The expected logic and output are as follows.

Sample Input

Suppose the user enters a 3 × 4 matrix:

Enter the number of rows and columns of the matrix: 3 4
Enter the elements of the matrix:
0 0 3 0
22 0 0 0
0 0 0 7*/
#include<stdio.h>
#include<stdlib.h>
int main(){
    int r,c;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d",&r,&c);
    //dynamic memory allocation for 2D array
    int **a;    
    a= (int **)malloc(r * sizeof(int *)); 
    for(int i=0;i<r;i++){
        a[i]= (int *)malloc(c * sizeof(int));
    }
    printf("Enter the elements of the matrix:\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int row=r, col=c,n=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(a[i][j]!=0){
                n++;//printf("%d ",a[i][j]);
            }
        }
    }
    //dynamic memory allocation for 2D array
    int **b;
    b= (int **)malloc((n + 1) * sizeof(int *)); 
    for(int i=0;i<n+1;i++){
        b[i]= (int *)malloc(3 * sizeof(int));
    }
    b[0][0]=row;
    b[0][1]=col;    
    b[0][2]=n;
    int k=1;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(a[i][j]!=0){
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=a[i][j];
                k++;
            }
        }
    }
    printf("The sparse matrix is:\n");
    for(int i=0;i<=n;i++){   
        for(int j=0;j<3;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    //transverse of sparse matrix
    int **z;
    z= (int **)malloc((n + 1) * sizeof(int *));
    for(int i=0;i<n+1;i++){
        z[i]= (int *)malloc(3 * sizeof(int));
    }
    z[0][0]=col;
    z[0][1]=row;    
    z[0][2]=n;
    int g=1;
    for(int i=0;i<col;i++){ 
        for(int j=1;j<=n;j++){
            if(b[j][1]==i){
                z[g][0]=b[j][1];
                z[g][1]=b[j][0];
                z[g][2]=b[j][2];
                g++;
            }
        }
    }
    ;
    }//fast tranfer algorithm
    /*int *count;
    count= (int *)malloc(col * sizeof(int));
    for(int i=0;i<col;i++){
        count[i]=0;
    }
    for(int i=1;i<=n;i++){
        count[b[i][1]]++;
    }
    printf("The count of non-zero elements in each column is:\n");
    for(int i=0;i<col;i++){
        printf("%d ",count[i]);
    }
    int *index;
    index= (int *)malloc(col * sizeof(int));
    for(int i=0;i<col;i++){
        index[i]=0;
    }
    index[0]=1;
    for(int i=1;i<col;i++){
        index[i]=index[i-1]+count[i-1];
    }
    for(int i=1;i<=n;i++){
        int j=b[i][1];
        z[index[j]][0]=b[i][1];
        z[index[j]][1]=b[i][0];
        z[index[j]][2]=b[i][2];
        index[j]++;
    }*/
    printf("\nThe transverse of sparse matrix is:\n");
    for(int i=0;i<=n;i++){   
        for(int j=0;j<3;j++){
            printf("%d ",z[i][j]);
        }
        printf("\n")
    return 0;
}