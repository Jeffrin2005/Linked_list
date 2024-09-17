class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case: if the list is empty or has only one element
         if (head == NULL || head->next == NULL) {
            return head;
        }

        // Recursive case: reverse the rest of the list
        ListNode* rest = reverseList(head->next);

        // Reversal step: make the next node point to the current node
        head->next->next = head;
        head->next = NULL; // Set the current node's next to nullptr

        return rest; // Return the new head of the reversed list
    }
};
