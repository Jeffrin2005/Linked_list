class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Base case: If the list is empty or has only one node, return it as is.
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Recursive call on the next node
        head->next = deleteDuplicates(head->next);

        // If the current node has the same value as the next node, skip the next node
        if (head->val == head->next->val) {
            ListNode* temp = head->next;
            head->next = head->next->next; // Skip the duplicate node
            delete temp; // Free memory of the duplicate node
        }

        return head; // Return the modified list
    }
};
