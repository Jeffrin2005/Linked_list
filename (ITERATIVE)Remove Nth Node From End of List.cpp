class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // First pass: Calculate the total length of the linked list
        int length = 0;
        ListNode* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        
        // If the node to remove is the head
        if (n == length){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        
        // Second pass: Find the (length - n)th node
        current = head;
        for (int i = 1; i < length - n; ++i) {
            current = current->next;
        }
        
        // Remove the nth node from the end
        ListNode* nodeToRemove = current->next;
        current->next = current->next->next;
        delete nodeToRemove;
        
        return head;
    }
};
