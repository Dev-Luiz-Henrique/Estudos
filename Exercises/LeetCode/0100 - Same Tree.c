/*
    Given the roots of two binary trees p and q, write a function to check if they are the same or not.

    Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
*/

#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(!p && !q) return 1;
    if(!p || !q || p->val != q->val) return 0;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(){
    return 0;
}