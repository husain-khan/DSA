class Solution {
public:
    struct compare {
        bool operator()(const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        
        // Insert heads of non-empty lists into min-heap
        for (ListNode* head : lists) {
            if (head) {
                minHeap.push(head);
            }
        }
        
        // Create dummy node for merged list
        ListNode* dummyHead = new ListNode();
        ListNode* current = dummyHead;
        
        // Merge process
        while (!minHeap.empty()) {
            ListNode* smallestNode = minHeap.top();
            minHeap.pop();
            
            current->next = smallestNode;
            current = current->next;
            
            if (smallestNode->next) {
                minHeap.push(smallestNode->next);
            }
        }
        
        return dummyHead->next;
    }
};
