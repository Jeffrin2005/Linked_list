class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy node that points to the head of the list
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        // Create a pointer to traverse the list, starting from the dummy node
        ListNode* current = dummy;
        // Traverse the list
        while (current->next != NULL){
            if(current->next->val == val){
                // If the next node should be removed, skip it
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp; // Free memory
            } else {
                // Otherwise, move to the next node
                current = current->next;
            }
        }
        // The new head of the list is the node after the dummy node
        ListNode* newHead = dummy->next;
        delete dummy; // Free the dummy node
        return newHead;
    }
};
