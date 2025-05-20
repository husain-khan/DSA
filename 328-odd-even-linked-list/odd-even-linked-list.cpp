class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;  // base case

        ListNode* temp = head;
        vector<int> v;

        // Remove even-indexed nodes and collect their values
        while (temp != NULL && temp->next != NULL) {
            ListNode* toDelete = temp->next;
            v.push_back(toDelete->val);
            temp->next = toDelete->next;
            delete toDelete;
            temp = temp->next;
        }

        // Move temp to the end of the current (shortened) list
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Re-append even-indexed values
        for (int i = 0; i < v.size(); i++) {
            temp->next = new ListNode(v[i]);
            temp = temp->next;
        }

        return head;
    }
};
