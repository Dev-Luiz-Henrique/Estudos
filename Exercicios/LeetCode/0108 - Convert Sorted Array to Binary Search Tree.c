/*
    Given an integer array nums where the elements are sorted in ascending order, 
        convert it to a height-balanced binary search tree.
*/

#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* balanced(int* nums, int start, int end) {
    if(start > end) return NULL;
    int middle = (start + end) / 2;

    struct TreeNode* root = (struct TreeNode*) malloc (sizeof(struct TreeNode));
    root->val   = nums[middle];
    root->left  = balanced(nums, start, middle-1);
    root->right = balanced(nums, middle+1, end);
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return balanced(nums, 0, numsSize-1);
}

int main(){
    return 0;
}