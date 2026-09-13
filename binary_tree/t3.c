/*
Program Description

This C program validates a sequence of operations using 
a Binary Search Tree (BST). The program accepts a string 
containing operation characters and performs BST operations 
based on the sequence.

D (Define/Insert): Inserts the following character into the Binary Search Tree.
U (Use/Search): Searches for the following character in the Binary Search Tree and checks whether it exists.
K (Kill/Delete): Deletes the following character from the Binary Search Tree.

The program uses a BST to perform the following operations:

Node Creation – makeNode() creates a new node containing a character.
Insertion – isert() inserts characters into the BST while maintaining BST order.
Searching – search() checks whether a specified character exists in the tree.
Finding Minimum – minNode() finds the smallest element in a subtree.
Deletion – Delete() removes a specified character from the BST.
Validation – validate() reads the input sequence and performs insert, search, and delete operations according to the operation characters.*/
#include <stdio.h>
#include <stdlib.h>
typedef enum { False,True} Bool;
typedef struct node
{
    char data;
    struct node *left;
    struct node *right;
} BT;
BT *makeNode(char x)
{
    BT *temp = (BT *)malloc(sizeof(BT));

    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
char minNode(BT* t){
    if(!t) return 0;
    if(!t->left) return t->data;
    return minNode(t->left);
}
BT * isert(BT *t, char data)

{

    if(!t)

        return makeNode(data);

    if(t->data>data)

        t->left = isert(t->left,data);

    if(t->data<data)

        t->right = isert(t->right,data);
    else {printf("not in sequence ");exit(0);}
    return t;

}

int search(BT *root, char key)
{
    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;

    return search(root->left, key) ||
           search(root->right, key);
}





void inorder(BT *root)
{
    if (root == NULL)
        return;

    inorder(root->left);

    printf("%c", root->data);

    inorder(root->right);
}



BT *Delete(BT *t,char data)
{
    if(!t)
        return NULL;
    if(!search(t,data)){printf("This element is not found");return t;}
    if(t->data==data)
    {
        if(!t->right && !t->left)
            return NULL;
        if(!t->right)
            return t->left;
        if(!t->left)
            return t->right;
        t->data=minNode(t->right);
        t->right=Delete(t->right,t->data);
        return t;
    }
    else if(t->data>data)
        t->left=Delete(t->left,data);
    else
        t->right=Delete(t->right,data);
    return t;
}

int validate(char str[]){
    BT *t = NULL;
    int i=0;
    if(str[i]!='D') {printf("Not in sequence");return 0;}
    while(str[i])
    {
        if(str[i]=='D')
        {
            t=isert(t,str[++i]);i++;
            
        }
        else if(str[i]=='U')
        {
            i++;
            if(str[i]!='D' && str[i]!='U' && str[i]!='K')
             {
                if(search(t,str[i])) i++;
                else {printf("Not valid sequence!!");return 0;}
             }
             else {printf("Not valid sequence!!");return 0;}
        }
        else if(str[i]=='K')
        {
            i=i+1;
            if(str[i]!='D' && str[i]!='U' && str[i]!='K')
            {t=Delete(t,str[i]);i++;}
        }
    }
    
    return 1;
}


int main(){


char a[10];
printf("enter the string :");
scanf("%s",a);
if(validate(a)){
    printf("Valid sequence");
}
    return 0;
}
