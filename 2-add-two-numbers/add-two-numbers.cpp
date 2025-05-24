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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy;

        ListNode* temp1=l1;
        ListNode* temp2=l2;
        stack<int> ans;
        int carry=0;
        while(temp1!=NULL|| temp2!=NULL){

            int n = (temp1 != NULL) ? temp1->val : 0;
            int m = (temp2 != NULL) ? temp2->val : 0;

            int sum=n+m+carry;
            carry=sum/10;
            int digit=sum%10;
            ans.push(digit);
            
            if (temp1 != NULL) temp1 = temp1->next;
            if (temp2 != NULL) temp2 = temp2->next;
            
        }
        if(carry) ans.push(carry);
        ListNode* head=NULL;

        while(!ans.empty()){
            ListNode* newnode=new ListNode(ans.top());
            ans.pop();
            newnode->next=head;
            head=newnode;
        }
        return head;
    }
};