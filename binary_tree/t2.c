/*
Program Description

This C program implements a Binary Search Tree (BST) 
with duplicate element counting.
Unlike a normal BST where duplicate values are ignored,
this program stores the number of occurrences of each 
element using a count variable.

Operations performed
Node Creation – makeNode() creates a new node with:
data → stores the value
count → stores frequency of the value
Insertion – isert() inserts elements into the BST:
Smaller values go to the left subtree.
Larger values go to the right subtree.
Duplicate values increase the count of the existing node.
Inorder Traversal – Displays elements in sorted order as:*/
#include <stdio.h>
#include <stdlib.h>
typedef enum { False,True} Bool;
typedef struct node
{
    int data;
    int count;
    struct node *left;
    struct node *right;
} BT;
BT *makeNode(int x)
{
    BT *temp = (BT *)malloc(sizeof(BT));

    temp->data = x;
    temp->count=1;
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

    if(!t) return makeNode(data);
    if(t->data>data) t->left = isert(t->left,data);
    else if(t->data<data) t->right = isert(t->right,data);
    else t->count++;

    return t;

}


int count(BT *root)
{
    if (root == NULL)
        return 0;

    return 1 + count(root->left) + count(root->right);
}


/* Height */
int height(BT *root)
{
    int lh, rh;

    if (root == NULL)
        return 0;

    lh = height(root->left);
    rh = height(root->right);

    if (lh > rh)
        return lh + 1;
    else
        return rh + 1;
}


/* Preorder - Root Left Right */

/* Inorder - Left Root Right */
void inorder(BT *root)
{
    if (root == NULL)
        return;

    inorder(root->left);

    printf("(%d,%d)", root->data,root->count);

    inorder(root->right);
}




int main(){

BT *root = NULL,*l=NULL;
    int n, x, i;
    printf("Binary Tree1\n");
    for (i = 0; i < 500; i++)
    {
        root=isert(root, rand()%10);
    }
    printf("\nInorder Traversal : ");
    inorder(root);
    return 0;
}
