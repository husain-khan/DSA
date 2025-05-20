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
    bool isPalindrome(ListNode* head) {
        // ListNode* slow=head;
        ListNode* fast=head;
        vector<int> storage;
        string s;
        while(fast!=NULL){
            s.push_back(fast->val);
            fast=fast->next;
        }
        string r=s;
        reverse(r.begin(),r.end());
        if(s==r){
            return true;
        }
        else {
            return false;
        }
    }
};