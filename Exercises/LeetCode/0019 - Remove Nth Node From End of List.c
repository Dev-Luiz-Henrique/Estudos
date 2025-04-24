/*
    Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/

#include <stdlib.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* L = head;
    int len = 0;
    while(L){
        len++;
        L = L->next;
    }

    if(len == n) return head->next;
    L = head;
    for(int i = 0; i < len-n-1; i++) L = L->next;

    struct ListNode* tmp = L->next;
    L->next = L->next->next;
    free(tmp);
    return head;
}

int main(){
    return 0;
}