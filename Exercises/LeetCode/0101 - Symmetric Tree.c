/*
    Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
*/

#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool helper(struct TreeNode* L, struct TreeNode* R){
    if(!L && !R) return 1;
    if(!L || !R || (L->val != R->val) ) return 0;
    return helper(L->left, R->right) && helper(L->right, R->left);
}

bool isSymmetric(struct TreeNode* root) {
    if(!root) return true;
    return helper(root->left, root->right);
}

int main(){
    return 0;
}