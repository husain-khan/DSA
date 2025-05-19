#include <iostream>
#include <unordered_map>

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
   unordered_set<ListNode*> storage; 
    bool hasCycle(ListNode *head) {
        ListNode* temp=head;
        while(temp!=NULL){
           auto num=temp->next;
           storage.insert(temp);

           if(storage.count(num)>0){
              return true;
           }
           temp=temp->next;

        }

        return false;
        
    }
};