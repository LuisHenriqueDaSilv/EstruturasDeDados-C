#include <stdio.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode ;

// Solution:

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *cur = head;

    while(cur != NULL && cur->next != NULL){
        if(cur->val == cur->next->val){
            cur->next = cur->next->next;
        } else {
            cur = cur->next;
        }
    }

    return head;
}