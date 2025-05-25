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
    ListNode* reversesub(ListNode* H, ListNode* T) {
        ListNode* curr = H;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while (curr != T) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev; // New head of reversed part
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0); // Dummy node before head
        dummy.next = head;
        ListNode* prevGroupTail = &dummy;
        ListNode* Head = head;

        while (true) {
            ListNode* Tail = Head;

            // Check if there are at least k nodes ahead
            for (int i = 0; i < k; ++i) {
                if (!Tail) return dummy.next; // Not enough nodes
                Tail = Tail->next;
            }

            // Reverse sublist from Head to Tail (exclusive)
            ListNode* reversedHead = reversesub(Head, Tail);

            // Link previous group's tail to new head
            prevGroupTail->next = reversedHead;

            // Head now becomes tail of the reversed sublist
            Head->next = Tail;

            // Update for next iteration
            prevGroupTail = Head;
            Head = Tail;
        }

        return dummy.next;
    }
};
