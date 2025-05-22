#include <bits/stdc++.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> store;
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        while(tempA!=NULL){
            store[tempA]=1;
            tempA=tempA->next;
        }
        while(tempB!=NULL){
            if(store[tempB]==1){
                return tempB;
            }
            tempB=tempB->next;
        }
        return NULL;
    }
};