
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // If the list is empty or has only one node, no rotation is needed
        if (head == NULL || head->next == NULL || k == 0) return head;
        // First, compute the length of the list and get the last node
        ListNode* old_tail = head;
        int length = 1; // Start counting from head
        while(old_tail->next != NULL){
            old_tail = old_tail->next;
            length++;
        }
        // Make the list circular by connecting the last node to the head
        old_tail->next = head;
        // Compute the effective rotations needed as k might be greater than length
        k = k % length;

        // If k is 0 after modulo, no rotation is needed
        if (k == 0) {
            old_tail->next = NULL; // Break the circular connection
            return head;
        }
        // Find the new tail: (length - k)th node from the beginning
        // and the new head: (length - k + 1)th node
        ListNode* new_tail = head;
        for(int i = 1; i < length - k; i++){
            new_tail = new_tail->next;
        }
        ListNode* new_head = new_tail->next;  // and the new head: (length - k + 1)th node

        // Break the circular connection to finalize the rotated list
        new_tail->next = NULL;
        return new_head;
    }
};
