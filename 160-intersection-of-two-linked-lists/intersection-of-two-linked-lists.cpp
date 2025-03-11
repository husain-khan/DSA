class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pointerA = headA;
        ListNode *pointerB = headB;
        
        while (pointerA != pointerB) {
            // Move pointerA one step forward
            if (pointerA) {
                pointerA = pointerA->next;
            } else {
                pointerA = headB; // Redirect to the head of list B
            }
            
            // Move pointerB one step forward
            if (pointerB) {
                pointerB = pointerB->next;
            } else {
                pointerB = headA; // Redirect to the head of list A
            }
        }
        
        // Return the intersection node or nullptr
        return pointerA;
    }
};
