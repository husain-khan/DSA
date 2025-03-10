class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;

        while (head != NULL) {
            if (visited.find(head) != visited.end()) {
                return true; // Cycle detected
            }
            visited.insert(head);
            head = head->next;
        }

        return false; // No cycle if end of list is reached
    }
};
