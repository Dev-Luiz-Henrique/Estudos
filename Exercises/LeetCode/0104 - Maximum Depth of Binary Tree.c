/*
    Given the root of a binary tree, return its maximum depth.

    A binary tree's maximum depth is the number of nodes along the longest path from the root node down 
        to the farthest leaf node.
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {
    if(!root) return 0;
    return 1 + fmax(maxDepth(root->left), maxDepth(root->right));
}

int main(){
    return 0;
}