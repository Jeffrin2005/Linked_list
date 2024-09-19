class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;

        while(current->next != NULL && current->next->next != NULL){
            ListNode* first = current->next;
            ListNode* second = current->next->next;
            // Swapping the nodes
            first->next = second->next;
            second->next = first;
            current->next = second;

            // Move to the next pair
            current = first;
        }

        ListNode* newHead = dummy->next;
        delete dummy; // Clean up dummy node
        return newHead;
    }
};
