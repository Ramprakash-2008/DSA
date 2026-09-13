#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Enter the non-zero values of the matrix: ");
    scanf("%d",&n);
    //dynamic memory allocation for 2D array
    int **a;    
    a= (int **)malloc((n+1) * sizeof(int *)); 
    for(int i=0;i<n+1;i++){
        a[i]= (int *)malloc(3 * sizeof(int));
    }
    printf("Enter the elements of the matrix:\n");
    for(int i=0;i<n+1;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int row=a[0][0], col=a[0][1];
    //dynamic memory allocation for 2D array
    int **b;
    b= (int **)malloc((a[0][0]) * sizeof(int *)); 
    for(int i=0;i<a[0][0]+1;i++){
        b[i]= (int *)malloc(a[0][1] * sizeof(int));
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            b[i][j]=0;
            }
        }
    for(int i=1;i<=n;i++){
        b[a[i][0]][a[i][1]]=a[i][2];
    }   
    printf("The matrix from sparse representation is:\n");
    for(int i=0;i<row;i++){   
        for(int j=0;j<col;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
  
    return 0;
}