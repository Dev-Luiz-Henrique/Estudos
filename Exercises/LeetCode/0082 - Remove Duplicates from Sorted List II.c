/*
    Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
        leaving only distinct numbers from the original list. 
    
    Return the linked list sorted as well.
*/

#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(!head) return head;
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = head->next;

    while(curr && next){
        if(curr->val == next->val){
            while(next && curr->val == next->val)
                next = next->next;
            if(!prev) 
                head = next;
            else
                prev->next = next;
        }
        else 
            prev = curr;
        curr = next;
        next = next ? next->next : NULL;
    }
    return head;
}

int main(){
    return 0;
}