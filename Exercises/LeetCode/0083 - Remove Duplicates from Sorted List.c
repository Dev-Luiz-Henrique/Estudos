/*
    Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
    Return the linked list sorted as well.
*/

#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// First Solution
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(!head) return head;
    struct ListNode* prev = head;
    struct ListNode* curr = NULL;
    curr = head->next;
    while(curr){
        if(prev->val == curr->val)
            prev->next = curr->next;
        else 
            prev = curr;
        curr = curr->next;
    }
    return head;
}

// Optimized Solution
struct ListNode* deleteDuplicates2(struct ListNode* head) {
    struct ListNode* curr = head;
    while(curr && curr->next){
        if(curr->val == curr->next->val)
            curr->next = curr->next->next;
        else
            curr = curr->next;
    }
    return head;
}

int main(){
    return 0;
}