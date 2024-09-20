
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Create a dummy node with value 0
        ListNode* dummy = new ListNode(0);
        // Assign the next pointer of dummy to head
        dummy->next = head;
        ListNode* prev = dummy; // Pointer to the node before the current sequence
        ListNode* current = head; // Pointer to traverse the list
        while(current != NULL){
            bool duplicate = false;
            // Check if the current node has duplicates
            while(current->next != NULL && current->val == current->next->val) {
                duplicate = true;
                current = current->next; // Skip the duplicate
            }
            if(duplicate==true){
                // Skip all duplicates
                prev->next = current->next;
            }else{
                // No duplicates, move prev to current
                prev = prev->next;
            }

            current = current->next; // Move to the next distinct element
        }

        // Get the new head and delete the dummy node to free memory
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
