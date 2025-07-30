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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* sum = new ListNode();
        ListNode* currentSumNode = nullptr;
        int carry = 0;

        while(l1 || l2 || carry > 0)
        {
            if (currentSumNode == nullptr)
            {
                currentSumNode = sum;
            }
            else
            {
                ListNode* lastNode = currentSumNode;
                currentSumNode = new ListNode();
                lastNode->next = currentSumNode;
            }

            if (l1)
            {
                currentSumNode->val += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                currentSumNode->val += l2->val;
                l2 = l2->next;
            }

            currentSumNode->val += carry;


            if (currentSumNode->val >= 10)
            {
                currentSumNode->val -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
        }

        return sum;
    }
};