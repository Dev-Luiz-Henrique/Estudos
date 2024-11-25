/*
    Given a binary tree, determine if it is height-balanced.
*/

#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int height(struct TreeNode* root) {
    if (!root) return 0;
    return fmax(height(root->left), height(root->right)) + 1;
}

bool isBalanced(struct TreeNode* root) {
    if (!root) return true;
    if (abs(height(root->left) - height(root->right)) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}

int main(){
    return 0;
}