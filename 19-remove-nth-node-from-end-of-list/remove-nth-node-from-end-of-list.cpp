class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast pointer n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If fast is null, we need to remove the head
        if (fast == NULL) {
            ListNode* to_delete = head;
            head = head->next;
            delete to_delete;
            return head;
        }

        // Move both pointers until fast reaches the last node
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete the nth node from end
        ListNode* to_delete = slow->next;
        slow->next = to_delete->next;
        delete to_delete;

        return head;
    }
};
