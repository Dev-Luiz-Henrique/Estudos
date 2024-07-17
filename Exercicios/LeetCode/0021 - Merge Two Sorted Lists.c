/*
    You are given the heads of two sorted linked lists list1 and list2.
    Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
    Return the head of the merged linked list.
*/

#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (!list1 && !list2) return NULL;
    if (!list1) return list2;
    if (!list2) return list1;
    
    struct ListNode* listM = (struct ListNode*) malloc (sizeof(struct ListNode));
    struct ListNode* L = listM;
    while(list1 && list2){
        if(list1->val < list2->val){
            L->next = list1;
            list1 = list1->next;
        }
        else {
            L->next = list2;
            list2 = list2->next;
        }
        L = L->next;
    }
    if(list1) L->next = list1;
    else L->next = list2;
    return listM->next;
}

int main(){
    return 0;
}