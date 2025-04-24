/*
    You are given two non-empty linked lists representing two non-negative integers. 
    The digits are stored in reverse order, and each of their nodes contains a single digit. 
    Add the two numbers and return the sum as a linked list.
    
    You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = (struct ListNode*) malloc (sizeof(struct ListNode));
    head->val = 0;
    head->next = NULL;

    int ac = 0; // Acumulattor
    struct ListNode* tail = head;
    while(l1 || l2 || ac){ 
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + ac;
        ac = sum / 10;

        tail->next = (struct ListNode*) malloc (sizeof(struct ListNode));
        tail->next->val = sum % 10;
        tail->next->next = NULL;
        tail = tail->next;

        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
    struct ListNode* lr = head->next;
    free(head);
    return lr;
}

int main() {
    return 0;
}