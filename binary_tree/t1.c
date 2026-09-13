/*
This program is intended to create a Binary Search Tree 
using strings and display the inorder traversal along with 
counts of leaf nodes, nodes with one child, and nodes with 
two children.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    char data[50];
    struct node *left, *right;
} BT;

void assign(char *t1, char *t2)
{
    int i = 0;
    while (t2[i])
    {
        t1[i] = t2[i];
        i++;
    }
    t1[i] = '\0';
}

BT* makeNode(char *data)
{
    BT *t = (BT *)malloc(sizeof(BT));

    assign(t->data, data);
    t->left = t->right = NULL;

    return t;
}

void inOrder(BT *t)
{
    if (t)
    {
        inOrder(t->left);
        printf("%5s", t->data);
        inOrder(t->right);
    }
}

BT *insert(BT *t, char *data)
{
    if (!t)
        return makeNode(data);

    if (strcmp(t->data, data) > 0)
        t->left = insert(t->left, data);

    else if (strcmp(t->data, data) < 0)
        t->right = insert(t->right, data);

    return t;
}

int countLeaf(BT *t)
{
    if (!t)
        return 0;

    if (!t->right && !t->left)
        return 1;

    return countLeaf(t->left) + countLeaf(t->right);
}

int count1(BT *t)
{
    if (!t)
        return 0;

    if (t->right && t->left)
        return count1(t->right) + count1(t->left);

    if (!t->right && !t->left)
        return 0;

    if (!t->right)
        return 1 + count1(t->left);

    return 1 + count1(t->right);
}

int count2(BT *t)
{
    if (!t)
        return 0;

    if (t->right && t->left)
        return 1 + count2(t->right) + count2(t->left);

    if (!t->right && !t->left)
        return 0;

    if (!t->right)
        return count2(t->left);

    return count2(t->right);
}

int main()
{
    int n;
    char ch[50];
    BT *t = NULL;

    printf("Enter The No.Of Elements : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter The Element %d : ", i + 1);
        scanf("%s", ch);
        t = insert(t, ch);
    }

    printf("\nInOrder : ");
    inOrder(t);

    printf("\nCount Leaf : %d", countLeaf(t));
    printf("\nCount Of One Child : %d", count1(t));
    printf("\nCount Of Two Children : %d", count2(t));

    return 0;
}