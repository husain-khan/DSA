// #include <bits/stdc++.h>
#include<map>
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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int> visited;

        ListNode* temp=head;
        while(temp!=NULL){
            if(visited[temp]){
                return temp;
            }
            visited[temp]=1;
            temp=temp->next;
        }

        // ListNode* fast=head;
        // ListNode* slow=head;


        // While(fast!=NULL && fast->next!=NULL){
        // //    fast->next->next;
        // //    slow->next;
           
        // }
        return NULL;
    }
};