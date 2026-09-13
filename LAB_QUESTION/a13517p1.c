//divide the 2^n x 2^n matrix into four submatrix with  2^n-1 x 2^n-1
#include<stdio.h>
#include<stdlib.h>
int** createMatrix(int n){
	int** a=(int**)malloc(n*sizeof(int*));
	for(int i=0;i<n;i++){
		a[i]=(int*)malloc(n*sizeof(int));
	}
	return a;
}
void init(int** a,int n){
	for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		a[i][j]=rand()%100;
	}}
}
void display(int **a,int n){
	for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		printf("%d ",a[i][j]);
	}
	printf("\n");
	}printf("\n");
}
void fourdiv(int** a,int n){
	int** A11=createMatrix(n/2);
	int** A12=createMatrix(n/2);
	int** A21=createMatrix(n/2);
	int** A22=createMatrix(n/2);
	init(A11,n/2);
	init(A12,n/2);
	init(A21,n/2);
	init(A22,n/2);
	for(int i=0;i<(n/2);i++){
	for(int j=0;j<(n/2);j++){
		A11[i][j]=a[i][j];
	}}
	for(int i=(n/2);i<n;i++){
	for(int j=0;j<(n/2);j++){
		A12[i-(n/2)][j]=a[i][j];
	}}
	for(int i=0;i<(n/2);i++){
	for(int j=(n/2);j<n;j++){
		A21[i][j-(n/2)]=a[i][j];
	}}
	for(int i=(n/2);i<n;i++){
	for(int j=(n/2);j<n;j++){
		A22[i-(n/2)][j-(n/2)]=a[i][j];
	}}
	printf("Matrix A11 :\n");
	display(A11,n/2);
	printf("Matrix A12 :\n");
	display(A12,n/2);
	printf("Matrix A21 :\n");
	display(A21,n/2);
	printf("Matrix A22 :\n");
	display(A22,n/2);
	}


int main(){
	int n,m=1;int** b;
	printf("enter the n value for matrix :");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
	m*=2;}
	b=createMatrix(m);
	init(b,m);
	display(b,m);
	fourdiv(b,m);
	return 0;
}
