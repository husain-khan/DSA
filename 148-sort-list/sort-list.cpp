#include<bits/stdc++.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* temp=head;
        vector<int> storage;
        ListNode* temp1=head;
        
        if (head == nullptr || head->next == nullptr){
    return head;}

        while(temp!=NULL){
            int nums=temp->val;
            storage.push_back(nums);
            temp=temp->next;
        }
        sort(storage.begin(),storage.end());
        int i=0;
        int n=storage.size();

        
        while(temp1 !=NULL && i<n){
            if(temp1->val != storage[i]){
                temp1->val=storage[i];
            }
            temp1=temp1->next;
            i++;
        }
        return head;
    }
};