/*
    Given the head of a singly linked list where elements are sorted in ascending order, 
        convert it to a height-balanced binary search tree.
*/

#include <stdlib.h>
#include <stdbool.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* helper(struct ListNode* head, struct ListNode* tail) {
    if(head == tail) return NULL;
    struct ListNode* slow = head; // Slow will be the middle
    struct ListNode* fast = head;
        
    // Find middle
    while(fast != tail && fast->next != tail) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct TreeNode* root = (struct TreeNode*) malloc (sizeof(struct TreeNode));
    root->val   = slow->val;
    root->left  = helper(head, slow);
    root->right = helper(slow->next, tail);
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    return helper(head, NULL);
}

int main(){
    return 0;
}