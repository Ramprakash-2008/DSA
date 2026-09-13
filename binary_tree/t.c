#include <stdio.h>
#include <stdlib.h>
typedef enum { False,True} Bool;
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} BT;
BT *makeNode(int x)
{
    BT *temp = (BT *)malloc(sizeof(BT));

    temp->data = x;
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
Bool isIdentical(BT* r1, BT* r2) {
    if (r1 == NULL && r2 == NULL)
        return True;
    if (r1 == NULL || r2 == NULL)
        return False;
    return (r1->data == r2->data) &&
           isIdentical(r1->left, r2->left) &&
           isIdentical(r1->right, r2->right);
}
BT * isert(BT *t, int data)

{

    if(!t)

        return makeNode(data);

    if(t->data>data)

        t->left = isert(t->left,data);

    if(t->data<data)

        t->right = isert(t->right,data);

    return t;

}

int search(BT *root, int key)
{
    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;

    return search(root->left, key) ||
           search(root->right, key);
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
void preorder(BT *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);

    preorder(root->left);
    preorder(root->right);
}


/* Inorder - Left Root Right */
void inorder(BT *root)
{
    if (root == NULL)
        return;

    inorder(root->left);

    printf("%d ", root->data);

    inorder(root->right);
}


/* Postorder - Left Right Root */
void postorder(BT *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);

    printf("%d ", root->data);
}
BT *Delete(BT *t,int data)
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
    if(t->data>data)
        t->left=Delete(t->left,data);
    else
        t->right=Delete(t->right,data);
    return t;
}

int main(){

BT *root = NULL,*l=NULL;
    int n, x, i, key;
    printf("Binary Tree1\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &x);
        root=isert(root, x);
    }

    printf("%d elements inserted successfully.\n", n);

    printf("\nInorder Traversal : ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n\nNumber of nodes: %d", count(root));

    printf("\nHeight of tree: %d", height(root));

    printf("\n\nEnter element to search: ");
    scanf("%d", &key);
    if(search(root, key))
        printf("%d is found in the tree.", key);
    else
        printf("%d is not found in the tree.", key);
    printf("\nMin value and Max value in tree : %d,%d",minNode(root),maxNode(root));
    printf("\n\nEnter element to delete: ");
    scanf("%d", &key);
    root=Delete(root,key);
    printf("After delete of element %d the tree become :\n",key);
    printf("\nInorder Traversal : ");
    inorder(root);
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    printf("\n\nNumber of nodes: %d", count(root));
    printf("\nHeight of tree: %d", height(root));
    printf("\nMin value and Max value in tree : %d,%d",minNode(root),maxNode(root));
    printf("\nBinary Tree2\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &x);
        l=isert(l, x);
    }
    if(isIdentical(root,l)){
        printf("Two trees are same\n");
    }
    else printf("Two trees aren't same\n");
    return 0;
}
