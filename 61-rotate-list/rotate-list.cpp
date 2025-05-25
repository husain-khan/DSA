class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Compute the length and make the list circular
        ListNode* temp = head;
        int length = 1;
        while (temp->next != NULL) {
            temp = temp->next;
            length++;
        }
        temp->next = head;  // Make it circular

        // Step 2: Find new tail at (length - k % length - 1)th node
        k = k % length;
        int stepsToNewTail = length - k;

        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        // Step 3: Set new head and break the cycle
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};
