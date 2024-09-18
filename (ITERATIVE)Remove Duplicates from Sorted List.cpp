class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL) return head; // If the list is empty, return it as is.

        ListNode* current = head;
        while(current->next != NULL){
            if(current->val == current->next->val) {
                ListNode* temp = current->next;
                current->next = temp->next; // Skip the duplicate node.
                delete temp; // Free memory of the duplicate node.
            } else {
                current = current->next; // Move to the next distinct element.
            }
        }
        return head;
    }
};
