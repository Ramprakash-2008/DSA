//k-th Smallest in BST
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char data[50];
    struct node *left, *right;
} BT;
BT* makeNode(char *data)
{
    BT *t = (BT *)malloc(sizeof(BT));

    assign(t->data, data);
    t->left = t->right = NULL;

    return t;
}
int kthSmallestRecur(BT * root, int *cnt, int k) {
    if (!root)
        return -1;
    
    int left = kthSmallestRecur(root->left, cnt, k);

    // If kth smallest is found in left subtree, return it
    if (left != -1)
        return left;
    
    (*cnt)++;

    // If current node is kth smallest, return it
    if (*cnt == k)
        return root->data;
    
    // Else process the right subtree and return its value
    return kthSmallestRecur(root->right, cnt, k);
}
// Function to find kth Smallest
int kthSmallest(BT *root, int k) {
    int cnt = 0;
    return kthSmallestRecur(root, &cnt, k);
}

// Driver Code Starts
int main() {
    
    // Binary search tree
    //      20
    //    /   \
    //   8     22
    //  / \
    // 4   12
    //    /  \
    //   10   14

    BT* root = makeNode("20");
    root->left = makeNode("8");
    root->right = makeNode("22");
    root->left->left = makeNode("4");
    root->left->right = makeNode("12");
    root->left->right->left = makeNode("10");
    root->left->right->right = makeNode("14");
    
    int k = 3;
    printf("%d\n", kthSmallest(root, k));

    return 0;
}
// Driver Code Ends