#include<stdio.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode *root)
{
    if(root == NULL)
        return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    // 把樹分為 root, leftSubtree, rightSubtree
    // 如果 leftSubtree 的 height <= rightSubtree 的 height 的話
    // 則傳回 leftSubtree 的高度，反之傳回 rightSubtree 的 height 
    if(leftDepth >= rightDepth) 
        return leftDepth+1;
    else
        return rightDepth+1;
}