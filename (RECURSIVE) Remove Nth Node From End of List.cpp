class Solution {
private:
    int removeNode(ListNode* node, int n) {
        if (node == NULL) return 0;
        int index = removeNode(node->next, n) + 1;
        if (index == n + 1) { // We are at the node just before the nth node from the end
            ListNode* toDelete = node->next;
            node->next = node->next->next;
            delete toDelete; 
        }
        return index;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0); // Create a dummy node to handle edge cases easily
        dummy->next = head;
        removeNode(dummy, n);
        ListNode* newHead = dummy->next;
        delete dummy; // Clean up dummy node
        return newHead;
    }
};
