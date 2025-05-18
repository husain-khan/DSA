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
    ListNode* middleNode(ListNode* head) {
        int size=1;

        ListNode* temp=head;
        
        if(head==NULL){
            return head;
        }
        while(temp->next!=NULL){
            size++;
            temp=temp->next;
        }
          int middle=size/2;
          ListNode* temp1=head;
        for(int i=0;i<middle;i++){
            temp1=temp1->next;
        }
        return temp1;
    }
};
